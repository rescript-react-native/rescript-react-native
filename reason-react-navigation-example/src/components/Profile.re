open ReactNavigation;
open Helpers;

[@react.component]
let make = (~navigation) => placeholder(~navigation, ~text="Profile");

make->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(~title="Profile", ()),
);
