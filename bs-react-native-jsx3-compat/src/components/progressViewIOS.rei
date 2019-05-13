/**
 Use [ProgressViewIOS] {{:https://facebook.github.io/react-native/docs/progressviewios}} to render a [UIProgressView] on iOS.

 {3 Example of use}
  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self => <ProgressViewIOS progress=0.4 progressTintColor="tomato" />,
    };
  ]}

 {3 Props}
 {{:\BsReactNative/View-BsReactNative} [View] props}
 {4 progress}
 {[
   ~progress: float
 ]}
 {4 progressImage}
 {[
   ~progressImage: Image.imageSource=?
 ]}
 {4 progressTintColor}
 {[
   ~progressTintColor: ReactNative.Color.t=?
 ]}
 {4 progressViewStyle}
 {[
   ~progressViewStyle: Style.t=?
 ]}
 {4 trackImage}
 {[
   trackImage: Image.imageSource=?
 ]}
 {4 trackTintColor}
 {[
   ~trackTintColor: ReactNative.Color.t=?
 ]}
*/

[@react.component]
let make:
  (
    ~progress: float,
    ~progressImage: Image.imageSource=?,
    ~progressTintColor: ReactNative.Color.t=?,
    ~progressViewStyle: [ | `default | `bar]=?,
    ~trackImage: Image.imageSource=?,
    ~trackTintColor: ReactNative.Color.t=?,
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: Types.pointerEvents=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: Types.accessibilityComponentType=?,
    ~accessibilityLiveRegion: Types.accessibilityLiveRegion=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: Types.importantForAccessibility=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(Types.accessibilityTrait)=?,
    ~accessibilityRole: Types.accessibilityRole=?,
    ~accessibilityStates: list(Types.accessibilityState)=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    unit
  ) =>
  React.element;
