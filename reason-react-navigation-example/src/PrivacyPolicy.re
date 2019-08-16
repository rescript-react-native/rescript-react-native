open ReactNative;
open ReactNavigation;

[@react.component]
let make = (~navigation as _: Navigation.t) =>
  <Text> {React.string("Privacy Policy")} </Text>;

make->NavigationOptions.setDynamicNavigationOptions(_params
  /* More properties can be set dynamically based on navigation, navigationOptions or screenProps. */
  =>
    NavigationOptions.t(~title="Privacy Policy", ~headerTintColor="red", ())
  );
