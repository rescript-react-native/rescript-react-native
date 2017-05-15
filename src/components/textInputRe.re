external view : ReactRe.reactClass = "TextInput" [@@bs.module "react-native"];

external _isFocused : ReactRe.reactRef => Js.boolean = "" [@@bs.send];

let isFocused = UtilsRN.(Js.to_bool << _isFocused);

external clear : ReactRe.reactRef => unit = "" [@@bs.send];

let createElement
    ::accessibleLeft=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::responderHandlers
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
    (
      Props.extendView
        Js.Undefined.(
          {
            "autoCapitalize":
              from_opt (
                UtilsRN.option_map
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
            "autoCorrect": from_opt (UtilsRN.optBoolToOptJsBoolean autoCorrect),
            "autoFocus": from_opt (UtilsRN.optBoolToOptJsBoolean autoFocus),
            "blurOnSubmit": from_opt (UtilsRN.optBoolToOptJsBoolean blurOnSubmit),
            "caretHidden": from_opt (UtilsRN.optBoolToOptJsBoolean caretHidden),
            "defaultValue": from_opt defaultValue,
            "editable": from_opt (UtilsRN.optBoolToOptJsBoolean editable),
            "keyboardType":
              from_opt (
                UtilsRN.option_map
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
            "multiline": from_opt (UtilsRN.optBoolToOptJsBoolean multiline),
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
                UtilsRN.option_map
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
            "secureTextEntry": from_opt (UtilsRN.optBoolToOptJsBoolean secureTextEntry),
            "selectTextOnFocus": from_opt (UtilsRN.optBoolToOptJsBoolean selectTextOnFocus),
            "selection": from_opt selection,
            "selectionColor": from_opt selectionColor,
            "value": from_opt value,
            "disableFullscreenUI": from_opt (UtilsRN.optBoolToOptJsBoolean disableFullscreenUI),
            /* TODO */
            "inlineImageLeft": from_opt inlineImageLeft,
            "inlineImagePadding": from_opt inlineImagePadding,
            "numberOfLines": from_opt numberOfLines,
            "returnKeyLabel": from_opt returnKeyLabel,
            "textBreakStrategy":
              from_opt (
                UtilsRN.option_map
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
                UtilsRN.option_map
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
            "clearTextOnFocus": from_opt (UtilsRN.optBoolToOptJsBoolean clearTextOnFocus),
            "dataDetectorTypes":
              from_opt (
                UtilsRN.option_map
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
              from_opt (UtilsRN.optBoolToOptJsBoolean enablesReturnKeyAutomatically),
            "keyboardAppearance":
              from_opt (
                UtilsRN.option_map
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
            "spellCheck": from_opt (UtilsRN.optBoolToOptJsBoolean spellCheck)
          }
        )
        ::accessibleLeft
        ::accessible
        ::hitSlop
        ::onAccessibilityTap
        ::onLayout
        ::onMagicTap
        ::pointerEvents
        ::removeClippedSubviews
        ::style
        ::testID
        ::accessibilityComponentType
        ::accessibilityLiveRegion
        ::collapsable
        ::importantForAccessibility
        ::needsOffscreenAlphaCompositing
        ::renderToHardwareTextureAndroid
        ::accessibilityTraits
        ::accessibilityViewIsModal
        ::shouldRasterizeIOS
        ::responderHandlers
    );
