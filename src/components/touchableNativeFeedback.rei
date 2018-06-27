type t;
let selectableBackground: unit => t;
let selectableBackgroundBorderless: unit => t;
let canUseNativeForeground: unit => t;
let ripple: (string, bool) => t;
let make:
  (
    ~accessible: string=?,
    ~accessibilityLabel: [
                           | `button
                           | `none
                           | `radiobutton_checked
                           | `radiobutton_unchecked
                         ]
                           =?,
    ~accessibilityComponentType: list(
                                   [
                                     | `adjustable
                                     | `allowsDirectInteraction
                                     | `button
                                     | `disabled
                                     | `frequentUpdates
                                     | `header
                                     | `image
                                     | `key
                                     | `link
                                     | `none
                                     | `pageTurn
                                     | `plays
                                     | `search
                                     | `selected
                                     | `startsMedia
                                     | `summary
                                     | `text
                                   ],
                                 )
                                   =?,
    ~accessibilityTraits: int=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: Rebolt.Types.insets=?,
    ~onLayout: Rebolt.RNEvent.NativeLayoutEvent.t => unit=?,
    ~onLongPress: unit => unit=?,
    ~onPress: unit => unit=?,
    ~onPressIn: unit => unit=?,
    ~onPressOut: unit => unit=?,
    ~pressRetentionOffset: Rebolt.Types.insets=?,
    ~background: t=?,
    ~useForeground: bool=?,
    ~style: Rebolt.Style.t=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );
