include TextInputElement;

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

module DataDetectorTypes = TextInput_DataDetectorTypes;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // TextInput props
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
                        | [@bs.as "while-editing"] `whileEditing
                        | [@bs.as "unless-editing"] `unlessEditing
                        | `always
                      ]
                        =?,
    ~clearTextOnFocus: bool=?,
    ~contextMenuHidden: bool=?,
    ~dataDetectorTypes: array(DataDetectorTypes.t)=?,
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
    ~placeholderTextColor: Color.t=?,
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
    ~selectionColor: Color.t=?,
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
    ~underlineColorAndroid: Color.t=?,
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
    ~hitSlop: Types.edgeInsets=?,
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
    ~onAccessibilityEscape: unit => unit=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~onResponderGrant: Event.pressEvent => unit=?,
    ~onResponderMove: Event.pressEvent => unit=?,
    ~onResponderReject: Event.pressEvent => unit=?,
    ~onResponderRelease: Event.pressEvent => unit=?,
    ~onResponderTerminate: Event.pressEvent => unit=?,
    ~onResponderTerminationRequest: Event.pressEvent => unit=?,
    ~onStartShouldSetResponder: Event.pressEvent => bool=?,
    ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
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
