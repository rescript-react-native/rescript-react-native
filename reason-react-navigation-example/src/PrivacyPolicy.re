open ReactNative;
open ReactNavigation;

[@react.component]
let make = (~navigation: navigation) =>
  <Text> {React.string("Privacy Policy")} </Text>;

make->setDynamicNavigationOptions(params => {
  let navigation = params->NavigationParams.navigation;
  let navigationOptions = params->NavigationParams.navigationOptions;
  let screenProps = params->NavigationParams.screenProps;

  /* More properties can be set dynamically based on navigation, navigationOptions or screenProps. */
  NavigationOptions.t(~title="Privacy Policy", ~headerTintColor="red", ());
});
