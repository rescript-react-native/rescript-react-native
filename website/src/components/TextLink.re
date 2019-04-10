open ReactNative;

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
