type event('a) = {. "nativeEvent": 'a};

type editingEvent =
  event({
    .
    "text": string,
    "eventCount": int,
    "target": int,
  });

type contentSizeChangeEvent =
  event({
    .
    "contentSize": {
      .
      "width": float,
      "height": float,
    },
  });

type focusEvent = event({. "target": int});

type scrollEvent =
  event({
    .
    "contentOffset": {
      .
      "x": float,
      "y": float,
    },
  });

type selection = {
  .
  "start": int,
  "_end": int,
};

type selectionEvent = event(selection);

type keyPressEvent = event({. "key": string});

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~allowFontScaling: bool=?,
    ~autoCapitalize: [@bs.string] [
                       | `characters
                       | `words
                       | `sentences
                       | `none
                     ]
                       =?,
    ~autoComplete: [@bs.string] [
                     | `off
                     | `username
                     | `password
                     | `email
                     | `name
                     | `tel
                     | [@bs.as "street-address"] `streetAddress
                     | [@bs.as "postal-code"] `postalCode
                     | [@bs.as "cc-number"] `ccNumber
                     | [@bs.as "cc-csc"] `ccCsc
                     | [@bs.as "cc-exp"] `ccExp
                     | [@bs.as "cc-exp-month"] `ccExpMonth
                     | [@bs.as "cc-exp-year"] `ccExpYear
                   ]
                     =?,
    ~autoCorrect: bool=?,
    ~autoFocus: bool=?,
    ~blurOnSubmit: bool=?,
    ~caretHidden: bool=?,
    ~clearButtonMode: [@bs.string] [
                        | `never
                        | `whileEditing
                        | `unlessEditing
                        | `always
                      ]
                        =?,
    ~clearTextOnFocus: bool=?,
    ~contextMenuHidden: bool=?,
    ~dataDetectorTypes: array(
                          [
                            | `phoneNumber
                            | `link
                            | `address
                            | `calendarEvent
                            | `none
                            | `all
                          ],
                        )
                          =?,
    ~defaultValue: string=?,
    ~disableFullscreenUI: bool=?,
    ~editable: bool=?,
    ~enablesReturnKeyAutomatically: bool=?,
    ~importantForAutofill: [@bs.string] [
                             | `auto
                             | `no
                             | `noExcludeDescendants
                             | `yes
                             | `yesExcludeDescendants
                           ]
                             =?,
    ~inlineImageLeft: string=?,
    ~inlineImagePadding: float=?,
    ~inputAccessoryViewID: string=?,
    ~keyboardAppearance: [@bs.string] [ | `default | `light | `dark]=?,
    ~keyboardType: [@bs.string] [
                     | `default
                     | [@bs.as "number-pad"] `numberPad
                     | [@bs.as "decimal-pad"] `decimalPad
                     | `numeric
                     | [@bs.as "email-address"] `emailAddress
                     | [@bs.as "phone-pad"] `phonePad
                     | [@bs.as "ascii-capable"] `asciiCapable
                     | [@bs.as "numbers-and-punctuation"]
                       `numbersAndPunctuation
                     | `url
                     | [@bs.as "name-phone-pad"] `namePhonePad
                     | `twitter
                     | [@bs.as "web-search"] `webSearch
                     | [@bs.as "visible-password"] `visiblePassword
                   ]
                     =?,
    ~maxFontSizeMultiplier: float=?,
    ~maxLength: int=?,
    ~multiline: bool=?,
    ~numberOfLines: int=?,
    ~onBlur: unit => unit=?,
    ~onChange: editingEvent => unit=?,
    ~onChangeText: string => unit=?,
    ~onContentSizeChange: contentSizeChangeEvent => unit=?,
    ~onEndEditing: editingEvent => unit=?,
    ~onFocus: focusEvent => unit=?,
    ~onKeyPress: keyPressEvent => unit=?,
    ~onScroll: scrollEvent => unit=?,
    ~onSelectionChange: selectionEvent => unit=?,
    ~onSubmitEditing: editingEvent => unit=?,
    ~placeholder: string=?,
    ~placeholderTextColor: Style.color=?,
    ~returnKeyLabel: string=?,
    ~returnKeyType: [@bs.string] [
                      | [@bs.as "done"] `done_
                      | `go
                      | `next
                      | `search
                      | `send
                      | `none
                      | `previous
                      | `default
                      | [@bs.as "emergency-call"] `emergencyCall
                      | `google
                      | `join
                      | `route
                      | `yahoo
                    ]
                      =?,
    ~rejectResponderTermination: bool=?,
    ~scrollEnabled: bool=?,
    ~secureTextEntry: bool=?,
    ~selection: selection=?,
    ~selectionColor: Style.color=?,
    ~selectionState: 'documentSelectionState=?, // TODO
    ~selectTextOnFocus: bool=?,
    ~spellCheck: bool=?,
    ~textBreakStrategy: [@bs.string] [ | `balanced | `highQuality | `simple]=?,
    ~textContentType: [@bs.string] [
                        | `none
                        | `URL
                        | `addressCity
                        | `addressCityAndState
                        | `addressState
                        | `countryName
                        | `creditCardNumber
                        | `emailAddress
                        | `familyName
                        | `fullStreetAddress
                        | `givenName
                        | `jobTitle
                        | `location
                        | `middleName
                        | `name
                        | `namePrefix
                        | `nameSuffix
                        | `nickname
                        | `organizationName
                        | `postalCode
                        | `streetAddressLine1
                        | `streetAddressLine2
                        | `sublocality
                        | `telephoneNumber
                        | `username
                        | `password
                        | `newPassword
                        | `oneTimeCode
                      ]
                        =?,
    ~underlineColorAndroid: Style.color=?,
    ~value: string=?,
    // View props
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityElementsHidden: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]=?,
    ~accessibilityRole: [@bs.string] [
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
                        ]
                          =?,
    ~accessibilityStates: array(AccessibilityState.t)=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~collapsable: bool=?,
    ~hitSlop: Types.insets=?,
    ~importantForAccessibility: [@bs.string] [
                                  | `auto
                                  | `yes
                                  | `no
                                  | [@bs.as "no-hide-descendants"]
                                    `noHideDescendants
                                ]
                                  =?,
    ~nativeID: string=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.t => bool=?,
    ~onMoveShouldSetResponderCapture: Event.t => bool=?,
    ~onResponderGrant: Event.t => unit=?,
    ~onResponderMove: Event.t => unit=?,
    ~onResponderReject: Event.t => unit=?,
    ~onResponderRelease: Event.t => unit=?,
    ~onResponderTerminate: Event.t => unit=?,
    ~onResponderTerminationRequest: Event.t => unit=?,
    ~onStartShouldSetResponder: Event.t => bool=?,
    ~onStartShouldSetResponderCapture: Event.t => bool=?,
    ~pointerEvents: [@bs.string] [
                      | `auto
                      | `none
                      | [@bs.as "box-none"] `boxNone
                      | [@bs.as "box-only"] `boxOnly
                    ]
                      =?,
    ~removeClippedSubviews: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~style: Style.t=?,
    ~testID: string=?
  ) =>
  React.element =
  "TextInput";

[@bs.send] external isFocused: ReasonReact.reactRef => bool = "";

[@bs.send] external clear: ReasonReact.reactRef => unit = "";

[@bs.send] external focus: ReasonReact.reactRef => unit = "";

[@bs.send] external blur: ReasonReact.reactRef => unit = "";
