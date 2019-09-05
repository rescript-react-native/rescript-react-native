[@react.component] [@bs.module "react-native"]
external make:
  (
    ~backgroundColor: Color.t=?,
    ~nativeID: string=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "InputAccessoryView";
