open Utils;

type pressRetentionOffset = {top: int, left: int, bottom: int, right: int};

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
    {
      "accessible": from_opt (option_map to_js_boolean accessible),
      "allowFontScaling": from_opt (option_map to_js_boolean allowFontScaling),
      "ellipsizeMode":
        from_opt (
          option_map
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
      "pressRetentionOffset":
        from_opt (
          option_map
            (
              fun {top, left, bottom, right} => {
                "top": top,
                "left": left,
                "bottom": bottom,
                "right": right
              }
            )
            pressRetentionOffset
        ),
      "selectable": from_opt (option_map to_js_boolean selectable),
      "style": from_opt style,
      "testID": from_opt testID,
      "selectionColor": from_opt selectionColor,
      "textBreakStrategy":
        from_opt (
          option_map
            (
              fun
              | `simple => "simple"
              | `highQuality => "highQuality"
              | `balanced => "balanced"
            )
            textBreakStrategy
        ),
      "adjustsFontSizeToFit": from_opt (option_map to_js_boolean adjustsFontSizeToFit),
      "minimumFontScale": from_opt minimumFontScale,
      "suppressHighlighting": from_opt (option_map to_js_boolean suppressHighlighting)
    };