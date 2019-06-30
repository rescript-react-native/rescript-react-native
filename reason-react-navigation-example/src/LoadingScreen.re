open ReactNative;
open ReactNavigation;

/* TODO: add to TextInput*/
external elementToObj: TextInput.element => Js.t({..}) = "%identity";

[@react.component]
let make = (~countdown=3, ~navigation: navigation) => {
  open Navigation;
  let (count, setCount) = React.useState(() => countdown);

  React.useEffect0(() => {
    let intervalId =
      Js.Global.setInterval(
        () => {
          Js.log2("count", count);
          setCount(count => count - 1);
        },
        1000,
      );
    Some(
      () => {
        Js.log("Clear Interval");
        Js.Global.clearInterval(intervalId);
      },
    );
  });

  React.useEffect1(
    () => {
      if (count == 0) {
        Js.log("navigating to Center");
        navigation->Navigation.navigate("App");
      } else {
        Js.log({j|Navigate to center in: $count|j});
      };
      None;
    },
    [|count|],
  );

  <>
    <View
      style=Style.(
        style(~flex=1., ~justifyContent=`center, ~alignItems=`center, ())
      )>
      <Text> {React.string(count |> string_of_int)} </Text>
    </View>
  </>;
};
