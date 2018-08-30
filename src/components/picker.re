[@bs.module "react-native"] external view : ReasonReact.reactClass = "Picker";

module Item = {
  [@bs.scope "Picker"] [@bs.module "react-native"]
  external item : ReasonReact.reactClass = "Item";
  let make = (~color=?, ~label, ~value=?, ~testID=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        Js.Undefined.(
          {
            "label": label,
            "value": fromOption(value),
            "color": fromOption(color),
            "testID": fromOption(testID),
          }
        ),
    );
};

let encodeMode = x =>
  switch (x) {
  | `dialog => "dialog"
  | `dropdown => "dropdown"
  };

let make =
    (
      ~onValueChange=?,
      ~selectedValue=?,
      ~enabled=?,
      ~mode=?,
      ~prompt=?,
      ~itemStyle=?,
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
            "enabled": fromOption(enabled),
            "onValueChange": fromOption(onValueChange),
            "selectedValue": fromOption(selectedValue),
            "itemStyle": fromOption(itemStyle),
            "prompt": fromOption(prompt),
            "mode": fromOption(UtilsRN.option_map(encodeMode, mode)),
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