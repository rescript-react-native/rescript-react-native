include TextInputElement
module ChangeEvent = {
  type payload = {
    eventCount: int,
    target: int,
    text: string,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type changeEvent = ChangeEvent.t

module EditingEvent = {
  type payload = {
    text: string,
    eventCount: int,
    target: int,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type editingEvent = EditingEvent.t

module ContentSizeChangeEvent = {
  type contentSize = {
    width: float,
    height: float,
  }
  type payload = {
    target: int,
    contentSize: contentSize,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type contentSizeChangeEvent = ContentSizeChangeEvent.t

module ScrollEvent = {
  type contentOffset = {
    x: float,
    y: float,
  }

  type payload = {contentOffset: contentOffset}

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type scrollEvent = ScrollEvent.t

type selection = {
  start: int,
  @as("end")
  _end: int,
}

module SelectionChangeEvent = {
  type payload = {
    selection: selection,
    target: int,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type selectionChangeEvent = SelectionChangeEvent.t

module KeyPressEvent = {
  type payload = {
    key: string,
    target: Js.Nullable.t<int>,
    eventCount: Js.Nullable.t<int>,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type keyPressEvent = KeyPressEvent.t

type autoCapitalize = [#characters | #words | #sentences | #none]

type autoComplete = [
  | #"birthdate-day"
  | #"birthdate-full"
  | #"birthdate-month"
  | #"birthdate-year"
  | #"cc-csc"
  | #"cc-exp-day"
  | #"cc-exp-month"
  | #"cc-exp-year"
  | #"cc-exp"
  | #"cc-number"
  | #"name-family"
  | #"name-given"
  | #"name-middle-initial"
  | #"name-middle"
  | #"name-prefix"
  | #"name-suffix"
  | #"password-new"
  | #"postal-address-country"
  | #"postal-address-extended-postal-code"
  | #"postal-address-extended"
  | #"postal-address-locality"
  | #"postal-address-region"
  | #"postal-address"
  | #"postal-code"
  | #"sms-otp"
  | #"street-address"
  | #"tel-country-code"
  | #"tel-device"
  | #"tel-national"
  | #"username-new"
  | #email
  | #gender
  | #name
  | #off
  | #password
  | #tel
  | #username
]

type t

type importantForAutofill = [
  | #auto
  | #no
  | #noExcludeDescendants
  | #yes
  | #yesExcludeDescendants
]

type keyboardAppearance = [#default | #light | #dark]

type textBreakStrategy = [#balanced | #highQuality | #simple]

type textContentType = [
  | #none
  | #URL
  | #addressCity
  | #addressCityAndState
  | #addressState
  | #countryName
  | #creditCardNumber
  | #emailAddress
  | #familyName
  | #fullStreetAddress
  | #givenName
  | #jobTitle
  | #location
  | #middleName
  | #name
  | #namePrefix
  | #nameSuffix
  | #nickname
  | #organizationName
  | #postalCode
  | #streetAddressLine1
  | #streetAddressLine2
  | #sublocality
  | #telephoneNumber
  | #username
  | #password
  | #newPassword
  | #oneTimeCode
]

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // TextInput props
  ~allowFontScaling: bool=?,
  ~autoCapitalize: autoCapitalize=?,
  ~autoComplete: autoComplete=?,
  ~autoCorrect: bool=?,
  ~autoFocus: bool=?,
  ~blurOnSubmit: bool=?,
  ~caretHidden: bool=?,
  ~clearButtonMode: @string
  [
    | #never
    | @as("while-editing") #whileEditing
    | @as("unless-editing") #unlessEditing
    | #always
  ]=?,
  ~clearTextOnFocus: bool=?,
  ~contextMenuHidden: bool=?,
  ~defaultValue: string=?,
  ~disableFullscreenUI: bool=?,
  ~editable: bool=?,
  ~enablesReturnKeyAutomatically: bool=?,
  ~importantForAutofill: importantForAutofill=?,
  ~inlineImageLeft: string=?,
  ~inlineImagePadding: float=?,
  ~inputAccessoryViewID: string=?,
  ~keyboardAppearance: keyboardAppearance=?,
  ~keyboardType: @string
  [
    | #default
    | @as("number-pad") #numberPad
    | @as("decimal-pad") #decimalPad
    | #numeric
    | @as("email-address") #emailAddress
    | @as("phone-pad") #phonePad
    | @as("ascii-capable") #asciiCapable
    | @as("numbers-and-punctuation") #numbersAndPunctuation
    | #url
    | @as("name-phone-pad") #namePhonePad
    | #twitter
    | @as("web-search") #webSearch
    | @as("visible-password") #visiblePassword
  ]=?,
  ~maxFontSizeMultiplier: float=?,
  ~maxLength: int=?,
  ~multiline: bool=?,
  ~numberOfLines: int=?,
  ~onBlur: Event.targetEvent => unit=?,
  ~onChange: changeEvent => unit=?,
  ~onChangeText: string => unit=?,
  ~onContentSizeChange: contentSizeChangeEvent => unit=?,
  ~onEndEditing: editingEvent => unit=?,
  ~onFocus: Event.targetEvent => unit=?,
  ~onKeyPress: keyPressEvent => unit=?,
  ~onPressIn: Event.pressEvent => bool=?,
  ~onPressOut: Event.pressEvent => bool=?,
  ~onScroll: scrollEvent => unit=?,
  ~onSelectionChange: selectionChangeEvent => unit=?,
  ~onSubmitEditing: editingEvent => unit=?,
  ~placeholder: string=?,
  ~placeholderTextColor: Color.t=?,
  ~returnKeyLabel: string=?,
  ~returnKeyType: @string
  [
    | @as("done") #done_
    | #go
    | #next
    | #search
    | #send
    | #none
    | #previous
    | #default
    | @as("emergency-call") #emergencyCall
    | #google
    | #join
    | #route
    | #yahoo
  ]=?,
  ~rejectResponderTermination: bool=?,
  ~scrollEnabled: bool=?,
  ~secureTextEntry: bool=?,
  ~selection: selection=?,
  ~selectionColor: Color.t=?,
  ~selectTextOnFocus: bool=?,
  ~showSoftInputOnFocus: bool=?,
  ~spellCheck: bool=?,
  ~textBreakStrategy: textBreakStrategy=?,
  ~textContentType: textContentType=?,
  ~underlineColorAndroid: Color.t=?,
  ~value: string=?,
  // rescript-react-native 0.64 || 0.65 || 0.66 View props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
  ~accessibilityElementsHidden: bool=?,
  ~accessibilityHint: string=?,
  ~accessibilityIgnoresInvertColors: bool=?,
  ~accessibilityLabel: string=?,
  ~accessibilityLiveRegion: Accessibility.liveRegion=?,
  ~accessibilityRole: Accessibility.role=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessibilityValue: Accessibility.value=?,
  ~accessibilityViewIsModal: bool=?,
  ~accessible: bool=?,
  ~collapsable: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~importantForAccessibility: @string
  [
    | #auto
    | #yes
    | #no
    | @as("no-hide-descendants") #noHideDescendants
  ]=?,
  ~nativeID: string=?,
  ~needsOffscreenAlphaCompositing: bool=?,
  ~onAccessibilityAction: Accessibility.actionEvent => unit=?,
  ~onAccessibilityEscape: unit => unit=?,
  ~onAccessibilityTap: unit => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onMagicTap: unit => unit=?,
  // Gesture Responder props
  ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
  ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
  ~onResponderEnd: Event.pressEvent => unit=?,
  ~onResponderGrant: Event.pressEvent => unit=?,
  ~onResponderMove: Event.pressEvent => unit=?,
  ~onResponderReject: Event.pressEvent => unit=?,
  ~onResponderRelease: Event.pressEvent => unit=?,
  ~onResponderStart: Event.pressEvent => unit=?,
  ~onResponderTerminate: Event.pressEvent => unit=?,
  ~onResponderTerminationRequest: Event.pressEvent => bool=?,
  ~onStartShouldSetResponder: Event.pressEvent => bool=?,
  ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
  ~pointerEvents: @string
  [
    | #auto
    | #none
    | @as("box-none") #boxNone
    | @as("box-only") #boxOnly
  ]=?,
  ~removeClippedSubviews: bool=?,
  ~renderToHardwareTextureAndroid: bool=?,
  ~shouldRasterizeIOS: bool=?,
  ~style: Style.t=?,
  ~testID: string=?,
  ~children: React.element=?,
  // react-native-web 0.16 View props
  ~href: string=?,
  ~hrefAttrs: Web.hrefAttrs=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseMove: ReactEvent.Mouse.t => unit=?,
  ~onMouseOver: ReactEvent.Mouse.t => unit=?,
  ~onMouseOut: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
) => React.element = "TextInput"
