type t;

type styleElement = (string, Js.Json.t);

type px_pct =
  | Px(float)
  | Pct(float);

let encode_px_pct = (value) =>
  switch value {
  | Px(px) => Encode.float(px)
  | Pct(pct) => Encode.pct(pct)
  };

type px_auto =
  | Px(float)
  | Auto;

let encode_px_auto = (value) =>
  switch value {
  | Px(value) => Encode.float(value)
  | Auto => Encode.string("auto")
  };

type px_pct_animated_interpolated =
  | Px(float)
  | Pct(float)
  | Animated(AnimatedRe.Value.t)
  | Interpolated(AnimatedRe.Interpolation.t);

let encode_px_pct_animated_interpolated = (value: px_pct_animated_interpolated) =>
  switch value {
  | Px(px) => Encode.float(px)
  | Pct(pct) => Encode.pct(pct)
  | Animated(value) => Encode.animatedValue(value)
  | Interpolated(value) => Encode.interpolatedValue(value)
  };

type float_interpolated_animated =
  | Float(float)
  | Animated(AnimatedRe.Value.t)
  | Interpolated(AnimatedRe.Interpolation.t);

let encode_float_interpolated_animated = (value) =>
  switch value {
  | Float(value) => Encode.float(value)
  | Animated(value) => Encode.animatedValue(value)
  | Interpolated(value) => Encode.interpolatedValue(value)
  };

external flatten : array(t) => t = "%identity";

external to_style : Js.Dict.t(Js.Json.t) => t = "%identity";

external style_to_dict : t => Js.Dict.t(Js.Json.t) = "%identity";

external array_to_style : array(t) => t = "%identity";

let combine = (a, b) => {
  let entries =
    Array.append(
      UtilsRN.dictEntries(style_to_dict(a)),
      UtilsRN.dictEntries(style_to_dict(b))
    );
  UtilsRN.dictFromArray(entries) |> to_style
};

let concat = (styles) => array_to_style(Array.of_list(styles));

let floatStyle = (key, value) => (key, Encode.float(value));

let stringStyle = (key, value) => (key, Encode.string(value));

let objectStyle = (key, value) => (key, Encode.object_(value));

let arrayStyle = (key, value) => (key, Encode.array(value));

let style = (sarr) => sarr |> UtilsRN.dictFromList |> to_style;


/***
 * Layout Props
 */
let alignContent = (v) =>
  stringStyle(
    "alignContent",
    switch v {
    | `FlexStart => "flex-start"
    | `FlexEnd => "flex-end"
    | `Center => "center"
    | `Stretch => "stretch"
    | `SpaceAround => "space-around"
    | `SpaceBetween => "space-between"
    }
  );

let alignItems = (v) =>
  stringStyle(
    "alignItems",
    switch v {
    | `FlexStart => "flex-start"
    | `FlexEnd => "flex-end"
    | `Center => "center"
    | `Stretch => "stretch"
    | `Baseline => "baseline"
    }
  );

let alignSelf = (v) =>
  stringStyle(
    "alignSelf",
    switch v {
    | `FlexStart => "flex-start"
    | `FlexEnd => "flex-end"
    | `Center => "center"
    | `Stretch => "stretch"
    | `Baseline => "baseline"
    }
  );

let aspectRatio = floatStyle("aspectRatio");

let borderBottomWidth = floatStyle("borderBottomWidth");

let borderLeftWidth = floatStyle("borderLeftWidth");

let borderRightWidth = floatStyle("borderRightWidth");

let borderTopWidth = floatStyle("borderTopWidth");

let borderWidth = floatStyle("borderWidth");

let display = (v) =>
  stringStyle(
    "display",
    switch v {
    | `Flex => "flex"
    | `None => "none"
    }
  );

let flex = floatStyle("flex");

let flexBasis = (value) => ("flexBasis", encode_px_pct(value));

let flexDirection = (v) =>
  stringStyle(
    "flexDirection",
    switch v {
    | `Row => "row"
    | `RowReverse => "row-reverse"
    | `Column => "column"
    | `ColumnReverse => "column-reverse"
    }
  );

