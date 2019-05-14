---
id: apis/UIManager
title: UIManager
wip: true
---

```reason
type popupAction;

[@bs.module "react-native"] [@bs.scope ("UIManager", "PopupMenu")]
external itemSelected: popupAction = "";

[@bs.module "react-native"] [@bs.scope ("UIManager", "PopupMenu")]
external dismissed: popupAction = "";

// Android-only. This function is intended to be removed in the future,
// at which point it would return undefined. Accordingly it is wrapped in
// option.
[@bs.module "react-native"] [@bs.scope "UIManager"]
external setLayoutAnimationEnabledExperimental: option(bool => unit) = "";

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
  "";

// Android-only
[@bs.module "react-native"] [@bs.scope "UIManager"]
external dismissPopupMenu: unit => unit = "";

[@bs.module "react-native"] [@bs.scope "UIManager"]
external setJSResponder: (int, bool) => unit = "";

[@bs.module "react-native"] [@bs.scope "UIManager"]
external clearJSResponder: unit => unit = "";

// Android-only
[@bs.module "react-native"] [@bs.scope "UIManager"]
external playTouchSound: unit => unit = "";

```
