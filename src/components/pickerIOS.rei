/**
  {3 Example of use}
  In order to render a [PickerIOS] {{:https://facebook.github.io/react-native/docs/pickerios}} component you will need to pass one or many [PickerIOS.Item] component(s) as children.

  And [PickerIOS.Item] has a required label prop
  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self =>
        <View>
          <PickerIOS>
            <PickerIOS.Item label="ReasonML" value="reason" />
            <PickerIOS.Item label="Ocaml" value="ocaml" />
            <PickerIOS.Item label="JavaScript" value="js" />
          </PickerIOS>
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
          <PickerIOS selectedValue="ocaml" onValueChange=(value => Js.log(value))>
            <PickerIOS.Item label="ReasonML" value="reason" />
            <PickerIOS.Item label="Ocaml" value="ocaml" />
            <PickerIOS.Item label="JavaScript" value="js" />
          </PickerIOS>
        </View>,
    };
  ]}
  {3 Props}
  {4 itemStyle}
  {[
    itemStyle: Style.t=?
  ]}
  {4 onValueChange}
  {[
    onValueChange: 'value => unit=?
  ]}
  {4 selectedValue}
  {[
    selectedValue: 'value=?
  ]}
*/
let make:
  (
    ~itemStyle: Style.t=?,
    ~onValueChange: 'value => unit=?,
    ~selectedValue: 'value=?,
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
    ReasonReact.actionless,
  );

/**
  [PickerIOS.Item] component is used {b only} inside [<PickerIOS></PickerIOS>] component

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
      ~label: string,
      ~value: 'value=?,
      ~color: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};
