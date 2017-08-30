type t;

external flatten : array t => t = "%identity";

external to_style : Js.Dict.t Js.Json.t => t = "%identity";

external style_to_dict : t => Js.Dict.t Js.Json.t = "%identity";

external array_to_style : array t => t = "%identity";

type style =
  | ArrayStyle string (array Js.Json.t)
  | BooleanStyle string bool
  | StringStyle string string
  | IntStyle string int
  | FloatStyle string float
  | ObjectStyle string (Js.Dict.t Js.Json.t)
  | AnimatedStyle
      string [ | `value AnimatedRe.Value.t | `interpolation AnimatedRe.Interpolation.t];

let combine a b => {
  let entries =
    Array.append (UtilsRN.dictEntries (style_to_dict a)) (UtilsRN.dictEntries (style_to_dict b));
  UtilsRN.dictFromArray entries |> to_style
};

let concat styles => array_to_style (Array.of_list styles);

let arrayStyle key value => ArrayStyle key value;

let booleanStyle key value => BooleanStyle key value;

let stringStyle key value => StringStyle key value;

let intStyle key value => IntStyle key value;

let floatStyle key value => FloatStyle key value;

let pctStyle key value => StringStyle key (string_of_float value ^ "%");

let objectStyle key value => ObjectStyle key value;

let animatedStyle key value => AnimatedStyle key (`value value);

let interpolatedStyle key value => AnimatedStyle key (`interpolation value);

let encodeStyle =
  fun
  | ArrayStyle key value => (key, Encode.array value)
  | BooleanStyle key value => (key, Encode.boolean (Js.Boolean.to_js_boolean value))
  | IntStyle key value => (key, Encode.int value)
  | FloatStyle key value => (key, Encode.float value)
  | StringStyle key value => (key, Encode.string value)
  | ObjectStyle key value => (key, Encode.object_ value)
  | AnimatedStyle key value => (
      key,
      switch value {
      | `value x => Encode.animatedValue x
      | `interpolation x => Encode.interpolatedValue x
      }
    );

let style sarr => sarr |> List.map encodeStyle |> UtilsRN.dictFromList |> to_style;


/**
 * Layout Props
 */
let alignContent v =>
  stringStyle
    "alignContent"
    (
      switch v {
      | `flexStart => "flex-start"
      | `flexEnd => "flex-end"
      | `center => "center"
      | `stretch => "stretch"
      | `spaceAround => "space-around"
      | `spaceBetween => "space-between"
      }
    );

let alignItems v =>
  stringStyle
    "alignItems"
    (
      switch v {
      | `flexStart => "flex-start"
      | `flexEnd => "flex-end"
      | `center => "center"
      | `stretch => "stretch"
      | `baseline => "baseline"
      }
    );

let alignSelf v =>
  stringStyle
    "alignSelf"
    (
      switch v {
      | `flexStart => "flex-start"
      | `flexEnd => "flex-end"
      | `center => "center"
      | `stretch => "stretch"
      | `baseline => "baseline"
      }
    );

let aspectRatio = floatStyle "aspectRatio";

let borderBottomWidth = floatStyle "borderBottomWidth";

let borderLeftWidth = floatStyle "borderLeftWidth";

let borderRightWidth = floatStyle "borderRightWidth";

let borderTopWidth = floatStyle "borderTopWidth";

let borderWidth = floatStyle "borderWidth";

let bottom = floatStyle "bottom";

let bottomPct = pctStyle "bottom";

let bottomAnimated = animatedStyle "bottom";

let bottomInterpolated = interpolatedStyle "bottom";

let display v =>
  stringStyle
    "display"
    (
      switch v {
      | `flex => "flex"
      | `none => "none"
      }
    );

let flex = floatStyle "flex";

let flexBasis = floatStyle "flexBasis";

let flexBasisPct = pctStyle "flexBasis";

let flexDirection v =>
  stringStyle
    "flexDirection"
    (
      switch v {
      | `row => "row"
      | `rowReverse => "row-reverse"
      | `column => "column"
      | `columnReverse => "column-reverse"
      }
    );

let flexGrow = floatStyle "flexGrow";

let flexShrink = floatStyle "flexShrink";

let flexWrap v =>
  stringStyle
    "flexWrap"
    (
      switch v {
      | `wrap => "wrap"
      | `nowrap => "nowrap"
      }
    );

let height = floatStyle "height";

let heightPct = pctStyle "height";

let heightAnimated = animatedStyle "height";

let heightInterpolated = interpolatedStyle "height";

let justifyContent v =>
  stringStyle
    "justifyContent"
    (
      switch v {
      | `flexStart => "flex-start"
      | `flexEnd => "flex-end"
      | `center => "center"
      | `stretch => "stretch"
      | `spaceAround => "space-around"
      | `spaceBetween => "space-between"
      }
    );

let left = floatStyle "left";

let leftPct = pctStyle "left";

let leftAnimated = animatedStyle "left";

let leftInterpolated = interpolatedStyle "left";

let margin = floatStyle "margin";

