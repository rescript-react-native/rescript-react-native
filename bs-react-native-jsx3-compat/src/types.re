type insets = {
  .
  "left": int,
  "right": int,
  "top": int,
  "bottom": int,
};

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
  onStartShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool),
};

[@bs.deriving {jsConverter: newType}]
type pointerEvents = [
  | `auto
  | `none
  | [@bs.as "box-none"] `boxNone
  | [@bs.as "box-only"] `boxOnly
];

/* deprecated : Please use accessibilityRole and accessibilityState instead */
[@bs.deriving {jsConverter: newType}]
type accessibilityComponentType = [
  | `none
  | `button
  | `radiobutton_checked
  | `radiobutton_unchecked
];

/* deprecated : Please use accessibilityRole and accessibilityState instead */
[@bs.deriving {jsConverter: newType}]
type accessibilityTrait = [
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
];

[@bs.deriving {jsConverter: newType}]
type accessibilityLiveRegion = [ | `none | `polite | `assertive];

[@bs.deriving {jsConverter: newType}]
type importantForAccessibility = [
  | `auto
  | `yes
  | `no
  | [@bs.as "no-hide-descendants"] `noHideDescendants
];

[@bs.deriving {jsConverter: newType}]
type accessibilityRole = [
  | `none
  | `button
  | `link
  | `search
  | `image
  | `keyboardkey
  | `text
  | `adjustable
  | `header
  | `summary
  | `imagebutton
];

[@bs.deriving {jsConverter: newType}]
type accessibilityState = [ | `selected | `disabled];
