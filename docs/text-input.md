---
title: TextInput
---

## Props

### accessibilityLabel

```reason
accessibilityLabel: ReasonReact.reactElement=?
```

### accessible

```reason
accessible: bool=?
```

### hitSlop

```reason
hitSlop: {
  .
  "left": int,
  "right": int,
  "top": int,
  "bottom": int
}=?
```

### onAccessibilityTap

```reason
onAccessibilityTap: unit => unit=?
```

### onLayout

```reason
onLayout: RNEvent.NativeLayoutEvent.t => unit=?
```

_reference:_

```reason
module NativeLayoutEvent: {
  type t;
  type layout = {
    x: float,
    y: float,
    width: float,
    height: float
  };
  let layout: t => layout;
};
```

### onMagicTap

```reason
onMagicTap: unit => unit=?
```

### responderHandlers

```reason
responderHandlers: Types.touchResponderHandlers=?
```

_reference:_

**Types.rei**

```reason
type touchResponderHandlers = {
  onMoveShouldSetResponder: option(RNEvent.NativeEvent.t => bool),
  onMoveShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool),
  onResponderGrant: option(RNEvent.NativeEvent.t => unit),
  onResponderMove: option(RNEvent.NativeEvent.t => unit),
  onResponderReject: option(RNEvent.NativeEvent.t => unit),
  onResponderRelease: option(RNEvent.NativeEvent.t => unit),
  onResponderTerminate: option(RNEvent.NativeEvent.t => unit),
  onResponderTerminationRequest: option(RNEvent.NativeEvent.t => unit),
  onStartShouldSetResponder: option(RNEvent.NativeEvent.t => bool),
  onStartShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool)
};
```

**RNEvent.rei**

```reason
module NativeEvent: {
  type t;
  let changedTouches: t => array(Js.t({..}));
  let identifier: t => int;
  let locationX: t => float;
  let locationY: t => float;
  let pageX: t => float;
  let pageY: t => float;
  let target: t => Js.t({..});
  let touches: t => array(Js.t({..}));
  let timestamp: t => int;
  let data: t => string;
};
```

### pointerEvents

```reason
pointerEvents: [
  | `auto
  | `none
  | `boxNone
  | `boxOnly
]=?
```

### removeClippedSubviews

```reason
removeClippedSubviews: bool=?
```

### style

```reason
style: Style.t=?
```

### testID

```reason
testID: string=?
```

### accessibilityComponentType

```reason
accessibilityComponentType: [
  | `none
  | `button
  | `radiobutton_checked
  | `radiobutton_unchecked
]=?
```

### accessibilityLiveRegion

