/**
    {3 Example of use}
    In order to render a [Picker] component {{:https://facebook.github.io/react-native/docs/picker}} you will need to pass one or many [Picker.Item]
    components as children.

    And [Picker.Item] has a required [label] prop

    {4 default}
    {[
      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <View>
            <Picker>
              <Picker.Item label="ReasonML" value="reason" />
              <Picker.Item label="Ocaml" value="ocaml" />
              <Picker.Item label="JavaScript" value="js" />
            </Picker>
          </View>,
      };
    ]}
    {4 selectedValue and onValueChange}
    {[
      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <View>
            <Picker selectedValue="ocaml" onValueChange=(value => Js.log(value))>
              <Picker.Item label="ReasonML" value="reason" />
              <Picker.Item label="Ocaml" value="ocaml" />
              <Picker.Item label="JavaScript" value="js" />
            </Picker>
          </View>,
      };
    ]}
    {3 Props}
    {4 onValueChange}
    {[
      onValueChange: 'value => unit=?
    ]}
    {4 selectedValue}
    {[
      selectedValue: 'value=?
    ]}
    {4 enabled}
    {[
      enabled: bool=?
    ]}
    {4 mode}
    On {b Android only}, specifies how to display the selection items when the user taps on the picker:

    - [`dialog] - shows a modal dialog. This is the default.
    - [`dropdown] - shows a dropdown anchored to the picker view
    {[
      mode: [
        | `dialog
        | `dropdown
      ]=?
    ]}
    {4 prompt}
    {[
      prompt: string=?
    ]}
    {4 itemStyle}
    {[
      itemStyle: Style.t=?
    ]}
    {4 accessibilityLabel}
    {[
      accessibilityLabel: ReasonReact.reactElement=?
    ]}
    {4 accessible}
    {[
      accessible: bool=?
    ]}
    {4 hitSlop}
    {[
      hitSlop: Types.insets=?
    ]}
    reference:
    {4 Types.rei}
    {[
      type insets = {
        .
        "left": int,
        "right": int,
        "top": int,
        "bottom": int,
      };
    ]}
    {4 onAccessibilityTap}
    {[
      onAccessibilityTap: unit => unit=?
    ]}
    {4 onLayout}
    {[
      onLayout: RNEvent.NativeLayoutEvent.t => unit=?
    ]}
    Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeLayoutEvent/} [RNEvent.NativeLayoutEvent]}

    {4 onMagicTap}
    {[
      onMagicTap: unit => unit=?
    ]}
    {4 responderHandlers}
    {[
      responderHandlers: Types.touchResponderHandlers=?
    ]}
    reference:
    {4 Types.rei}
    {[
      type touchResponderHandlers = {
        onMoveShouldSetResponder: option(RNEvent.NativeEvent.t => bool),
        onMoveShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool),
        onResponderGrant: option(RNEvent.NativeEvent.t => unit),
        onResponderMove: option(RNEvent.NativeEvent.t => unit),
        onResponderReject: option(RNEvent.NativeEvent.t => unit),
        onResponderRelease: option(RNEvent.NativeEvent.t => unit),
        onResponderTerminate: option(RNEvent.NativeEvent.t => unit),
        onResponderTerminationRequest: option(RNEvent.NativeEvent.t => unit),
        onStartShouldSetResponder: option(RNEvent.NativeEvent.t => bool),
        onStartShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool)
      };
    ]}
    {4 RNEvent.rei}
    {[
      module NativeEvent: {
        type t;
        let changedTouches: t => array(Js.t({..}));
        let identifier: t => int;
        let locationX: t => float;
        let locationY: t => float;
        let pageX: t => float;
        let pageY: t => float;
        let target: t => Js.t({..});
        let touches: t => array(Js.t({..}));
        let timestamp: t => int;
        let data: t => string;
      };
    ]}
    {4 pointerEvents}
    {[
      pointerEvents: [
        | `auto
        | `none
        | `boxNone
        | `boxOnly
      ]=?
    ]}
    {4 removeClippedSubviews}
    {[
      removeClippedSubviews: bool=?
    ]}
    {4 style}
    {[
      style: Style.t=?
    ]}
    {4 testID}
    {[
      testID: string=?
    ]}
    {4 accessibilityComponentType}
    {[
      accessibilityComponentType: [
        | `none
        | `button
        | `radiobutton_checked
        | `radiobutton_unchecked
      ]=?
    ]}
    {4 accessibilityLiveRegion}
    {[
      accessibilityLiveRegion: [
        | `none
        | `polite
        | `assertive
      ]=?
    ]}
    {4 collapsable}
    {[
      collapsable: bool=?
    ]}
    {4 importantForAccessibility}
    {[
      importantForAccessibility: [
        | `auto
        | `yes
        | `no
        | `noHideDescendants
      ]=?
    ]}
    {4 needsOffscreenAlphaCompositing}
    {[
      needsOffscreenAlphaCompositing: bool=?
    ]}
    {4 renderToHardwareTextureAndroid}
    {[
      renderToHardwareTextureAndroid: bool=?
    ]}
    {4 accessibilityTraits}
    {[
      accessibilityTraits: list(
        [
          | `none
          | `button
          | `link
          | `header
          | `search
          | `image
          | `selected
          | `plays
          | `key
          | `text
          | `summary
          | `disabled
          | `frequentUpdates
          | `startsMedia
          | `adjustable
          | `allowsDirectInteraction
          | `pageTurn
        ]
      )=?
    ]}
    {4 accessibilityViewIsModal}
    {[
      accessibilityViewIsModal: bool=?
    ]}
    {4 shouldRasterizeIOS}
    {[
      shouldRasterizeIOS: bool=?
    ]}
*/

let make:
  (
    ~onValueChange: 'value => unit=?,
    ~selectedValue: 'value=?,
    ~enabled: bool=?,
    ~mode: [ | `dialog | `dropdown]=?,
    ~prompt: string=?,
    ~itemStyle: Style.t=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
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
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );

/**
  [Picker.Item] component is used {b only} inside [<Picker></Picker>] component

  {3 Props}
  {4 label}
  {[
    label: string
  ]}
  {4 color}
  {[
    color: string=?
  ]}
  {4 value}
  {[
    value: 'value=?
  ]}
*/

module Item: {
  let make:
    (
      ~color: string=?,
      ~label: string,
      ~value: 'value=?,
      ~testID: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};
