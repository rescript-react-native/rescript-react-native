external statusBar : ReasonReact.reactClass = "StatusBar" [@@bs.module "react-native"];

/*barStyle::[ | `darkContent | `default | `lightContent]? =>
  hidden::bool? =>
  backgroundColor::string? =>
  translucent::bool? =>
  networkActivityIndicatorVisible::bool? =>
  showHideTransition::[ | `fade | `none | `slide]*/
external _setHidden : Js.boolean => Js.Undefined.t string => unit =
  "setHidden" [@@bs.scope "StatusBar"] [@@bs.module "react-native"];

let setHidden hidden ::animation=? () =>
  _setHidden
    (Js.Boolean.to_js_boolean hidden)
    (
      Js.Undefined.from_opt (
        UtilsRN.option_map
          (
            fun x =>
              switch x {
              | `none => "none"
              | `fade => "fade"
              | `slide => "slide"
              }
          )
          animation
      )
    );

external _setBarStyle : string => Js.Undefined.t Js.boolean => unit =
  "setBarStyle" [@@bs.scope "StatusBar"] [@@bs.module "react-native"];

let setBarStyle style ::animated=? () =>
  _setBarStyle
    (
      switch style {
      | `default => "default"
      | `lightContent => "light-content"
      | `darkContent => "dark-content"
      }
    )
    (Js.Undefined.from_opt (UtilsRN.optBoolToOptJsBoolean animated));

external _setNetworkActivityIndicatorVisible : Js.boolean => unit =
  "setNetworkActivityIndicatorVisible" [@@bs.scope "StatusBar"] [@@bs.module "react-native"];

let setNetworkActivityIndicatorVisible visible =>
  _setNetworkActivityIndicatorVisible (Js.Boolean.to_js_boolean visible);

external _setBackgroundColor : string => Js.Undefined.t Js.boolean => unit =
  "setBackgroundColor" [@@bs.scope "StatusBar"] [@@bs.module "react-native"];

let setBackgroundColor color ::animated=? () =>
  _setBackgroundColor color (Js.Undefined.from_opt (UtilsRN.optBoolToOptJsBoolean animated));

external _setTranslucent : Js.boolean => unit =
  "setTranslucent" [@@bs.scope "StatusBar"] [@@bs.module "react-native"];

let setTranslucent translucent => _setTranslucent (Js.Boolean.to_js_boolean translucent);

let make
    ::animated=?
    ::barStyle=?
    ::hidden=?
    ::backgroundColor=?
    ::translucent=?
    ::networkActivityIndicatorVisible=?
    ::showHideTransition=? =>
  ReasonReact.wrapJsForReason
    reactClass::statusBar
    props::
      Js.Undefined.(
        {
          "animated": from_opt (UtilsRN.optBoolToOptJsBoolean animated),
          "barStyle":
            from_opt (
              UtilsRN.option_map
                (
                  fun x =>
                    switch x {
                    | `default => "default"
                    | `lightContent => "light-content"
                    | `darkContent => "dark-content"
                    }
                )
                barStyle
            ),
          "backgroundColor": from_opt backgroundColor,
          "hidden": from_opt (UtilsRN.optBoolToOptJsBoolean hidden),
          "translucent": from_opt (UtilsRN.optBoolToOptJsBoolean translucent),
          "networkActivityIndicatorVisible":
            from_opt (UtilsRN.optBoolToOptJsBoolean networkActivityIndicatorVisible),
          "showHideTransition":
            from_opt (
              UtilsRN.option_map
                (
                  fun x =>
                    switch x {
                    | `none => "none"
                    | `fade => "fade"
                    | `slide => "slide"
                    }
                )
                showHideTransition
            )
        }
      );