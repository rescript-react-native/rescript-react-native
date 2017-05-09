type t;

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
    Array.append (Utils.dictEntries (style_to_dict a)) (Utils.dictEntries (style_to_dict b));
  Utils.dictFromArray entries |> to_style
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

let style sarr => sarr |> List.map encodeStyle |> Utils.dictFromList |> to_style;


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

let borderBottomWidth = intStyle "borderBottomWidth";

let borderLeftWidth = intStyle "borderLeftWidth";

let borderRightWidth = intStyle "borderRightWidth";

let borderTopWidth = intStyle "borderTopWidth";

let borderWidth = intStyle "borderWidth";

let bottom = intStyle "bottom";

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

let flexBasis = intStyle "flexBasis";

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

let height = intStyle "height";

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

let left = intStyle "left";

let leftAnimated = animatedStyle "left";

let leftInterpolated = interpolatedStyle "left";

let margin = intStyle "margin";

let marginBottom = intStyle "marginBottom";

let marginHorizontal = intStyle "marginHorizontal";

let marginLeft = intStyle "marginLeft";

let marginRight = intStyle "marginRight";

let marginTop = intStyle "marginTop";

let marginVertical = intStyle "marginVertical";

let maxHeight = intStyle "maxHeight";

let maxHeightPct = pctStyle "maxHeight";

let maxWidth = intStyle "maxHeight";

let maxWidthPct = pctStyle "maxHeight";

let minHeight = intStyle "minHeight";

let minHeightPct = pctStyle "minHeight";

let minWidth = intStyle "minWidth";

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

let padding = intStyle "padding";

let paddingBottom = intStyle "paddingBottom";

let paddingHorizontal = intStyle "paddingHorizontal";

let paddingLeft = intStyle "paddingLeft";

let paddingRight = intStyle "paddingRight";

let paddingTop = intStyle "paddingTop";

let paddingVertical = intStyle "paddingVertical";

let position v =>
  stringStyle
    "position"
    (
      switch v {
      | `absolute => "absolute"
      | `relative => "relative"
      }
    );

let right = intStyle "right";

let rightAnimated = animatedStyle "right";

let rightInterpolated = interpolatedStyle "right";

let top = intStyle "top";

let topAnimated = animatedStyle "top";

let topInterpolated = interpolatedStyle "top";

let width = intStyle "width";

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
  Utils.dictFromArray [|("height", Encode.int height), ("width", Encode.int width)|] |>
  objectStyle "shadowOffset";

let shadowOpacity = floatStyle "shadowOpacity";

let shadowRadius = intStyle "shadowRadius";


/**
 * Transform Props
 */
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
    () => {
  let opt_values = [
    ("perspective", Utils.option_map Encode.float perspective),
    ("rotate", Utils.option_map Encode.string rotate),
    ("rotateX", Utils.option_map Encode.string rotateX),
    ("rotateY", Utils.option_map Encode.string rotateY),
    ("rotateZ", Utils.option_map Encode.string rotateZ),
    ("scaleX", Utils.option_map Encode.float scaleX),
    ("scaleY", Utils.option_map Encode.float scaleY),
    ("translateX", Utils.option_map Encode.float translateX),
    ("translateY", Utils.option_map Encode.float translateY),
    ("skewX", Utils.option_map Encode.float skewX),
    ("skewY", Utils.option_map Encode.float skewY)
  ];
  let values =
    List.fold_right
      (
        fun x acc =>
          switch x {
          | (key, Some value) =>
            let val_ = Utils.dictFromArray [|(key, value)|] |> Encode.object_;
            [val_, ...acc]
          | _ => acc
          }
      )
      opt_values
      [];
  Array.of_list values |> arrayStyle "transform"
};


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

let borderRadius = intStyle "borderRadius";

let borderTopLeftRadius = intStyle "borderTopLeftRadius";

let borderTopRightRadius = intStyle "borderTopRightRadius";

let borderBottomLeftRadius = intStyle "borderBottomLeftRadius";

let borderBottomRightRadius = intStyle "borderBottomRightRadius";

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

let elevation = floatStyle "elevation";


/**
 * Text Props
 */
let color = stringStyle "color";

let fontSize = intStyle "fontSize";

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

let lineHeight = intStyle "lineHeight";

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

let textShadowColor = stringStyle "string";

let textShadowOffset ::height ::width =>
  Utils.dictFromArray [|("height", Encode.int height), ("width", Encode.int width)|] |>
  objectStyle "textShadowOffset";

let textShadowRadius = intStyle "textShadowRadius";

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
