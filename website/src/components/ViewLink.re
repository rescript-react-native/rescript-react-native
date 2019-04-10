open ReactNative;

module Wrapper = {
  [@react.component] [@bs.module "./TextLink"]
  external make:
    (
      ~href: string,
      ~accessibilityLabel: string=?,
      ~style: Style.t=?,
      ~activeStyle: Style.t=?,
      ~children: React.element,
      unit
    ) =>
    React.element =
    "default";
};

[@react.component]
let make =
    (~href, ~accessibilityLabel=?, ~style as s=?, ~activeStyle=?, ~children) =>
  <Wrapper
    href
    ?accessibilityLabel
    style=Style.(
      arrayOption([|
        Some(style(~display=`flex, ~flexDirection=`column, ())),
        s,
      |])
    )
    ?activeStyle>
    ...children
  </Wrapper>;
