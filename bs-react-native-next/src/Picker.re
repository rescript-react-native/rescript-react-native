[@react.component] [@bs.module "react-native"]
// value == string || float
external make:
  (
    ~onValueChange: ('a, int) => unit=?,
    ~selectedValue: 'a=?,
    ~enabled: bool=?,
    // Android only
    ~mode: [@bs.string] [ | `dialog | `dropdown]=?,
    ~prompt: string=?,
    // iOS only
    ~itemStyle: Style.t=?,
    // View Props
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityElementsHidden: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: React.element=?,
    ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]=?,
    ~accessibilityRole: [@bs.string] [
                          | `none
                          | `button
                          | `link
                          | `search
                          | `image
                          | `keyboardkey
                          | `text
                          | `adjustable
                          | `header
                          | `summary
                          | `imagebutton
                        ]
                          =?,
    ~accessibilityStates: array(Types.AccessibilityState.t)=?,
    ~accessibilityTraits: array(Types.AccessibilityTrait.t)=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~collapsable: bool=?,
    ~hitSlop: Types.insets=?,
    ~importantForAccessibility: [@bs.string] [
                                  | `auto
                                  | `yes
                                  | `no
                                  | [@bs.as "no-hide-descendants"]
                                    `noHideDescendants
                                ]
                                  =?,
    ~nativeID: string=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~onMoveShouldSetResponder: Event.NativeEvent.t => bool=?,
    ~onMoveShouldSetResponderCapture: Event.NativeEvent.t => bool=?,
    ~onResponderGrant: Event.NativeEvent.t => unit=?,
    ~onResponderMove: Event.NativeEvent.t => unit=?,
    ~onResponderReject: Event.NativeEvent.t => unit=?,
    ~onResponderRelease: Event.NativeEvent.t => unit=?,
    ~onResponderTerminate: Event.NativeEvent.t => unit=?,
    ~onResponderTerminationRequest: Event.NativeEvent.t => unit=?,
    ~onStartShouldSetResponder: Event.NativeEvent.t => bool=?,
    ~onStartShouldSetResponderCapture: Event.NativeEvent.t => bool=?,
    ~pointerEvents: [@bs.string] [
                      | `auto
                      | `none
                      | [@bs.as "box-none"] `boxNone
                      | [@bs.as "box-only"] `boxOnly
                    ]
                      =?,
    ~removeClippedSubviews: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Picker";

module Item = {
  [@react.component] [@bs.module "react-native"] [@bs.scope "Picker"]
  external make:
    (~value: 'a=?, ~label: string, ~color: Style.color=?, ~testID: string=?) =>
    React.element =
    "Item";
};