```reason
accessibilityLiveRegion: [
  | `none
  | `polite
  | `assertive
]=?
```

### collapsable

```reason
collapsable: bool=?
```

### importantForAccessibility

```reason
importantForAccessibility: [
  | `auto
  | `yes
  | `no
  | `noHideDescendants
]=?
```

### needsOffscreenAlphaCompositing

```reason
needsOffscreenAlphaCompositing: bool=?
```

### renderToHardwareTextureAndroid

```reason
renderToHardwareTextureAndroid: bool=?
```

### accessibilityTraits

```reason
accessibilityTraits: list(
  [
    | `none
    | `button
    | `link
    | `header
    | `search
    | `image
    | `selected
    | `plays
    | `key
    | `text
    | `summary
    | `disabled
    | `frequentUpdates
    | `startsMedia
    | `adjustable
    | `allowsDirectInteraction
    | `pageTurn
  ]
)=?
```

### accessibilityViewIsModal

```reason
accessibilityViewIsModal: bool=?
```

### shouldRasterizeIOS

```reason
shouldRasterizeIOS: bool=?
```

### autoCapitalize

```reason
autoCapitalize: [<
  | `characters
  | `none
  | `sentences
  | `words
]=?
```

### autoCorrect

```reason
autoCorrect: bool=?
```

### autoFocus

```reason
autoFocus: bool=?
```

### blurOnSubmit

```reason
blurOnSubmit: bool=?
```

### caretHidden

```reason
caretHidden: bool=?
```

### defaultValue

```reason
defaultValue: string=?
```

### editable

```reason
editable: bool=?
```

### keyboardType

```reason
keyboardType: [
  | `asciiCapable
  | `decimalPad
  | `default
  | `emailAddress
  | `namePhonePad
  | `numberPad
  | `numbersAndPunctuation
  | `numeric
  | `phonePad
  | `twitter
  | `url
  | `webSearch
]=?
```

### maxLength

```reason
maxLength: int=?
```

### multiline

```reason
multiline: bool=?
```

### onBlur

```reason
onBlur: unit => unit=?
```

### onChange

```reason
onChange: unit => unit=?
```

### onChangeText

```reason
onChangeText: string => unit=?
```

### onContentSizeChange

```reason
onContentSizeChange: {
  .
  "nativeEvent": {
    .
    "contentSize": {
      .
      "width": float,
      "height": float
    }
  }
} => unit=?
```

### onEndEditing

```reason
onEndEditing: unit => unit=?
```

### onFocus

```reason
onFocus: unit => unit=?
```

### onScroll

```reason
onScroll: {
  .
  "nativeEvent": {
    .
    "contentOffset": {
      .
      "x": float,
      "y": float
    }
  }
} => unit=?
```

### onSelectionChange

```reason
onSelectionChange: {
  .
  "nativeEvent": {
    .
    "selection": {
      .
      "start": int,
      "_end": int
    }
  }
} => unit=?
```

### onSubmitEditing

```reason
onSubmitEditing: unit => unit=?
```

### placeholder

```reason
placeholder: string=?
```

### placeholderTextColor

```reason
placeholderTextColor: string=?
```

### returnKeyType

```reason
returnKeyType: [
  | `default
  | `done_
  | `emergencyCall
  | `go
  | `google
  | `join
  | `next
  | `none
  | `previous
  | `route
  | `search
  | `send
  | `yahoo
]=?
```

### secureTextEntry

```reason
secureTextEntry: bool=?
```

### selectTextOnFocus

```reason
selectTextOnFocus: bool=?
```

### selection

```reason
selection: {
  .
  "start": int,
  "_end": int
}=?
```

### selectionColor

```reason
selectionColor: string=?
```

### value

```reason
value: string=?
```

### disableFullscreenUI

```reason
disableFullscreenUI: bool=?
```

### inlineImageLeft

```reason
inlineImageLeft: string=?
```

### inlineImagePadding

```reason
inlineImagePadding: int=?
```

### numberOfLines

```reason
numberOfLines: int=?
```

### returnKeyLabel

```reason
returnKeyLabel: string=?
```

### textBreakStrategy

```reason
textBreakStrategy: [
  | `balanced
  | `highQuality
  | `simple
]=?
```

### underlineColorAndroid

```reason
underlineColorAndroid: string=?
```

### clearButtonMode

```reason
clearButtonMode: [
  | `always
  | `never
  | `unlessEditing
  | `whileEditing
]=?
```

### clearTextOnFocus

```reason
clearTextOnFocus: bool=?
```

### dataDetectorTypes

```reason
dataDetectorTypes: array([
  | `all
  | `calendarEvent
  | `link
  | `none
  | `phoneNumber
])=?
```

### enablesReturnKeyAutomatically

```reason
enablesReturnKeyAutomatically: bool=?
```

### keyboardAppearance

```reason
keyboardAppearance: [
  | `dark
  | `default
  | `light
]=?
```

### onKeyPress

```reason
onKeyPress: {
  .
  "nativeEvent": {
    .
    "key": string
  }
} => unit=?
```

### selectionState

```reason
selectionState: 'documentSelectionState=?
```

### spellCheck

```reason
spellCheck: bool=?
```
