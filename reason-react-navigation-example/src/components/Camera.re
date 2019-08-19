open ReactNative;
open ReactNavigation;

[@react.component]
let cameraScreen = () =>
  <SafeAreaView style=Style.(style(~flex=1.0, ~backgroundColor="black", ()))>
    <TouchableOpacity
      style=Style.(
        style(
          ~backgroundColor="#aaa",
          ~position=`absolute,
          ~bottom=34.->dp,
          ~alignItems=`center,
          ~alignSelf=`center,
          ~justifyContent=`center,
          ~borderRadius=25.,
          ~width=50.->dp,
          ~height=50.->dp,
          (),
        )
      )>
      <View
        style=Style.(
          style(~width=24.->dp, ~backgroundColor="#eee", ~height=24.->dp, ())
        )
      />
    </TouchableOpacity>
  </SafeAreaView>;

let routes = {"Camera": cameraScreen, "CameraModal": PrivacyPolicy.make};

let navigator =
  StackNavigator.(
    makeWithConfig(routes, config(~mode=`modal, ~headerMode=`none, ()))
  );

navigator->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(~tabBarVisible=false, ~swipeEnabled=true, ()),
);
