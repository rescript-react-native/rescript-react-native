type t;

type style;

let style: list style => t;

let combine: t => t => t;

let concat: list t => t;
/** Equivalent to [style_a, style_b] in js */

/**
 * Layout Props
 */
let alignContent:
  [ | `flexStart | `flexEnd | `center | `stretch | `spaceAround | `spaceBetween] => style;

let alignItems: [ | `flexStart | `flexEnd | `center | `stretch | `baseline] => style;

let alignSelf: [ | `flexStart | `flexEnd | `center | `stretch | `baseline] => style;

let aspectRatio: float => style;

let borderBottomWidth: int => style;

let borderLeftWidth: int => style;

let borderRightWidth: int => style;

let borderTopWidth: int => style;

let borderWidth: int => style;

let bottom: float => style;

let bottomAnimated: AnimatedRe.Value.t => style;

let bottomInterpolated: AnimatedRe.Interpolation.t => style;

let display: [ | `flex | `none] => style;

let flex: float => style;

let flexBasis: int => style;

let flexBasisPct: float => style;

let flexDirection: [ | `row | `rowReverse | `column | `columnReverse] => style;

let flexGrow: float => style;

let flexShrink: float => style;

let flexWrap: [ | `wrap | `nowrap] => style;

let height: float => style;

let heightPct: float => style;

let heightAnimated: AnimatedRe.Value.t => style;

let heightInterpolated: AnimatedRe.Interpolation.t => style;

let justifyContent:
  [ | `flexStart | `flexEnd | `center | `stretch | `spaceAround | `spaceBetween] => style;

let left: float => style;

let leftAnimated: AnimatedRe.Value.t => style;

let leftInterpolated: AnimatedRe.Interpolation.t => style;

let margin: int => style;

let marginBottom: int => style;

let marginHorizontal: int => style;

let marginLeft: int => style;

let marginRight: int => style;

let marginTop: int => style;

let marginVertical: int => style;

let maxHeight: int => style;

let maxHeightPct: float => style;

let maxWidth: int => style;

let maxWidthPct: float => style;

let minHeight: int => style;

let minHeightPct: float => style;

let minWidth: int => style;

let minWidthPct: float => style;

let overflow: [ | `visible | `hidden | `scroll] => style;

let padding: int => style;

let paddingBottom: int => style;

let paddingHorizontal: int => style;

let paddingLeft: int => style;

let paddingRight: int => style;

let paddingTop: int => style;

let paddingVertical: int => style;

let position: [ | `absolute | `relative] => style;

let right: float => style;

let rightAnimated: AnimatedRe.Value.t => style;

let rightInterpolated: AnimatedRe.Interpolation.t => style;

let top: float => style;

let topAnimated: AnimatedRe.Value.t => style;

let topInterpolated: AnimatedRe.Interpolation.t => style;

let width: float => style;

let widthPct: float => style;

let widthAnimated: AnimatedRe.Value.t => style;

let widthInterpolated: AnimatedRe.Interpolation.t => style;

let zIndex: int => style;

let direction: [ | `_inherit | `ltr | `rtl] => style;


/**
 * Shadow Props
 */
let shadowColor: string => style;

let shadowOffset: height::int => width::int => style;

let shadowOpacity: float => style;

let shadowRadius: int => style;


/**
 * Transform Props
 */
let transform:
  perspective::float? =>
  rotate::string? =>
  rotateX::string? =>
  rotateY::string? =>
  rotateZ::string? =>
  scaleX::float? =>
  scaleY::float? =>
  translateX::float? =>
  translateY::float? =>
  skewX::float? =>
  skewY::float? =>
  unit =>
  style;


/**
 * View Props
 */
let backfaceVisibility: [ | `visible | `hidden] => style;

let backgroundColor: string => style;

let borderColor: string => style;

let borderTopColor: string => style;

let borderRightColor: string => style;

let borderBottomColor: string => style;

let borderLeftColor: string => style;

let borderRadius: int => style;

let borderTopLeftRadius: int => style;

let borderTopRightRadius: int => style;

let borderBottomLeftRadius: int => style;

let borderBottomRightRadius: int => style;

let borderStyle: [ | `solid | `dotted | `dashed] => style;

let opacity: float => style;

let elevation: float => style;


/**
 *  Text Props
 */
let color: string => style;

let fontSize: int => style;

let fontStyle: [ | `normal | `italic] => style;

let fontWeight:
  [ | `normal | `bold | `_100 | `_200 | `_300 | `_400 | `_500 | `_600 | `_700 | `_800 | `_900] =>
  style;

let lineHeight: int => style;

let textAlign: [ | `auto | `left | `right | `center | `justify] => style;

let textDecorationLine: [ | `none | `underline | `lineThrough | `underlineLineThrough] => style;

let textShadowColor: string => style;

let textShadowOffset: height::int => width::int => style;

let textShadowRadius: int => style;

let includeFontPadding: bool => style;

let textAlignVertical: [ | `auto | `top | `bottom | `center] => style;

let fontVariant: list string => style;

let letterSpacing: float => style;

let textDecorationColor: string => style;

let textDecorationStyle: [ | `solid | `double | `dotted | `dashed] => style;

let writingDirection: [ | `auto | `ltr | `rtl] => style;
