[@react.component] [@bs.module "react-native"]
// View props
external make:
  (
    ~keyboardVerticalOffset: float=?,
    ~behavior: [@bs.string] [ | `height | `position | `padding]=?,
    ~contentContainerStyle: Style.t=?,
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
    ~onMoveShouldSetResponder: Event.t => bool=?,
    ~onMoveShouldSetResponderCapture: Event.t => bool=?,
    ~onResponderGrant: Event.t => unit=?,
    ~onResponderMove: Event.t => unit=?,
    ~onResponderReject: Event.t => unit=?,
    ~onResponderRelease: Event.t => unit=?,
    ~onResponderTerminate: Event.t => unit=?,
    ~onResponderTerminationRequest: Event.t => unit=?,
    ~onStartShouldSetResponder: Event.t => bool=?,
    ~onStartShouldSetResponderCapture: Event.t => bool=?,
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
    // Children
    ~children: React.element=?
  ) =>
  React.element =
  "KeyboardAvoidingView";
