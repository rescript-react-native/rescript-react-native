let isFocused: ReasonReact.reactRef => bool;

let clear: ReasonReact.reactRef => unit;

let focus: ReasonReact.reactRef => unit;

let blur: ReasonReact.reactRef => unit;

module AutoCapitalize: {
  type t = [
    | `none
    | `sentences
    | `words
    | `characters
  ];
  let to_string: t => string
};

module ReturnKeyType: {
  type t = [
    | `done_
    | `go
    | `next
    | `search
    | `send
    | `none
    | `previous
    | `default
    | `emergencyCall
    | `google
    | `join
    | `route
    | `yahoo
  ];
  let to_string: t =>  string;
}

module KeyboardType: {
  type t = [
    | `default
    | `emailAddress
    | `numeric
    | `phonePad
    | `asciiCapable
    | `numbersAndPunctuation
    | `url
    | `numberPad
    | `namePhonePad
    | `decimalPad
    | `twitter
    | `webSearch
  ];
  let to_string: t => string;
}

module TextBreakStrategy: {
  type t = [
    | `simple
    | `highQuality
    | `balanced
  ]

  let to_string: t => string;
}

module ClearButtonMode: {
  type t = [
    | `never
    | `whileEditing
    | `unlessEditing
    | `always
  ]

  let to_string: t => string;
}

module KeyboardAppearance: {
  type t = [
    | `default
    | `light
    | `dark
  ]

  let to_string: t => string;
}

let make:
  (
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: {
                .
                "left": int,
                "right": int,
                "top": int,
                "bottom": int,
              }
                =?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(
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
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~autoCapitalize: AutoCapitalize.t=?,
    ~autoCorrect: bool=?,
    ~autoFocus: bool=?,
    ~blurOnSubmit: bool=?,
    ~caretHidden: bool=?,
    ~defaultValue: string=?,
    ~editable: bool=?,
    ~keyboardType: KeyboardType.t =?,
    ~maxLength: int=?,
    ~multiline: bool=?,
    ~onBlur: unit => unit=?,
    ~onChange: unit => unit=?,
    ~onChangeText: string => unit=?,
    ~onContentSizeChange: {
                            .
                            "nativeEvent": {
                              .
                              "contentSize": {
                                .
                                "width": float,
                                "height": float,
                              },
                            },
                          } =>
                          unit
                            =?,
    ~onEndEditing: unit => unit=?,
    ~onFocus: unit => unit=?,
    ~onScroll: {
                 .
                 "nativeEvent": {
                   .
                   "contentOffset": {
                     .
                     "x": float,
                     "y": float,
                   },
                 },
               } =>
               unit
                 =?,
    ~onSelectionChange: {
                          .
                          "nativeEvent": {
                            .
                            "selection": {
                              .
                              "start": int,
                              "_end": int,
                            },
                          },
                        } =>
                        unit
                          =?,
    ~onSubmitEditing: unit => unit=?,
    ~placeholder: string=?,
    ~placeholderTextColor: string=?,
    ~returnKeyType: ReturnKeyType.t=?,
    ~secureTextEntry: bool=?,
    ~selectTextOnFocus: bool=?,
    ~selection: {
                  .
                  "start": int,
                  "_end": int,
                }
                  =?,
    ~selectionColor: string=?,
    ~value: string=?,
    ~disableFullscreenUI: bool=?,
    ~inlineImageLeft: string=?,
    ~inlineImagePadding: int=?,
    ~numberOfLines: int=?,
    ~returnKeyLabel: string=?,
    ~textBreakStrategy: TextBreakStrategy.t=?,
    ~underlineColorAndroid: string=?,
    ~clearButtonMode: ClearButtonMode.t=?,
    ~clearTextOnFocus: bool=?,
    ~dataDetectorTypes: array(
                          [
                            | `all
                            | `calendarEvent
                            | `link
                            | `none
                            | `phoneNumber
                          ],
                        )
                          =?,
    ~enablesReturnKeyAutomatically: bool=?,
    ~keyboardAppearance: KeyboardAppearance.t=?,
    ~onKeyPress: {. "nativeEvent": {. "key": string}} => unit=?,
    ~selectionState: 'documentSelectionState=?,
    ~spellCheck: bool=?,
    ~inputAccessoryViewID: string=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
