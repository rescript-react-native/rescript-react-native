module Item = {
  [@bs.scope "TabBarIOS"] [@bs.module "react-native"]
  external tabBarItemIOS : ReasonReact.reactClass = "Item";
  let make =
      (
        ~title: option(string)=?,
        ~badgeColor: option(string)=?,
        ~badge=?,
        ~icon=?,
        ~onPress=?,
        ~renderAsOriginal=?,
        ~style=?,
        ~selected=?,
        ~selectedIcon=?,
        ~isTVSelectable=?,
        ~accessibilityLabel=?,
        ~accessible=?,
        ~hitSlop=?,
        ~onAccessibilityTap=?,
        ~onLayout=?,
        ~onMagicTap=?,
        ~responderHandlers=?,
        ~pointerEvents=?,
        ~removeClippedSubviews=?,
        ~testID=?,
        ~accessibilityComponentType=?,
        ~accessibilityLiveRegion=?,
        ~collapsable=?,
        ~importantForAccessibility=?,
        ~needsOffscreenAlphaCompositing=?,
        ~renderToHardwareTextureAndroid=?,
        ~accessibilityTraits=?,
        ~accessibilityViewIsModal=?,
        ~shouldRasterizeIOS=?
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=tabBarItemIOS,
      ~props=
        Props.extendView(
          Js.Undefined.(
            {
              "badgeColor": fromOption(badgeColor),
              "title": fromOption(title),
              "badge": fromOption(badge),
              "icon": fromOption(icon),
              "onPress": fromOption(onPress),
              "renderAsOriginal":
                fromOption(UtilsRN.optBoolToOptJsBoolean(renderAsOriginal)),
              "selected": fromOption(UtilsRN.optBoolToOptJsBoolean(selected)),
              "selectedIcon": fromOption(selectedIcon),
              "style": fromOption(style),
              "isTVSelectable":
                fromOption(UtilsRN.optBoolToOptJsBoolean(isTVSelectable))
            }
          ),
          ~accessibilityLabel?,
          ~accessible?,
          ~hitSlop?,
          ~onAccessibilityTap?,
          ~onLayout?,
          ~onMagicTap?,
          ~responderHandlers?,
          ~pointerEvents?,
          ~removeClippedSubviews?,
          ~style?,
          ~testID?,
          ~accessibilityComponentType?,
          ~accessibilityLiveRegion?,
          ~collapsable?,
          ~importantForAccessibility?,
          ~needsOffscreenAlphaCompositing?,
          ~renderToHardwareTextureAndroid?,
          ~accessibilityTraits?,
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?
        )
    );
};

[@bs.module "react-native"]
external tabBarIOS : ReasonReact.reactClass = "TabBarIOS";

let make =
    (
      ~barTintColor=?,
      ~itemPositioning=?,
      ~style=?,
      ~tintColor=?,
      ~translucent=?,
      ~unselectedItemTintColor=?,
      ~unselectedTintColor=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~testID=?,
      ~accessibilityComponentType=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityTraits=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=tabBarIOS,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "barTintColor": fromOption(barTintColor),
            "itemPositioning":
              fromOption(
                UtilsRN.option_map(
                  x =>
                    switch x {
                    | `fill => "fill"
                    | `center => "center"
                    | `auto => "auto"
                    },
                  itemPositioning
                )
              ),
            "tintColor": fromOption(tintColor),
            "translucent":
              fromOption(UtilsRN.optBoolToOptJsBoolean(translucent)),
            "unselectedItemTintColor": fromOption(unselectedItemTintColor),
            "unselectedTintColor": fromOption(unselectedTintColor)
          }
        ),
        ~accessibilityLabel?,
        ~accessible?,
        ~hitSlop?,
        ~onAccessibilityTap?,
        ~onLayout?,
        ~onMagicTap?,
        ~responderHandlers?,
        ~pointerEvents?,
        ~removeClippedSubviews?,
        ~style?,
        ~testID?,
        ~accessibilityComponentType?,
        ~accessibilityLiveRegion?,
        ~collapsable?,
        ~importantForAccessibility?,
        ~needsOffscreenAlphaCompositing?,
        ~renderToHardwareTextureAndroid?,
        ~accessibilityTraits?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?
      )
  );
