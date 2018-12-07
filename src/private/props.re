let serialize = (handlers: option(Types.touchResponderHandlers)) =>
  switch (handlers) {
  | None => Js.Obj.empty()
  | Some(handlers) => Types.{
      "onMoveShouldSetResponder":
        UtilsRN.option_map(
          (g, x) => g(x),
          handlers.onMoveShouldSetResponder,
        ),
      "onMoveShouldSetResponderCapture":
        UtilsRN.option_map(
          (g, x) => g(x),
          handlers.onMoveShouldSetResponderCapture,
        ),
      "onResponderGrant": handlers.onResponderGrant,
      "onResponderMove": handlers.onResponderMove,
      "onResponderReject": handlers.onResponderReject,
      "onResponderRelease": handlers.onResponderRelease,
      "onResponderTerminate": handlers.onResponderTerminate,
      "onResponderTerminationRequest": handlers.onResponderTerminationRequest,
      "onStartShouldSetResponder":
        UtilsRN.option_map(
          (g, x) => g(x),
          handlers.onStartShouldSetResponder,
        ),
      "onStartShouldSetResponderCapture":
        UtilsRN.option_map(
          (g, x) => g(x),
          handlers.onStartShouldSetResponderCapture,
        ),
    }
  };

let extendView =
    (
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
      moreProps,
    ) =>
  UtilsRN.objAssign2(
    {
      "accessibilityLabel": accessibilityLabel,
      "accessible": accessible,
      "hitSlop": hitSlop,
      "onAccessibilityTap": onAccessibilityTap,
      "onLayout": onLayout,
      "onMagicTap": onMagicTap,
      "removeClippedSubviews": removeClippedSubviews,
      "pointerEvents":
        UtilsRN.option_map(
          x =>
            switch (x) {
            | `auto => "auto"
            | `none => "none"
            | `boxNone => "box-none"
            | `boxOnly => "box-only"
            },
          pointerEvents,
        ),
      "style": style,
      "testID": testID,
      "accessibilityComponentType":
        UtilsRN.option_map(
          x =>
            switch (x) {
            | `none => "none"
            | `button => "button"
            | `radiobutton_checked => "radiobutton_checked-none"
            | `radiobutton_unchecked => "radiobutton_unchecked"
            },
          accessibilityComponentType,
        ),
      "accessibilityLiveRegion":
        UtilsRN.option_map(
          x =>
            switch (x) {
            | `polite => "polite"
            | `none => "none"
            | `assertive => "assertive"
            },
          accessibilityLiveRegion,
        ),
      "collapsable": collapsable,
      "importantForAccessibility":
        UtilsRN.option_map(
          prop =>
            switch (prop) {
            | `auto => "auto"
            | `yes => "yes"
            | `no => "no"
            | `noHideDescendants => "noHideDescendants"
            },
          importantForAccessibility,
        ),
      "needsOffscreenAlphaCompositing": needsOffscreenAlphaCompositing,
      "renderToHardwareTextureAndroid": renderToHardwareTextureAndroid,
      "accessibilityTraits":
        UtilsRN.option_map(
          traits => {
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
            traits |> List.map(to_string) |> Array.of_list;
          },
          accessibilityTraits,
        ),
      "accessibilityViewIsModal": accessibilityViewIsModal,
      "shouldRasterizeIOS": shouldRasterizeIOS,
    },
    moreProps,
    serialize(responderHandlers),
  );
