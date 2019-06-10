open ReactNative;
open ReactMultiversal;

let styles =
  Style.(
    StyleSheet.create({
      "title":
        style(
          ~fontSize=14.,
          ~fontWeight=`_200,
          ~color=Predefined.Colors.grey,
          (),
        ),
    })
  );

[@react.component]
let make = (~style as s=?, ~children) => {
  <Text style=Style.(arrayOption([|Some(styles##title), s|]))>
    children
  </Text>;
};
