type t;

/**

A wrapper for making views respond properly to touches (Android only). On Android this component uses native state drawable to display touch feedback.

At the moment it only supports having a single View instance as a child node, as it's implemented by replacing that View with another instance of RCTView node with some additional properties set.

Background drawable of native feedback touchable can be customized with [background] property.

You can read more on [TouchableNativeFeedback] component usage in official docs: {{:https://facebook.github.io/react-native/docs/touchablenativefeedback}}

{3 Example}
{[
  let component = ReasonReact.statelessComponent("MyComponent");

  let make = _children => {
    ...component,
    render: _self =>
      <TouchableNativeFeedback>
        <View style=Style.(style([backgroundColor(String("#03DAC5"))]))>
          <Text style=Style.(style([height(Pt(50.))]))>
            (ReasonReact.string("Press the button"))
          </Text>
        </View>
      </TouchableNativeFeedback>,
  };
]}
  {3 Props}

  {{:\BsReactNative/TouchableWithoutFeedback-BsReactNative} [TouchableWithoutFeedback] props}
  {4 background}
  {[
    ~background: string=?
  ]}
  {4 useForeground}
  {[
    ~useForeground: bool=?
  ]}

  {3 Methods}
  {4 selectableBackground}
  Creates an object that represents android theme's default background for selectable elements (?android:attr/selectableItemBackground).
 */

let make:
  (
    ~accessible: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityComponentType: Types.accessibilityComponentType=?,
    ~accessibilityTraits: list(Types.accessibilityTrait)=?,
    ~accessibilityRole: Types.accessibilityRole=?,
    ~accessibilityStates: list(Types.accessibilityState)=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: Types.insets=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onLongPress: RNEvent.NativePressEvent.t => unit=?,
    ~onPress: RNEvent.NativePressEvent.t => unit=?,
    ~onPressIn: RNEvent.NativePressEvent.t => unit=?,
    ~onPressOut: RNEvent.NativePressEvent.t => unit=?,
    ~pressRetentionOffset: Types.insets=?,
    ~style: Style.t=?,
    ~background: t=?,
    ~useForeground: bool=?,
    ~testID: string=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );

/**
{4 selectableBackgroundBorderless}
Creates an object that represent android theme's default background for borderless selectable elements (?android:attr/selectableItemBackgroundBorderless). Available on android API level 21+.
 */
let selectableBackground: unit => t;

/**
{4 canUseNativeForeground}

 */
let selectableBackgroundBorderless: unit => t;

/**
{4 ripple}
Creates an object that represents ripple drawable with specified color (as a string). If property borderless evaluates to true the ripple will render outside of the view bounds (see native actionbar buttons as an example of that behavior). This background type is available on Android API level 21+.
 */
let canUseNativeForeground: unit => t;
let ripple: (string, bool) => t;
