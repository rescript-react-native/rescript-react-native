type touchResponderHandlers = {
  onMoveShouldSetResponder: option (RNEvent.NativeEvent.t => bool),
  onMoveShouldSetResponderCapture: option (RNEvent.NativeEvent.t => bool),
  onResponderGrant: option (RNEvent.NativeEvent.t => unit),
  onResponderMove: option (RNEvent.NativeEvent.t => unit),
  onResponderReject: option (RNEvent.NativeEvent.t => unit),
  onResponderRelease: option (RNEvent.NativeEvent.t => unit),
  onResponderTerminate: option (RNEvent.NativeEvent.t => unit),
  onResponderTerminationRequest: option (RNEvent.NativeEvent.t => unit),
  onStartShouldSetResponder: option (RNEvent.NativeEvent.t => bool),
  onStartShouldSetResponderCapture: option (RNEvent.NativeEvent.t => bool)
};

let serialize (handlers: option touchResponderHandlers) =>
  switch handlers {
  | None => Js.Obj.empty ()
  | Some handlers =>
    Js.Undefined.(
      {
        "onMoveShouldSetResponder":
          from_opt (
            UtilsRN.option_map
              (fun g x => Js.Boolean.to_js_boolean (g x)) handlers.onMoveShouldSetResponder
          ),
        "onMoveShouldSetResponderCapture":
          from_opt (
            UtilsRN.option_map
              (fun g x => Js.Boolean.to_js_boolean (g x)) handlers.onMoveShouldSetResponderCapture
          ),
        "onResponderGrant": from_opt handlers.onResponderGrant,
        "onResponderMove": from_opt handlers.onResponderMove,
        "onResponderReject": from_opt handlers.onResponderReject,
        "onResponderRelease": from_opt handlers.onResponderRelease,
        "onResponderTerminate": from_opt handlers.onResponderTerminate,
        "onResponderTerminationRequest": from_opt handlers.onResponderTerminationRequest,
        "onStartShouldSetResponder":
          from_opt (
            UtilsRN.option_map
              (fun g x => Js.Boolean.to_js_boolean (g x)) handlers.onStartShouldSetResponder
          ),
        "onStartShouldSetResponderCapture":
          from_opt (
            UtilsRN.option_map
              (fun g x => Js.Boolean.to_js_boolean (g x)) handlers.onStartShouldSetResponderCapture
          )
      }
    )
  };

let extendView
    ::accessibilityLabel=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::responderHandlers=?
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
    ::shouldRasterizeIOS=?
    moreProps =>
  UtilsRN.objAssign2
    Js.Undefined.(
      {
        "accessibilityLabel": from_opt accessibilityLabel,
        "accessible": from_opt (UtilsRN.optBoolToOptJsBoolean accessible),
        "hitSlop": from_opt hitSlop,
        "onAccessibilityTap": from_opt onAccessibilityTap,
        "onLayout": from_opt onLayout,
        "onMagicTap": from_opt onMagicTap,
        "removeClippedSubviews": from_opt (UtilsRN.optBoolToOptJsBoolean removeClippedSubviews),
        "pointerEvents":
          from_opt (
            UtilsRN.option_map
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
            UtilsRN.option_map
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
            UtilsRN.option_map
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
        "collapsable": from_opt (UtilsRN.optBoolToOptJsBoolean collapsable),
        "importantForAccessibility":
          from_opt (
            UtilsRN.option_map
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
          from_opt (UtilsRN.optBoolToOptJsBoolean needsOffscreenAlphaCompositing),
        "renderToHardwareTextureAndroid":
          from_opt (UtilsRN.optBoolToOptJsBoolean renderToHardwareTextureAndroid),
        "accessibilityTraits":
          from_opt (
            UtilsRN.option_map
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
        "accessibilityViewIsModal":
          from_opt (UtilsRN.optBoolToOptJsBoolean accessibilityViewIsModal),
        "shouldRasterizeIOS": from_opt (UtilsRN.optBoolToOptJsBoolean shouldRasterizeIOS)
      }
    )
    moreProps
    (serialize responderHandlers);