let flexGrow = floatStyle("flexGrow");

let flexShrink = floatStyle("flexShrink");

let flexWrap = (v) =>
  stringStyle(
    "flexWrap",
    switch v {
    | `Wrap => "wrap"
    | `Nowrap => "nowrap"
    }
  );

let justifyContent = (v) =>
  stringStyle(
    "justifyContent",
    switch v {
    | `FlexStart => "flex-start"
    | `FlexEnd => "flex-end"
    | `Center => "center"
    | `Stretch => "stretch"
    | `SpaceAround => "space-around"
    | `SpaceBetween => "space-between"
    }
  );

let margin = (value) => ("margin", encode_px_auto(value));

let marginBottom = (value) => ("marginBottom", encode_px_auto(value));

let marginHorizontal = (value) => ("marginHorizontal", encode_px_auto(value));

let marginLeft = (value) => ("marginLeft", encode_px_auto(value));

let marginRight = (value) => ("marginRight", encode_px_auto(value));

let marginTop = (value) => ("marginTop", encode_px_auto(value));

let marginVertical = (value) => ("marginVertical", encode_px_auto(value));

let maxHeight = (value) => ("maxHeight", encode_px_pct(value));

let maxWidth = (value) => ("maxWidth", encode_px_pct(value));

let minHeight = (value) => ("minHeight", encode_px_pct(value));

let minWidth = (value) => ("minWidth", encode_px_pct(value));

let overflow = (v) =>
  stringStyle(
    "overflow",
    switch v {
    | `Visible => "visible"
    | `Hidden => "hidden"
    | `Scroll => "scroll"
    }
  );

let padding = (value) => ("padding", encode_px_pct(value));

let paddingBottom = (value) => ("paddingBottom", encode_px_pct(value));

let paddingHorizontal = (value) => ("paddingHorizontal", encode_px_pct(value));

let paddingLeft = (value) => ("paddingLeft", encode_px_pct(value));

let paddingRight = (value) => ("paddingRight", encode_px_pct(value));

let paddingTop = (value) => ("paddingTop", encode_px_pct(value));

let paddingVertical = (value) => ("paddingVertical", encode_px_pct(value));

let position = (v) =>
  stringStyle(
    "position",
    switch v {
    | `Absolute => "absolute"
    | `Relative => "relative"
    }
  );

let top = (value) => ("top", encode_px_pct_animated_interpolated(value));

let left = (value) => ("left", encode_px_pct_animated_interpolated(value));

let right = (value) => ("right", encode_px_pct_animated_interpolated(value));

let bottom = (value) => ("bottom", encode_px_pct_animated_interpolated(value));

let height = (value) => ("height", encode_px_pct_animated_interpolated(value));

let width = (value) => ("width", encode_px_pct_animated_interpolated(value));

let zIndex = (value) => ("zIndex", Encode.int(value));

let direction = (v) =>
  stringStyle(
    "direction",
    switch v {
    | `Inherit => "inherit"
    | `Ltr => "ltr"
    | `Rtl => "rtl"
    }
  );


/***
 * Shadow Props
 */
let shadowColor = stringStyle("shadowColor");

let shadowOffset = (~height, ~width) =>
  UtilsRN.dictFromArray([|
    ("height", Encode.float(height)),
    ("width", Encode.float(width))
  |])
  |> objectStyle("shadowOffset");

let shadowOpacity = floatStyle("shadowOpacity");

let shadowRadius = floatStyle("shadowRadius");


/***
 * Transform Props
 */
let createTransformObject =
    (
      perspective,
      rotate,
      rotateX,
      rotateY,
      rotateZ,
      scaleX,
      scaleY,
      translateX,
      translateY,
      skewX,
      skewY
    ) => {
  let opt_values = [
    ("perspective", perspective),
    ("rotate", rotate),
    ("rotateX", rotateX),
    ("rotateY", rotateY),
    ("rotateZ", rotateZ),
    ("scaleX", scaleX),
    ("scaleY", scaleY),
    ("translateX", translateX),
    ("translateY", translateY),
    ("skewX", skewX),
    ("skewY", skewY)
  ];
  let values =
    List.fold_right(
      (x, acc) =>
        switch x {
        | (key, Some(value)) =>
          let val_ = UtilsRN.dictFromArray([|(key, value)|]) |> Encode.object_;
          [val_, ...acc]
        | _ => acc
        },
      opt_values,
      []
    );
  Array.of_list(values) |> arrayStyle("transform")
};

