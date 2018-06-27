---
title: WebView
---

## Props

### source

```reason
source: source=?
```

_reference:_

```reason
let sourceUri:
  (
    ~uri: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    unit
  ) =>
  source;

[@deprecated "Please use WebView.sourceUri instead"]
let source:
  (
    ~uri: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    unit
  ) =>
  source;
```

### style

```reason
style: Style.t=?
```

### renderError

```reason
renderError: unit => ReasonReact.reactElement=?
```

### renderLoading

```reason
renderLoading: unit => ReasonReact.reactElement=?
```

### onError

```reason
onError: {
  .
  "url": option(string),
  "title": option(string),
  "loading": option(bool),
  "canGoBack": option(bool),
  "canGoForward": option(bool)
} => unit=?
```

### onLoad

```reason
onLoad: {
  .
  "url": option(string),
  "title": option(string),
  "loading": option(bool),
  "canGoBack": option(bool),
  "canGoForward": option(bool)
} => unit=?
```

### onLoadEnd

```reason
onLoadEnd: {
  .
  "url": option(string),
  "title": option(string),
  "loading": option(bool),
  "canGoBack": option(bool),
  "canGoForward": option(bool)
} => unit=?
```

### onLoadStart

```reason
onLoadStart: {
  .
  "url": option(string),
  "title": option(string),
  "loading": option(bool),
  "canGoBack": option(bool),
  "canGoForward": option(bool)
} => unit=?
```

### automaticallyAdjustContentInsets

```reason
automaticallyAdjustContentInsets: bool=?
```

### contentInsets

```reason
contentInsets: contentInsets=?
```

_reference:_

```reason
let contentInsets:
  (
    ~top: int=?,
    ~left: int=?,
    ~bottom: int=?,
    ~right: int=?,
    unit
  ) =>
  contentInsets;
```

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
hitSlop: Types.insets=?
```

_reference:_

**Types.rei**

```reason
type insets = {
  .
  "left": int,
  "right": int,
  "top": int,
  "bottom": int,
};
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

**RNEvent.rei**

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

### injectJavaScript

```reason
injectJavaScript: string => unit=?
```

### injectedJavaScript

```reason
injectedJavaScript: string=?
```

### mediaPlaybackRequiresUserAction

```reason
mediaPlaybackRequiresUserAction: bool=?
```

### onMessage

```reason
onMessage: RNEvent.NativeEvent.t => unit=?
```

_reference:_

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

### onNavigationStateChange

```reason
onNavigationStateChange: {
  .
  "url": option(string),
  "title": option(string),
  "loading": option(bool),
  "canGoBack": option(bool),
  "canGoForward": option(bool)
} => unit=?
```

### scalesPageToFit

```reason
scalesPageToFit: bool=?
```

### startInLoadingState

```reason
startInLoadingState: bool=?
```

### domStorageEnabled

```reason
domStorageEnabled: bool=?
```

### javaScriptEnabled

```reason
javaScriptEnabled: bool=?
```

### mixedContentMode

```reason
mixedContentMode: list([
  | `never
  | `always
  | `compatibility
])=?
```

### thirdPartyCookiesEnabled

```reason
thirdPartyCookiesEnabled: bool=?
```

### userAgent

```reason
userAgent: string=?
```

### allowsInlineMediaPlayback

```reason
allowsInlineMediaPlayback: bool=?
```

### bounces

```reason
bounces: bool=?
```

### dataDetectorTypes

```reason
dataDetectorTypes: list([
  | `phoneNumber
  | `link
  | `address
  | `calendarEvent
  | `none
  | `all
])=?
```

### decelerationRate

```reason
decelerationRate: list([
  | `normal
  | `fast
  | `value(float)
])=?
```

### onShouldStartLoadWithRequest

```reason
onShouldStartLoadWithRequest: iOSLoadRequestEvent => bool=?
```

_reference:_

```reason
type iOSLoadRequestEvent = {
  .
  "target": int,
  "canGoBack": bool,
  "lockIdentifier": int,
  "loading": bool,
  "title": string,
  "canGoForward": bool,
  "navigationType": string,
  "url": string
};
```

### scrollEnabled

```reason
scrollEnabled: bool=?
```
