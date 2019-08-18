open ReactNative;
open ReactNavigation;

[@react.component]
let make = (~navigation as _) => <View />;

make->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(~title="Compose", ()),
);
