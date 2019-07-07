open ReactNative;
open Navigation;

[@react.component]
let make = (~navigation: navigation) =>
  <Text> {React.string("Privacy Policy")} </Text>;

make->setDynamicNavigationOptions(_params
  /* More properties can be set dynamically based on navigation, navigationOptions or screenProps. */
  =>
    NavigationOptions.t(~title="Privacy Policy", ~headerTintColor="red", ())
  );
