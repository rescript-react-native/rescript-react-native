open Utils;

external view : ReactRe.reactClass = "TextInput" [@@bs.module "react-native"];

external _isFocused: ReactRe.reactRef => Js.boolean = "" [@@bs.send];
let isFocused = Js.to_bool << _isFocused;

external clear: ReactRe.reactRef => unit = "" [@@bs.send];

let createElement
    ::accessibleLeft=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::onMoveShouldSetResponder=?
    ::onMoveShouldSetResponderCapture=?
    ::onResponderGrant=?
    ::onResponderMove=?
    ::onResponderReject=?
    ::onResponderRelease=?
    ::onResponderTerminate=?
    ::onResponderTerminationRequest=?
    ::onStartShouldSetResponder=?
    ::onStartShouldSetResponderCapture=?
    ::pointerEvents=?
    ::removeClippedSubviews=?
    ::style=?
    ::testID=?
    ::accessibilityComponentType=?
    ::accessibilityLiveRegion=?
    ::collapsable=?
    ::importantForAccessibility=?
    ::needsOffscreenAlphaCompositing=?
    ::renderToHardwareTextureAndroid=?
    ::accessibilityTraits=?
    ::accessibilityViewIsModal=?
    ::shouldRasterizeIOS=?
    ::autoCapitalize=?
    ::autoCorrect=?
    ::autoFocus=?
    ::blurOnSubmit=?
    ::caretHidden=?
    ::defaultValue=?
    ::editable=?
    ::keyboardType=?
    ::maxLength=?
    ::multiline=?
    ::onBlur=?
    ::onChange=?
    ::onChangeText=?
    ::onContentSizeChange=?
    ::onEndEditing=?
    ::onFocus=?
    ::onScroll=?
    ::onSelectionChange=?
    ::onSubmitEditing=?
    ::placeholder=?
    ::placeholderTextColor=?
    ::returnKeyType=?
    ::secureTextEntry=?
    ::selectTextOnFocus=?
    ::selection=?
    ::selectionColor=?
    ::value=?
    ::disableFullscreenUI=?
    ::inlineImageLeft=?
    ::inlineImagePadding=?
    ::numberOfLines=?
    ::returnKeyLabel=?
    ::textBreakStrategy=?
    ::underlineColorAndroid=?
    ::clearButtonMode=?
    ::clearTextOnFocus=?
    ::dataDetectorTypes=?
    ::enablesReturnKeyAutomatically=?
    ::keyboardAppearance=?
    ::onKeyPress=?
    ::selectionState=?
    ::spellCheck=? =>
  ReactRe.wrapPropsShamelessly
    view
    {
      "accessibleLeft": from_opt accessibleLeft,
      "accessible": from_opt (option_map to_js_boolean accessible),
      "hitSlop": from_opt hitSlop,
      "onAccessibilityTap": from_opt onAccessibilityTap,
      "onLayout": from_opt onLayout,
      "onMagicTap": from_opt onMagicTap,
      "onMoveShouldSetResponder":
        from_opt (option_map ((<<) to_js_boolean) onMoveShouldSetResponder),
      "onMoveShouldSetResponderCapture":
        from_opt (option_map ((<<) to_js_boolean) onMoveShouldSetResponderCapture),
      "onResponderGrant": from_opt onResponderGrant,
      "onResponderMove": from_opt onResponderMove,
      "onResponderReject": from_opt onResponderReject,
      "onResponderRelease": from_opt onResponderRelease,
      "onResponderTerminate": from_opt onResponderTerminate,
      "onResponderTerminationRequest": from_opt onResponderTerminationRequest,
      "onStartShouldSetResponder":
        from_opt (option_map ((<<) to_js_boolean) onStartShouldSetResponder),
      "onStartShouldSetResponderCapture":
        from_opt (option_map ((<<) to_js_boolean) onStartShouldSetResponderCapture),
      "removeClippedSubviews": from_opt (option_map to_js_boolean removeClippedSubviews),
      "pointerEvents":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `auto => "auto"
                | `none => "none"
                | `boxNone => "box-none"
                | `boxOnly => "box-only"
                }
            )
            pointerEvents
        ),
      "style": from_opt style,
      "testID": from_opt testID,
      "accessibilityComponentType":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `none => "none"
                | `button => "button"
                | `radiobutton_checked => "radiobutton_checked-none"
                | `radiobutton_unchecked => "radiobutton_unchecked"
                }
            )
            accessibilityComponentType
        ),
      "accessibilityLiveRegion":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `polite => "polite"
                | `none => "none"
                | `assertive => "assertive"
                }
            )
            accessibilityLiveRegion
        ),
      "collapsable": from_opt (option_map to_js_boolean collapsable),
      "importantForAccessibility":
        from_opt (
          option_map
            (
              fun prop =>
                switch prop {
                | `auto => "auto"
                | `yes => "yes"
                | `no => "no"
                | `noHideDescendants => "noHideDescendants"
                }
            )
            importantForAccessibility
        ),
      "needsOffscreenAlphaCompositing":
        from_opt (option_map to_js_boolean needsOffscreenAlphaCompositing),
      "renderToHardwareTextureAndroid":
        from_opt (option_map to_js_boolean renderToHardwareTextureAndroid),
      "accessibilityTraits":
        from_opt (
          option_map
            (
              fun traits => {
                let to_string =
                  fun
                  | `none => "none"
                  | `button => "button"
                  | `link => "link"
                  | `header => "header"
                  | `search => "search"
                  | `image => "image"
                  | `selected => "selected"
                  | `plays => "plays"
                  | `key => "key"
                  | `text => "text"
                  | `summary => "summary"
                  | `disabled => "disabled"
                  | `frequentUpdates => "frequentUpdates"
                  | `startsMedia => "startsMedia"
                  | `adjustable => "adjustable"
                  | `allowsDirectInteraction => "allowsDirectInteraction"
                  | `pageTurn => "pageTurn";
                traits |> List.map to_string |> Array.of_list
              }
            )
            accessibilityTraits
        ),
      "accessibilityViewIsModal": from_opt (option_map to_js_boolean accessibilityViewIsModal),
      "shouldRasterizeIOS": from_opt (option_map to_js_boolean shouldRasterizeIOS),
      "autoCapitalize":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `none => "none"
                | `sentences => "sentences"
                | `words => "words"
                | `characters => "characters"
                }
            )
            autoCapitalize
        ),
      "autoCorrect": from_opt (option_map to_js_boolean autoCorrect),
      "autoFocus": from_opt (option_map to_js_boolean autoFocus),
      "blurOnSubmit": from_opt (option_map to_js_boolean blurOnSubmit),
      "caretHidden": from_opt (option_map to_js_boolean caretHidden),
      "defaultValue": from_opt defaultValue,
      "editable": from_opt (option_map to_js_boolean editable),
      "keyboardType":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `default => "default"
                | `emailAddress => "email-address"
                | `numeric => "numeric"
                | `phonePad => "phone-pad"
                | `asciiCapable => "ascii-capable"
                | `numbersAndPunctuation => "numbers-and-punctuation"
                | `url => "url"
                | `numberPad => "number-pad"
                | `namePhonePad => "name-phone-pad"
                | `decimalPad => "decimal-pad"
                | `twitter => "twitter"
                | `webSearch => "web-search"
                }
            )
            keyboardType
        ),
      "maxLength": from_opt maxLength,
      "multiline": from_opt (option_map to_js_boolean multiline),
      "onBlur": from_opt onBlur,
      "onChange": from_opt onChange,
      "onChangeText": from_opt onChangeText,
      "onContentSizeChange": from_opt onContentSizeChange,
      "onEndEditing": from_opt onEndEditing,
      "onFocus": from_opt onFocus,
      "onScroll": from_opt onScroll,
      "onSelectionChange": from_opt onSelectionChange,
      "onSubmitEditing": from_opt onSubmitEditing,
      "placeholder": from_opt placeholder,
      "placeholderTextColor": from_opt placeholderTextColor,
      "returnKeyType":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `done_ => "done_"
                | `go => "go"
                | `next => "next"
                | `search => "search"
                | `send => "send"
                | `none => "none"
                | `previous => "previous"
                | `default => "default"
                | `emergencyCall => "emergencyCall"
                | `google => "google"
                | `join => "join"
                | `route => "route"
                | `yahoo => "yahoo"
                }
            )
            returnKeyType
        ),
      "secureTextEntry": from_opt (option_map to_js_boolean secureTextEntry),
      "selectTextOnFocus": from_opt (option_map to_js_boolean selectTextOnFocus),
      "selection": from_opt selection,
      "selectionColor": from_opt selectionColor,
      "value": from_opt value,
      "disableFullscreenUI": from_opt (option_map to_js_boolean disableFullscreenUI),
      /* TODO */
      "inlineImageLeft": from_opt inlineImageLeft,
      "inlineImagePadding": from_opt inlineImagePadding,
      "numberOfLines": from_opt numberOfLines,
      "returnKeyLabel": from_opt returnKeyLabel,
      "textBreakStrategy":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `simple => "simple"
                | `highQuality => "highQuality"
                | `balanced => "balanced"
                }
            )
            textBreakStrategy
        ),
      "underlineColorAndroid": from_opt underlineColorAndroid,
      "clearButtonMode":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `never => "never"
                | `whileEditing => "whileEditing"
                | `unlessEditing => "unless-editing"
                | `always => "always"
                }
            )
            clearButtonMode
        ),
      "clearTextOnFocus": from_opt (option_map to_js_boolean clearTextOnFocus),
      "dataDetectorTypes":
        from_opt (
          option_map
            (
              Array.map (
                fun x =>
                  switch x {
                  | `phoneNumber => "phoneNumber"
                  | `link => "link"
                  | `calendarEvent => "calendarEvent"
                  | `none => "none"
                  | `all => "all"
                  }
              )
            )
            dataDetectorTypes
        ),
      "enablesReturnKeyAutomatically":
        from_opt (option_map to_js_boolean enablesReturnKeyAutomatically),
      "keyboardAppearance":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `default => "never"
                | `light => "light"
                | `dark => "dark"
                }
            )
            keyboardAppearance
        ),
      "onKeyPress": from_opt onKeyPress,
      "selectionState": from_opt selectionState,
      "spellCheck": from_opt (option_map to_js_boolean spellCheck)
    };