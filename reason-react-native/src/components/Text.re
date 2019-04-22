[@react.component] [@bs.module "react-native"]
external make:
  (
    ~accessible: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityLabel: string=?,
    ~allowFontScaling: bool=?,
    ~ellipsizeMode: [@bs.string] [ | `clip | `head | `middle | `tail]=?,
    ~numberOfLines: int=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onLongPress: unit => unit=?,
    ~onPress: unit => unit=?,
    ~pressRetentionOffset: Types.edgeInsets=?,
    ~selectable: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~selectionColor: string=?,
    ~textBreakStrategy: [@bs.string] [ | `simple | `highQuality | `balanced]=?,
    ~adjustsFontSizeToFit: bool=?,
    ~minimumFontScale: float=?,
    ~suppressHighlighting: bool=?,
    ~value: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Text";
