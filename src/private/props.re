let serialize = (handlers: option(Types.touchResponderHandlers)) =>
  switch (handlers) {
  | None => Js.Obj.empty()
  | Some(handlers) =>
    Js.Undefined.(
      {
        "onMoveShouldSetResponder":
          fromOption(
            UtilsRN.option_map(
              (g, x) => g(x),
              handlers.onMoveShouldSetResponder,
            ),
          ),
        "onMoveShouldSetResponderCapture":
          fromOption(
            UtilsRN.option_map(
              (g, x) => g(x),
              handlers.onMoveShouldSetResponderCapture,
            ),
          ),
        "onResponderGrant": fromOption(handlers.onResponderGrant),
        "onResponderMove": fromOption(handlers.onResponderMove),
        "onResponderReject": fromOption(handlers.onResponderReject),
        "onResponderRelease": fromOption(handlers.onResponderRelease),
        "onResponderTerminate": fromOption(handlers.onResponderTerminate),
        "onResponderTerminationRequest":
          fromOption(handlers.onResponderTerminationRequest),
        "onStartShouldSetResponder":
          fromOption(
            UtilsRN.option_map(
              (g, x) => g(x),
              handlers.onStartShouldSetResponder,
            ),
          ),
        "onStartShouldSetResponderCapture":
          fromOption(
            UtilsRN.option_map(
              (g, x) => g(x),
              handlers.onStartShouldSetResponderCapture,
            ),
          ),
      }
    )
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
    Js.Undefined.(
      {
        "accessibilityLabel": fromOption(accessibilityLabel),
        "accessible": fromOption(UtilsRN.optBoolToOptJsBoolean(accessible)),
        "hitSlop": fromOption(hitSlop),
        "onAccessibilityTap": fromOption(onAccessibilityTap),
        "onLayout": fromOption(onLayout),
        "onMagicTap": fromOption(onMagicTap),
        "removeClippedSubviews":
          fromOption(UtilsRN.optBoolToOptJsBoolean(removeClippedSubviews)),
        "pointerEvents":
          fromOption(
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
          ),
        "style": fromOption(style),
        "testID": fromOption(testID),
        "accessibilityComponentType":
          fromOption(
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
          ),
        "accessibilityLiveRegion":
          fromOption(
            UtilsRN.option_map(
              x =>
                switch (x) {
                | `polite => "polite"
                | `none => "none"
                | `assertive => "assertive"
                },
              accessibilityLiveRegion,
            ),
          ),
        "collapsable":
          fromOption(UtilsRN.optBoolToOptJsBoolean(collapsable)),
        "importantForAccessibility":
          fromOption(
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
          ),
        "needsOffscreenAlphaCompositing":
          fromOption(
            UtilsRN.optBoolToOptJsBoolean(needsOffscreenAlphaCompositing),
          ),
        "renderToHardwareTextureAndroid":
          fromOption(
            UtilsRN.optBoolToOptJsBoolean(renderToHardwareTextureAndroid),
          ),
        "accessibilityTraits":
          fromOption(
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
          ),
        "accessibilityViewIsModal":
          fromOption(
            UtilsRN.optBoolToOptJsBoolean(accessibilityViewIsModal),
          ),
        "shouldRasterizeIOS":
          fromOption(UtilsRN.optBoolToOptJsBoolean(shouldRasterizeIOS)),
      }
    ),
    moreProps,
    serialize(responderHandlers),
  );