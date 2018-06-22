let make:
  (
    ~accessible: string=?,
    ~accessibilityLabel: [
                           | `none
                           | `button
                           | `radiobutton_checked
                           | `radiobutton_unchecked
                         ]
                           =?,
    ~accessibilityComponentType: list(
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
                                   ],
                                 )
                                   =?,
    ~accessibilityTraits: int=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: Types.insets=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onLongPress: unit => unit=?,
    ~onPress: unit => unit=?,
    ~onPressIn: unit => unit=?,
    ~onPressOut: unit => unit=?,
    ~pressRetentionOffset: Types.insets=?,
    ~background: string=?,
    ~useForeground: bool=?,
    ~style: Style.t=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );