open ReactNative;
open ReactNavigation;
let placeholder = (~text, ~navigation: Navigation.t) =>
  <>
    <Centered> <Text> {text |> React.string} </Text> </Centered>
    <ComposeButton
      onPress={_ => navigation->Navigation.navigate("Compose")}
    />
  </>;

let headerIcon = (~style as additionalStyle=Style.style(), source) =>
  <Image
    style=Style.(
      array([|
        style(~width=24.->dp, ~margin=11.->dp, ~height=24.->dp, ()),
        additionalStyle,
      |])
    )
    source
  />;

let tabBarIcon = source =>
  NavigationOptions.TabBarIcon.render(props =>
    <Image
      style=Style.(
        style(
          ~tintColor=props##focused ? "#1da1f2" : "grey",
          ~width=24.->dp,
          ~margin=11.->dp,
          ~height=24.->dp,
          (),
        )
      )
      source
    />
  );

let avatarIcon = params =>
  <TouchableOpacity onPress={_ => params##navigation->Navigation.openDrawer}>
    <Image
      style=Style.(
        style(
          ~backgroundColor="grey",
          ~width=24.->dp,
          ~borderRadius=12.,
          ~margin=11.->dp,
          ~height=24.->dp,
          (),
        )
      )
      source=Icons.avatar
    />
  </TouchableOpacity>;

let rec getActiveRoute = route =>
  switch (route##routes) {
  | Some(routes) =>
    let routeCount = routes->Array.length;
    if (routeCount == 0 || route##index >= routeCount) {
      route;
    } else {
      getActiveRoute(routes->Belt.Array.getUnsafe(route##index));
    };
  | None => route
  };
