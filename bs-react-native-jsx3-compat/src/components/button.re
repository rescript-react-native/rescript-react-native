[@react.component]
let make =
    (
      ~accessibilityLabel=?,
      ~color=?,
      ~disabled=?,
      ~onPress,
      ~testID=?,
      ~title,
    ) =>
  <ReactNative.Button
    ?accessibilityLabel
    ?color
    ?disabled
    onPress={_ => onPress()}
    ?testID
    title
  />;
