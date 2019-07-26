type t;
[@bs.send] external dispatch: (t, NavigationActions.action) => unit = "";