let marginBottom = floatStyle "marginBottom";

let marginHorizontal = floatStyle "marginHorizontal";

let marginLeft = floatStyle "marginLeft";

let marginRight = floatStyle "marginRight";

let marginTop = floatStyle "marginTop";

let marginVertical = floatStyle "marginVertical";

let maxHeight = floatStyle "maxHeight";

let maxHeightPct = pctStyle "maxHeight";

let maxWidth = floatStyle "maxWidth";

let maxWidthPct = pctStyle "maxHeight";

let minHeight = floatStyle "minHeight";

let minHeightPct = pctStyle "minHeight";

let minWidth = floatStyle "minWidth";

let minWidthPct = pctStyle "minWidth";

let overflow v =>
  stringStyle
    "overflow"
    (
      switch v {
      | `visible => "visible"
      | `hidden => "hidden"
      | `scroll => "scroll"
      }
    );

let padding = floatStyle "padding";

let paddingBottom = floatStyle "paddingBottom";

let paddingHorizontal = floatStyle "paddingHorizontal";

let paddingLeft = floatStyle "paddingLeft";

let paddingRight = floatStyle "paddingRight";

let paddingTop = floatStyle "paddingTop";

let paddingVertical = floatStyle "paddingVertical";

let position v =>
  stringStyle
    "position"
    (
      switch v {
      | `absolute => "absolute"
      | `relative => "relative"
      }
    );

let right = floatStyle "right";

let rightPct = pctStyle "right";

let rightAnimated = animatedStyle "right";

let rightInterpolated = interpolatedStyle "right";

let top = floatStyle "top";

let topPct = pctStyle "top";

let topAnimated = animatedStyle "top";

let topInterpolated = interpolatedStyle "top";

let width = floatStyle "width";

let widthPct = pctStyle "width";

let widthAnimated = animatedStyle "width";

let widthInterpolated = interpolatedStyle "width";

let zIndex = intStyle "zIndex";

let direction v =>
  stringStyle
    "direction"
    (
      switch v {
      | `_inherit => "inherit"
      | `ltr => "ltr"
      | `rtl => "rtl"
      }
    );


/**
 * Shadow Props
 */
let shadowColor = stringStyle "shadowColor";

let shadowOffset ::height ::width =>
  UtilsRN.dictFromArray [|("height", Encode.float height), ("width", Encode.float width)|] |>
  objectStyle "shadowOffset";

let shadowOpacity = floatStyle "shadowOpacity";

let shadowRadius = floatStyle "shadowRadius";


/**
 * Transform Props
 */
let createTransformObject
    perspective
    rotate
    rotateX
    rotateY
    rotateZ
    scaleX
    scaleY
    translateX
    translateY
    skewX
    skewY => {
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
    List.fold_right
      (
        fun x acc =>
          switch x {
          | (key, Some value) =>
            let val_ = UtilsRN.dictFromArray [|(key, value)|] |> Encode.object_;
            [val_, ...acc]
          | _ => acc
          }
      )
      opt_values
      [];
  Array.of_list values |> arrayStyle "transform"
};

let transform
    ::perspective=?
    ::rotate=?
    ::rotateX=?
    ::rotateY=?
    ::rotateZ=?
    ::scaleX=?
    ::scaleY=?
    ::translateX=?
    ::translateY=?
    ::skewX=?
    ::skewY=?
    () =>
  createTransformObject
    (UtilsRN.option_map Encode.float perspective)
    (UtilsRN.option_map Encode.string rotate)
    (UtilsRN.option_map Encode.string rotateX)
    (UtilsRN.option_map Encode.string rotateY)
    (UtilsRN.option_map Encode.string rotateZ)
    (UtilsRN.option_map Encode.float scaleX)
    (UtilsRN.option_map Encode.float scaleY)
    (UtilsRN.option_map Encode.float translateX)
    (UtilsRN.option_map Encode.float translateY)
    (UtilsRN.option_map Encode.float skewX)
    (UtilsRN.option_map Encode.float skewY);

let transformAnimated
    ::perspective=?
    ::rotate=?
    ::rotateX=?
    ::rotateY=?
    ::rotateZ=?
    ::scaleX=?
    ::scaleY=?
    ::translateX=?
    ::translateY=?
    ::skewX=?
    ::skewY=?
    () =>
  createTransformObject
    (UtilsRN.option_map Encode.animatedValue perspective)
    (UtilsRN.option_map Encode.animatedValue rotate)
    (UtilsRN.option_map Encode.animatedValue rotateX)
    (UtilsRN.option_map Encode.animatedValue rotateY)
    (UtilsRN.option_map Encode.animatedValue rotateZ)
    (UtilsRN.option_map Encode.animatedValue scaleX)
    (UtilsRN.option_map Encode.animatedValue scaleY)
    (UtilsRN.option_map Encode.animatedValue translateX)
    (UtilsRN.option_map Encode.animatedValue translateY)
    (UtilsRN.option_map Encode.animatedValue skewX)
    (UtilsRN.option_map Encode.animatedValue skewY);

