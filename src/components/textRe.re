module type TextComponent = {
  let make:
    accessible::bool? =>
    allowFontScaling::bool? =>
    ellipsizeMode::[ | `clip | `head | `middle | `tail]? =>
    numberOfLines::int? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onLongPress::(unit => unit)? =>
    onPress::(unit => unit)? =>
    pressRetentionOffset::TypesRN.insets? =>
    selectable::bool? =>
    style::StyleRe.t? =>
    testID::string? =>
    selectionColor::string? =>
    textBreakStrategy::[ | `simple | `highQuality | `balanced]? =>
    adjustsFontSizeToFit::bool? =>
    minimumFontScale::float? =>
    suppressHighlighting::bool? =>
    value::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;
};

module CreateComponent (Impl: ViewRe.Impl) :TextComponent => {
  let make
      ::accessible=?
      ::allowFontScaling=?
      ::ellipsizeMode=?
      ::numberOfLines=?
      ::onLayout=?
      ::onLongPress=?
      ::onPress=?
      ::pressRetentionOffset=?
      ::selectable=?
      ::style=?
      ::testID=?
      ::selectionColor=?
      ::textBreakStrategy=?
      ::adjustsFontSizeToFit=?
      ::minimumFontScale=?
      ::suppressHighlighting=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      reactClass::Impl.view
      props::
        Js.Undefined.(
          {
            "accessible": from_opt (UtilsRN.optBoolToOptJsBoolean accessible),
            "allowFontScaling": from_opt (UtilsRN.optBoolToOptJsBoolean allowFontScaling),
            "ellipsizeMode":
              from_opt (
                UtilsRN.option_map
                  (
                    fun
                    | `head => "head"
                    | `middle => "middle"
                    | `tail => "tail"
                    | `clip => "clip"
                  )
                  ellipsizeMode
              ),
            "numberOfLines": from_opt numberOfLines,
            "onLayout": from_opt onLayout,
            "onLongPress": from_opt onLongPress,
            "onPress": from_opt onPress,
            "pressRetentionOffset": from_opt pressRetentionOffset,
            "selectable": from_opt (UtilsRN.optBoolToOptJsBoolean selectable),
            "style": from_opt style,
            "testID": from_opt testID,
            "selectionColor": from_opt selectionColor,
            "textBreakStrategy":
              from_opt (
                UtilsRN.option_map
                  (
                    fun
                    | `simple => "simple"
                    | `highQuality => "highQuality"
                    | `balanced => "balanced"
                  )
                  textBreakStrategy
              ),
            "adjustsFontSizeToFit": from_opt (UtilsRN.optBoolToOptJsBoolean adjustsFontSizeToFit),
            "minimumFontScale": from_opt minimumFontScale,
            "suppressHighlighting": from_opt (UtilsRN.optBoolToOptJsBoolean suppressHighlighting)
          }
        )
      (
        switch value {
        | Some string => Array.append [|ReasonReact.stringToElement string|] children
        | None => children
        }
      );
};

module Text =
  CreateComponent {
    external view : ReasonReact.reactClass = "Text" [@@bs.module "react-native"];
  };