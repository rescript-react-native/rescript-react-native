open ReactNative;
[@react.component]
let make = (~onPress) =>
  <TouchableOpacity
    onPress
    style=Style.(
      style(
        ~backgroundColor="#5D9FEF",
        ~elevation=3.,
        ~shadowRadius=3.,
        ~shadowOpacity=0.3,
        ~shadowOffset=offset(~height=2., ~width=0.),
        ~position=`absolute,
        ~right=16.->dp,
        ~bottom=14.->dp,
        ~alignItems=`center,
        ~justifyContent=`center,
        ~borderRadius=25.,
        ~width=50.->dp,
        ~height=50.->dp,
        (),
      )
    )>
    <Image
      style=Style.(
        style(~width=24.->dp, ~margin=11.->dp, ~height=24.->dp, ())
      )
      source=Icons.compose
    />
  </TouchableOpacity>;
