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
  switch (List.rev(Longident.flatten(ident))) {
  | [] => Longident.Lident("")
  | [_] => Longident.parse(replacement)
  | [_, x, ...leading] =>
    Longident.parse(String.concat(".", List.rev([x, ...leading])) ++ "." ++ replacement)
  };

let try_ = (expr) =>
  try expr {
  | _ => `None
  };

let funcReplacement = (ident) =>
  try (`StyleFunc(Hashtbl.find(Replacements.styleFuncTable, ident))) {
  | _ =>
    try (`TransformFunc(Hashtbl.find(Replacements.transformReplacementsTable, ident))) {
    | _ => `None
    }
  };

let variantReplacement = (ident) =>
  try (Some(Hashtbl.find(Replacements.variantReplacementsTable, ident))) {
  | _ => None
  };

let mapper = {
  ...Ast_mapper.default_mapper,
  expr: (mapper, expr) =>
    switch expr {
    | {pexp_desc: Pexp_apply(description, args)} =>
      switch description.pexp_desc {
      | Pexp_ident(funcDescription) =>
        switch (args, funcReplacement(Longident.last(funcDescription.txt))) {
        | (args, `TransformFunc(newIdentifier)) =>
          let txt = replaceLastIdentPart(funcDescription.txt, newIdentifier);
          {
            ...expr,
            pexp_desc:
              Pexp_apply({...description, pexp_desc: Pexp_ident({...funcDescription, txt})}, args)
          }
        | ([(_, arg)], `StyleFunc(newIdentifier, typ)) =>
          let txt = replaceLastIdentPart(funcDescription.txt, newIdentifier);
          {
            ...expr,
            pexp_desc:
              Pexp_apply(
                {...description, pexp_desc: Pexp_ident({...funcDescription, txt})},
                [
                  (
                    "",
                    {
                      ...expr,
                      pexp_desc: Pexp_construct({...funcDescription, txt: Lident(typ)}, Some(arg))
                    }
                  )
                ]
              )
          }
        | _ => {
            ...expr,
            pexp_desc:
              Pexp_apply(
                description,
                List.map(((lbl, expr)) => (lbl, mapper.expr(mapper, expr)), args)
              )
          }
        }
      | _ => {
          ...expr,
          pexp_desc:
            Pexp_apply(
              description,
              List.map(((lbl, expr)) => (lbl, mapper.expr(mapper, expr)), args)
            )
        }
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
  open_description: (mapper, desc) =>
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

Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1)
|> Array.iter(
     (file) =>
       if (Sys.command(inputPrinter ++ " " ++ file ++ " -p binary > temp") == 0) {
         Ast_mapper.apply(~source="temp", ~target="temp_processed", mapper);
         if (0 != Sys.command(outputPrinter ++ " --parse=binary -p re temp_processed > " ++ file)) {
           print_endline("Could not print output file")
         }
       } else {
         print_endline("Could not parse the input file named: " ++ file)
       }
   );
