/**
Detect hardware button presses for back navigation.

Android: Detect hardware back button presses, and programmatically invoke the default back button functionality to exit the app if there are no listeners or if none of the listeners return true.

tvOS: Detect presses of the menu button on the TV remote. (Still to be implemented: programmatically disable menu button handling functionality to exit the app if there are no listeners or if none of the listeners return true.)

iOS: Not applicable.

The event subscriptions are called in reverse order (i.e. last registered subscription first), and if one subscription returns true then subscriptions registered earlier will not be called.


You can read more on [BackHandler] API usage in official docs: {{:https://facebook.github.io/react-native/docs/backhandler}}

{3 Methods}
{4 exitApp}
{[
  exitApp: unit => unit = ""
]}
{4 addEventListener}
{[
  addEventListener: (string, unit => bool) => unit = "";
]}
{4 removeEventListener}
{[
  removeEventListener: (string, unit => bool) => unit = "";
]}
*/
[@bs.scope "BackHandler"] [@bs.module "react-native"]
external exitApp: unit => unit = "";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external addEventListener: (string, unit => bool) => unit = "";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external removeEventListener: (string, unit => bool) => unit = "";
