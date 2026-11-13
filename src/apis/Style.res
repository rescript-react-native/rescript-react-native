type t

external array: array<t> => t = "%identity"
external arrayOption: array<option<t>> => t = "%identity"

// Escape hatch, in case something is added into RN but unsupported,
// Useful if you play with fancy platforms
// Use with caution
@val
external unsafeAddStyle: (@as(json`{}`) _, t, {..}) => t = "Object.assign"

external unsafeStyle: {..} => t = "%identity"

type size = string

external dp: float => size = "%identity"

let pct = num => num->Float.toString ++ "%"

type margin = size

@inline
let auto = "auto"

type offset = Layout.size

type angle = string
let deg: float => angle = num => num->Float.toString ++ "deg"
let rad: float => angle = num => num->Float.toString ++ "rad"

type transform
@obj external perspective: (~perspective: float) => transform = ""
@obj external rotate: (~rotate: angle) => transform = ""
@obj external rotateX: (~rotateX: angle) => transform = ""
@obj external rotateY: (~rotateY: angle) => transform = ""
@obj external rotateZ: (~rotateZ: angle) => transform = ""
@obj external scale: (~scale: float) => transform = ""
@obj external scaleX: (~scaleX: float) => transform = ""
@obj external scaleY: (~scaleY: float) => transform = ""
@obj external translateX: (~translateX: size) => transform = ""
@obj external translateY: (~translateY: size) => transform = ""
@obj external skewX: (~skewX: angle) => transform = ""
@obj external skewY: (~skewY: angle) => transform = ""
@obj external matrix: (~matrix: array<float>) => transform = ""

external unsafeTransform: {..} => transform = "%identity"

@unboxed
type transformOriginX =
  | @as("0%") Left
  | @as("100%") Right
  | @as("50%") Center
  | Size(size)

@unboxed
type transformOriginY =
  | @as("0%") Top
  | @as("100%") Bottom
  | @as("50%") Center
  | Size(size)

type transformOrigin = (transformOriginX, transformOriginY, float)

// `positions` are pixels (`dp`) or percentages (`pct`).
// A stop without `color` and with exactly one position is a transition hint
// (CSS `red, 40%, blue`): `[{color: "red"}, {positions: [pct(40.)]}, {color: "blue"}]`
type gradientColorStop = {
  color?: Color.t,
  positions?: array<size>,
}

@unboxed
type linearGradientDirection =
  | @as("to top") ToTop
  | @as("to right") ToRight
  | @as("to bottom") ToBottom
  | @as("to left") ToLeft
  | @as("to top right") ToTopRight
  | @as("to bottom right") ToBottomRight
  | @as("to top left") ToTopLeft
  | @as("to bottom left") ToBottomLeft
  | Angle(angle)

@unboxed
type radialGradientSize =
  | @as("closest-corner") ClosestCorner
  | @as("closest-side") ClosestSide
  | @as("farthest-corner") FarthestCorner
  | @as("farthest-side") FarthestSide
  | Size({x: size, y: size})

// one vertical and one horizontal side,
// e.g. `RadialGradientPosition.topLeft(~top=pct(50.), ~left=pct(50.))`
module RadialGradientPosition = {
  @notUndefined
  type t

  @obj external topLeft: (~top: size, ~left: size) => t = ""
  @obj external topRight: (~top: size, ~right: size) => t = ""
  @obj external bottomLeft: (~bottom: size, ~left: size) => t = ""
  @obj external bottomRight: (~bottom: size, ~right: size) => t = ""
}

type radialGradientPosition = RadialGradientPosition.t

