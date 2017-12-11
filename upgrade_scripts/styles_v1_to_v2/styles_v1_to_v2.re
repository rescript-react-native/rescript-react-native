module Replacements = {
  let combine = (l) =>
    List.map(((prefix, suffixes)) => List.map((suffix) => prefix ++ suffix, suffixes), l)
    |> List.flatten;
  let pt_pct =
    combine([
      ("flexBasis", [""]),
      ("max", ["Height", "Width"]),
      ("min", ["Width", "Height"]),
      ("padding", ["", "Horizontal", "Vertical", "Left", "Right", "Bottom", "Top"])
    ]);
  let pt_pct_animated_interpolated = ["height", "width", "top", "bottom", "left", "right"];
  let pt_auto =
    combine([("margin", ["", "Bottom", "Top", "Right", "Left", "Horizontal", "Vertical"])]);
  let variantReplacements = [
    ("flexStart", "FlexStart"),
    ("flexEnd", "FlexEnd"),
    ("center", "Center"),
    ("spaceAround", "SpaceAround"),
    ("spaceBetween", "SpaceBetween"),
    ("baseline", "Baseline"),
    ("flex", "Flex"),
    ("none", "None"),
    ("row", "Row"),
    ("rowReverse", "RowReverse"),
    ("column", "Column"),
    ("columnReverse", "ColumnReverse"),
    ("visible", "Visible"),
    ("hidden", "Hidden"),
    ("scroll", "Scroll"),
    ("absolute", "Absolute"),
    ("relative", "Relative"),
    ("_inherit", "Inherit"),
    ("ltr", "Ltr"),
    ("rtl", "Rtl"),
    ("solid", "Solid"),
    ("dotted", "Dotted"),
    ("dashed", "Dashed"),
    ("normal", "Normal"),
    ("italic", "Italic"),
    ("normal", "Normal"),
    ("bold", "Bold"),
    ("auto", "Auto"),
    ("left", "Left"),
    ("right", "Right"),
    ("center", "Center"),
    ("justify", "Justify"),
    ("underline", "Underline"),
    ("lineThrough", "LineThrough"),
    ("underlineLineThrough", "UnderlineLineThrough"),
    ("double", "Double"),
    ("cover", "Cover"),
    ("contain", "Contain"),
    ("stretch", "Stretch"),
    ("repeat", "Repeat"),
    ("wrap", "Wrap"),
    ("nowrap", "Nowrap")
  ];
  let suffix_pt =
    pt_auto @ pt_pct @ pt_pct_animated_interpolated |> List.map((prefix) => (prefix, prefix));
  let suffix_pct =
    pt_pct @ pt_pct_animated_interpolated |> List.map((prefix) => (prefix ++ "Pct", prefix));
  let suffix_animated =
    pt_pct_animated_interpolated |> List.map((prefix) => (prefix ++ "Animated", prefix));
  let suffix_interpolated =
    pt_pct_animated_interpolated |> List.map((prefix) => (prefix ++ "Interpolated", prefix));
  let styleFuncTable =
    Hashtbl.create(
      List.length(suffix_pt)
      + List.length(suffix_pct)
      + List.length(suffix_animated)
      + List.length(suffix_interpolated)
    );
  List.iter(
    ((item, basicItem)) => Hashtbl.add(styleFuncTable, item, (basicItem, "Pt")),
    suffix_pt
  );
  List.iter(
    ((item, basicItem)) => Hashtbl.add(styleFuncTable, item, (basicItem, "Pct")),
    suffix_pct
  );
  List.iter(
    ((item, basicItem)) => Hashtbl.add(styleFuncTable, item, (basicItem, "Animated")),
    suffix_animated
  );
  List.iter(
    ((item, basicItem)) => Hashtbl.add(styleFuncTable, item, (basicItem, "Interpolated")),
    suffix_interpolated
  );
  Hashtbl.add(styleFuncTable, "opacity", ("opacity", "Float"));
  Hashtbl.add(styleFuncTable, "opacityInterpolated", ("opacity", "Interpolated"));
  Hashtbl.add(styleFuncTable, "opacityAnimated", ("opacity", "Animated"));
  let variantReplacementsTable = Hashtbl.create(List.length(variantReplacements));
  List.iter(
    ((item, replacement)) => Hashtbl.add(variantReplacementsTable, item, replacement),
    variantReplacements
  );
  let transformReplacements = [
    ("transform", "Transform.make"),
    ("transformAnimated", "Transform.makeAnimated"),
    ("transformInterpolated", "Transform.makeInterpolated")
  ];
  let transformReplacementsTable = Hashtbl.create(List.length(transformReplacements));
  List.iter(
    ((item, replacement)) => Hashtbl.add(transformReplacementsTable, item, replacement),
    transformReplacements
  );
};

open Parsetree;

open Ast_mapper;

let replaceLastIdentPart = (ident, replacement) =>
  Asttypes.{
    ...ident,
    txt:
      switch (List.rev(Longident.flatten(ident.txt))) {
      | [] => Longident.Lident("")
      | [_] => Longident.parse(replacement)
      | [_, x, ...leading] =>
        Longident.parse(String.concat(".", List.rev([x, ...leading])) ++ "." ++ replacement)
      }
  };

