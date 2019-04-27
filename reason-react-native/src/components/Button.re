include NativeElement;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // Button props
    ~accessibilityLabel: string=?,
    ~color: Color.t=?,
    ~disabled: bool=?,
    ~hasTVPreferredFocus: bool=?,
    ~onPress: unit => unit,
    ~testID: string=?,
    ~title: string
  ) =>
  React.element =
  "Button";
