type navigationState = {
  .
  "index": int,
  "routes": option(array(navigationState)),
  "isDrawerOpen": bool,
};

type navigatorProps;
type navigator = React.component(navigatorProps);

type persistNavigationState = navigationState => Js.Promise.t(unit);
type loadNavigationState = unit => Js.Promise.t(option(navigationState));