let try_ = (expr) =>
  try expr {
  | _ => `None
  };

let funcReplacement = (funcExpression) =>
  switch funcExpression.pexp_desc {
  | Pexp_ident(funcDescription) =>
    let ident = Longident.last(funcDescription.Location.txt);
    try {
      let (newFuncName, typ) = Hashtbl.find(Replacements.styleFuncTable, ident);
      `StyleFunc((replaceLastIdentPart(funcDescription, newFuncName), typ))
    } {
    | _ =>
      try (
        `TransformFunc(
          replaceLastIdentPart(
            funcDescription,
            Hashtbl.find(Replacements.transformReplacementsTable, ident)
          )
        )
      ) {
      | _ => `None
      }
    }
  | _ => `None
  };

let variantReplacement = (ident) =>
  try (Some(Hashtbl.find(Replacements.variantReplacementsTable, ident))) {
  | _ => None
  };

let mapFunctionCall = (~func, ~args) =>
  switch (funcReplacement(func), args) {
  | (`TransformFunc(mappedFunc), args) => Some((Pexp_ident(mappedFunc), args))
  | (`StyleFunc(mappedFunc, typ), [(_label, arg)]) =>
    Some((
      Pexp_ident(mappedFunc),
      [("", {...arg, pexp_desc: Pexp_construct({...mappedFunc, txt: Lident(typ)}, Some(arg))})]
    ))
  | _ => None
  };

let detectApplicationExpression = (~funcDesc, ~args) =>
  switch (funcDesc, args) {
  | ({pexp_desc: Pexp_ident({txt: Lident("@@")})}, [("", funcExpression), arg]) =>
    `OperatorApplication((`AtAt, funcExpression, arg))
  | ({pexp_desc: Pexp_ident({txt: Lident("|>")})}, [arg, ("", funcExpression)]) =>
    `OperatorApplication((`Pipe, funcExpression, arg))
  | (funcDesc, args) => `OrdinaryApplication((funcDesc, args))
  };

let mapApplicationExpression = (~funcDesc, ~args) =>
  switch (detectApplicationExpression(~funcDesc, ~args)) {
  | `OperatorApplication(operator, funcExpression, arg) =>
    switch (mapFunctionCall(~func=funcExpression, ~args=[arg])) {
    | Some((mappedFunc, args)) =>
      switch operator {
      | `AtAt => Some((funcDesc, [("", {...funcDesc, pexp_desc: mappedFunc}), ...args]))
      | `Pipe => Some((funcDesc, List.append(args, [("", {...funcDesc, pexp_desc: mappedFunc})])))
      }
    | None => None
    }
  | `OrdinaryApplication(funcDesc, args) =>
    switch (mapFunctionCall(~func=funcDesc, ~args)) {
    | Some((mappedFunc, args)) => Some(({...funcDesc, pexp_desc: mappedFunc}, args))
    | None => None
    }
  };

let mapper = {
  ...Ast_mapper.default_mapper,
  expr: (mapper, expr) =>
    switch expr {
    | {pexp_desc: Pexp_apply(funcDesc, args)} =>
      switch (mapApplicationExpression(~funcDesc, ~args)) {
      | Some((mappedFuncDesc, mappedArgs)) => {
          ...expr,
          pexp_desc: Pexp_apply(mappedFuncDesc, mappedArgs)
        }
      | None => /* Map children expressions */ default_mapper.expr(mapper, expr)
      }
    | {pexp_desc: Pexp_variant(txt, arg)} =>
      switch (variantReplacement(txt)) {
      | Some(txt') => {
          ...expr,
          pexp_desc: Pexp_construct({loc: expr.pexp_loc, txt: Lident(txt')}, arg)
        }
      | None => expr
      }
    | expr => default_mapper.expr(mapper, expr)
    },
  open_description: (_mapper, desc) =>
    switch (Longident.flatten(desc.popen_lid.txt)) {
    | [hd, ...tl] when String.compare(hd, "ReactNative") == 0 => {
        ...desc,
        popen_lid: {
          ...desc.popen_lid,
          txt: Longident.parse(String.concat(".", ["BsReactNative", ...tl]))
        }
      }
    | _ => desc
    }
};

let inputPrinter =
  try (Sys.getenv("INPUT_PRINTER")) {
  | _ => "refmt"
  };

let outputPrinter =
  try (Sys.getenv("OUTPUT_PRINTER")) {
  | _ => "refmt"
  };

if (Sys.file_exists("temp") || Sys.file_exists("temp_processed")) {
  print_endline(
    "temp and/or temp_processed files are presesnt in the current directory. Move or remove them to continue."
  )
} else {
  Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1)
  |> Array.iter(
       (file) =>
         if (Sys.command(inputPrinter ++ " " ++ file ++ " -p binary > temp") == 0) {
           Ast_mapper.apply(~source="temp", ~target="temp_processed", mapper);
           if (0
               != Sys.command(
                    outputPrinter ++ " --parse=binary -p re temp_processed | tail -n +3 > " ++ file
                  )) {
             print_endline("Could not print output file")
           } else {
             ()
           }
         } else {
           print_endline("Could not parse the input file named: " ++ file)
         }
     )
  |> (() => ignore(Sys.command("rm temp; rm temp_processed")))
};
