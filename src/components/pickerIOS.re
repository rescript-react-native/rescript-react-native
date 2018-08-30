[@bs.module "react-native"]
external pickerIOS : ReasonReact.reactClass = "PickerIOS";

module Item = {
  [@bs.scope "PickerIOS"] [@bs.module "react-native"]
  external item : ReasonReact.reactClass = "Item";
  let make = (~label, ~value=?, ~color=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        Js.Undefined.(
          {
            "label": label,
            "value": fromOption(value),
            "color": fromOption(color),
          }
        ),
    );
};

let make =
    (
      ~itemStyle=?,
      ~onValueChange=?,
      ~selectedValue=?,
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
    ~reactClass=pickerIOS,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "itemStyle": fromOption(itemStyle),
            "onValueChange": fromOption(onValueChange),
            "selectedValue": fromOption(selectedValue),
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