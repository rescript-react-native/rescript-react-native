type t;

type styleElement;

type pt_pct =
  | Pt(float)
  | Pct(float);

type pt_pct_auto =
  | Pt(float)
  | Pct(float)
  | Auto;

type pt_pct_animated_interpolated =
  | Pt(float)
  | Pct(float)
  | Animated(AnimatedRe.Value.t)
  | Interpolated(AnimatedRe.Interpolation.t);

type float_interpolated_animated =
  | Float(float)
  | Animated(AnimatedRe.Value.t)
  | Interpolated(AnimatedRe.Interpolation.t);

let style: list(styleElement) => t;


/*** Generates a style out of an array of styles.
  * This is equivalent:
  * // js
  * <View style={[styleA, styleB]} />
  * // reason
  * <View style=(Style.flatten [|styleA, styleB|]) />
 */
let flatten: array(t) => t;

let combine: (t, t) => t;

let concat: list(t) => t;


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

let flex: float => styleElement;

type display =
  | Flex
  | None;

let display: display => styleElement;

let flexBasis: pt_pct => styleElement;

let flexGrow: float => styleElement;

type flexDirection =
  | Row
  | RowReverse
  | Column
  | ColumnReverse;

let flexDirection: flexDirection => styleElement;

let flexShrink: float => styleElement;

type flexWrap =
  | Wrap
  | Nowrap;

let flexWrap: flexWrap => styleElement;

type justifyContent =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | SpaceAround
  | SpaceBetween;

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

let top: pt_pct_animated_interpolated => styleElement;

let left: pt_pct_animated_interpolated => styleElement;

let right: pt_pct_animated_interpolated => styleElement;

let bottom: pt_pct_animated_interpolated => styleElement;

let height: pt_pct_animated_interpolated => styleElement;

let width: pt_pct_animated_interpolated => styleElement;

let zIndex: int => styleElement;

type direction =
  | Inherit
  | Ltr
  | Rtl;

let direction: direction => styleElement;


/***
 * Shadow Props
 */
let shadowColor: string => styleElement;

let shadowOffset: (~height: float, ~width: float) => styleElement;

let shadowOpacity: float => styleElement;

let shadowRadius: float => styleElement;

module Transform: {
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
      ~skewX: float=?,
      ~skewY: float=?,
      unit
    ) =>
    styleElement;
  let makeAnimated:
    (
      ~perspective: AnimatedRe.Value.t=?,
      ~rotate: AnimatedRe.Value.t=?,
      ~rotateX: AnimatedRe.Value.t=?,
      ~rotateY: AnimatedRe.Value.t=?,
      ~rotateZ: AnimatedRe.Value.t=?,
      ~scaleX: AnimatedRe.Value.t=?,
      ~scaleY: AnimatedRe.Value.t=?,
      ~translateX: AnimatedRe.Value.t=?,
      ~translateY: AnimatedRe.Value.t=?,
      ~skewX: AnimatedRe.Value.t=?,
      ~skewY: AnimatedRe.Value.t=?,
      unit
    ) =>
    styleElement;
  let makeInterpolated:
    (
      ~perspective: AnimatedRe.Interpolation.t=?,
      ~rotate: AnimatedRe.Interpolation.t=?,
      ~rotateX: AnimatedRe.Interpolation.t=?,
      ~rotateY: AnimatedRe.Interpolation.t=?,
      ~rotateZ: AnimatedRe.Interpolation.t=?,
      ~scaleX: AnimatedRe.Interpolation.t=?,
      ~scaleY: AnimatedRe.Interpolation.t=?,
      ~translateX: AnimatedRe.Interpolation.t=?,
      ~translateY: AnimatedRe.Interpolation.t=?,
      ~skewX: AnimatedRe.Interpolation.t=?,
      ~skewY: AnimatedRe.Interpolation.t=?,
      unit
    ) =>
    styleElement;
};


/***
 * View Props
 */
type backfaceVisibility =
  | Visible
  | Hidden;

let backfaceVisibility: backfaceVisibility => styleElement;

let backgroundColor: string => styleElement;

let borderColor: string => styleElement;

let borderTopColor: string => styleElement;

let borderRightColor: string => styleElement;

let borderBottomColor: string => styleElement;

let borderLeftColor: string => styleElement;

let borderRadius: float => styleElement;

let borderTopLeftRadius: float => styleElement;

let borderTopRightRadius: float => styleElement;

type borderStyle =
  | Solid
  | Dotted
  | Dashed;

let borderStyle: borderStyle => styleElement;

let borderBottomLeftRadius: float => styleElement;

let borderBottomRightRadius: float => styleElement;

let opacity: float_interpolated_animated => styleElement;

let elevation: float => styleElement;


/***
 *  Text Props
 */
let color: string => styleElement;

let fontFamily: string => styleElement;

let fontSize: float => styleElement;

type fontStyle =
  | Normal
  | Italic;

let fontStyle: fontStyle => styleElement;

let fontWeight:
  [ | `Normal | `Bold | `_100 | `_200 | `_300 | `_400 | `_500 | `_600 | `_700 | `_800 | `_900] =>
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

let textShadowColor: string => styleElement;

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

let textDecorationColor: string => styleElement;

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

let tintColor: string => styleElement;

let overlayColor: string => styleElement;
