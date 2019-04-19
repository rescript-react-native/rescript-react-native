/**
    {3 Example of use}
    [Modal] component {{:https://facebook.github.io/react-native/docs/modal}} simply displays content over an enclosing view.

    {4 default}
    Wrap some content in [<Modal></Modal>] and you are good to go
    {[
      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <Modal>
            <View
              style=Style.(
                      style([
                        flex(1.),
                        justifyContent(Center),
                        alignItems(Center),
                        backgroundColor(String("tomato")),
                      ])
                    )>
              <Text> (ReasonReact.string("hey ho")) </Text>
            </View>
          </Modal>,
      };
    ]}
    {3 Props}
    {4 animationType}
    {[
      animationType: [
        | `fade
        | `none
        | `slide
      ]=?
    ]}
    And this is how you apply one of those types:
    {[
      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <Modal animationType=`slide>
            <View
              style=Style.(
                      style([
                        flex(1.),
                        justifyContent(Center),
                        alignItems(Center),
                        backgroundColor(String("tomato")),
                      ])
                    )>
              <Text> (ReasonReact.string("hey ho")) </Text>
            </View>
          </Modal>,
      };
    ]}

    {4 onShow}
    {[
      onShow: unit => unit=?
    ]}
    Example:
    {[
      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <Modal onShow=(() => Js.log("Just displayed the modal..."))>
            <View
              style=Style.(
                      style([
                        flex(1.),
                        justifyContent(Center),
                        alignItems(Center),
                        backgroundColor(String("tomato")),
                      ])
                    )>
              <Text> (ReasonReact.string("hey ho")) </Text>
            </View>
          </Modal>,
      };
    ]}
    {4 transparent}
    {[
      transparent: bool=?
    ]}
    {4 visible}
    {[
      visible: bool=?
    ]}
    {4 hardwareAccelerated}
    {[
      hardwareAccelerated: bool=?
    ]}
    {4 onRequestClose}
    {[
      onRequestClose: unit => unit=?
    ]}
    {4 onOrientationChange}
    {[
      onOrientationChange: unit => unit=?
    ]}
    {4 supportedOrientations}
    {[
      supportedOrientations: array(
        [
          | `landscape
          | `landscapeLeft
          | `landscapeRight
          | `portrait
          | `portraitUpsideDown
        ],
      )=?
    ]}
    Example:
    {[
      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <Modal supportedOrientations=[|`landscape, `portrait|]>
            <View
              style=Style.(
                      style([
                        flex(1.),
                        justifyContent(Center),
                        alignItems(Center),
                        backgroundColor(String("tomato")),
                      ])
                    )>
              <Text> (ReasonReact.string("hey ho")) </Text>
            </View>
          </Modal>,
      };
    ]}

*/
let make:
  (
    ~animationType: [ | `fade | `none | `slide]=?,
    ~onShow: unit => unit=?,
    ~transparent: bool=?,
    ~visible: bool=?,
    ~hardwareAccelerated: bool=?,
    ~onRequestClose: unit => unit=?,
    ~onOrientationChange: unit => unit=?,
    ~supportedOrientations: array(
                              [
                                | `landscape
                                | `landscapeLeft
                                | `landscapeRight
                                | `portrait
                                | `portraitUpsideDown
                              ],
                            )
                              =?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
