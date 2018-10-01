[@bs.module "react-native"]
external view: ReasonReact.reactClass = "TextInput";

[@bs.send] external isFocused: ReasonReact.reactRef => bool = "";

[@bs.send] external clear: ReasonReact.reactRef => unit = "";

[@bs.send] external focus: ReasonReact.reactRef => unit = "";

[@bs.send] external blur: ReasonReact.reactRef => unit = "";

let make =
    (
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~style=?,
      ~testID=?,
      ~accessibilityComponentType=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityTraits=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
      ~autoCapitalize=?,
      ~autoCorrect=?,
      ~autoFocus=?,
      ~blurOnSubmit=?,
      ~caretHidden=?,
      ~defaultValue=?,
      ~editable=?,
      ~keyboardType=?,
      ~maxLength=?,
      ~multiline=?,
      ~onBlur=?,
      ~onChange=?,
      ~onChangeText=?,
      ~onContentSizeChange=?,
      ~onEndEditing=?,
      ~onFocus=?,
      ~onScroll=?,
      ~onSelectionChange=?,
      ~onSubmitEditing=?,
      ~placeholder=?,
      ~placeholderTextColor=?,
      ~returnKeyType=?,
      ~secureTextEntry=?,
      ~selectTextOnFocus=?,
      ~selection=?,
      ~selectionColor=?,
      ~value=?,
      ~disableFullscreenUI=?,
      ~inlineImageLeft=?,
      ~inlineImagePadding=?,
      ~numberOfLines=?,
      ~returnKeyLabel=?,
      ~textBreakStrategy=?,
      ~underlineColorAndroid=?,
      ~clearButtonMode=?,
      ~clearTextOnFocus=?,
      ~dataDetectorTypes=?,
      ~enablesReturnKeyAutomatically=?,
      ~keyboardAppearance=?,
      ~onKeyPress=?,
      ~selectionState=?,
      ~spellCheck=?,
      ~inputAccessoryViewID=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        {
          "autoCapitalize":
            UtilsRN.option_map(
              x =>
                switch (x) {
                | `none => "none"
                | `sentences => "sentences"
                | `words => "words"
                | `characters => "characters"
                },
              autoCapitalize,
            ),
          "autoCorrect": autoCorrect,
          "autoFocus": autoFocus,
          "blurOnSubmit": blurOnSubmit,
          "caretHidden": caretHidden,
          "defaultValue": defaultValue,
          "editable": editable,
          "keyboardType":
            UtilsRN.option_map(
              x =>
                switch (x) {
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
                },
              keyboardType,
            ),
          "maxLength": maxLength,
          "multiline": multiline,
          "onBlur": onBlur,
          "onChange": onChange,
          "onChangeText": onChangeText,
          "onContentSizeChange": onContentSizeChange,
          "onEndEditing": onEndEditing,
          "onFocus": onFocus,
          "onScroll": onScroll,
          "onSelectionChange": onSelectionChange,
          "onSubmitEditing": onSubmitEditing,
          "placeholder": placeholder,
          "placeholderTextColor": placeholderTextColor,
          "returnKeyType":
            UtilsRN.option_map(
              x =>
                switch (x) {
                | `done_ => "done"
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
                },
              returnKeyType,
            ),
          "secureTextEntry": secureTextEntry,
          "selectTextOnFocus": selectTextOnFocus,
          "selection": selection,
          "selectionColor": selectionColor,
          "value": value,
          "disableFullscreenUI": disableFullscreenUI,
          /* TODO */
          "inlineImageLeft": inlineImageLeft,
          "inlineImagePadding": inlineImagePadding,
          "numberOfLines": numberOfLines,
          "returnKeyLabel": returnKeyLabel,
          "textBreakStrategy":
            UtilsRN.option_map(
              x =>
                switch (x) {
                | `simple => "simple"
                | `highQuality => "highQuality"
                | `balanced => "balanced"
                },
              textBreakStrategy,
            ),
          "underlineColorAndroid": underlineColorAndroid,
          "clearButtonMode":
            UtilsRN.option_map(
              x =>
                switch (x) {
                | `never => "never"
                | `whileEditing => "while-editing"
                | `unlessEditing => "unless-editing"
                | `always => "always"
                },
              clearButtonMode,
            ),
          "clearTextOnFocus": clearTextOnFocus,
          "dataDetectorTypes":
            UtilsRN.option_map(
              Array.map(x =>
                switch (x) {
                | `phoneNumber => "phoneNumber"
                | `link => "link"
                | `calendarEvent => "calendarEvent"
                | `none => "none"
                | `all => "all"
                }
              ),
              dataDetectorTypes,
            ),
          "enablesReturnKeyAutomatically": enablesReturnKeyAutomatically,
          "keyboardAppearance":
            UtilsRN.option_map(
              x =>
                switch (x) {
                | `default => "never"
                | `light => "light"
                | `dark => "dark"
                },
              keyboardAppearance,
            ),
          "onKeyPress": onKeyPress,
          "selectionState": selectionState,
          "spellCheck": spellCheck,
          "inputAccessoryViewID": inputAccessoryViewID,
        },
        ~accessibilityLabel?,
        ~accessible?,
        ~hitSlop?,
        ~onAccessibilityTap?,
        ~onLayout?,
        ~onMagicTap?,
        ~responderHandlers?,
        ~pointerEvents?,
        ~removeClippedSubviews?,
        ~style?,
        ~testID?,
        ~accessibilityComponentType?,
        ~accessibilityLiveRegion?,
        ~collapsable?,
        ~importantForAccessibility?,
        ~needsOffscreenAlphaCompositing?,
        ~renderToHardwareTextureAndroid?,
        ~accessibilityTraits?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );