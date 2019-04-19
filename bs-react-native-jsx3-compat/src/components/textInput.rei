/**
A React component for displaying text.
You can read more on [Text] component usage in official docs: {{:https://facebook.github.io/react-native/docs/text}}

  {3 Props}

  {{:\BsReactNative/View-BsReactNative} [View] props}

  {4 autoCapitalize}
  {[
    autoCapitalize: [<
      | `characters
      | `none
      | `sentences
      | `words
    ]=?
  ]}
  {4 autoComplete}
  {[
    autoComplete: [<
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
    ]=?
  ]}
  {4 autoCorrect}
  {[
    ~autoCorrect: bool=?
  ]}
  {4 autoFocus}
  {[
    ~autoFocus: bool=?
  ]}
  {4 blurOnSubmit}
  {[
    ~blurOnSubmit: bool=?
  ]}
  {4 caretHidden}
  {[
    ~caretHidden: bool=?
  ]}
  {4 defaultValue}
  {[
    ~defaultValue: string=?
  ]}
  {4 editable}
  {[
    ~editable: bool=?
  ]}
  {4 keyboardType}
  {[
    ~keyboardType: [
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
      | `webSearch
    ]
      =?
  ]}
  {4 maxLength}
  {[
    ~maxLength: int=?
  ]}
  {4 multiline}
  {[
    ~multiline: bool=?
  ]}
  {4 onBlur}
  {[
    ~onBlur: unit => unit=?
  ]}
  {4 onChangeText}
  {[
    ~onChangeText: string => unit=?
  ]}
  {4 onChange}
  {[
    ~onChange: editingEvent => unit=?
  ]}
  {4 onEndEditing}
  {[
    ~onEndEditing: editingEvent => unit=?
  ]}
  {4 onSubmitEditing}
  {[
    ~onSubmitEditing: editingEvent => unit=?
  ]}

  {4 onContentSizeChange}
  {[
    ~onContentSizeChange: {
      .
      "nativeEvent": {
        .
        "contentSize": {
          .
          "width": float,
          "height": float
        }
      }
    } => unit=?
  ]}
  {4 onFocus}
  {[
    ~onFocus: unit => unit=?
  ]}
  {4 onScroll}
  {[
    ~onScroll: {
      .
      "nativeEvent": {
        .
        "contentOffset": {
          .
          "x": float,
          "y": float
        }
      }
    } => unit=?
  ]}
  {4 onSelectionChange}
  {[
    ~onSelectionChange: {
      .
      "nativeEvent": {
        .
        "selection": {
          .
          "start": int,
          "_end": int
        }
      }
    } => unit=?
  ]}
  {4 placeholder}
  {[
    ~placeholder: string=?
  ]}
  {4 placeholderTextColor}
  {[
    ~placeholderTextColor: string=?
  ]}
  {4 returnKeyType}
  {[
    ~returnKeyType: [
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
    ]=?
  ]}
  {4 secureTextEntry}
  {[
    ~secureTextEntry
  ]}
  {4 selectTextOnFocus}
  {[
    ~selectTextOnFocus: bool=?
  ]}
  {4 selection}
  {[
    ~selection: {
      .
      "start": int,
      "_end": int
    }=?
  ]}
  {4 selectionColor}
  {[
    ~selectionColor: string=?
  ]}
  {4 value}
  {[
    ~value: string=?
  ]}
  {4 disableFullscreenUI}
  {[
    ~disableFullscreenUI: bool=?
  ]}
  {4 inlineImageLeft}
  {[
    ~inlineImageLeft: string=?
  ]}
  {4 inlineImagePadding}
  {[
    ~inlineImagePadding: int=?
  ]}
  {4 numberOfLines}
  {[
    ~numberOfLines: int=?
  ]}
  {4 returnKeyLabel}
  {[
    ~returnKeyLabel: string=?
  ]}
  {4 textBreakStrategy}
  {[
    ~textBreakStrategy: [
      | `balanced
      | `highQuality
      | `simple
    ]=?
  ]}
  {4 underlineColorAndroid}
  {[
    ~underlineColorAndroid: string=?
  ]}
  {4 clearButtonMode}
  {[
    ~clearButtonMode: [
      | `always
      | `never
      | `unlessEditing
      | `whileEditing
    ]=?
  ]}
  {4 clearTextOnFocus}
  {[
    ~clearTextOnFocus: bool=?
  ]}
  {4 dataDetectorTypes}
  {[
    ~dataDetectorTypes: array([
      | `all
      | `calendarEvent
      | `link
      | `none
      | `phoneNumber
    ])=?
  ]}
  {4 enablesReturnKeyAutomatically}
  {[
    ~enablesReturnKeyAutomatically: bool=?
  ]}
  {4 keyboardAppearance}
  {[
    ~keyboardAppearance: [
      | `dark
      | `default
      | `light
    ]=?
  ]}
  {4 onKeyPress}
  {[
    ~onKeyPress: {
      .
      "nativeEvent": {
        .
        "key": string
      }
    } => unit=?
  ]}
  {4 selectionState}
  {[
    ~selectionState: 'documentSelectionState=?
  ]}
  {4 spellCheck}
  {[
    ~spellCheck: bool=?
  ]}
  {4 inputAccessoryViewID}
  {[
    ~inputAccessoryViewID: string=?
  ]}

{3 Methods}

{4 isFocused()}
Returns [true] if the input is currently focused; [false] otherwise.
 */

