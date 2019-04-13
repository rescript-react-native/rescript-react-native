[@react.component] [@bs.module "react-native"]
external make:
  (
    ~disabled: bool=?,
    ~trackColor: Style.color=?,
    ~ios_backgroundColor: Style.color=?,
    ~onValueChange: bool => unit=?,
    ~thumbColor: Style.color=?,
    ~tintColor: Style.color=?,
    ~value: bool=?,
    // View props
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
    ~accessibilityLabel: string=?,
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
    ~accessibilityStates: array(AccessibilityState.t)=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
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
    ~testID: string=?
  ) =>
  React.element =
  "Switch";
