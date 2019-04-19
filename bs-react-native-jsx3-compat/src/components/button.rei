/**

  Button in {{:https://facebook.github.io/react-native/docs/button.html} React Native},
  has two required props title and onPress, so in order to render a Button component you need to provide them:

  {2 Example}

  {3 default}

  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self =>
        <Button title="Press me" onPress=(() => Js.log("pressed")) />,
    };
  ]}

  {3 color}

  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self =>
        <Button
          color="tomato"
          title="Press me"
          onPress=(() => Js.log("pressed"))
        />,
    };
  ]}

  {3 hex colors}

  let component = ReasonReact.statelessComponent("MyComponent");
  {[
    let make = _children => {
      ...component,
      render: _self =>
        <Button
          color="#ff00ff"
          title="Press me"
          onPress=(() => Js.log("pressed"))
        />,
    };
  ]}

  {3 rgb colors}

  let component = ReasonReact.statelessComponent("MyComponent");
  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self =>
        <Button
          color="rgb(255, 34, 11)"
          title="Press me"
          onPress=(() => Js.log("pressed"))
        />,
    };
  ]}

  {3 disabled}
  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self =>
        <Button
          disabled=true
          title="Press me"
          onPress=(() => Js.log("pressed"))
        />,
    };
  ]}

  {2 Props}

  {3 accessibilityLabel}

  {[
    ~accessibilityLabel: string=?
  ]}

  {3 color}

  {[
    ~color: string=?
  ]}

  {3 disabled}

  {[
    ~disabled: bool=?
  ]}

  {3 onPress}

  {[
    ~onPress: unit => unit
  ]}

  {3 testID}

  {[
    ~testID: string=?
  ]}

  {3 title}

  {[
    ~title: string
  ]}

 */
let make:
  (
    ~accessibilityLabel: string=?,
    ~color: string=?,
    ~disabled: bool=?,
    ~onPress: unit => unit,
    ~testID: string=?,
    ~title: string,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
