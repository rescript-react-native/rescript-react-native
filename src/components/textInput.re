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
      ~autoComplete=?,
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
            autoCapitalize
            ->Belt.Option.map(
                fun
                | `none => "none"
                | `sentences => "sentences"
                | `words => "words"
                | `characters => "characters",
              ),
          "autoComplete":
            autoComplete
            ->Belt.Option.map(
                fun
                | `off => "off"
                | `username => "username"
                | `password => "password"
                | `email => "email"
                | `name => "name"
                | `tel => "tel"
                | `streetAddress => "street-address"
                | `postalCode => "postal-code"
                | `ccNumber => "cc-number"
                | `ccCsc => "cc-csc"
                | `ccExp => "cc-exp"
                | `ccExpMonth => "cc-exp-month"
                | `ccExpYear => "cc-exp-year",
              ),
          "autoCorrect": autoCorrect,
          "autoFocus": autoFocus,
          "blurOnSubmit": blurOnSubmit,
          "caretHidden": caretHidden,
          "defaultValue": defaultValue,
          "editable": editable,
          "keyboardType":
            keyboardType
            ->Belt.Option.map(
                fun
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
                | `webSearch => "web-search",
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
            returnKeyType
            ->Belt.Option.map(
                fun
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
                | `yahoo => "yahoo",
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
            textBreakStrategy
            ->Belt.Option.map(
                fun
                | `simple => "simple"
                | `highQuality => "highQuality"
                | `balanced => "balanced",
              ),
          "underlineColorAndroid": underlineColorAndroid,
          "clearButtonMode":
            clearButtonMode
            ->Belt.Option.map(
                fun
                | `never => "never"
                | `whileEditing => "while-editing"
                | `unlessEditing => "unless-editing"
                | `always => "always",
              ),
          "clearTextOnFocus": clearTextOnFocus,
          "dataDetectorTypes":
            dataDetectorTypes
            ->Belt.Option.map(
                Array.map(
                  fun
                  | `phoneNumber => "phoneNumber"
                  | `link => "link"
                  | `calendarEvent => "calendarEvent"
                  | `none => "none"
                  | `all => "all",
                ),
              ),
          "enablesReturnKeyAutomatically": enablesReturnKeyAutomatically,
          "keyboardAppearance":
            keyboardAppearance
            ->Belt.Option.map(
                fun
                | `default => "never"
                | `light => "light"
                | `dark => "dark",
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
