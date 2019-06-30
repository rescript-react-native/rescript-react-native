open ReactNative;
[@react.component]
let make = (~children) =>
  <View
    style=Style.(
      style(~flex=1., ~justifyContent=`center, ~alignItems=`center, ())
    )>
    children
  </View>;
