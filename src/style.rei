type t;

type style;

let style: list style => t;

let combine: t => t => t;

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

let bottom: int => style;

let display: [ | `flex | `none] => style;

let flex: float => style;

let flexBasis: int => style;

let flexDirection: [ | `row | `rowReverse | `column | `columnReverse] => style;

let flexGrow: float => style;

let flexShrink: float => style;

let flexWrap: [ | `wrap | `nowrap] => style;

let height: int => style;

let justifyContent:
  [ | `flexStart | `flexEnd | `center | `stretch | `spaceAround | `spaceBetween] => style;

let left: int => style;

let margin: int => style;

let marginBottom: int => style;

let marginHorizontal: int => style;

let marginLeft: int => style;

let marginRight: int => style;

let marginTop: int => style;

let marginVertical: int => style;

let maxHeight: int => style;

let maxWidth: int => style;

let minHeight: int => style;

let minWidth: int => style;

let overflow: [ | `visible | `hidden | `scroll] => style;

let padding: int => style;

let paddingBottom: int => style;

let paddingHorizontal: int => style;

let paddingLeft: int => style;

let paddingRight: int => style;

let paddingTop: int => style;

let paddingVertical: int => style;

let position: [ | `absolute | `relative] => style;

let right: int => style;

let top: int => style;

let width: int => style;

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