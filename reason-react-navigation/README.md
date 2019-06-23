# reason-react-navigation

[Reason](https://reasonml.github.io) bindings to
[react-navigation](https://github.com/react-navigation/react-navigation).

## Status

WIP WIP WIP WIP

## Example

Instantiate a navigation module with your `screenProps` type (Navigation.re):

```reason
include ReactNavigation.Make({
  type screenProps = {
    .
    "someProp": int,
  };
});
```

A screen component with dynamic navigation options (Screen1.re):

```reason
open ReactNative;
open Navigation;

[@react.component]
let make = (~navigation, ~screenProps) => {
  <Text> {React.string("Hello world!")} </Text>,
};

make->setDynamicNavigationOptions(params => {
  let navigation = params##navigation;
  let navigationOptions = params##navigationOptions;
  let screenProps = params##screenProps;

  /* More properties can be set dynamically based on navigation, navigationOptions or screenProps. */
  NavigationOptions.t(~title="Screen 1", ~headerTintColor="red", ());
});
```

A stack navigator containing this screen (MyStackNavigator.re):

```reason
open Navigation;

let routes = {
  "Screen1": Screen1.make,
  "Screen2": Screen2.make,
  "Screen3": Screen3.make,
};

let navigator = StackNavigator.make(routes);
navigator->setNavigationOptions(NavigationOptions.t(~gesturesEnabled=false, ()));
```

The main React component of the app (App.re):

```reason
open Navigation;

module AppContainer = (val makeAppContainer(MyStackNavigator.navigator));

[@react.component]
let make = () => {
  let screenProps = {"someProp": 42};

  <AppContainer screenProps />;
};
```
