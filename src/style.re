type t;

type styleElement = (string, Js.Json.t);

type pt_only =
  | Pt(float);

type pt_pct =
  | Pt(float)
  | Pct(float);

let encode_pt_pct =
  fun
  | Pt(value) => Encode.float(value)
  | Pct(value) => Encode.pct(value);

type pt_pct_auto =
  | Pt(float)
  | Pct(float)
  | Auto;

let encode_pt_pct_auto = value =>
  switch (value) {
  | Pt(pt) => Encode.float(pt)
  | Pct(pct) => Encode.pct(pct)
  | Auto => Encode.string("auto")
  };

type pt_pct_animated('a) =
  | Pt(float)
  | Pct(float)
  | Animated(AnimatedRe.value('a));

let encode_pt_pct_animated =
  fun
  | Pt(value) => Encode.float(value)
  | Pct(value) => Encode.pct(value)
  | Animated(value) => Encode.animatedValue(value);

type float_animated('a) =
  | Float(float)
  | Animated(AnimatedRe.value('a));

let encode_float_animated =
  fun
  | Float(value) => Encode.float(value)
  | Animated(value) => Encode.animatedValue(value);

type string_interpolated =
  | String(string)
  | Animated(AnimatedRe.Interpolation.t);

let encode_string_interpolated =
  fun
  | String(value) => Encode.string(value)
  | Animated(value) => Encode.animatedValue(value);

external flatten: array(t) => t = "%identity";

external to_style: Js.Dict.t(Js.Json.t) => t = "%identity";

external style_to_dict: t => Js.Dict.t(Js.Json.t) = "%identity";

external array_to_style: array(t) => t = "%identity";

let combine = (a, b) => {
  let entries =
    Array.append(
      Js.Dict.entries(style_to_dict(a)),
      Js.Dict.entries(style_to_dict(b)),
    );
  Js.Dict.fromArray(entries) |> to_style;
};

let concat = styles => array_to_style(Array.of_list(styles));

let floatStyle = (key, value) => (key, Encode.float(value));

let stringStyle = (key, value) => (key, Encode.string(value));

let objectStyle = (key, value) => (key, Encode.object_(value));

let arrayStyle = (key, value) => (key, Encode.array(value));

let style = sarr => sarr |> Js.Dict.fromList |> to_style;

/***
 * Layout Props
 */
type alignContent =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | SpaceAround
  | SpaceBetween;

let alignContent = v =>
  stringStyle(
    "alignContent",
    switch (v) {
    | FlexStart => "flex-start"
    | FlexEnd => "flex-end"
    | Center => "center"
    | Stretch => "stretch"
    | SpaceAround => "space-around"
    | SpaceBetween => "space-between"
    },
  );

type alignItems =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | Baseline;

let alignItems = v =>
  stringStyle(
    "alignItems",
    switch (v) {
    | FlexStart => "flex-start"
    | FlexEnd => "flex-end"
    | Center => "center"
    | Stretch => "stretch"
    | Baseline => "baseline"
    },
  );

type alignSelf =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | Baseline;

let alignSelf = v =>
  stringStyle(
    "alignSelf",
    switch (v) {
    | FlexStart => "flex-start"
    | FlexEnd => "flex-end"
    | Center => "center"
    | Stretch => "stretch"
    | Baseline => "baseline"
    },
  );

let aspectRatio = floatStyle("aspectRatio");

let borderBottomWidth = floatStyle("borderBottomWidth");

let borderLeftWidth = floatStyle("borderLeftWidth");

let borderRightWidth = floatStyle("borderRightWidth");

let borderTopWidth = floatStyle("borderTopWidth");

let borderWidth = floatStyle("borderWidth");

type display =
  | Flex
  | None;

let display = v =>
  stringStyle(
    "display",
    switch (v) {
    | Flex => "flex"
    | None => "none"
    },
  );

let flex = floatStyle("flex");

let flexBasis = value => ("flexBasis", encode_pt_pct(value));

type flexDirection =
  | Row
  | RowReverse
  | Column
  | ColumnReverse;

let flexDirection = v =>
  stringStyle(
    "flexDirection",
    switch (v) {
    | Row => "row"
    | RowReverse => "row-reverse"
    | Column => "column"
    | ColumnReverse => "column-reverse"
    },
  );

let flexGrow = floatStyle("flexGrow");

let flexShrink = floatStyle("flexShrink");

type flexWrap =
  | Wrap
  | Nowrap;

let flexWrap = v =>
  stringStyle(
    "flexWrap",
    switch (v) {
    | Wrap => "wrap"
    | Nowrap => "nowrap"
    },
  );

type justifyContent =
  | FlexStart
  | FlexEnd
  | Center
  | SpaceAround
  | SpaceBetween
  | SpaceEvenly;

let justifyContent = v =>
  stringStyle(
    "justifyContent",
    switch (v) {
    | FlexStart => "flex-start"
    | FlexEnd => "flex-end"
    | Center => "center"
    | SpaceAround => "space-around"
    | SpaceBetween => "space-between"
    | SpaceEvenly => "space-evenly"
    },
  );

let margin = value => ("margin", encode_pt_pct_auto(value));

let marginBottom = value => ("marginBottom", encode_pt_pct_auto(value));

let marginHorizontal = value => (
  "marginHorizontal",
  encode_pt_pct_auto(value),
);

let marginLeft = value => ("marginLeft", encode_pt_pct_auto(value));

let marginRight = value => ("marginRight", encode_pt_pct_auto(value));

let marginTop = value => ("marginTop", encode_pt_pct_auto(value));

let marginVertical = value => ("marginVertical", encode_pt_pct_auto(value));

let maxHeight = value => ("maxHeight", encode_pt_pct(value));

let maxWidth = value => ("maxWidth", encode_pt_pct(value));

let minHeight = value => ("minHeight", encode_pt_pct(value));

let minWidth = value => ("minWidth", encode_pt_pct(value));

type overflow =
  | Visible
  | Hidden
  | Scroll;

let overflow = v =>
  stringStyle(
    "overflow",
    switch (v) {
    | Visible => "visible"
    | Hidden => "hidden"
    | Scroll => "scroll"
    },
  );

let padding = value => ("padding", encode_pt_pct(value));

let paddingBottom = value => ("paddingBottom", encode_pt_pct(value));

let paddingHorizontal = value => ("paddingHorizontal", encode_pt_pct(value));

let paddingLeft = value => ("paddingLeft", encode_pt_pct(value));

let paddingRight = value => ("paddingRight", encode_pt_pct(value));

let paddingTop = value => ("paddingTop", encode_pt_pct(value));

let paddingVertical = value => ("paddingVertical", encode_pt_pct(value));

type position =
  | Absolute
  | Relative;

let position = v =>
  stringStyle(
    "position",
    switch (v) {
    | Absolute => "absolute"
    | Relative => "relative"
    },
  );

let top = value => ("top", encode_pt_pct_animated(value));

let left = value => ("left", encode_pt_pct_animated(value));

let right = value => ("right", encode_pt_pct_animated(value));

let bottom = value => ("bottom", encode_pt_pct_animated(value));

let height = value => ("height", encode_pt_pct_animated(value));

let width = value => ("width", encode_pt_pct_animated(value));

let zIndex = value => ("zIndex", Encode.int(value));

type direction =
  | Inherit
  | Ltr
  | Rtl;

let direction = v =>
  stringStyle(
    "direction",
    switch (v) {
    | Inherit => "inherit"
    | Ltr => "ltr"
    | Rtl => "rtl"
    },
  );

/***
 * Shadow Props
 */
let shadowColor = value => (
  "shadowColor",
  encode_string_interpolated(value),
);

let shadowOffset = (~height, ~width) =>
  Js.Dict.fromArray([|
    ("height", Encode.float(height)),
    ("width", Encode.float(width)),
  |])
  |> objectStyle("shadowOffset");

let shadowOpacity = floatStyle("shadowOpacity");

let shadowRadius = floatStyle("shadowRadius");

module Transform = {
  let create_ =
      (
        encoder,
        rotationEncoder,
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
        skewY,
      ) => {
    let opt_values = [|
      ("perspective", encoder(. perspective)),
      ("rotate", rotationEncoder(. rotate)),
      ("rotateX", rotationEncoder(. rotateX)),
      ("rotateY", rotationEncoder(. rotateY)),
      ("rotateZ", rotationEncoder(. rotateZ)),
      ("scaleX", encoder(. scaleX)),
      ("scaleY", encoder(. scaleY)),
      ("translateX", encoder(. translateX)),
      ("translateY", encoder(. translateY)),
      ("skewX", rotationEncoder(. skewX)),
      ("skewY", rotationEncoder(. skewY)),
    |];
    let values =
      Array.fold_right(
        (x, acc) =>
          switch (x) {
          | (key, Some(value)) =>
            let val_ = Js.Dict.fromArray([|(key, value)|]) |> Encode.object_;
            [val_, ...acc];
          | _ => acc
          },
        opt_values,
        [],
      );
    Array.of_list(values) |> arrayStyle("transform");
  };
  let make =
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
        (),
      ) =>
    create_(
      (. value) => UtilsRN.option_map(Encode.float, value),
      (. value) => UtilsRN.option_map(Encode.string, value),
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
      skewY,
    );
  let makeAnimated =
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
        (),
      ) =>
    create_(
      (. value) => UtilsRN.option_map(Encode.animatedValue, value),
      (. value) => UtilsRN.option_map(Encode.animatedValue, value),
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
      skewY,
    );
};

/***
 * View Props
 */
type backfaceVisibility =
  | Visible
  | Hidden;

let backfaceVisibility = v =>
  stringStyle(
    "backfaceVisibility",
    switch (v) {
    | Visible => "visible"
    | Hidden => "hidden"
    },
  );

let backgroundColor = value => (
  "backgroundColor",
  encode_string_interpolated(value),
);

let borderColor = value => (
  "borderColor",
  encode_string_interpolated(value),
);

let borderTopColor = value => (
  "borderTopColor",
  encode_string_interpolated(value),
);

let borderRightColor = value => (
  "borderRightColor",
  encode_string_interpolated(value),
);

let borderBottomColor = value => (
  "borderBottomColor",
  encode_string_interpolated(value),
);

let borderLeftColor = value => (
  "borderLeftColor",
  encode_string_interpolated(value),
);

let borderRadius = floatStyle("borderRadius");

let borderTopLeftRadius = floatStyle("borderTopLeftRadius");

let borderTopRightRadius = floatStyle("borderTopRightRadius");

let borderBottomLeftRadius = floatStyle("borderBottomLeftRadius");

let borderBottomRightRadius = floatStyle("borderBottomRightRadius");

type borderStyle =
  | Solid
  | Dotted
  | Dashed;

let borderStyle = v =>
  stringStyle(
    "borderStyle",
    switch (v) {
    | Solid => "solid"
    | Dotted => "dotted"
    | Dashed => "dashed"
    },
  );

let opacity = value => ("opacity", encode_float_animated(value));

let elevation = floatStyle("elevation");

/***
 * Text Props
 */
let color = value => ("color", encode_string_interpolated(value));

let fontFamily = stringStyle("fontFamily");

let fontSize = value => ("fontSize", encode_float_animated(value));

type fontStyle =
  | Normal
  | Italic;

let fontStyle = v =>
  stringStyle(
    "fontStyle",
    switch (v) {
    | Normal => "normal"
    | Italic => "italic"
    },
  );

let fontWeight = v =>
  stringStyle(
    "fontWeight",
    switch (v) {
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
    },
  );

let lineHeight = floatStyle("lineHeight");

type textAlign =
  | Auto
  | Left
  | Right
  | Center
  | Justify;

let textAlign = v =>
  stringStyle(
    "textAlign",
    switch (v) {
    | Auto => "auto"
    | Left => "left"
    | Right => "right"
    | Center => "center"
    | Justify => "justify"
    },
  );

type textDecorationLine =
  | None
  | Underline
  | LineThrough
  | UnderlineLineThrough;

let textDecorationLine = v =>
  stringStyle(
    "textDecorationLine",
    switch (v) {
    | None => "none"
    | Underline => "underline"
    | LineThrough => "line-through"
    | UnderlineLineThrough => "underline line-through"
    },
  );

let textShadowColor = value => (
  "textShadowColor",
  encode_string_interpolated(value),
);

let textShadowOffset = (~height, ~width) =>
  Js.Dict.fromArray([|
    ("height", Encode.float(height)),
    ("width", Encode.float(width)),
  |])
  |> objectStyle("textShadowOffset");

let textShadowRadius = floatStyle("textShadowRadius");

let includeFontPadding = value => (
  "includeFontPadding",
  Encode.boolean(value),
);

type textAlignVertical =
  | Auto
  | Top
  | Bottom
  | Center;

let textAlignVertical = v =>
  stringStyle(
    "textAlignVertical",
    switch (v) {
    | Auto => "auto"
    | Top => "top"
    | Bottom => "bottom"
    | Center => "center"
    },
  );

let fontVariant = fontVariants =>
  fontVariants
  |> Array.of_list
  |> Array.map(Encode.string)
  |> arrayStyle("fontVariant");

let letterSpacing = floatStyle("letterSpacing");

let textDecorationColor = value => (
  "textDecorationColor",
  encode_string_interpolated(value),
);

type textDecorationStyle =
  | Solid
  | Double
  | Dotted
  | Dashed;

let textDecorationStyle = v =>
  stringStyle(
    "textDecorationStyle",
    switch (v) {
    | Solid => "solid"
    | Double => "double"
    | Dotted => "dotted"
    | Dashed => "dashed"
    },
  );

type writingDirection =
  | Auto
  | Ltr
  | Rtl;

let writingDirection = v =>
  stringStyle(
    "writingDirection",
    switch (v) {
    | Auto => "auto"
    | Ltr => "ltr"
    | Rtl => "rtl"
    },
  );

type resizeMode =
  | Cover
  | Contain
  | Stretch
  | Repeat
  | Center;

/*** Image props */
let resizeMode = v =>
  stringStyle(
    "resizeMode",
    switch (v) {
    | Cover => "cover"
    | Contain => "contain"
    | Stretch => "stretch"
    | Repeat => "repeat"
    | Center => "center"
    },
  );

let tintColor = value => ("tintColor", encode_string_interpolated(value));

let overlayColor = value => (
  "overlayColor",
  encode_string_interpolated(value),
);

type color =
  | String(string);
