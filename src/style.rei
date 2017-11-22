type t;

type styleElement;

type px_pct =
  | Px(float)
  | Pct(float);

type px_auto =
  | Px(float)
  | Auto;

type px_pct_animated_interpolated =
  | Px(float)
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
let alignContent:
  [ | `FlexStart | `FlexEnd | `Center | `Stretch | `SpaceAround | `SpaceBetween] =>
  styleElement;

let alignItems:
  [ | `FlexStart | `FlexEnd | `Center | `Stretch | `Baseline] => styleElement;

let alignSelf:
  [ | `FlexStart | `FlexEnd | `Center | `Stretch | `Baseline] => styleElement;

let aspectRatio: float => styleElement;

let borderBottomWidth: float => styleElement;

let borderLeftWidth: float => styleElement;

let borderRightWidth: float => styleElement;

let borderTopWidth: float => styleElement;

let borderWidth: float => styleElement;

let flex: float => styleElement;

let display: [ | `Flex | `None] => styleElement;

let flexBasis: px_pct => styleElement;

let flexGrow: float => styleElement;

let flexDirection: [ | `Row | `RowReverse | `Column | `ColumnReverse] => styleElement;

let flexShrink: float => styleElement;

let flexWrap: [ | `Wrap | `Nowrap] => styleElement;

let justifyContent:
  [ | `FlexStart | `FlexEnd | `Center | `Stretch | `SpaceAround | `SpaceBetween] =>
  styleElement;

let margin: px_auto => styleElement;

let marginBottom: px_auto => styleElement;

let marginHorizontal: px_auto => styleElement;

let marginLeft: px_auto => styleElement;

let marginRight: px_auto => styleElement;

let marginTop: px_auto => styleElement;

let marginVertical: px_auto => styleElement;

let maxHeight: px_pct => styleElement;

let maxWidth: px_pct => styleElement;

let minHeight: px_pct => styleElement;

let minWidth: px_pct => styleElement;

let overflow: [ | `Visible | `Hidden | `Scroll] => styleElement;

let padding: px_pct => styleElement;

let paddingBottom: px_pct => styleElement;

let paddingHorizontal: px_pct => styleElement;

let paddingLeft: px_pct => styleElement;

let paddingRight: px_pct => styleElement;

let paddingTop: px_pct => styleElement;

let paddingVertical: px_pct => styleElement;

let position: [ | `Absolute | `Relative] => styleElement;

let top: px_pct_animated_interpolated => styleElement;

let left: px_pct_animated_interpolated => styleElement;

let right: px_pct_animated_interpolated => styleElement;

let bottom: px_pct_animated_interpolated => styleElement;

let height: px_pct_animated_interpolated => styleElement;

let width: px_pct_animated_interpolated => styleElement;

let zIndex: int => styleElement;

let direction: [ | `Inherit | `Ltr | `Rtl] => styleElement;


/***
 * Shadow Props
 */
let shadowColor: string => styleElement;

let shadowOffset: (~height: float, ~width: float) => styleElement;

let shadowOpacity: float => styleElement;

let shadowRadius: float => styleElement;


/***
 * Transform Props
 */
let transform:
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

let transformAnimated:
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

let transformInterpolated:
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


/***
 * View Props
 */
let backfaceVisibility: [ | `Visible | `Hidden] => styleElement;

let backgroundColor: string => styleElement;

let borderColor: string => styleElement;

let borderTopColor: string => styleElement;

let borderRightColor: string => styleElement;

let borderBottomColor: string => styleElement;

let borderLeftColor: string => styleElement;

let borderRadius: float => styleElement;

let borderTopLeftRadius: float => styleElement;

let borderTopRightRadius: float => styleElement;

let borderStyle: [ | `Solid | `Dotted | `Dashed] => styleElement;

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

let fontStyle: [ | `Normal | `Italic] => styleElement;

let fontWeight:
  [
    | `Normal
    | `Bold
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

let textAlign: [ | `Auto | `Left | `Right | `Center | `Justify] => styleElement;

let textDecorationLine:
  [ | `None | `Underline | `LineThrough | `UnderlineLineThrough] => styleElement;

let textShadowColor: string => styleElement;

let textShadowOffset: (~height: float, ~width: float) => styleElement;

let textShadowRadius: float => styleElement;

let includeFontPadding: bool => styleElement;

let textAlignVertical: [ | `Auto | `Top | `Bottom | `Center] => styleElement;

let fontVariant: list(string) => styleElement;

let letterSpacing: float => styleElement;

let textDecorationColor: string => styleElement;

let textDecorationStyle: [ | `Solid | `Double | `Dotted | `Dashed] => styleElement;

let writingDirection: [ | `Auto | `Ltr | `Rtl] => styleElement;

let resizeMode: [ | `Center | `Contain | `Cover | `Repeat | `Stretch] => styleElement;

let tintColor: string => styleElement;

let overlayColor: string => styleElement;