let transform =
    (
      ~perspective=?,
      ~rotate=?,
      ~rotateX=?,
      ~rotateY=?,
      ~rotateZ=?,
      ~scaleX=?,
      ~scaleY=?,
      ~translateX=?,
      ~translateY=?,
      ~skewX=?,
      ~skewY=?,
      ()
    ) =>
  createTransformObject(
    UtilsRN.option_map(Encode.float, perspective),
    UtilsRN.option_map(Encode.string, rotate),
    UtilsRN.option_map(Encode.string, rotateX),
    UtilsRN.option_map(Encode.string, rotateY),
    UtilsRN.option_map(Encode.string, rotateZ),
    UtilsRN.option_map(Encode.float, scaleX),
    UtilsRN.option_map(Encode.float, scaleY),
    UtilsRN.option_map(Encode.float, translateX),
    UtilsRN.option_map(Encode.float, translateY),
    UtilsRN.option_map(Encode.float, skewX),
    UtilsRN.option_map(Encode.float, skewY)
  );

let transformAnimated =
    (
      ~perspective=?,
      ~rotate=?,
      ~rotateX=?,
      ~rotateY=?,
      ~rotateZ=?,
      ~scaleX=?,
      ~scaleY=?,
      ~translateX=?,
      ~translateY=?,
      ~skewX=?,
      ~skewY=?,
      ()
    ) =>
  createTransformObject(
    UtilsRN.option_map(Encode.animatedValue, perspective),
    UtilsRN.option_map(Encode.animatedValue, rotate),
    UtilsRN.option_map(Encode.animatedValue, rotateX),
    UtilsRN.option_map(Encode.animatedValue, rotateY),
    UtilsRN.option_map(Encode.animatedValue, rotateZ),
    UtilsRN.option_map(Encode.animatedValue, scaleX),
    UtilsRN.option_map(Encode.animatedValue, scaleY),
    UtilsRN.option_map(Encode.animatedValue, translateX),
    UtilsRN.option_map(Encode.animatedValue, translateY),
    UtilsRN.option_map(Encode.animatedValue, skewX),
    UtilsRN.option_map(Encode.animatedValue, skewY)
  );

let transformInterpolated =
    (
      ~perspective=?,
      ~rotate=?,
      ~rotateX=?,
      ~rotateY=?,
      ~rotateZ=?,
      ~scaleX=?,
      ~scaleY=?,
      ~translateX=?,
      ~translateY=?,
      ~skewX=?,
      ~skewY=?,
      ()
    ) =>
  createTransformObject(
    UtilsRN.option_map(Encode.interpolatedValue, perspective),
    UtilsRN.option_map(Encode.interpolatedValue, rotate),
    UtilsRN.option_map(Encode.interpolatedValue, rotateX),
    UtilsRN.option_map(Encode.interpolatedValue, rotateY),
    UtilsRN.option_map(Encode.interpolatedValue, rotateZ),
    UtilsRN.option_map(Encode.interpolatedValue, scaleX),
    UtilsRN.option_map(Encode.interpolatedValue, scaleY),
    UtilsRN.option_map(Encode.interpolatedValue, translateX),
    UtilsRN.option_map(Encode.interpolatedValue, translateY),
    UtilsRN.option_map(Encode.interpolatedValue, skewX),
    UtilsRN.option_map(Encode.interpolatedValue, skewY)
  );


/***
 * View Props
 */
let backfaceVisibility = (v) =>
  stringStyle(
    "backfaceVisibility",
    switch v {
    | `Visible => "visible"
    | `Hidden => "hidden"
    }
  );

let backgroundColor = stringStyle("backgroundColor");

