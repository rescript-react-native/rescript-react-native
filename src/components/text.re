module type TextComponent = {
  let make:
    (
      ~accessible: bool=?,
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
      unit
    );
};

module CreateComponent = (Impl: View.Impl) : TextComponent => {
  let make =
      (
        ~accessible=?,
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
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props=
        Js.Undefined.(
          {
            "accessible": fromOption(UtilsRN.optBoolToOptJsBoolean(accessible)),
            "allowFontScaling":
              fromOption(UtilsRN.optBoolToOptJsBoolean(allowFontScaling)),
            "ellipsizeMode":
              fromOption(
                UtilsRN.option_map(
                  fun
                  | `head => "head"
                  | `middle => "middle"
                  | `tail => "tail"
                  | `clip => "clip",
                  ellipsizeMode
                )
              ),
            "numberOfLines": fromOption(numberOfLines),
            "onLayout": fromOption(onLayout),
            "onLongPress": fromOption(onLongPress),
            "onPress": fromOption(onPress),
            "pressRetentionOffset": fromOption(pressRetentionOffset),
            "selectable": fromOption(UtilsRN.optBoolToOptJsBoolean(selectable)),
            "style": fromOption(style),
            "testID": fromOption(testID),
            "selectionColor": fromOption(selectionColor),
            "textBreakStrategy":
              fromOption(
                UtilsRN.option_map(
                  fun
                  | `simple => "simple"
                  | `highQuality => "highQuality"
                  | `balanced => "balanced",
                  textBreakStrategy
                )
              ),
            "adjustsFontSizeToFit":
              fromOption(UtilsRN.optBoolToOptJsBoolean(adjustsFontSizeToFit)),
            "minimumFontScale": fromOption(minimumFontScale),
            "suppressHighlighting":
              fromOption(UtilsRN.optBoolToOptJsBoolean(suppressHighlighting))
          }
        ),
      switch value {
      | Some(string) =>
        Array.append([|ReasonReact.stringToElement(string)|], children)
      | None => children
      }
    );
};

include
  CreateComponent(
    {
      [@bs.module "react-native"]
      external view : ReasonReact.reactClass = "Text";
    }
  );
