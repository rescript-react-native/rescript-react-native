type t

external array: array<t> => t = "%identity"
external arrayOption: array<option<t>> => t = "%identity"

// Escape hatch, in case something is added into RN but unsupported,
// Useful if you play with fancy platforms
// Use with caution
@val
external unsafeAddStyle: (@as(json`{}`) _, t, Js.t<'a>) => t = "Object.assign"

external unsafeStyle: Js.t<'a> => t = "%identity"

type size = string

external dp: float => size = "%identity"

let pct = num => num->Js.Float.toString ++ "%"

type margin = size

@inline
let auto = "auto"

type offset
@obj external offset: (~height: float, ~width: float) => offset = ""

type angle
let deg: float => angle = num => (num->Js.Float.toString ++ "deg")->Obj.magic
let rad: float => angle = num => (num->Js.Float.toString ++ "rad")->Obj.magic

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

type resizeMode = [#cover | #contain | #stretch | #repeat | #center]

type fontStyle = [#normal | #italic]

type fontWeight = [#normal | #bold | #100 | #200 | #300 | #400 | #500 | #600 | #700 | #800 | #900]

// @todo in 0.71.0
// Apparently there are more `fontVariant` options IOS specific
// (`stylistic-one` ... `stylistic-twenty`) but they are not documented.
// Found in the 0.71.0 changelog:
// https://github.com/facebook/react-native/blob/main/CHANGELOG.md#ios-specific-4
// and found in code:
// https://github.com/facebook/react-native/blob/4e117cb09d208ca02f513d2101592d0ac10d4739/Libraries/StyleSheet/StyleSheetTypes.js#L784
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

type position = [#absolute | #relative]

type alignContent = [
  | #"flex-start"
  | #"flex-end"
  | #center
  | #stretch
  | #"space-around"
  | #"space-between"
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
// https://github.com/facebook/react-native/blob/master/Libraries/StyleSheet/StyleSheetTypes.js

// Note that all border*Width are in layout styles & view styles too
// React Native JS codebase have those in View Styles Props again but with different types
// because layout styles props don't accept animated values.
// We don't do the distinction as ReScript is an HMTS that doesn't support implicit subtyping

// Dangerous Imprecise Style
// Contains all of
// - image style
// - text style
// - view style
// - transform style
// - shadow style
// - layout style
type style = {
  // Image Style Props (https://reactnative.dev/docs/image-style-props)
  resizeMode?: resizeMode,
  overlayColor?: Color.t,
  tintColor?: Color.t,
  objectFit?: objectFit,
  // Text Style Props (https://reactnative.dev/docs/text-style-props)
  color?: Color.t,
  fontFamily?: string,
  fontSize?: float,
  fontStyle?: fontStyle,
  fontVariant?: array<fontVariant>,
  fontWeight?: fontWeight,
  includeFontPadding?: bool,
  letterSpacing?: float,
  lineHeight?: float,
  textAlign?: textAlign,
  textAlignVertical?: textAlignVertical,
  textDecorationColor?: Color.t,
  textDecorationLine?: textDecorationLine,
  textDecorationStyle?: textDecorationStyle,
  textShadowColor?: Color.t,
  textShadowOffset?: offset,
  textShadowRadius?: float,
  textTransform?: textTransform,
  verticalAlign?: verticalAlign,
  writingDirection?: writingDirection,
  // View styles https://reactnative.dev/docs/view-style-props
  backfaceVisibility?: backfaceVisibility,
  backgroundColor?: Color.t,
  borderBottomColor?: Color.t,
  borderBottomEndRadius?: float,
  borderBottomLeftRadius?: float,
  borderBottomRightRadius?: float,
  borderBottomStartRadius?: float,
  borderBottomWidth?: float,
  borderColor?: Color.t,
  borderCurve?: borderCurve,
  borderEndColor?: Color.t,
  borderEndWidth?: float,
  borderLeftColor?: Color.t,
  borderLeftWidth?: float,
  borderRadius?: float,
  borderRightColor?: Color.t,
  borderRightWidth?: float,
  borderStartColor?: Color.t,
  borderStartWidth?: float,
  borderStyle?: borderStyle,
  borderTopColor?: Color.t,
  borderTopEndRadius?: float,
  borderTopLeftRadius?: float,
  borderTopRightRadius?: float,
  borderTopStartRadius?: float,
  borderTopWidth?: float,
  borderWidth?: float,
  elevation?: float,
  opacity?: float,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  transform?: array<transform>, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  shadowColor?: Color.t,
  shadowOffset?: offset,
  shadowOpacity?: float,
  shadowRadius?: float,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  alignContent?: alignContent,
  alignItems?: alignItems,
  alignSelf?: alignSelf,
  aspectRatio?: float,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // borderBottomWidth?: float,
  // borderEndWidth?: float,
  // borderLeftWidth?: float,
  // borderRightWidth?: float,
  // borderStartWidth?: float,
  // borderTopWidth?: float,
  // borderWidth?: float,
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
  marginBottom?: margin,
  marginEnd?: margin,
  marginHorizontal?: margin,
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
  paddingBottom?: size,
  paddingEnd?: size,
  paddingHorizontal?: size,
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
@obj
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
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderCurve: borderCurve=?,
  ~borderEndColor: Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
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
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
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
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
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
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderCurve: borderCurve=?,
  ~borderEndColor: Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
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
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
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
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
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
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderCurve: borderCurve=?,
  ~borderEndColor: Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
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
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
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
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
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
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderCurve: borderCurve=?,
  ~borderEndColor: Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
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
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
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
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
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

let empty: t = style()
