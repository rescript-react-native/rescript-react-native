external tabBarItemIOS : ReasonReact.reactClass =
  "Item" [@@bs.scope "TabBarIOS"] [@@bs.module "react-native"];

let make
    title::(title: option string)=?
    badgeColor::(badgeColor: option string)=?
    ::badge=?
    ::icon=?
    ::onPress=?
    ::renderAsOriginal=?
    ::style=?
    ::selected=?
    ::selectedIcon=?
    ::isTVSelectable=? =>
  ReasonReact.wrapJsForReason
    reactClass::tabBarItemIOS
    props::
      Js.Undefined.(
        {
          "badgeColor": from_opt badgeColor,
          "title": from_opt title,
          "badge": from_opt badge,
          "icon": from_opt icon,
          "onPress": from_opt onPress,
          "renderAsOriginal": from_opt (UtilsRN.optBoolToOptJsBoolean renderAsOriginal),
          "selected": from_opt (UtilsRN.optBoolToOptJsBoolean selected),
          "selectedIcon": from_opt selectedIcon,
          "style": from_opt style,
          "isTVSelectable": from_opt (UtilsRN.optBoolToOptJsBoolean isTVSelectable)
        }
      );
