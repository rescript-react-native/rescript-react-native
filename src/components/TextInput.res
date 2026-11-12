include TextInputElement

type selection = {
  start: int,
  end: int,
}

module ChangeEvent = {
  type payload = {
    eventCount: int,
    target: int,
    text: string,
    // This is usually only used as a callback param and not created by the user.
    // Therefore prefer option<...> to an optional field for easier matching.
    selection: option<selection>,
  }

  include Event.SyntheticEvent({type _payload = payload})
}

type changeEvent = ChangeEvent.t

module EditingEvent = {
  type payload = {
    text: string,
    eventCount: int,
    target: int,
  }

  include Event.SyntheticEvent({type _payload = payload})
}

type editingEvent = EditingEvent.t

module ContentSizeChangeEvent = {
  type payload = {
    target: int,
    contentSize: Layout.size,
  }

  include Event.SyntheticEvent({type _payload = payload})
}

type contentSizeChangeEvent = ContentSizeChangeEvent.t

module ScrollEvent = {
  type payload = {contentOffset: Layout.point}

  include Event.SyntheticEvent({type _payload = payload})
}

type scrollEvent = ScrollEvent.t

module SelectionChangeEvent = {
  type payload = {
    selection: selection,
    target: int,
  }

  include Event.SyntheticEvent({type _payload = payload})
}

type selectionChangeEvent = SelectionChangeEvent.t

module KeyPressEvent = {
  type payload = {
    key: string,
    target: nullable<int>,
    eventCount: nullable<int>,
  }

  include Event.SyntheticEvent({type _payload = payload})
}

type keyPressEvent = KeyPressEvent.t

