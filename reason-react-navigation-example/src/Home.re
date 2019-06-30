open ReactNative;
open ReactNavigation;

/* TODO: add to TextInput*/
external elementToObj: TextInput.element => Js.t({..}) = "%identity";

[@react.component]
let make = (~navigation: navigation) => {
  open Navigation;
  let (text, onChangeText) = React.useState(() => "Home");
  let ref = React.useRef(Js.Nullable.null);

  React.useEffect0(() => {
    let intervalId =
      Js.Global.setTimeout(
        () =>
          switch (ref->React.Ref.current->Js.Nullable.toOption) {
          | Some(_ref) => Js.log("Hello from home")
          | None => ()
          },
        5000,
      );
    Some(() => Js.Global.clearTimeout(intervalId));
  });

  <SafeAreaView style={Style.style(~flex=1., ())}>
    <Centered>
      <TouchableOpacity
        onPress={_ => navigation->Navigation.navigate("PrivacyPolicy")}>
        <Text> {React.string(text)} </Text>
      </TouchableOpacity>
      <TextInput ref onChangeText={text => onChangeText(_ => text)} />
    </Centered>
  </SafeAreaView>;
};

make->setDynamicNavigationOptions(params => {
  let navigation = params->NavigationParams.navigation;
  let navigationOptions = params->NavigationParams.navigationOptions;
  let screenProps = params->NavigationParams.screenProps;

  /* More properties can be set dynamically based on navigation, navigationOptions or screenProps. */
  NavigationOptions.t(~title="Home", ());
});
