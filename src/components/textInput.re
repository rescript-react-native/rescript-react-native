[@bs.module "react-native"]
external view : ReasonReact.reactClass = "TextInput";

[@bs.send] external isFocused : ReasonReact.reactRef => bool = "";

[@bs.send] external clear : ReasonReact.reactRef => unit = "";

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
        Js.Undefined.(
          {
            "autoCapitalize":
              fromOption(
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
              ),
            "autoCorrect":
              fromOption(UtilsRN.optBoolToOptJsBoolean(autoCorrect)),
            "autoFocus":
              fromOption(UtilsRN.optBoolToOptJsBoolean(autoFocus)),
            "blurOnSubmit":
              fromOption(UtilsRN.optBoolToOptJsBoolean(blurOnSubmit)),
            "caretHidden":
              fromOption(UtilsRN.optBoolToOptJsBoolean(caretHidden)),
            "defaultValue": fromOption(defaultValue),
            "editable": fromOption(UtilsRN.optBoolToOptJsBoolean(editable)),
            "keyboardType":
              fromOption(
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
              ),
            "maxLength": fromOption(maxLength),
            "multiline":
              fromOption(UtilsRN.optBoolToOptJsBoolean(multiline)),
            "onBlur": fromOption(onBlur),
            "onChange": fromOption(onChange),
            "onChangeText": fromOption(onChangeText),
            "onContentSizeChange": fromOption(onContentSizeChange),
            "onEndEditing": fromOption(onEndEditing),
            "onFocus": fromOption(onFocus),
            "onScroll": fromOption(onScroll),
            "onSelectionChange": fromOption(onSelectionChange),
            "onSubmitEditing": fromOption(onSubmitEditing),
            "placeholder": fromOption(placeholder),
            "placeholderTextColor": fromOption(placeholderTextColor),
            "returnKeyType":
              fromOption(
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
              ),
            "secureTextEntry":
              fromOption(UtilsRN.optBoolToOptJsBoolean(secureTextEntry)),
            "selectTextOnFocus":
              fromOption(UtilsRN.optBoolToOptJsBoolean(selectTextOnFocus)),
            "selection": fromOption(selection),
            "selectionColor": fromOption(selectionColor),
            "value": fromOption(value),
            "disableFullscreenUI":
              fromOption(UtilsRN.optBoolToOptJsBoolean(disableFullscreenUI)),
            /* TODO */
            "inlineImageLeft": fromOption(inlineImageLeft),
            "inlineImagePadding": fromOption(inlineImagePadding),
            "numberOfLines": fromOption(numberOfLines),
            "returnKeyLabel": fromOption(returnKeyLabel),
            "textBreakStrategy":
              fromOption(
                UtilsRN.option_map(
                  x =>
                    switch (x) {
                    | `simple => "simple"
                    | `highQuality => "highQuality"
                    | `balanced => "balanced"
                    },
                  textBreakStrategy,
                ),
              ),
            "underlineColorAndroid": fromOption(underlineColorAndroid),
            "clearButtonMode":
              fromOption(
                UtilsRN.option_map(
                  x =>
                    switch (x) {
                    | `never => "never"
                    | `whileEditing => "whileEditing"
                    | `unlessEditing => "unless-editing"
                    | `always => "always"
                    },
                  clearButtonMode,
                ),
              ),
            "clearTextOnFocus":
              fromOption(UtilsRN.optBoolToOptJsBoolean(clearTextOnFocus)),
            "dataDetectorTypes":
              fromOption(
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
              ),
            "enablesReturnKeyAutomatically":
              fromOption(
                UtilsRN.optBoolToOptJsBoolean(enablesReturnKeyAutomatically),
              ),
            "keyboardAppearance":
              fromOption(
                UtilsRN.option_map(
                  x =>
                    switch (x) {
                    | `default => "never"
                    | `light => "light"
                    | `dark => "dark"
                    },
                  keyboardAppearance,
                ),
              ),
            "onKeyPress": fromOption(onKeyPress),
            "selectionState": fromOption(selectionState),
            "spellCheck":
              fromOption(UtilsRN.optBoolToOptJsBoolean(spellCheck)),
            "inputAccessoryViewID": fromOption(inputAccessoryViewID),
          }
        ),
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