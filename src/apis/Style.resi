type t

external array: array<t> => t = "%identity"
external arrayOption: array<option<t>> => t = "%identity"
@val
external unsafeAddStyle: (@as(json`{}`) _, t, Js.t<'a>) => t = "Object.assign"
external unsafeStyle: Js.t<'a> => t = "%identity"

type size

external dp: float => size = "%identity"

let pct: float => size

type margin = size

@inline("auto")
let auto: margin

type offset
@obj external offset: (~height: float, ~width: float) => offset = ""

type angle
let deg: float => angle
let rad: float => angle

type transform
@obj external perspective: (~perspective: float) => transform = ""
@obj external rotate: (~rotate: angle) => transform = ""
@obj external rotateX: (~rotateX: angle) => transform = ""
@obj external rotateY: (~rotateY: angle) => transform = ""
@obj external rotateZ: (~rotateZ: angle) => transform = ""
@obj external scale: (~scale: float) => transform = ""
@obj external scaleX: (~scaleX: float) => transform = ""
@obj external scaleY: (~scaleY: float) => transform = ""
@obj external translateX: (~translateX: float) => transform = ""
@obj external translateY: (~translateY: float) => transform = ""
@obj external skewX: (~skewX: angle) => transform = ""
@obj external skewY: (~skewY: angle) => transform = ""
// @todo matrix

external unsafeTransform: Js.t<'a> => transform = "%identity"

@unboxed
type transformOrigin =
  | @as("top") Top
  | @as("bottom") Bottom
  | @as("left") Left
  | @as("right") Right
  | @as("center") Center
  | Size(size)

type resizeMode = [#cover | #contain | #stretch | #repeat | #center]

type fontStyle = [#normal | #italic]

type fontWeight = [#normal | #bold | #100 | #200 | #300 | #400 | #500 | #600 | #700 | #800 | #900]

type fontVariant = [
  | #"small-caps"
  | #"oldstyle-nums"
  | #"lining-nums"
  | #"tabular-nums"
  | #"proportional-nums"
]

type textAlign = [#auto | #left | #right | #center | #justify]

type textAlignVertical = [#auto | #top | #bottom | #center]

type textDecorationLine = [
  | #none
  | #underline
  | #"line-through"
  | #"underline line-through"
]

type textDecorationStyle = [#solid | #double | #dotted | #dashed]

type textTransform = [#none | #uppercase | #lowercase | #capitalize]

type writingDirection = [#auto | #ltr | #rtl]

type backfaceVisibility = [#visible | #hidden]

type borderStyle = [#solid | #dotted | #dashed]

type display = [#none | #flex]

type overflow = [#visible | #hidden | #scroll]

type flexWrap = [#wrap | #nowrap]

type position = [#absolute | #relative | #static]

type alignContent = [
  | #"flex-start"
  | #"flex-end"
  | #center
  | #stretch
  | #"space-around"
  | #"space-between"
  | #"space-evenly"
]

type alignItems = [
  | #"flex-start"
  | #"flex-end"
  | #center
  | #stretch
  | #baseline
]

type alignSelf = [
  | #auto
  | #"flex-start"
  | #"flex-end"
  | #center
  | #stretch
  | #baseline
]

type direction = [#inherit | #ltr | #rtl]

type flexDirection = [
  | #row
  | #"row-reverse"
  | #column
  | #"column-reverse"
]

type justifyContent = [
  | #"flex-start"
  | #"flex-end"
  | #center
  | #"space-around"
  | #"space-between"
  | #"space-evenly"
]

type objectFit = [
  | #cover
  | #contain
  | #fill
  | #"scale-down"
]

type verticalAlign = [
  | #auto
  | #top
  | #bottom
  | #middle
]

type borderCurve = [
  | #circular
  | #continuous
]

// Styles are documented here
// https://github.com/facebook/react-native/blob/main/packages/react-native/Libraries/StyleSheet/StyleSheetTypes.d.ts

// Layout Style Props (https://reactnative.dev/docs/layout-props)
type flexStyle = {
  alignContent?: alignContent,
  alignItems?: alignItems,
  alignSelf?: alignSelf,
  aspectRatio?: float,
  borderBottomWidth?: float,
  borderEndWidth?: float,
  borderLeftWidth?: float,
  borderRightWidth?: float,
  borderStartWidth?: float,
  borderTopWidth?: float,
  borderWidth?: float,
  bottom?: size,
  columnGap?: float,
  direction?: direction,
  display?: display,
  end?: size,
  flex?: float,
  flexBasis?: margin,
  flexDirection?: flexDirection,
  flexGrow?: float,
  flexShrink?: float,
  flexWrap?: flexWrap,
  gap?: float,
  height?: size,
  justifyContent?: justifyContent,
  left?: size,
  margin?: margin,
  marginBlock?: size,
  marginBlockEnd?: size,
  marginBlockStart?: size,
  marginBottom?: margin,
  marginEnd?: margin,
  marginHorizontal?: margin,
  marginInline?: size,
  marginInlineEnd?: size,
  marginInlineStart?: size,
  marginLeft?: margin,
  marginRight?: margin,
  marginStart?: margin,
  marginTop?: margin,
  marginVertical?: margin,
  maxHeight?: size,
  maxWidth?: size,
  minHeight?: size,
  minWidth?: size,
  overflow?: overflow,
  padding?: size,
  paddingBlock?: size,
  paddingBlockEnd?: size,
  paddingBlockStart?: size,
  paddingBottom?: size,
  paddingEnd?: size,
  paddingHorizontal?: size,
  paddingInline?: size,
  paddingInlineEnd?: size,
  paddingInlineStart?: size,
  paddingLeft?: size,
  paddingRight?: size,
  paddingStart?: size,
  paddingTop?: size,
  paddingVertical?: size,
  position?: position,
  right?: size,
  rowGap?: float,
  start?: size,
  top?: size,
  width?: size,
  zIndex?: int,
}

// Shadow Props (https://reactnative.dev/docs/shadow-props)
type shadowIOSStyle = {
  shadowColor?: Color.t,
  shadowOffset?: offset,
  shadowOpacity?: float,
  shadowRadius?: float,
}

// Transform Props (https://reactnative.dev/docs/transforms#props)
type transformStyle = {
  transform?: array<transform>,
  transformOrigin?: array<transformOrigin>,
}

// View styles https://reactnative.dev/docs/view-style-props
type viewCoreStyle = {
  backfaceVisibility?: backfaceVisibility,
  backgroundColor?: Color.t,
  borderBlockColor?: Color.t,
  borderBlockEndColor?: Color.t,
  borderBlockStartColor?: Color.t,
  borderBottomColor?: Color.t,
  borderBottomEndRadius?: float,
  borderBottomLeftRadius?: float,
  borderBottomRightRadius?: float,
  borderBottomStartRadius?: float,
  borderColor?: Color.t,
  borderCurve?: borderCurve,
  borderEndColor?: Color.t,
  borderEndEndRadius?: float,
  borderEndStartRadius?: float,
  borderLeftColor?: Color.t,
  borderRadius?: float,
  borderRightColor?: Color.t,
  borderStartColor?: Color.t,
  borderStartEndRadius?: float,
  borderStartStartRadius?: float,
  borderStyle?: borderStyle,
  borderTopColor?: Color.t,
  borderTopEndRadius?: float,
  borderTopLeftRadius?: float,
  borderTopRightRadius?: float,
  borderTopStartRadius?: float,
  elevation?: float,
  opacity?: float,
}

// Text Style Props (https://reactnative.dev/docs/text-style-props)
type textIOSStyle = {
  fontVariant?: array<fontVariant>,
  textDecorationColor?: Color.t,
  textDecorationStyle?: textDecorationStyle,
  writingDirection?: writingDirection,
}
type textAndroidStyle = {
  textAlignVertical?: textAlignVertical,
  verticalAlign?: verticalAlign,
  includeFontPadding?: bool,
}
type textCoreStyle = {
  ...textIOSStyle,
  ...textAndroidStyle,
  color?: Color.t,
  fontFamily?: string,
  fontSize?: float,
  fontStyle?: fontStyle,
  fontWeight?: fontWeight,
  letterSpacing?: float,
  lineHeight?: float,
  textAlign?: textAlign,
  textDecorationLine?: textDecorationLine,
  textShadowColor?: Color.t,
  textShadowOffset?: offset,
  textShadowRadius?: float,
  textTransform?: textTransform,
}

// Image Style Props (https://reactnative.dev/docs/image-style-props)
type imageCoreStyle = {
  resizeMode?: resizeMode,
  overlayColor?: Color.t,
  tintColor?: Color.t,
  objectFit?: objectFit,
}

// Dangerous Imprecise Style
// Contains all of
// - image style
// - text style
// - view style
// - transform style
// - shadow style
// - layout style
type style = {
  ...imageCoreStyle,
  ...textCoreStyle,
  ...viewCoreStyle,
  ...transformStyle,
  ...shadowIOSStyle,
  ...flexStyle,
}

external s: style => t = "%identity"

// ____DangerouslyImpreciseStyle_Internal
// Dangerous Imprecise Style
// Contains all of
// - image style
// - text style
// - view style
// - transform style
// - shadow style
// - layout style
@deprecated("Use style record with s() function") @obj
external style: (
  // Image Style Props (https://reactnative.dev/docs/image-style-props)
  ~resizeMode: resizeMode=?,
  ~overlayColor: Color.t=?,
  ~tintColor: Color.t=?,
  // Text Style Props (https://reactnative.dev/docs/text-style-props)
  ~color: Color.t=?,
  ~fontFamily: string=?,
  ~fontSize: float=?,
  ~fontStyle: fontStyle=?,
  ~fontVariant: array<fontVariant>=?,
  ~fontWeight: fontWeight=?,
  ~includeFontPadding: bool=?,
  ~letterSpacing: float=?,
  ~lineHeight: float=?,
  ~textAlign: textAlign=?,
  ~textAlignVertical: textAlignVertical=?,
  ~textDecorationColor: Color.t=?,
  ~textDecorationLine: textDecorationLine=?,
  ~textDecorationStyle: textDecorationStyle=?,
  ~textShadowColor: Color.t=?,
  ~textShadowOffset: offset=?,
  ~textShadowRadius: float=?,
  ~textTransform: textTransform=?,
  ~verticalAlign: verticalAlign=?,
  ~writingDirection: writingDirection=?,
  // View styles https://reactnative.dev/docs/view-style-props
  ~backfaceVisibility: backfaceVisibility=?,
  ~backgroundColor: Color.t=?,
  ~borderBlockColor: Color.t=?,
  ~borderBlockEndColor: Color.t=?,
  ~borderBlockStartColor: Color.t=?,
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderCurve: borderCurve=?,
  ~borderEndColor: Color.t=?,
  ~borderEndEndRadius: float=?,
  ~borderEndStartRadius: float=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
  ~borderStartEndRadius: float=?,
  ~borderStartStartRadius: float=?,
  ~borderStartWidth: float=?,
  ~borderStyle: borderStyle=?,
  ~borderTopColor: Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~elevation: float=?,
  ~opacity: float=?,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  ~transform: array<transform>=?, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  ~shadowColor: Color.t=?,
  ~shadowOffset: offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~alignSelf: alignSelf=?,
  ~aspectRatio: float=?,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // ~borderBottomWidth: float=?,
  // ~borderEndWidth: float=?,
  // ~borderLeftWidth: float=?,
  // ~borderRightWidth: float=?,
  // ~borderStartWidth: float=?,
  // ~borderTopWidth: float=?,
  // ~borderWidth: float=?,
  ~bottom: size=?,
  ~columnGap: float=?,
  ~direction: direction=?,
  ~display: display=?,
  ~end: size=?,
  ~flex: float=?,
  ~flexBasis: margin=?,
  ~flexDirection: flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: flexWrap=?,
  ~gap: float=?,
  ~height: size=?,
  ~justifyContent: justifyContent=?,
  ~left: size=?,
  ~margin: margin=?,
  ~marginBlock: margin=?,
  ~marginBlockEnd: margin=?,
  ~marginBlockStart: margin=?,
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
  ~marginInline: margin=?,
  ~marginInlineEnd: margin=?,
  ~marginInlineStart: margin=?,
  ~marginLeft: margin=?,
  ~marginRight: margin=?,
  ~marginStart: margin=?,
  ~marginTop: margin=?,
  ~marginVertical: margin=?,
  ~maxHeight: size=?,
  ~maxWidth: size=?,
  ~minHeight: size=?,
  ~minWidth: size=?,
  ~overflow: overflow=?,
  ~padding: size=?,
  ~paddingBlock: size=?,
  ~paddingBlockEnd: size=?,
  ~paddingBlockStart: size=?,
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
  ~paddingInline: size=?,
  ~paddingInlineEnd: size=?,
  ~paddingInlineStart: size=?,
  ~paddingLeft: size=?,
  ~paddingRight: size=?,
  ~paddingStart: size=?,
  ~paddingTop: size=?,
  ~paddingVertical: size=?,
  ~position: position=?,
  ~right: size=?,
  ~rowGap: float=?,
  ~start: size=?,
  ~top: size=?,
  ~width: size=?,
  ~zIndex: int=?,
  unit,
) => t = ""

// ____ViewStyleProp_Internal
@obj
external viewStyle: (
  // View styles https://reactnative.dev/docs/view-style-props
  ~backfaceVisibility: backfaceVisibility=?,
  ~backgroundColor: Color.t=?,
  ~borderBlockColor: Color.t=?,
  ~borderBlockEndColor: Color.t=?,
  ~borderBlockStartColor: Color.t=?,
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderCurve: borderCurve=?,
  ~borderEndColor: Color.t=?,
  ~borderEndEndRadius: float=?,
  ~borderEndStartRadius: float=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
  ~borderStartEndRadius: float=?,
  ~borderStartStartRadius: float=?,
  ~borderStartWidth: float=?,
  ~borderStyle: borderStyle=?,
  ~borderTopColor: Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~elevation: float=?,
  ~opacity: float=?,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  ~transform: array<transform>=?, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  ~shadowColor: Color.t=?,
  ~shadowOffset: offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~alignSelf: alignSelf=?,
  ~aspectRatio: float=?,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // ~borderBottomWidth: float=?,
  // ~borderEndWidth: float=?,
  // ~borderLeftWidth: float=?,
  // ~borderRightWidth: float=?,
  // ~borderStartWidth: float=?,
  // ~borderTopWidth: float=?,
  // ~borderWidth: float=?,
  ~bottom: size=?,
  ~columnGap: float=?,
  ~direction: direction=?,
  ~display: display=?,
  ~end: size=?,
  ~flex: float=?,
  ~flexBasis: margin=?,
  ~flexDirection: flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: flexWrap=?,
  ~gap: float=?,
  ~height: size=?,
  ~justifyContent: justifyContent=?,
  ~left: size=?,
  ~margin: margin=?,
  ~marginBlock: margin=?,
  ~marginBlockEnd: margin=?,
  ~marginBlockStart: margin=?,
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
  ~marginInline: margin=?,
  ~marginInlineEnd: margin=?,
  ~marginInlineStart: margin=?,
  ~marginLeft: margin=?,
  ~marginRight: margin=?,
  ~marginStart: margin=?,
  ~marginTop: margin=?,
  ~marginVertical: margin=?,
  ~maxHeight: size=?,
  ~maxWidth: size=?,
  ~minHeight: size=?,
  ~minWidth: size=?,
  ~overflow: overflow=?,
  ~padding: size=?,
  ~paddingBlock: size=?,
  ~paddingBlockEnd: size=?,
  ~paddingBlockStart: size=?,
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
  ~paddingInline: size=?,
  ~paddingInlineEnd: size=?,
  ~paddingInlineStart: size=?,
  ~paddingLeft: size=?,
  ~paddingRight: size=?,
  ~paddingStart: size=?,
  ~paddingTop: size=?,
  ~paddingVertical: size=?,
  ~position: position=?,
  ~right: size=?,
  ~rowGap: float=?,
  ~start: size=?,
  ~top: size=?,
  ~width: size=?,
  ~zIndex: int=?,
  unit,
) => t = ""

// ____TextStyleProp_Internal
@obj
external textStyle: (
  // Text Style Props (https://reactnative.dev/docs/text-style-props)
  ~color: Color.t=?,
  ~fontFamily: string=?,
  ~fontSize: float=?,
  ~fontStyle: fontStyle=?,
  ~fontVariant: array<fontVariant>=?,
  ~fontWeight: fontWeight=?,
  ~includeFontPadding: bool=?,
  ~letterSpacing: float=?,
  ~lineHeight: float=?,
  ~textAlign: textAlign=?,
  ~textAlignVertical: textAlignVertical=?,
  ~textDecorationColor: Color.t=?,
  ~textDecorationLine: textDecorationLine=?,
  ~textDecorationStyle: textDecorationStyle=?,
  ~textShadowColor: Color.t=?,
  ~textShadowOffset: offset=?,
  ~textShadowRadius: float=?,
  ~textTransform: textTransform=?,
  ~verticalAlign: verticalAlign=?,
  ~writingDirection: writingDirection=?,
  // View styles https://reactnative.dev/docs/view-style-props
  ~backfaceVisibility: backfaceVisibility=?,
  ~backgroundColor: Color.t=?,
  ~borderBlockColor: Color.t=?,
  ~borderBlockEndColor: Color.t=?,
  ~borderBlockStartColor: Color.t=?,
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderCurve: borderCurve=?,
  ~borderEndColor: Color.t=?,
  ~borderEndEndRadius: float=?,
  ~borderEndStartRadius: float=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
  ~borderStartEndRadius: float=?,
  ~borderStartStartRadius: float=?,
  ~borderStartWidth: float=?,
  ~borderStyle: borderStyle=?,
  ~borderTopColor: Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~elevation: float=?,
  ~opacity: float=?,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  ~transform: array<transform>=?, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  ~shadowColor: Color.t=?,
  ~shadowOffset: offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~alignSelf: alignSelf=?,
  ~aspectRatio: float=?,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // ~borderBottomWidth: float=?,
  // ~borderEndWidth: float=?,
  // ~borderLeftWidth: float=?,
  // ~borderRightWidth: float=?,
  // ~borderStartWidth: float=?,
  // ~borderTopWidth: float=?,
  // ~borderWidth: float=?,
  ~bottom: size=?,
  ~columnGap: float=?,
  ~direction: direction=?,
  ~display: display=?,
  ~end: size=?,
  ~flex: float=?,
  ~flexBasis: margin=?,
  ~flexDirection: flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: flexWrap=?,
  ~gap: float=?,
  ~height: size=?,
  ~justifyContent: justifyContent=?,
  ~left: size=?,
  ~margin: margin=?,
  ~marginBlock: margin=?,
  ~marginBlockEnd: margin=?,
  ~marginBlockStart: margin=?,
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
  ~marginInline: margin=?,
  ~marginInlineEnd: margin=?,
  ~marginInlineStart: margin=?,
  ~marginLeft: margin=?,
  ~marginRight: margin=?,
  ~marginStart: margin=?,
  ~marginTop: margin=?,
  ~marginVertical: margin=?,
  ~maxHeight: size=?,
  ~maxWidth: size=?,
  ~minHeight: size=?,
  ~minWidth: size=?,
  ~overflow: overflow=?,
  ~padding: size=?,
  ~paddingBlock: size=?,
  ~paddingBlockEnd: size=?,
  ~paddingBlockStart: size=?,
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
  ~paddingInline: size=?,
  ~paddingInlineEnd: size=?,
  ~paddingInlineStart: size=?,
  ~paddingLeft: size=?,
  ~paddingRight: size=?,
  ~paddingStart: size=?,
  ~paddingTop: size=?,
  ~paddingVertical: size=?,
  ~position: position=?,
  ~right: size=?,
  ~rowGap: float=?,
  ~start: size=?,
  ~top: size=?,
  ~width: size=?,
  ~zIndex: int=?,
  unit,
) => t = ""

// ____ImageStyleProp_Internal
@obj
external imageStyle: (
  // Image Style Props (https://reactnative.dev/docs/image-style-props)
  ~resizeMode: resizeMode=?,
  ~overlayColor: Color.t=?,
  ~tintColor: Color.t=?,
  ~objectFit: objectFit=?,
  // View styles https://reactnative.dev/docs/view-style-props
  ~backfaceVisibility: backfaceVisibility=?,
  ~backgroundColor: Color.t=?,
  ~borderBlockColor: Color.t=?,
  ~borderBlockEndColor: Color.t=?,
  ~borderBlockStartColor: Color.t=?,
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderCurve: borderCurve=?,
  ~borderEndColor: Color.t=?,
  ~borderEndEndRadius: float=?,
  ~borderEndStartRadius: float=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
  ~borderStartEndRadius: float=?,
  ~borderStartStartRadius: float=?,
  ~borderStartWidth: float=?,
  ~borderStyle: borderStyle=?,
  ~borderTopColor: Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~elevation: float=?,
  ~opacity: float=?,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  ~transform: array<transform>=?, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  ~shadowColor: Color.t=?,
  ~shadowOffset: offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~alignSelf: alignSelf=?,
  ~aspectRatio: float=?,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // ~borderBottomWidth: float=?,
  // ~borderEndWidth: float=?,
  // ~borderLeftWidth: float=?,
  // ~borderRightWidth: float=?,
  // ~borderStartWidth: float=?,
  // ~borderTopWidth: float=?,
  // ~borderWidth: float=?,
  ~bottom: size=?,
  ~columnGap: float=?,
  ~direction: direction=?,
  ~display: display=?,
  ~end: size=?,
  ~flex: float=?,
  ~flexBasis: margin=?,
  ~flexDirection: flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: flexWrap=?,
  ~gap: float=?,
  ~height: size=?,
  ~justifyContent: justifyContent=?,
  ~left: size=?,
  ~margin: margin=?,
  ~marginBlock: margin=?,
  ~marginBlockEnd: margin=?,
  ~marginBlockStart: margin=?,
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
  ~marginInline: margin=?,
  ~marginInlineEnd: margin=?,
  ~marginInlineStart: margin=?,
  ~marginLeft: margin=?,
  ~marginRight: margin=?,
  ~marginStart: margin=?,
  ~marginTop: margin=?,
  ~marginVertical: margin=?,
  ~maxHeight: size=?,
  ~maxWidth: size=?,
  ~minHeight: size=?,
  ~minWidth: size=?,
  ~overflow: overflow=?,
  ~padding: size=?,
  ~paddingBlock: size=?,
  ~paddingBlockEnd: size=?,
  ~paddingBlockStart: size=?,
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
  ~paddingInline: size=?,
  ~paddingInlineEnd: size=?,
  ~paddingInlineStart: size=?,
  ~paddingLeft: size=?,
  ~paddingRight: size=?,
  ~paddingStart: size=?,
  ~paddingTop: size=?,
  ~paddingVertical: size=?,
  ~position: position=?,
  ~right: size=?,
  ~rowGap: float=?,
  ~start: size=?,
  ~top: size=?,
  ~width: size=?,
  ~zIndex: int=?,
  unit,
) => t = ""

let empty: t
