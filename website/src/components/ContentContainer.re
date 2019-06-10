open ReactNative;
open ReactMultiversal;

let styles =
  StyleSheet.create(
    Style.{"container": style(~flex=1., ~flexBasis=500.->dp, ())},
  );

[@react.component]
let make = (~children) => {
  <SpacedView style=styles##container vertical=SpacedView.L>
    children
  </SpacedView>;
};