let transformInterpolated
    ::perspective=?
    ::rotate=?
    ::rotateX=?
    ::rotateY=?
    ::rotateZ=?
    ::scaleX=?
    ::scaleY=?
    ::translateX=?
    ::translateY=?
    ::skewX=?
    ::skewY=?
    () =>
  createTransformObject
    (UtilsRN.option_map Encode.interpolatedValue perspective)
    (UtilsRN.option_map Encode.interpolatedValue rotate)
    (UtilsRN.option_map Encode.interpolatedValue rotateX)
    (UtilsRN.option_map Encode.interpolatedValue rotateY)
    (UtilsRN.option_map Encode.interpolatedValue rotateZ)
    (UtilsRN.option_map Encode.interpolatedValue scaleX)
    (UtilsRN.option_map Encode.interpolatedValue scaleY)
    (UtilsRN.option_map Encode.interpolatedValue translateX)
    (UtilsRN.option_map Encode.interpolatedValue translateY)
    (UtilsRN.option_map Encode.interpolatedValue skewX)
    (UtilsRN.option_map Encode.interpolatedValue skewY);


/**
 * View Props
 */
let backfaceVisibility v =>
  stringStyle
    "backfaceVisibility"
    (
      switch v {
      | `visible => "visible"
      | `hidden => "hidden"
      }
    );

let backgroundColor = stringStyle "backgroundColor";

let borderColor = stringStyle "borderColor";

let borderTopColor = stringStyle "borderTopColor";

let borderRightColor = stringStyle "borderRightColor";

let borderBottomColor = stringStyle "borderBottomColor";

let borderLeftColor = stringStyle "borderLeftColor";

let borderRadius = floatStyle "borderRadius";

let borderTopLeftRadius = floatStyle "borderTopLeftRadius";

let borderTopRightRadius = floatStyle "borderTopRightRadius";

let borderBottomLeftRadius = floatStyle "borderBottomLeftRadius";

let borderBottomRightRadius = floatStyle "borderBottomRightRadius";

let borderStyle v =>
  stringStyle
    "borderStyle"
    (
      switch v {
      | `solid => "solid"
      | `dotted => "dotted"
      | `dashed => "dashed"
      }
    );

let opacity = floatStyle "opacity";

let opacityInterpolated = interpolatedStyle "opacity";

let opacityAnimated = animatedStyle "opacity";

let elevation = floatStyle "elevation";


/**
 * Text Props
 */
let color = stringStyle "color";

let fontFamily = stringStyle "fontFamily";

let fontSize = floatStyle "fontSize";

let fontStyle v =>
  stringStyle
    "fontStyle"
    (
      switch v {
      | `normal => "normal"
      | `italic => "italic"
      }
    );

let fontWeight v =>
  stringStyle
    "fontWeight"
    (
      switch v {
      | `normal => "normal"
      | `bold => "bold"
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

let lineHeight = floatStyle "lineHeight";

let textAlign v =>
  stringStyle
    "textAlign"
    (
      switch v {
      | `auto => "auto"
      | `left => "left"
      | `right => "right"
      | `center => "center"
      | `justify => "justify"
      }
    );

let textDecorationLine v =>
  stringStyle
    "textDecorationLine"
    (
      switch v {
      | `none => "none"
      | `underline => "underline"
      | `lineThrough => "line-through"
      | `underlineLineThrough => "underline line-through"
      }
    );

let textShadowColor = stringStyle "textShadowColor";

let textShadowOffset ::height ::width =>
  UtilsRN.dictFromArray [|("height", Encode.float height), ("width", Encode.float width)|] |>
  objectStyle "textShadowOffset";

let textShadowRadius = floatStyle "textShadowRadius";

let includeFontPadding = booleanStyle "includeFontPadding";

let textAlignVertical v =>
  stringStyle
    "textAlignVertical"
    (
      switch v {
      | `auto => "auto"
      | `top => "top"
      | `bottom => "bottom"
      | `center => "center"
      }
    );

let fontVariant fontVariants =>
  fontVariants |> Array.of_list |> Array.map Encode.string |> arrayStyle "fontVariant";

let letterSpacing = floatStyle "letterSpacing";

let textDecorationColor = stringStyle "textDecorationColor";

let textDecorationStyle v =>
  stringStyle
    "textDecorationStyle"
    (
      switch v {
      | `solid => "solid"
      | `double => "double"
      | `dotted => "dotted"
      | `dashed => "dashed"
      }
    );

let writingDirection v =>
  stringStyle
    "writingDirection"
    (
      switch v {
      | `auto => "auto"
      | `ltr => "ltr"
      | `rtl => "rtl"
      }
    );


/** Image props */
let resizeMode v =>
  stringStyle
    "resizeMode"
    (
      switch v {
      | `cover => "cover"
      | `contain => "contain"
      | `stretch => "stretch"
      | `repeat => "repeat"
      | `center => "center"
      }
    );

let tintColor = stringStyle "tintColor";

let overlayColor = stringStyle "overlayColor";