let borderColor = stringStyle("borderColor");

let borderTopColor = stringStyle("borderTopColor");

let borderRightColor = stringStyle("borderRightColor");

let borderBottomColor = stringStyle("borderBottomColor");

let borderLeftColor = stringStyle("borderLeftColor");

let borderRadius = floatStyle("borderRadius");

let borderTopLeftRadius = floatStyle("borderTopLeftRadius");

let borderTopRightRadius = floatStyle("borderTopRightRadius");

let borderBottomLeftRadius = floatStyle("borderBottomLeftRadius");

let borderBottomRightRadius = floatStyle("borderBottomRightRadius");

let borderStyle = (v) =>
  stringStyle(
    "borderStyle",
    switch v {
    | `Solid => "solid"
    | `Dotted => "dotted"
    | `Dashed => "dashed"
    }
  );

let opacity = (value) => ("opacity", encode_float_interpolated_animated(value));

let elevation = floatStyle("elevation");


/***
 * Text Props
 */
let color = stringStyle("color");

let fontFamily = stringStyle("fontFamily");

let fontSize = floatStyle("fontSize");

let fontStyle = (v) =>
  stringStyle(
    "fontStyle",
    switch v {
    | `Normal => "normal"
    | `Italic => "italic"
    }
  );

let fontWeight = (v) =>
  stringStyle(
    "fontWeight",
    switch v {
    | `Normal => "normal"
    | `Bold => "bold"
    | `_100 => "100"
    | `_200 => "200"
    | `_300 => "300"
    | `_400 => "400"
    | `_500 => "500"
    | `_600 => "600"
    | `_700 => "700"
    | `_800 => "800"
    | `_900 => "900"
    }
  );

let lineHeight = floatStyle("lineHeight");

let textAlign = (v) =>
  stringStyle(
    "textAlign",
    switch v {
    | `Auto => "auto"
    | `Left => "left"
    | `Right => "right"
    | `Center => "center"
    | `Justify => "justify"
    }
  );

let textDecorationLine = (v) =>
  stringStyle(
    "textDecorationLine",
    switch v {
    | `None => "none"
    | `Underline => "underline"
    | `LineThrough => "line-through"
    | `UnderlineLineThrough => "underline line-through"
    }
  );

let textShadowColor = stringStyle("textShadowColor");

let textShadowOffset = (~height, ~width) =>
  UtilsRN.dictFromArray([|
    ("height", Encode.float(height)),
    ("width", Encode.float(width))
  |])
  |> objectStyle("textShadowOffset");

let textShadowRadius = floatStyle("textShadowRadius");

let includeFontPadding = (value) => (
  "includeFontPadding",
  Encode.boolean(Js.Boolean.to_js_boolean(value))
);

let textAlignVertical = (v) =>
  stringStyle(
    "textAlignVertical",
    switch v {
    | `Auto => "auto"
    | `Top => "top"
    | `Bottom => "bottom"
    | `Center => "center"
    }
  );

let fontVariant = (fontVariants) =>
  fontVariants |> Array.of_list |> Array.map(Encode.string) |> arrayStyle("fontVariant");

let letterSpacing = floatStyle("letterSpacing");

let textDecorationColor = stringStyle("textDecorationColor");

let textDecorationStyle = (v) =>
  stringStyle(
    "textDecorationStyle",
    switch v {
    | `Solid => "solid"
    | `Double => "double"
    | `Dotted => "dotted"
    | `Dashed => "dashed"
    }
  );

let writingDirection = (v) =>
  stringStyle(
    "writingDirection",
    switch v {
    | `Auto => "auto"
    | `Ltr => "ltr"
    | `Rtl => "rtl"
    }
  );


/*** Image props */
let resizeMode = (v) =>
  stringStyle(
    "resizeMode",
    switch v {
    | `Cover => "cover"
    | `Contain => "contain"
    | `Stretch => "stretch"
    | `Repeat => "repeat"
    | `Center => "center"
    }
  );

let tintColor = stringStyle("tintColor");

let overlayColor = stringStyle("overlayColor");
