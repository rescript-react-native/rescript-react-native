open Utils;

external view : ReactRe.reactClass = "View" [@@bs.module "react-native"];

type hitSlop = {left: int, right: int, top: int, bottom: int};

let createElement
    ::accessibleLeft=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::onMoveShouldSetResponder=?
    ::onMoveShouldSetResponderCapture=?
    ::onResponderGrant=?
    ::onResponderMove=?
    ::onResponderReject=?
    ::onResponderRelease=?
    ::onResponderTerminate=?
    ::onResponderTerminationRequest=?
    ::onStartShouldSetResponder=?
    ::onStartShouldSetResponderCapture=?
    ::pointerEvents=?
    ::removeClippedSubviews=?
    ::style=?
    ::testID=?
    ::accessibilityComponentType=?
    ::accessibilityLiveRegion=?
    ::collapsable=?
    ::importantForAccessibility=?
    ::needsOffscreenAlphaCompositing=?
    ::renderToHardwareTextureAndroid=?
    ::accessibilityTraits=?
    ::accessibilityViewIsModal=?
    ::shouldRasterizeIOS=? =>
  ReactRe.wrapPropsShamelessly
    view
    {
      "accessibleLeft": from_opt accessibleLeft,
      "accessible": from_opt (option_map to_js_boolean accessible),
      "hitSlop": from_opt (option_map (fun {left} => {"left": left}) hitSlop),
      "onAccessibilityTap": from_opt onAccessibilityTap,
      "onLayout": from_opt onLayout,
      "onMagicTap": from_opt onMagicTap,
      "onMoveShouldSetResponder":
        from_opt (option_map ((<<) to_js_boolean) onMoveShouldSetResponder),
      "onMoveShouldSetResponderCapture":
        from_opt (option_map ((<<) to_js_boolean) onMoveShouldSetResponderCapture),
      "onResponderGrant": from_opt onResponderGrant,
      "onResponderMove": from_opt onResponderMove,
      "onResponderReject": from_opt onResponderReject,
      "onResponderRelease": from_opt onResponderRelease,
      "onResponderTerminate": from_opt onResponderTerminate,
      "onResponderTerminationRequest": from_opt onResponderTerminationRequest,
      "onStartShouldSetResponder":
        from_opt (option_map ((<<) to_js_boolean) onStartShouldSetResponder),
      "onStartShouldSetResponderCapture":
        from_opt (option_map ((<<) to_js_boolean) onStartShouldSetResponderCapture),
      "removeClippedSubviews": from_opt (option_map to_js_boolean removeClippedSubviews),
      "pointerEvents":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `auto => "auto"
                | `none => "none"
                | `boxNone => "box-none"
                | `boxOnly => "box-only"
                }
            )
            pointerEvents
        ),
      "style": from_opt style,
      "testID": from_opt testID,
      "accessibilityComponentType":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `none => "none"
                | `button => "button"
                | `radiobutton_checked => "radiobutton_checked-none"
                | `radiobutton_unchecked => "radiobutton_unchecked"
                }
            )
            accessibilityComponentType
        ),
      "accessibilityLiveRegion":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `polite => "polite"
                | `none => "none"
                | `assertive => "assertive"
                }
            )
            accessibilityLiveRegion
        ),
      "collapsable": from_opt (option_map to_js_boolean collapsable),
      "importantForAccessibility":
        from_opt (
          option_map
            (
              fun prop =>
                switch prop {
                | `auto => "auto"
                | `yes => "yes"
                | `no => "no"
                | `noHideDescendants => "noHideDescendants"
                }
            )
            importantForAccessibility
        ),
      "needsOffscreenAlphaCompositing":
        from_opt (option_map to_js_boolean needsOffscreenAlphaCompositing),
      "renderToHardwareTextureAndroid":
        from_opt (option_map to_js_boolean renderToHardwareTextureAndroid),
      "accessibilityTraits":
        from_opt (
          option_map
            (
              fun traits => {
                let to_string =
                  fun
                  | `none => "none"
                  | `button => "button"
                  | `link => "link"
                  | `header => "header"
                  | `search => "search"
                  | `image => "image"
                  | `selected => "selected"
                  | `plays => "plays"
                  | `key => "key"
                  | `text => "text"
                  | `summary => "summary"
                  | `disabled => "disabled"
                  | `frequentUpdates => "frequentUpdates"
                  | `startsMedia => "startsMedia"
                  | `adjustable => "adjustable"
                  | `allowsDirectInteraction => "allowsDirectInteraction"
                  | `pageTurn => "pageTurn";
                traits |> List.map to_string |> Array.of_list
              }
            )
            accessibilityTraits
        ),
      "accessibilityViewIsModal": from_opt (option_map to_js_boolean accessibilityViewIsModal),
      "shouldRasterizeIOS": from_opt (option_map to_js_boolean shouldRasterizeIOS)
    };