external tabBarIOS : ReasonReact.reactClass = "TabBarIOS" [@@bs.module "react-native"];

let make
    ::barTintColor=?
    ::itemPositioning=?
    ::style=?
    ::tintColor=?
    ::translucent=?
    ::unselectedItemTintColor=?
    ::unselectedTintColor=? =>
  ReasonReact.wrapJsForReason
    reactClass::tabBarIOS
    props::
      Js.Undefined.(
        {
          "barTintColor": from_opt barTintColor,
          "itemPositioning":
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
                itemPositioning
            ),
          "style": from_opt style,
          "tintColor": from_opt tintColor,
          "translucent": from_opt (UtilsRN.optBoolToOptJsBoolean translucent),
          "unselectedItemTintColor": from_opt unselectedItemTintColor,
          "unselectedTintColor": from_opt unselectedTintColor
        }
      );
