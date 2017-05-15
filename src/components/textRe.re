module type TextComponent = {
  let createElement:
    accessible::bool? =>
    allowFontScaling::bool? =>
    ellipsizeMode::[ | `clip | `head | `middle | `tail]? =>
    numberOfLines::int? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onLongPress::(unit => unit)? =>
    onPress::(unit => unit)? =>
    pressRetentionOffset::Types.insets? =>
    selectable::bool? =>
    style::StyleRe.t? =>
    testID::string? =>
    selectionColor::string? =>
    textBreakStrategy::[ | `simple | `highQuality | `balanced]? =>
    adjustsFontSizeToFit::bool? =>
    minimumFontScale::float? =>
    suppressHighlighting::bool? =>
    value::string? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};

module CreateComponent (Impl: ViewRe.Impl) :TextComponent => {
  let createElement
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
      ::children =>
    ReactRe.wrapPropsShamelessly
      Impl.view
      Js.Undefined.(
        {
          "accessible": from_opt (Utils.optBoolToOptJsBoolean accessible),
          "allowFontScaling": from_opt (Utils.optBoolToOptJsBoolean allowFontScaling),
          "ellipsizeMode":
            from_opt (
              Utils.option_map
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
          "selectable": from_opt (Utils.optBoolToOptJsBoolean selectable),
          "style": from_opt style,
          "testID": from_opt testID,
          "selectionColor": from_opt selectionColor,
          "textBreakStrategy":
            from_opt (
              Utils.option_map
                (
                  fun
                  | `simple => "simple"
                  | `highQuality => "highQuality"
                  | `balanced => "balanced"
                )
                textBreakStrategy
            ),
          "adjustsFontSizeToFit": from_opt (Utils.optBoolToOptJsBoolean adjustsFontSizeToFit),
          "minimumFontScale": from_opt minimumFontScale,
          "suppressHighlighting": from_opt (Utils.optBoolToOptJsBoolean suppressHighlighting)
        }
      )
      children::(
        switch value {
        | Some string => [ReactRe.stringToElement string, ...children]
        | None => children
        }
      );
};

module Text =
  CreateComponent {
    external view : ReactRe.reactClass = "Text" [@@bs.module "react-native"];
  };