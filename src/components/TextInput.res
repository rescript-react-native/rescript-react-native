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
  end: int,
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
  | #"one-time-code"
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
  blurOnSubmit?: bool,
  caretHidden?: bool,
  clearButtonMode?: clearButtonMode,
  clearTextOnFocus?: bool,
  contextMenuHidden?: bool,
  defaultValue?: string,
  disableFullscreenUI?: bool,
  dataDetectorTypes?: array<Text.dataDetectorType>,
  editable?: bool,
  enablesReturnKeyAutomatically?: bool,
  // `enterKeyHint` has precedence over the `returnKeyType`
  enterKeyHint?: enterKeyHint,
  importantForAutofill?: importantForAutofill,
  inlineImageLeft?: string,
  inlineImagePadding?: float,
  inputAccessoryViewID?: string,
  // `inputMode` has precedence over `keyboardType`
  inputMode?: inputMode,
  keyboardAppearance?: keyboardAppearance,
  keyboardType?: keyboardType,
  lineBreakStrategyIOS?: Text.lineBreakStrategyIOS,
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
  onPressIn?: Event.pressEvent => bool,
  onPressOut?: Event.pressEvent => bool,
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
  selectTextOnFocus?: bool,
  showSoftInputOnFocus?: bool,
  spellCheck?: bool,
  textAlign?: [#left | #center | #right],
  textAlignVertical?: Style.textAlignVertical,
  textBreakStrategy?: Text.textBreakStrategy,
  textContentType?: textContentType,
  underlineColorAndroid?: Color.t,
  value?: string,
}

@module("react-native")
external make: React.component<props> = "TextInput"
