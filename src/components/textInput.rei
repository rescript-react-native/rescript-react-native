let isFocused: ReasonReact.reactRef => bool;

let clear: ReasonReact.reactRef => unit;

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
    ~autoCapitalize: [< | `characters | `none | `sentences | `words]=?,
    ~autoCorrect: bool=?,
    ~autoFocus: bool=?,
    ~blurOnSubmit: bool=?,
    ~caretHidden: bool=?,
    ~defaultValue: string=?,
    ~editable: bool=?,
    ~keyboardType: [
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
                   ]
                     =?,
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
                          }
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
               }
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
                        }
                          =?,
    ~onSubmitEditing: unit => unit=?,
    ~placeholder: string=?,
    ~placeholderTextColor: string=?,
    ~returnKeyType: [
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
                    ]
                      =?,
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
    ~textBreakStrategy: [ | `balanced | `highQuality | `simple]=?,
    ~underlineColorAndroid: string=?,
    ~clearButtonMode: [ | `always | `never | `unlessEditing | `whileEditing]=?,
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
    ~keyboardAppearance: [ | `dark | `default | `light]=?,
    ~onKeyPress: {. "nativeEvent": {. "key": string}}=?,
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