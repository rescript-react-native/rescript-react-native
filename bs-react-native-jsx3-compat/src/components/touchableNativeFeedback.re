type t = ReactNative.TouchableNativeFeedback.Background.t;

[@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
external selectableBackground: unit => t = "SelectableBackground";

[@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
external selectableBackgroundBorderless: unit => t =
  "SelectableBackgroundBorderless";

[@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
external canUseNativeForeground: unit => t = "CanUseNativeForeground";

[@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
external ripple: (string, bool) => t = "Ripple";

[@react.component]
let make =
    (
      ~accessible=?,
      ~accessibilityLabel=?,
      ~accessibilityComponentType=?,
      ~accessibilityTraits=?,
      ~accessibilityRole=?,
      ~accessibilityStates=?,
      ~accessibilityHint=?,
      ~accessibilityIgnoresInvertColors=?,
      ~delayLongPress=?,
      ~delayPressIn=?,
      ~delayPressOut=?,
      ~disabled=?,
      ~hitSlop=?,
      ~onLayout=?,
      ~onLongPress=?,
      ~onPress=?,
      ~onPressIn=?,
      ~onPressOut=?,
      ~pressRetentionOffset=?,
      ~background=?,
      ~useForeground=?,
      ~testID=?,
      ~children=?,
    ) =>
  <ReactNative.TouchableNativeFeedback
    ?background
    ?useForeground
    ?accessible
    ?accessibilityLabel
    ?delayLongPress
    ?delayPressIn
    ?delayPressOut
    ?disabled
    hitSlop=?{Types.toEdgeInsets(hitSlop)}
    ?onLayout
    ?onLongPress
    ?onPress
    ?onPressIn
    ?onPressOut
    pressRetentionOffset=?{Types.toEdgeInsets(pressRetentionOffset)}
    ?accessibilityComponentType
    accessibilityTraits=?{
      accessibilityTraits->Belt.Option.map(Belt.List.toArray)
    }
    ?accessibilityRole
    accessibilityStates=?{
      accessibilityStates->Belt.Option.map(Belt.List.toArray)
    }
    ?accessibilityHint
    ?accessibilityIgnoresInvertColors
    ?testID>
    {children->Belt.Option.getWithDefault(React.null)}
  </ReactNative.TouchableNativeFeedback>;
