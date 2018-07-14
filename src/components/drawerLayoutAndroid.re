[@bs.module "react-native"]
external view : ReasonReact.reactClass = "DrawerLayoutAndroid";
[@bs.module "react-native"] [@bs.scope "DrawerLayoutAndroid"]
external positions : Js.Dict.t(int) = "";

[@bs.send] external openDrawer : ReasonReact.reactRef => unit = "";
[@bs.send] external closeDrawer : ReasonReact.reactRef => unit = "";

let make =
    (
      ~renderNavigationView,
      ~onDrawerClose=?,
      ~onDrawerOpen=?,
      ~onDrawerSlide=?,
      ~onDrawerStateChanged=?,
      ~drawerWidth=?,
      ~drawerPosition=?,
      ~keyboardDismissMode=?,
      ~drawerLockMode=?,
      ~drawerBackgroundColor=?,
      ~statusBarBackgroundColor=?,
      /* view props */
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~style=?,
      ~testID=?,
      ~accessibilityComponentType=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityTraits=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "renderNavigationView": renderNavigationView,
            "onDrawerClose": fromOption(onDrawerClose),
            "onDrawerOpen": fromOption(onDrawerOpen),
            "onDrawerSlide": fromOption(onDrawerSlide),
            "onDrawerStateChanged": fromOption(onDrawerStateChanged),
            "drawerWidth": fromOption(drawerWidth),
            "drawerPosition":
              fromOption(
                UtilsRN.option_map(
                  fun
                  | `left => fromOption(Js.Dict.get(positions, "Left"))
                  | `right => fromOption(Js.Dict.get(positions, "Right")),
                  drawerPosition,
                ),
              ),
            "keyboardDismissMode":
              fromOption(
                UtilsRN.option_map(
                  fun
                  | `none => "none"
                  | `onDrag => "on-drag",
                  keyboardDismissMode,
                ),
              ),
            "drawerLockMode":
              fromOption(
                UtilsRN.option_map(
                  fun
                  | `unlocked => "unlocked"
                  | `lockedClosed => "locked-closed"
                  | `lockedOpen => "locked-open",
                  drawerLockMode,
                ),
              ),
            "drawerBackgroundColor": fromOption(drawerBackgroundColor),
            "statusBarBackgroundColor": fromOption(statusBarBackgroundColor),
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
        ~shouldRasterizeIOS?,
      ),
  );