type popupAction;

[@bs.module "react-native"] [@bs.scope ("UIManager", "PopupMenu")]
external itemSelected: popupAction = "itemSelected";

[@bs.module "react-native"] [@bs.scope ("UIManager", "PopupMenu")]
external dismissed: popupAction = "dismissed";

// Android-only. This function is intended to be removed in the future,
// at which point it would return undefined. Accordingly it is wrapped in
// option.
[@bs.module "react-native"] [@bs.scope "UIManager"]
external setLayoutAnimationEnabledExperimental: option(bool => unit) =
  "setLayoutAnimationEnabledExperimental";

// Android-only
[@bs.module "react-native"] [@bs.scope "UIManager"]
external showPopupMenu:
  (
    int,
    array(string),
    ~onError: unit => unit,
    ~onSuccess: (popupAction, option(int)) => unit
  ) =>
  unit =
  "showPopupMenu";

// Android-only
[@bs.module "react-native"] [@bs.scope "UIManager"]
external dismissPopupMenu: unit => unit = "dismissPopupMenu";

[@bs.module "react-native"] [@bs.scope "UIManager"]
external setJSResponder: (int, bool) => unit = "setJSResponder";

[@bs.module "react-native"] [@bs.scope "UIManager"]
external clearJSResponder: unit => unit = "clearJSResponder";

// Android-only
[@deprecated
  "Deprecated with RN 0.61.1, please use ReactNative.SoundManager.playTouchSound instead"
]
[@bs.module "react-native"]
[@bs.scope "UIManager"]
external playTouchSound: unit => unit = "playTouchSound";
