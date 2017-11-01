type t;


/*** Generates a style out of an array of styles.
  * This is equivalent:
  * // js
  * <ViewRe style={[styleA, styleB]} />
  * // reason
  * <ViewRe style=(Style.flatten [|styleA, styleB|]) />
 */
let flatten: array(t) => t;

type style;

let style: list(style) => t;

let combine: (t, t) => t;

let concat: list(t) => t;


/***
 * Layout Props
 */
let alignContent:
  [ | `flexStart | `flexEnd | `center | `stretch | `spaceAround | `spaceBetween] => style;

let alignItems: [ | `flexStart | `flexEnd | `center | `stretch | `baseline] => style;

let alignSelf: [ | `flexStart | `flexEnd | `center | `stretch | `baseline] => style;

let aspectRatio: float => style;

let borderBottomWidth: float => style;

let borderLeftWidth: float => style;

let borderRightWidth: float => style;

let borderTopWidth: float => style;

let borderWidth: float => style;

let bottom: float => style;

let bottomPct: float => style;

let bottomAnimatedRe: AnimatedRe.Value.t => style;

let bottomInterpolated: AnimatedRe.Interpolation.t => style;

let display: [ | `flex | `none] => style;

let flex: float => style;

let flexBasis: float => style;

let flexBasisPct: float => style;

let flexDirection: [ | `row | `rowReverse | `column | `columnReverse] => style;

let flexGrow: float => style;

let flexShrink: float => style;

let flexWrap: [ | `wrap | `nowrap] => style;

let height: float => style;

let heightPct: float => style;

let heightAnimatedRe: AnimatedRe.Value.t => style;

let heightInterpolated: AnimatedRe.Interpolation.t => style;

let justifyContent:
  [ | `flexStart | `flexEnd | `center | `stretch | `spaceAround | `spaceBetween] => style;

let left: float => style;

let leftPct: float => style;

let leftAnimatedRe: AnimatedRe.Value.t => style;

let leftInterpolated: AnimatedRe.Interpolation.t => style;

let margin: float => style;

let marginBottom: float => style;

let marginHorizontal: float => style;

let marginLeft: float => style;

let marginRight: float => style;

let marginTop: float => style;

let marginVertical: float => style;

let maxHeight: float => style;

let maxHeightPct: float => style;

let maxWidth: float => style;

let maxWidthPct: float => style;

let minHeight: float => style;

let minHeightPct: float => style;

let minWidth: float => style;

let minWidthPct: float => style;

let overflow: [ | `visible | `hidden | `scroll] => style;

let padding: float => style;

let paddingBottom: float => style;

let paddingHorizontal: float => style;

let paddingLeft: float => style;

let paddingRight: float => style;

let paddingTop: float => style;

let paddingVertical: float => style;

let position: [ | `absolute | `relative] => style;

let right: float => style;

let rightPct: float => style;

let rightAnimatedRe: AnimatedRe.Value.t => style;

let rightInterpolated: AnimatedRe.Interpolation.t => style;

let top: float => style;

let topPct: float => style;

let topAnimatedRe: AnimatedRe.Value.t => style;

let topInterpolated: AnimatedRe.Interpolation.t => style;

let width: float => style;

let widthPct: float => style;

let widthAnimatedRe: AnimatedRe.Value.t => style;

let widthInterpolated: AnimatedRe.Interpolation.t => style;

let zIndex: int => style;

let direction: [ | `_inherit | `ltr | `rtl] => style;


/***
 * Shadow Props
 */
let shadowColor: string => style;

let shadowOffset: (~height: float, ~width: float) => style;

let shadowOpacity: float => style;

let shadowRadius: float => style;


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
  style;

let transformAnimatedRe:
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
  style;

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
  style;


/***
 * ViewRe Props
 */
let backfaceVisibility: [ | `visible | `hidden] => style;

let backgroundColor: string => style;

let borderColor: string => style;

let borderTopColor: string => style;

let borderRightColor: string => style;

let borderBottomColor: string => style;

let borderLeftColor: string => style;

let borderRadius: float => style;

let borderTopLeftRadius: float => style;

let borderTopRightRadius: float => style;

let borderBottomLeftRadius: float => style;

let borderBottomRightRadius: float => style;

let borderStyle: [ | `solid | `dotted | `dashed] => style;

let opacity: float => style;

let opacityAnimatedRe: AnimatedRe.Value.t => style;

let opacityInterpolated: AnimatedRe.Interpolation.t => style;

let elevation: float => style;


/***
 *  Text Props
 */
let color: string => style;

let fontFamily: string => style;

let fontSize: float => style;

let fontStyle: [ | `normal | `italic] => style;

let fontWeight:
  [ | `normal | `bold | `_100 | `_200 | `_300 | `_400 | `_500 | `_600 | `_700 | `_800 | `_900] =>
  style;

let lineHeight: float => style;

let textAlign: [ | `auto | `left | `right | `center | `justify] => style;

let textDecorationLine: [ | `none | `underline | `lineThrough | `underlineLineThrough] => style;

let textShadowColor: string => style;

let textShadowOffset: (~height: float, ~width: float) => style;

let textShadowRadius: float => style;

let includeFontPadding: bool => style;

let textAlignVertical: [ | `auto | `top | `bottom | `center] => style;

let fontVariant: list(string) => style;

let letterSpacing: float => style;

let textDecorationColor: string => style;

let textDecorationStyle: [ | `solid | `double | `dotted | `dashed] => style;

let writingDirection: [ | `auto | `ltr | `rtl] => style;

let resizeMode: [ | `center | `contain | `cover | `repeat | `stretch] => style;

let tintColor: string => style;

let overlayColor: string => style;
