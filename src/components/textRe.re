external text : ReactRe.reactClass = "Text" [@@bs.module "react-native"];

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
    ::suppressHighlighting=? =>
  ReactRe.wrapPropsShamelessly
    text
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
    );