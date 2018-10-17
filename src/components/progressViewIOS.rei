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
   ~progressTintColor: string=?
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
   ~trackTintColor: string=?
 ]}
*/

let make:
  (
    ~progress: float,
    ~progressImage: Image.imageSource=?,
    ~progressTintColor: string=?,
    ~progressViewStyle: Style.t=?,
    ~trackImage: Image.imageSource=?,
    ~trackTintColor: string=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(
                            [
                              | `none
                              | `button
                              | `link
                              | `header
                              | `search
                              | `image
                              | `selected
                              | `plays
                              | `key
                              | `text
                              | `summary
                              | `disabled
                              | `frequentUpdates
                              | `startsMedia
                              | `adjustable
                              | `allowsDirectInteraction
                              | `pageTurn
                            ],
                          )
                            =?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );
