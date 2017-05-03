external view : ReactRe.reactClass = "View" [@@bs.module "react-native"];

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
    Js.Undefined.(
      {
        "accessibleLeft": from_opt accessibleLeft,
        "accessible": from_opt (Utils.optBoolToOptJsBoolean accessible),
        "hitSlop": from_opt hitSlop,
        "onAccessibilityTap": from_opt onAccessibilityTap,
        "onLayout": from_opt onLayout,
        "onMagicTap": from_opt onMagicTap,
        "onMoveShouldSetResponder":
          from_opt (Utils.option_map (fun g x => (Js.Boolean.to_js_boolean (g x))) onMoveShouldSetResponder),
        "onMoveShouldSetResponderCapture":
          from_opt (Utils.option_map (fun g x => (Js.Boolean.to_js_boolean (g x))) onMoveShouldSetResponderCapture),
        "onResponderGrant": from_opt onResponderGrant,
        "onResponderMove": from_opt onResponderMove,
        "onResponderReject": from_opt onResponderReject,
        "onResponderRelease": from_opt onResponderRelease,
        "onResponderTerminate": from_opt onResponderTerminate,
        "onResponderTerminationRequest": from_opt onResponderTerminationRequest,
        "onStartShouldSetResponder":
          from_opt (Utils.option_map (fun g x => (Js.Boolean.to_js_boolean (g x))) onStartShouldSetResponder),
        "onStartShouldSetResponderCapture":
          from_opt (Utils.option_map (fun g x => (Js.Boolean.to_js_boolean (g x))) onStartShouldSetResponderCapture),
        "removeClippedSubviews": from_opt (Utils.optBoolToOptJsBoolean removeClippedSubviews),
        "pointerEvents":
          from_opt (
            Utils.option_map
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
            Utils.option_map
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
            Utils.option_map
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
        "collapsable": from_opt (Utils.optBoolToOptJsBoolean collapsable),
        "importantForAccessibility":
          from_opt (
            Utils.option_map
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
          from_opt (Utils.optBoolToOptJsBoolean needsOffscreenAlphaCompositing),
        "renderToHardwareTextureAndroid":
          from_opt (Utils.optBoolToOptJsBoolean renderToHardwareTextureAndroid),
        "accessibilityTraits":
          from_opt (
            Utils.option_map
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
        "accessibilityViewIsModal": from_opt (Utils.optBoolToOptJsBoolean accessibilityViewIsModal),
        "shouldRasterizeIOS": from_opt (Utils.optBoolToOptJsBoolean shouldRasterizeIOS)
      }
    );