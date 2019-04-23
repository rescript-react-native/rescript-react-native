type t = ReactNative.Style.t;
type styleElement;
type styleTransformElement = (string, Js.Json.t);
type pt_only =
  | Pt(float);
type pt_pct =
  | Pt(float)
  | Pct(float);
type pt_pct_auto =
  | Pt(float)
  | Pct(float)
  | Auto;
type pt_pct_animated('a) =
  | Pt(float)
  | Pct(float)
  | Animated(AnimatedRe.value('a));
type float_animated('a) =
  | Float(float)
  | Animated(AnimatedRe.value('a));
type string_interpolated =
  | String(string)
  | Animated(AnimatedRe.Interpolation.t);
type deg_animated('a) =
  | Deg(float)
  | Animated(AnimatedRe.value('a));

let style: list(styleElement) => t;

/*
 <View style=array([|
   styles##thing,
   styles##whatever,
 |])>
   */
let array: array(t) => t;
/*
 <View style=arrayOption([|
   Some(styles##thing),
   Some(styles##whatever),
   optionalStyle,
   cond ? Some({something:"dynamic"}) : None
 |])>
 */
let arrayOption: array(option(t)) => t;
/* list works too since RN accept recursive array of styles (list are just recursive arrays)*/
/*
 <View style=list([
   styles##thing,
   styles##whatever,
 ])>
   */
let list: list(t) => t;
/*
 <View style=listOption([
   Some(styles##thing),
   Some(styles##whatever),
   optionalStyle,
   cond ? Some({something:"dynamic"}) : None
 ])>
 */
let listOption: list(option(t)) => t;
[@deprecated "Use Style.array([|t|]) instead"]
let flatten: array(t) => t;
[@deprecated "Use Style.list([t]) instead"]
let concat: list(t) => t;
[@deprecated
  "This method is unsafe as it doesn't work well with StyleSheet values."
]
let combine: (t, t) => t;

type alignContent =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | SpaceAround
  | SpaceBetween;
let alignContent: alignContent => styleElement;
type alignItems =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | Baseline;
let alignItems: alignItems => styleElement;
type alignSelf =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | Baseline;
let alignSelf: alignSelf => styleElement;
let aspectRatio: float => styleElement;
let borderBottomWidth: float => styleElement;
let borderLeftWidth: float => styleElement;
let borderRightWidth: float => styleElement;
let borderTopWidth: float => styleElement;
let borderWidth: float => styleElement;
type display =
  | Flex
  | None;
let display: display => styleElement;
let flex: float => styleElement;
let flexBasis: pt_pct_auto => styleElement;
type flexDirection =
  | Row
  | RowReverse
  | Column
  | ColumnReverse;
let flexDirection: flexDirection => styleElement;
let flexGrow: float => styleElement;
let flexShrink: float => styleElement;
type flexWrap =
  | Wrap
  | Nowrap;
let flexWrap: flexWrap => styleElement;
type justifyContent =
  | FlexStart
  | FlexEnd
  | Center
  | SpaceAround
  | SpaceBetween
  | SpaceEvenly;
let justifyContent: justifyContent => styleElement;
let margin: pt_pct_auto => styleElement;
let marginBottom: pt_pct_auto => styleElement;
let marginHorizontal: pt_pct_auto => styleElement;
let marginLeft: pt_pct_auto => styleElement;
let marginRight: pt_pct_auto => styleElement;
let marginTop: pt_pct_auto => styleElement;
let marginVertical: pt_pct_auto => styleElement;
let maxHeight: pt_pct => styleElement;
let maxWidth: pt_pct => styleElement;
let minHeight: pt_pct => styleElement;
let minWidth: pt_pct => styleElement;
type overflow =
  | Visible
  | Hidden
  | Scroll;
let overflow: overflow => styleElement;
let padding: pt_pct => styleElement;
let paddingBottom: pt_pct => styleElement;
let paddingHorizontal: pt_pct => styleElement;
let paddingLeft: pt_pct => styleElement;
let paddingRight: pt_pct => styleElement;
let paddingTop: pt_pct => styleElement;
let paddingVertical: pt_pct => styleElement;
type position =
  | Absolute
  | Relative;
let position: position => styleElement;
let top: pt_pct_animated('a) => styleElement;
let left: pt_pct_animated('a) => styleElement;
let right: pt_pct_animated('a) => styleElement;
let bottom: pt_pct_animated('a) => styleElement;
let height: pt_pct_animated('a) => styleElement;
let width: pt_pct_animated('a) => styleElement;
let zIndex: int => styleElement;
type direction =
  | Inherit
  | Ltr
  | Rtl;
let direction: direction => styleElement;
let shadowColor: string_interpolated => styleElement;
let shadowOffset: (~height: float, ~width: float) => styleElement;
let shadowOpacity: float => styleElement;
let shadowRadius: float => styleElement;

let transform: list(styleTransformElement) => styleElement;

let perspective: float_animated('a) => styleTransformElement;
let translateX: float_animated('a) => styleTransformElement;
let translateY: float_animated('a) => styleTransformElement;
let scaleX: float_animated('a) => styleTransformElement;
let scaleY: float_animated('a) => styleTransformElement;
let scale: float_animated('a) => styleTransformElement;
let rotate: deg_animated('a) => styleTransformElement;
let rotateX: deg_animated('a) => styleTransformElement;
let rotateY: deg_animated('a) => styleTransformElement;
let rotateZ: deg_animated('a) => styleTransformElement;
let skewX: deg_animated('a) => styleTransformElement;
let skewY: deg_animated('a) => styleTransformElement;

module Transform: {
  [@deprecated
    "Style.Transform.perspective as been deprecated in favor of Style.perspective"
  ]
  let perspective: float_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.translateX as been deprecated in favor of Style.translateX"
  ]
  let translateX: float_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.translateY as been deprecated in favor of Style.translateY"
  ]
  let translateY: float_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.scaleX as been deprecated in favor of Style.scaleX"
  ]
  let scaleX: float_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.scaleY as been deprecated in favor of Style.scaleY"
  ]
  let scaleY: float_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.scale as been deprecated in favor of Style.scale"
  ]
  let scale: float_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.rotate as been deprecated in favor of Style.rotate"
  ]
  let rotate: deg_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.rotateX as been deprecated in favor of Style.rotateX"
  ]
  let rotateX: deg_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.rotateY as been deprecated in favor of Style.rotateY"
  ]
  let rotateY: deg_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.rotateZ as been deprecated in favor of Style.rotateZ"
  ]
  let rotateZ: deg_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.skewX as been deprecated in favor of Style.skewX"
  ]
  let skewX: deg_animated('a) => styleTransformElement;
  [@deprecated
    "Style.Transform.skewY as been deprecated in favor of Style.skewY"
  ]
  let skewY: deg_animated('a) => styleTransformElement;

  [@deprecated
    "Please use Style.transform instead. Read more at https://github.com/reasonml-community/bs-react-native/issues/333"
  ]
  let make:
    (
      ~perspective: float=?,
      ~rotate: string=?,
      ~rotateX: string=?,
      ~rotateY: string=?,
      ~rotateZ: string=?,
      ~scaleX: float=?,
      ~scaleY: float=?,
      ~translateX: float=?,
      ~translateY: float=?,
      ~skewX: string=?,
      ~skewY: string=?,
      unit
    ) =>
    styleElement;

  [@deprecated
    "Please use Style.transform instead. Read more at https://github.com/reasonml-community/bs-react-native/issues/333"
  ]
  let makeAnimated:
    (
      ~perspective: AnimatedRe.value('a)=?,
      ~rotate: AnimatedRe.value('a)=?,
      ~rotateX: AnimatedRe.value('a)=?,
      ~rotateY: AnimatedRe.value('a)=?,
      ~rotateZ: AnimatedRe.value('a)=?,
      ~scaleX: AnimatedRe.value('a)=?,
      ~scaleY: AnimatedRe.value('a)=?,
      ~translateX: AnimatedRe.value('a)=?,
      ~translateY: AnimatedRe.value('a)=?,
      ~skewX: AnimatedRe.value('a)=?,
      ~skewY: AnimatedRe.value('a)=?,
      unit
    ) =>
    styleElement;
};
type backfaceVisibility =
  | Visible
  | Hidden;
let backfaceVisibility: backfaceVisibility => styleElement;
let backgroundColor: string_interpolated => styleElement;
let borderColor: string_interpolated => styleElement;
let borderTopColor: string_interpolated => styleElement;
let borderRightColor: string_interpolated => styleElement;
let borderBottomColor: string_interpolated => styleElement;
let borderLeftColor: string_interpolated => styleElement;
let borderRadius: float => styleElement;
let borderTopLeftRadius: float => styleElement;
let borderTopRightRadius: float => styleElement;
let borderBottomLeftRadius: float => styleElement;
let borderBottomRightRadius: float => styleElement;
type borderStyle =
  | Solid
  | Dotted
  | Dashed;
let borderStyle: borderStyle => styleElement;
let opacity: float_animated('a) => styleElement;
let elevation: float => styleElement;
let color: string_interpolated => styleElement;
let fontFamily: string => styleElement;
let fontSize: float_animated('a) => styleElement;
type fontStyle =
  | Normal
  | Italic;
let fontStyle: fontStyle => styleElement;
let fontWeight:
  [<
    | `Bold
    | `Normal
    | `_100
    | `_200
    | `_300
    | `_400
    | `_500
    | `_600
    | `_700
    | `_800
    | `_900
  ] =>
  styleElement;
let lineHeight: float => styleElement;
type textAlign =
  | Auto
  | Left
  | Right
  | Center
  | Justify;
let textAlign: textAlign => styleElement;
type textDecorationLine =
  | None
  | Underline
  | LineThrough
  | UnderlineLineThrough;
let textDecorationLine: textDecorationLine => styleElement;
let textShadowColor: string_interpolated => styleElement;
let textShadowOffset: (~height: float, ~width: float) => styleElement;
let textShadowRadius: float => styleElement;
let includeFontPadding: bool => styleElement;
type textAlignVertical =
  | Auto
  | Top
  | Bottom
  | Center;
let textAlignVertical: textAlignVertical => styleElement;
let fontVariant: list(string) => styleElement;
let letterSpacing: float => styleElement;
let textDecorationColor: string_interpolated => styleElement;
type textDecorationStyle =
  | Solid
  | Double
  | Dotted
  | Dashed;
let textDecorationStyle: textDecorationStyle => styleElement;
type writingDirection =
  | Auto
  | Ltr
  | Rtl;
let writingDirection: writingDirection => styleElement;
type resizeMode =
  | Cover
  | Contain
  | Stretch
  | Repeat
  | Center;
let resizeMode: resizeMode => styleElement;
let tintColor: string_interpolated => styleElement;
let overlayColor: string_interpolated => styleElement;
type color =
  | String(string);

let toReasonReactNativeColor: color => ReactNative.Color.t;
