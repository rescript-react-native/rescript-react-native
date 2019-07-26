module Make = (S: {type screenProps;}) => {
  type screenProps = S.screenProps;

  type appContainerProps = {
    .
    "persistNavigationState": option(Types.persistNavigationState),
    "loadNavigationState": option(Types.loadNavigationState),
    "screenProps": option(screenProps),
    "setNavigatorRef": Js.Nullable.t(NavigationContainer.t) => unit,
  };

  type navigationParams = {
    .
    "navigation": Navigation.t,
    "navigationOptions": NavigationOptions.t,
    "screenProps": screenProps,
  };

  module type AppContainer = {
    [@react.component]
    let make:
      (
        ~persistNavigationState: Types.persistNavigationState=?,
        ~loadNavigationState: Types.loadNavigationState=?,
        ~screenProps: screenProps=?,
        ~setNavigatorRef: Js.Nullable.t(NavigationContainer.t) => unit
      ) =>
      React.element;
  };

  [@bs.module "react-navigation"]
  external _createAppContainer:
    Types.navigator => React.component(appContainerProps) =
    "createAppContainer";

  let makeAppContainer = (navigator: Types.navigator): (module AppContainer) => {
    let make = _createAppContainer(navigator);

    (module
     {
       [@bs.obj]
       external makeProps:
         (
           ~persistNavigationState: Types.persistNavigationState=?,
           ~loadNavigationState: Types.loadNavigationState=?,
           ~screenProps: screenProps=?,
           ~setNavigatorRef: Js.Nullable.t(NavigationContainer.t) => unit,
           ~key: string=?,
           unit
         ) =>
         appContainerProps =
         "";

       let make = make;
     });
  };

  [@bs.set]
  external setNavigationOptions:
    (React.component('props), NavigationOptions.t) => unit =
    "navigationOptions";
  [@bs.set]
  external setDynamicNavigationOptions:
    (React.component('props), navigationParams => NavigationOptions.t) => unit =
    "navigationOptions";
};
