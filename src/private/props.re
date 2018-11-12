let serialize = (handlers: option(Types.touchResponderHandlers)) =>
  switch (handlers) {
  | None => Js.Obj.empty()
  | Some(handlers) => {
      "onMoveShouldSetResponder": UtilsRN.option_map((g, x) => g(x), handlers.onMoveShouldSetResponder),
      "onMoveShouldSetResponderCapture":
        UtilsRN.option_map((g, x) => g(x), handlers.onMoveShouldSetResponderCapture),
      "onResponderGrant": handlers.onResponderGrant,
      "onResponderMove": handlers.onResponderMove,
      "onResponderReject": handlers.onResponderReject,
      "onResponderRelease": handlers.onResponderRelease,
      "onResponderTerminate": handlers.onResponderTerminate,
      "onResponderTerminationRequest": handlers.onResponderTerminationRequest,
      "onStartShouldSetResponder": UtilsRN.option_map((g, x) => g(x), handlers.onStartShouldSetResponder),
      "onStartShouldSetResponderCapture":
        UtilsRN.option_map((g, x) => g(x), handlers.onStartShouldSetResponderCapture),
    }
  };

[@bs.deriving abstract]
type viewProps = {
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  accessible: bool,
  [@bs.optional]
  hitSlop: Types.insets,
  [@bs.optional]
  onAccessibilityTap: unit => unit,
  [@bs.optional]
  onLayout: RNEvent.NativeLayoutEvent.t => unit,
  [@bs.optional]
  onMagicTap: unit => unit,
  [@bs.optional]
  removeClippedSubviews: bool,
  [@bs.optional]
  responderHandlers: Types.touchResponderHandlers,
  [@bs.optional]
  pointerEvents: string,
  [@bs.optional]
  style: Style.t,
  [@bs.optional]
  testID: string,
  [@bs.optional]
  accessibilityComponentType: string,
  [@bs.optional]
  accessibilityLiveRegion: string,
  [@bs.optional]
  collapsable: bool,
  [@bs.optional]
  importantForAccessibility: string,
  [@bs.optional]
  needsOffscreenAlphaCompositing: bool,
  [@bs.optional]
  renderToHardwareTextureAndroid: bool,
  [@bs.optional]
  accessibilityTraits: array(string),
  [@bs.optional]
  accessibilityViewIsModal: bool,
  [@bs.optional]
  shouldRasterizeIOS: bool,
  [@bs.optional]
  keyboardVerticalOffset: int,
  [@bs.optional]
  behavior: string,
  [@bs.optional]
  contentContainerStyle: Style.t,
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
    ) => {
  let viewProps =
    viewProps(
      ~accessibilityLabel?,
      ~accessible?,
      ~hitSlop?,
      ~onAccessibilityTap?,
      ~onLayout?,
      ~onMagicTap?,
      ~removeClippedSubviews?,
      ~pointerEvents=?
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
      ~style?,
      ~testID?,
      ~accessibilityComponentType=?
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
      ~accessibilityLiveRegion=?
        UtilsRN.option_map(
          x =>
            switch (x) {
            | `polite => "polite"
            | `none => "none"
            | `assertive => "assertive"
            },
          accessibilityLiveRegion,
        ),
      ~collapsable?,
      ~importantForAccessibility=?
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
      ~needsOffscreenAlphaCompositing?,
      ~renderToHardwareTextureAndroid?,
      ~accessibilityTraits=?
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
      ~accessibilityViewIsModal?,
      ~shouldRasterizeIOS?,
      (),
    )
    ->Obj.magic;

  UtilsRN.objAssign2(viewProps, moreProps, serialize(responderHandlers));
};
