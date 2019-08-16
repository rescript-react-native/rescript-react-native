type persistNavigationState = Types.navigationState => Js.Promise.t(unit);
type loadNavigationState =
  unit => Js.Promise.t(option(Types.navigationState));

type appContainerProps('screenProps) = {
  .
  "persistNavigationState": option(persistNavigationState),
  "loadNavigationState": option(loadNavigationState),
  "screenProps": option('screenProps),
  "setNavigatorRef": Js.Nullable.t(NavigationContainer.t) => unit,
};

module Make = (S: {
                 type screenProps;
                 let navigator: Types.navigator;
               }) => {
  [@bs.module "react-navigation"]
  external make:
    Types.navigator => React.component(appContainerProps(S.screenProps)) =
    "createAppContainer";

  [@bs.obj]
  external makeProps:
    (
      ~persistNavigationState: persistNavigationState=?,
      ~loadNavigationState: loadNavigationState=?,
      ~screenProps: S.screenProps=?,
      ~setNavigatorRef: Js.Nullable.t(NavigationContainer.t) => unit=?,
      ~key: string=?,
      unit
    ) =>
    appContainerProps(S.screenProps) =
    "";

  let make = make(S.navigator);
};
