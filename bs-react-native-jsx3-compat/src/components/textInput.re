[@bs.send] external isFocused: ReasonReact.reactRef => bool = "";

[@bs.send] external clear: ReasonReact.reactRef => unit = "";

[@bs.send] external focus: ReasonReact.reactRef => unit = "";

[@bs.send] external blur: ReasonReact.reactRef => unit = "";

type editingEvent = ReactNative.TextInput.editingEvent;

[@react.component]
let make =
    (
      ~accessibilityLabel: option(string)=?,
      ~accessible: option(bool)=?,
      ~hitSlop: option(Types.insets)=?,
      ~onAccessibilityTap: option(unit => unit)=?,
      ~onLayout: option(RNEvent.NativeLayoutEvent.t => unit)=?,
      ~onMagicTap: option(unit => unit)=?,
      ~responderHandlers: option(Types.touchResponderHandlers)=?,
      ~pointerEvents: option(Types.pointerEvents)=?,
      ~removeClippedSubviews: option(bool)=?,
      ~style: option(Style.t)=?,
      ~testID: option(string)=?,
      ~accessibilityComponentType: option(Types.accessibilityComponentType)=?,
      ~accessibilityLiveRegion: option(Types.accessibilityLiveRegion)=?,
      ~collapsable: option(bool)=?,
      ~importantForAccessibility: option(Types.importantForAccessibility)=?,
      ~needsOffscreenAlphaCompositing: option(bool)=?,
      ~renderToHardwareTextureAndroid: option(bool)=?,
      ~accessibilityTraits: option(list(Types.accessibilityTrait))=?,
      ~accessibilityRole: option(Types.accessibilityRole)=?,
      ~accessibilityStates: option(list(Types.accessibilityState))=?,
      ~accessibilityHint: option(string)=?,
      ~accessibilityIgnoresInvertColors: option(bool)=?,
      ~accessibilityViewIsModal: option(bool)=?,
      ~shouldRasterizeIOS: option(bool)=?,
      ~autoCapitalize: option([ | `characters | `none | `sentences | `words])=?,
      ~autoComplete:
         option(
           [
             | `off
             | `username
             | `password
             | `email
             | `name
             | `tel
             | `streetAddress
             | `postalCode
             | `ccNumber
             | `ccCsc
             | `ccExp
             | `ccExpMonth
             | `ccExpYear
           ],
         )=?,
      ~autoCorrect: option(bool)=?,
      ~autoFocus: option(bool)=?,
      ~blurOnSubmit: option(bool)=?,
      ~caretHidden: option(bool)=?,
      ~defaultValue: option(string)=?,
      ~editable: option(bool)=?,
      ~keyboardType:
         option(
           [
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
             | `visiblePassword
             | `webSearch
           ],
         )=?,
      ~maxLength: option(int)=?,
      ~multiline: option(bool)=?,
      ~onBlur: option(unit => unit)=?,
      ~onChangeText: option(string => unit)=?,
      ~onChange: option(editingEvent => unit)=?,
      ~onEndEditing: option(editingEvent => unit)=?,
      ~onSubmitEditing: option(editingEvent => unit)=?,
      ~onContentSizeChange:
         option(ReactNative.TextInput.contentSizeChangeEvent => unit)=?,
      ~onFocus: option(unit => unit)=?,
      ~onScroll: option(ReactNative.TextInput.scrollEvent => unit)=?,
      ~onSelectionChange:
         option(ReactNative.TextInput.selectionChangeEvent => unit)=?,
      ~placeholder: option(string)=?,
      ~placeholderTextColor: option(ReactNative.Color.t)=?,
      ~returnKeyType:
         option(
           [
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
           ],
         )=?,
      ~secureTextEntry: option(bool)=?,
      ~selectTextOnFocus: option(bool)=?,
      ~selection: option(ReactNative.TextInput.selection)=?,
      ~selectionColor: option(ReactNative.Color.t)=?,
      ~value: option(string)=?,
      ~disableFullscreenUI: option(bool)=?,
      ~inlineImageLeft: option(string)=?,
      ~inlineImagePadding: option(int)=?,
      ~numberOfLines: option(int)=?,
      ~returnKeyLabel: option(string)=?,
      ~textBreakStrategy: option([ | `balanced | `highQuality | `simple])=?,
      ~underlineColorAndroid: option(ReactNative.Color.t)=?,
      ~clearButtonMode:
         option([ | `always | `never | `unlessEditing | `whileEditing])=?,
      ~clearTextOnFocus: option(bool)=?,
      ~dataDetectorTypes:
         option(
           array([ | `all | `calendarEvent | `link | `none | `phoneNumber]),
         )=?,
      ~enablesReturnKeyAutomatically: option(bool)=?,
      ~keyboardAppearance: option([ | `dark | `default | `light])=?,
      ~onKeyPress: option(ReactNative.TextInput.keyPressEvent => unit)=?,
      ~selectionState: option('documentSelectionState)=?,
      ~spellCheck: option(bool)=?,
      ~inputAccessoryViewID: option(string)=?,
      _,
    ) =>
  <ReactNative.TextInput
    ?autoCapitalize
    ?autoComplete
    ?autoCorrect
    ?autoFocus
    ?blurOnSubmit
    ?caretHidden
    ?defaultValue
    ?editable
    ?keyboardType
    ?maxLength
    ?multiline
    onBlur=?{onBlur->Belt.Option.map((cb, _) => cb())}
    ?onChangeText
    ?onChange
    ?onEndEditing
    ?onSubmitEditing
    ?onContentSizeChange
    onFocus=?{onFocus->Belt.Option.map((cb, _) => cb())}
    ?onScroll
    ?onSelectionChange
    ?placeholder
    ?placeholderTextColor
    ?returnKeyType
    ?secureTextEntry
    ?selectTextOnFocus
    ?selection
    ?selectionColor
    ?value
    ?disableFullscreenUI
    ?inlineImageLeft
    inlineImagePadding=?{inlineImagePadding->Belt.Option.map(float_of_int)}
    ?numberOfLines
    ?returnKeyLabel
    ?textBreakStrategy
    ?underlineColorAndroid
    ?clearButtonMode
    ?clearTextOnFocus
    dataDetectorTypes=?{
      dataDetectorTypes->Belt.Option.map(a =>
        a->Belt.Array.map(
          fun
          | `phoneNumber => ReactNative.TextInput_DataDetectorTypes.phoneNumber
          | `link => ReactNative.TextInput_DataDetectorTypes.link
          | `calendarEvent => ReactNative.TextInput_DataDetectorTypes.calendarEvent
          | `none => ReactNative.TextInput_DataDetectorTypes.none
          | `all => ReactNative.TextInput_DataDetectorTypes.all,
        )
      )
    }
    ?enablesReturnKeyAutomatically
    ?keyboardAppearance
    ?onKeyPress
    ?selectionState
    ?spellCheck
    ?inputAccessoryViewID
    ?accessibilityLabel
    ?accessible
    ?hitSlop
    ?onAccessibilityTap
    ?onLayout
    ?onMagicTap
    onMoveShouldSetResponder=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onMoveShouldSetResponder->Belt.Option.map((g, x) => g(x))
        )
      )
    onMoveShouldSetResponderCapture=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onMoveShouldSetResponderCapture
          ->Belt.Option.map((g, x) => g(x))
        )
      )
    onResponderGrant=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderGrant
        )
      )
    onResponderMove=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderMove
        )
      )
    onResponderReject=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderReject
        )
      )
    onResponderRelease=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderRelease
        )
      )
    onResponderTerminate=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderTerminate
        )
      )
    onResponderTerminationRequest=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderTerminationRequest
        )
      )
    onStartShouldSetResponder=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onStartShouldSetResponder->Belt.Option.map((g, x) => g(x))
        )
      )
    onStartShouldSetResponderCapture=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onStartShouldSetResponderCapture
          ->Belt.Option.map((g, x) => g(x))
        )
      )
    ?pointerEvents
    ?removeClippedSubviews
    ?style
    ?testID
    ?accessibilityComponentType
    ?accessibilityLiveRegion
    ?collapsable
    ?importantForAccessibility
    ?needsOffscreenAlphaCompositing
    ?renderToHardwareTextureAndroid
    accessibilityTraits=?{
      accessibilityTraits->Belt.Option.map(Belt.List.toArray)
    }
    ?accessibilityRole
    accessibilityStates=?{
      accessibilityStates->Belt.Option.map(Belt.List.toArray)
    }
    ?accessibilityHint
    ?accessibilityIgnoresInvertColors
    ?accessibilityViewIsModal
    ?shouldRasterizeIOS
  />;