@tag("type")
type gradient =
  | @as("linear-gradient")
  LinearGradient({
      direction?: linearGradientDirection,
      colorStops: array<gradientColorStop>,
    })
  | @as("radial-gradient")
  RadialGradient({
      shape: [#circle | #ellipse],
      size: radialGradientSize,
      position: radialGradientPosition,
      colorStops: array<gradientColorStop>,
    })

// `String("linear-gradient(...)")` (CSS syntax) or `Gradients([LinearGradient({...})])`
@unboxed
type backgroundImage = String(string) | Gradients(array<gradient>)

// one value per background image layer, or a CSS string

type backgroundSizeValue = {x: size, y: size}

@unboxed
type backgroundSize = String(string) | Sizes(array<backgroundSizeValue>)

// same shape as a radial gradient position
module BackgroundPosition = RadialGradientPosition

@unboxed
type backgroundPosition = String(string) | Positions(array<BackgroundPosition.t>)

type backgroundRepeatKeyword = [#repeat | #space | #round | #"no-repeat"]

type backgroundRepeatValue = {x: backgroundRepeatKeyword, y: backgroundRepeatKeyword}

@unboxed
type backgroundRepeat = String(string) | Repeats(array<backgroundRepeatValue>)

// variable fonts, registered OpenType axes
// (font-specific uppercase axes like `GRAD` use the string form: `String("'GRAD' 50")`)
type fontVariationAxes = {
  wght?: float, // weight, 1 to 1000
  wdth?: float, // width, in %
  ital?: float, // italic, 0 or 1
  slnt?: float, // slant, -90 to 90 degrees
  opsz?: float, // optical size
}

// CSS string (`String("'wght' 600")`) or registered axes (`Axes({wght: 600.})`)
@unboxed
type fontVariationSettings = String(string) | Axes(fontVariationAxes)

type boxShadow = {
  offsetX: float,
  offsetY: float,
  color?: Color.t,
  blurRadius?: float,
  spreadDistance?: float,
  inset?: bool,
}

type dropShadow = {
  offsetX: float,
  offsetY: float,
  standardDeviation?: float,
  color?: Color.t,
}

type filter
@obj external brightness: (~brightness: float) => filter = ""
@obj external blur: (~blur: float) => filter = ""
@obj external contrast: (~contrast: float) => filter = ""
@obj external grayscale: (~grayscale: float) => filter = ""
@obj external hueRotate: (~hueRotate: float) => filter = ""
@obj external invert: (~invert: float) => filter = ""
@obj external opacity: (~opacity: float) => filter = ""
@obj external saturate: (~saturate: float) => filter = ""
@obj external sepia: (~sepia: float) => filter = ""
@obj external dropShadow: (~dropShadow: dropShadow) => filter = ""

external unsafeFilter: {..} => filter = "%identity"

type blendMode = [
  | #normal
  | #multiply
  | #screen
  | #overlay
  | #darken
  | #lighten
  | #"color-dodge"
  | #"color-burn"
  | #"hard-light"
  | #"soft-light"
  | #difference
  | #exclusion
  | #hue
  | #saturation
  | #color
  | #luminosity
  | #"plus-lighter"
]

type isolation = [#auto | #isolate]

type outlineStyle = [#solid | #dotted | #dashed]

type resizeMode = [#cover | #contain | #stretch | #repeat | #center]

type fontStyle = [#normal | #italic]

type fontWeight = [#normal | #bold | #100 | #200 | #300 | #400 | #500 | #600 | #700 | #800 | #900]

type fontVariant = [
  | #"small-caps"
  | #"oldstyle-nums"
  | #"lining-nums"
  | #"tabular-nums"
  | #"common-ligatures"
  | #"no-common-ligatures"
  | #"discretionary-ligatures"
  | #"no-discretionary-ligatures"
  | #"historical-ligatures"
  | #"no-historical-ligatures"
  | #contextual
  | #"no-contextual"
  | #"proportional-nums"
  | #"stylistic-one"
  | #"stylistic-two"
  | #"stylistic-three"
  | #"stylistic-four"
  | #"stylistic-five"
  | #"stylistic-six"
  | #"stylistic-seven"
  | #"stylistic-eight"
  | #"stylistic-nine"
  | #"stylistic-ten"
  | #"stylistic-eleven"
  | #"stylistic-twelve"
  | #"stylistic-thirteen"
  | #"stylistic-fourteen"
  | #"stylistic-fifteen"
  | #"stylistic-sixteen"
  | #"stylistic-seventeen"
  | #"stylistic-eighteen"
  | #"stylistic-nineteen"
  | #"stylistic-twenty"
]

type textAlign = [#auto | #left | #right | #center | #justify | #start | #end]

type textAlignVertical = [#auto | #top | #bottom | #center]

type textDecorationLine = [
  | #none
  | #underline
  | #"line-through"
  | #"underline line-through"
]

type textDecorationStyle = [#solid | #double | #dotted | #dashed | #wavy]

type textTransform = [#none | #uppercase | #lowercase | #capitalize]

type writingDirection = [#auto | #ltr | #rtl]

type backfaceVisibility = [#visible | #hidden]

type borderStyle = [#solid | #dotted | #dashed]

type display = [#none | #flex | #contents]

type boxSizing = [#"border-box" | #"content-box"]

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
  columnGap?: size,
  direction?: direction,
  display?: display,
  boxSizing?: boxSizing,
  end?: size,
  flex?: float,
  flexBasis?: margin,
  flexDirection?: flexDirection,
  flexGrow?: float,
  flexShrink?: float,
  flexWrap?: flexWrap,
  gap?: size,
  height?: size,
  justifyContent?: justifyContent,
  inset?: size,
  insetBlock?: size,
  insetBlockEnd?: size,
  insetBlockStart?: size,
  insetInline?: size,
  insetInlineEnd?: size,
  insetInlineStart?: size,
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
  rowGap?: size,
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
  transformOrigin?: transformOrigin,
}

// View styles https://reactnative.dev/docs/view-style-props
type viewCoreStyle = {
  // iOS 17+: `#pointer` enables hover effects
  cursor?: [#auto | #pointer],
  pointerEvents?: [#auto | #none | #"box-none" | #"box-only"],
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
  backgroundImage?: backgroundImage,
  backgroundPosition?: backgroundPosition,
  backgroundRepeat?: backgroundRepeat,
  backgroundSize?: backgroundSize,
  boxShadow?: array<boxShadow>,
  filter?: array<filter>,
  mixBlendMode?: blendMode,
  isolation?: isolation,
  elevation?: float,
  opacity?: float,
  outlineColor?: Color.t,
  outlineOffset?: float,
  outlineStyle?: outlineStyle,
  outlineWidth?: float,
}

// Text Style Props (https://reactnative.dev/docs/text-style-props)
type textIOSStyle = {
  fontVariant?: array<fontVariant>,
  fontVariationSettings?: fontVariationSettings,
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
  userSelect?: [#auto | #text | #none | #contain | #all],
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

let empty: t = s({})
