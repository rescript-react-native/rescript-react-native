type t<+'a> = Style.typed_t<'a>

type flexStyle = [
  | #alignContent
  | #alignItems
  | #alignSelf
  | #aspectRatio
  | #borderBottomWidth
  | #borderEndWidth
  | #borderLeftWidth
  | #borderRightWidth
  | #borderStartWidth
  | #borderTopWidth
  | #borderWidth
  | #bottom
  | #display
  | #_end
  | #flex
  | #flexBasis
  | #flexDirection
  | #flexGrow
  | #flexShrink
  | #flexWrap
  | #height
  | #justifyContent
  | #left
  | #margin
  | #marginBottom
  | #marginEnd
  | #marginHorizontal
  | #marginLeft
  | #marginRight
  | #marginStart
  | #marginTop
  | #marginVertical
  | #maxHeight
  | #maxWidth
  | #minHeight
  | #minWidth
  | #overflow
  | #padding
  | #paddingBottom
  | #paddingEnd
  | #paddingHorizontal
  | #paddingLeft
  | #paddingRight
  | #paddingStart
  | #paddingTop
  | #paddingVertical
  | #position
  | #right
  | #start
  | #top
  | #width
  | #zIndex
  | #direction
]

type transformsStyle = [
  | #transform
  | #transformMatrix
  | #rotation
  | #scaleX
  | #scaleY
  | #translateX
  | #translateY
]

type shadowStyleIOS = [#shadowColor | #shadowOffset | #shadowOpacity | #shadowRadius]

type viewStyle = [
  | flexStyle
  | shadowStyleIOS
  | transformsStyle
  | #backfaceVisibility
  | #backgroundColor
  | #borderBottomColor
  | #borderBottomEndRadius
  | #borderBottomLeftRadius
  | #borderBottomRightRadius
  | #borderBottomStartRadius
  | #borderBottomWidth
  | #borderColor
  | #borderEndColor
  | #borderLeftColor
  | #borderLeftWidth
  | #borderRadius
  | #borderRightColor
  | #borderRightWidth
  | #borderStartColor
  | #borderStyle
  | #borderTopColor
  | #borderTopEndRadius
  | #borderTopLeftRadius
  | #borderTopRightRadius
  | #borderTopStartRadius
  | #borderTopWidth
  | #borderWidth
  | #opacity
  | #testID
  | #elevation
]

type textStyleIOS = [
  | viewStyle
  | #fontVariant
  | #letterSpacing
  | #textDecorationColor
  | #textDecorationStyle
  | #writingDirection
]

type textStyleAndroid = [viewStyle | #textAlignVertical | #includeFontPadding]

type textStyle = [
  | textStyleIOS
  | textStyleAndroid
  | viewStyle
  | #color
  | #fontFamily
  | #fontSize
  | #fontStyle
  | #fontWeight
  | #letterSpacing
  | #lineHeight
  | #textAlign
  | #textDecorationLine
  | #textDecorationStyle
  | #textDecorationColor
  | #textShadowColor
  | #textShadowOffset
  | #textShadowRadius
  | #textTransform
  | #testID
]

type imageStyle = [
  | flexStyle
  | shadowStyleIOS
  | transformsStyle
  | #resizeMode
  | #backfaceVisibility
  | #borderBottomLeftRadius
  | #borderBottomRightRadius
  | #backgroundColor
  | #borderColor
  | #borderWidth
  | #borderRadius
  | #borderTopLeftRadius
  | #borderTopRightRadius
  | #overflow
  | #overlayColor
  | #tintColor
  | #opacity
]

external ofArray: array<t<'a>> => t<'a> = "%identity"

let compose = (a, b) => ofArray([a, b])

module Infix = TypedStyleInfix

external flexStyle: t<[< flexStyle]> => Style.t = "%identity"

external transformsStyle: t<[< transformsStyle]> => Style.t = "%identity"

external shadowStyleIOS: t<[< shadowStyleIOS]> => Style.t = "%identity"

external viewStyle: t<[< viewStyle]> => Style.t = "%identity"

external textStyleIOS: t<[< textStyleIOS]> => Style.t = "%identity"

external textStyleAndroid: t<[< textStyleAndroid]> => Style.t = "%identity"

external textStyle: t<[< textStyle]> => Style.t = "%identity"

external imageStyle: t<[< imageStyle]> => Style.t = "%identity"