type editingEvent = {
  .
  "nativeEvent": {
    .
    "text": string,
    "eventCount": int,
    "target": int,
  },
};

let make:
  (
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: {
                .
                "left": int,
                "right": int,
                "top": int,
                "bottom": int,
              }
                =?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: Types.pointerEvents=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: Types.accessibilityComponentType=?,
    ~accessibilityLiveRegion: Types.accessibilityLiveRegion=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: Types.importantForAccessibility=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(Types.accessibilityTrait)=?,
    ~accessibilityRole: Types.accessibilityRole=?,
    ~accessibilityStates: list(Types.accessibilityState)=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~autoCapitalize: [< | `characters | `none | `sentences | `words]=?,
    ~autoComplete: [<
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
                   ]
                     =?,
    ~autoCorrect: bool=?,
    ~autoFocus: bool=?,
    ~blurOnSubmit: bool=?,
    ~caretHidden: bool=?,
    ~defaultValue: string=?,
    ~editable: bool=?,
    ~keyboardType: [
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
                     | `webSearch
                   ]
                     =?,
    ~maxLength: int=?,
    ~multiline: bool=?,
    ~onBlur: unit => unit=?,
    ~onChangeText: string => unit=?,
    ~onChange: editingEvent => unit=?,
    ~onEndEditing: editingEvent => unit=?,
    ~onSubmitEditing: editingEvent => unit=?,
    ~onContentSizeChange: {
                            .
                            "nativeEvent": {
                              .
                              "contentSize": {
                                .
                                "width": float,
                                "height": float,
                              },
                            },
                          } =>
                          unit
                            =?,
    ~onFocus: unit => unit=?,
    ~onScroll: {
                 .
                 "nativeEvent": {
                   .
                   "contentOffset": {
                     .
                     "x": float,
                     "y": float,
                   },
                 },
               } =>
               unit
                 =?,
    ~onSelectionChange: {
                          .
                          "nativeEvent": {
                            .
                            "selection": {
                              .
                              "start": int,
                              "_end": int,
                            },
                          },
                        } =>
                        unit
                          =?,
    ~placeholder: string=?,
    ~placeholderTextColor: string=?,
    ~returnKeyType: [
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
                    ]
                      =?,
    ~secureTextEntry: bool=?,
    ~selectTextOnFocus: bool=?,
    ~selection: {
                  .
                  "start": int,
                  "_end": int,
                }
                  =?,
    ~selectionColor: string=?,
    ~value: string=?,
    ~disableFullscreenUI: bool=?,
    ~inlineImageLeft: string=?,
    ~inlineImagePadding: int=?,
    ~numberOfLines: int=?,
    ~returnKeyLabel: string=?,
    ~textBreakStrategy: [ | `balanced | `highQuality | `simple]=?,
    ~underlineColorAndroid: string=?,
    ~clearButtonMode: [ | `always | `never | `unlessEditing | `whileEditing]=?,
    ~clearTextOnFocus: bool=?,
    ~dataDetectorTypes: array(
                          [
                            | `all
                            | `calendarEvent
                            | `link
                            | `none
                            | `phoneNumber
                          ],
                        )
                          =?,
    ~enablesReturnKeyAutomatically: bool=?,
    ~keyboardAppearance: [ | `dark | `default | `light]=?,
    ~onKeyPress: {. "nativeEvent": {. "key": string}} => unit=?,
    ~selectionState: 'documentSelectionState=?,
    ~spellCheck: bool=?,
    ~inputAccessoryViewID: string=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );

/**
{4 clear()}
Removes all text from the [TextInput].
 */
let isFocused: ReasonReact.reactRef => bool;

/**
{4 focus()}
focus [TextInput] programmatically
 */

let clear: ReasonReact.reactRef => unit;

/**
{4 blur()}
blur [TextInput] programmatically
 */

let focus: ReasonReact.reactRef => unit;

let blur: ReasonReact.reactRef => unit;
