type t;

[@bs.get] external state: t => Types.navigationState = "";

[@bs.send] external navigate: (t, string) => unit = "";
[@bs.send]
external navigateWithParams: (t, string, Js.t({..})) => unit = "navigate";
[@bs.send] external goBack: t => unit = "";
[@bs.send] external goBackToRoute: (t, string) => unit = "";
[@bs.send] external getParam: (t, string, 'a) => 'a = "";
// TODO: addListener, setParams, ...
// Stack Actions
// TODO: push, replace, ...
[@bs.send] external pop: t => unit = "";
[@bs.send] external popN: (t, int) => unit = "";
[@bs.send] external popToTop: t => unit = "";
// Drawer navigator only
[@bs.send] external openDrawer: t => unit = "";
[@bs.send] external closeDrawer: t => unit = "";
[@bs.send] external toggleDrawer: t => unit = "";
