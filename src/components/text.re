module type TextComponent = {
  let make:
    (
      ~accessible: bool=?,
      ~accessibilityHint: string=?,
      ~accessibilityLabel: string=?,
      ~allowFontScaling: bool=?,
      ~ellipsizeMode: [ | `clip | `head | `middle | `tail]=?,
      ~numberOfLines: int=?,
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
      ~onLongPress: unit => unit=?,
      ~onPress: unit => unit=?,
      ~pressRetentionOffset: Types.insets=?,
      ~selectable: bool=?,
      ~style: Style.t=?,
      ~testID: string=?,
      ~selectionColor: string=?,
      ~textBreakStrategy: [ | `simple | `highQuality | `balanced]=?,
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

module CreateComponent = (Impl: View.Impl) : TextComponent => {
  let make =
      (
        ~accessible=?,
        ~accessibilityHint=?,
        ~accessibilityLabel=?,
        ~allowFontScaling=?,
        ~ellipsizeMode=?,
        ~numberOfLines=?,
        ~onLayout=?,
        ~onLongPress=?,
        ~onPress=?,
        ~pressRetentionOffset=?,
        ~selectable=?,
        ~style=?,
        ~testID=?,
        ~selectionColor=?,
        ~textBreakStrategy=?,
        ~adjustsFontSizeToFit=?,
        ~minimumFontScale=?,
        ~suppressHighlighting=?,
        ~value=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props={
        "accessible": accessible,
        "accessibilityHint": accessibilityHint,
        "accessibilityLabel": accessibilityLabel,
        "allowFontScaling": allowFontScaling,
        "ellipsizeMode":
          ellipsizeMode->Belt.Option.map(
            fun
            | `head => "head"
            | `middle => "middle"
            | `tail => "tail"
            | `clip => "clip",
          ),
        "numberOfLines": numberOfLines,
        "onLayout": onLayout,
        "onLongPress": onLongPress,
        "onPress": onPress,
        "pressRetentionOffset": pressRetentionOffset,
        "selectable": selectable,
        "style": style,
        "testID": testID,
        "selectionColor": selectionColor,
        "textBreakStrategy":
          textBreakStrategy->Belt.Option.map(
            fun
            | `simple => "simple"
            | `highQuality => "highQuality"
            | `balanced => "balanced",
          ),
        "adjustsFontSizeToFit": adjustsFontSizeToFit,
        "minimumFontScale": minimumFontScale,
        "suppressHighlighting": suppressHighlighting,
      },
      switch (value) {
      | Some(string) =>
        Array.append([|ReasonReact.string(string)|], children)
      | None => children
      },
    );
};

include CreateComponent({
  [@bs.module "react-native"] external view: ReasonReact.reactClass = "Text";
});
