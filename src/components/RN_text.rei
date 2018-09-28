module type TextComponent = {
  let make:
    (
      ~accessible: bool=?,
      ~allowFontScaling: bool=?,
      ~ellipsizeMode: [ | `clip | `head | `middle | `tail]=?,
      ~numberOfLines: int=?,
      ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
      ~onLongPress: unit => unit=?,
      ~onPress: unit => unit=?,
      ~pressRetentionOffset: RN_types.insets=?,
      ~selectable: bool=?,
      ~style: RN_style.t=?,
      ~testID: string=?,
      ~selectionColor: string=?,
      ~textBreakStrategy: [ | `balanced | `highQuality | `simple]=?,
      ~adjustsFontSizeToFit: bool=?,
      ~minimumFontScale: float=?,
      ~suppressHighlighting: bool=?,
      ~value: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent: (Impl: RN_view.Impl) => TextComponent;

include TextComponent;