type autoCapitalize = [#characters | #words | #sentences | #none]

type autoComplete = [
  | #"2fa-app-otp"
  | #"additional-name"
  | #"address-line1"
  | #"address-line2"
  | #"birthdate-day"
  | #"birthdate-full"
  | #"birthdate-month"
  | #"birthdate-year"
  | #"cc-csc"
  | #"cc-exp"
  | #"cc-exp-day"
  | #"cc-exp-month"
  | #"cc-exp-year"
  | #"cc-family-name"
  | #"cc-given-name"
  | #"cc-middle-name"
  | #"cc-name"
  | #"cc-number"
  | #"cc-type"
  | #country
  | #"current-password"
  | #email
  | #"email-otp"
  | #"family-name"
  | #"flight-confirmation-code"
  | #"flight-number"
  | #gender
  | #"gift-card-number"
  | #"gift-card-pin"
  | #"given-name"
  | #"honorific-prefix"
  | #"honorific-suffix"
  | #"loyalty-account-number"
  | #name
  | #"name-family"
  | #"name-given"
  | #"name-middle"
  | #"name-middle-initial"
  | #"name-prefix"
  | #"name-suffix"
  | #"new-password"
  | #nickname
  | #off
  | #"one-time-code"
  | #organization
  | #"organization-title"
  | #password
  | #"password-new"
  | #"postal-address"
  | #"postal-address-country"
  | #"postal-address-dependent-locality"
  | #"postal-address-extended"
  | #"postal-address-extended-postal-code"
  | #"postal-address-locality"
  | #"postal-address-region"
  | #"postal-address-unit"
  | #"postal-code"
  | #"promo-code"
  | #"sms-otp"
  | #"street-address"
  | #tel
  | #"tel-country-code"
  | #"tel-device"
  | #"tel-national"
  | #"upi-vpa"
  | #url
  | #username
  | #"username-new"
  | #"wifi-password"
]

type t

type clearButtonMode = [
  | #never
  | #"while-editing"
  | #"unless-editing"
  | #always
]

type importantForAutofill = [
  | #auto
  | #no
  | #noExcludeDescendants
  | #yes
  | #yesExcludeDescendants
]

type keyboardAppearance = [#default | #light | #dark]

type keyboardType = [
  | #default
  | #"number-pad"
  | #"decimal-pad"
  | #numeric
  | #"email-address"
  | #"phone-pad"
  | #"ascii-capable"
  | #"numbers-and-punctuation"
  | #url
  | #"name-phone-pad"
  | #twitter
  | #"web-search"
  | #"visible-password"
]

type returnKeyType = [
  | #done
  | #go
  | #next
  | #search
  | #send
  | #none
  | #previous
  | #default
  | #"emergency-call"
  | #google
  | #join
  | #route
  | #yahoo
]

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
  | #creditCardExpiration
  | #birthdate
  | #cellularIMEI
]

type inputMode = [
  | #none
  | #text
  | #decimal
  | #numeric
  | #tel
  | #search
  | #email
  | #url
]

type enterKeyHint = [
  | #enter
  | #done
  | #next
  | #search
  | #send
  | #previous
]

type submitBehavior = [
  | #submit
  | #blurAndSubmit
  | #newline
]

type lineBreakModeIOS = [
  | #wordWrapping
  | #char
  | #clip
  | #head
  | #middle
  | #tail
]

type dataDetectorType = [
  | #phoneNumber
  | #link
  | #address
  | #calendarEvent
  | #trackingNumber
  | #flightNumber
  | #lookupSuggestion
  | #none
  | #all
]

type props = {
  ref?: ref,
  ...View.gestureResponderHandlersProps,
  ...View.accessibilityProps,
  ...View.iosProps,
  ...View.androidProps,
  ...View.webLinkProps,
  ...View.webClickProps,
  // don't use View.webFocusProps because TextInput
  // already has a react-native onFocus and onBlur
  ...View.webKeyboardProps,
  ...View.webMouseForwardedProps,
  ...View.coreProps,
  //
  allowFontScaling?: bool,
  autoCapitalize?: autoCapitalize,
  autoComplete?: autoComplete,
  autoCorrect?: bool,
  autoFocus?: bool,
  @deprecated("Use `submitBehavior` instead.") blurOnSubmit?: bool,
  submitBehavior?: submitBehavior,
  caretHidden?: bool,
  clearButtonMode?: clearButtonMode,
  clearTextOnFocus?: bool,
  contextMenuHidden?: bool,
  defaultValue?: string,
  disableKeyboardShortcuts?: bool,
  cursorColor?: Color.t,
  disableFullscreenUI?: bool,
  dataDetectorTypes?: array<dataDetectorType>,
  editable?: bool,
  enablesReturnKeyAutomatically?: bool,
  // `enterKeyHint` has precedence over the `returnKeyType`
  enterKeyHint?: enterKeyHint,
  importantForAutofill?: importantForAutofill,
  inlineImageLeft?: string,
  inlineImagePadding?: float,
  inputAccessoryViewButtonLabel?: string,
  inputAccessoryViewID?: string,
  // `inputMode` has precedence over `keyboardType`
  inputMode?: inputMode,
  keyboardAppearance?: keyboardAppearance,
  keyboardType?: keyboardType,
  lineBreakStrategyIOS?: Text.lineBreakStrategyIOS,
  lineBreakModeIOS?: lineBreakModeIOS,
  maxFontSizeMultiplier?: float,
  maxLength?: int,
  multiline?: bool,
  numberOfLines?: int,
  // `rows` has precedence over `numberOfLines`
  rows?: int,
  onBlur?: Event.targetEvent => unit,
  onChange?: changeEvent => unit,
  onChangeText?: string => unit,
  onContentSizeChange?: contentSizeChangeEvent => unit,
  onEndEditing?: editingEvent => unit,
  onFocus?: Event.targetEvent => unit,
  onKeyPress?: keyPressEvent => unit,
  onPressIn?: Event.pressEvent => unit,
  onPressOut?: Event.pressEvent => unit,
  onScroll?: scrollEvent => unit,
  onSelectionChange?: selectionChangeEvent => unit,
  onSubmitEditing?: editingEvent => unit,
  placeholder?: string,
  placeholderTextColor?: Color.t,
  // `readOnly` has precedence over `editable`
  readOnly?: bool,
  returnKeyLabel?: string,
  returnKeyType?: returnKeyType,
  rejectResponderTermination?: bool,
  scrollEnabled?: bool,
  secureTextEntry?: bool,
  selection?: selection,
  selectionColor?: Color.t,
  selectionHandleColor?: Color.t,
  selectTextOnFocus?: bool,
  showSoftInputOnFocus?: bool,
  smartInsertDelete?: bool,
  spellCheck?: bool,
  textAlign?: [#left | #center | #right | #start | #end],
  textAlignVertical?: Style.textAlignVertical,
  textBreakStrategy?: Text.textBreakStrategy,
  textContentType?: textContentType,
  passwordRules?: string,
  underlineColorAndroid?: Color.t,
  value?: string,
}

@module("react-native")
external make: React.component<props> = "TextInput"
