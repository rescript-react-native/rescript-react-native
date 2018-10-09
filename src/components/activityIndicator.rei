/**
  Displays a circular loading indicator. Check {{:https://facebook.github.io/react-native/docs/activityindicator.html} React Native docs}
  for details.
  
  {2 Example}

  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self => <ActivityIndicator />,
    };
  ]}

  To render a default ActivityIndicator (spinner) you don't need to pass any props:

  {2 Props}

  All {{:../View-BsReactNative/#props} [View]} props are accepted.

  {3 animating}

  {[
    ~animating: bool=?
  ]}

  {3 color}

  Changes the color of the indicator. Can be either a named color ["tomato"], hex ["#ff0ff"] or an rgb ["rgb(255, 34, 11)"].

  {[
    ~color: Style.color=?
  ]}

  {3 size}

  In order to change the size of the indicator pass one of the {{:http://2ality.com/2018/01/polymorphic-variants-reasonml.html} polymorphic variants}:

  {[
    ~size: [ | `large | `small | `exact(int)]=?
  ]}

  Note: [exact] is only supported on Android. On iOS, it defaults to [`small].
 */
let make:
  (
    ~animating: bool=?,
    ~color: Style.color=?,
    ~size: [ | `large | `small | `exact(int)]=?,
    ~hidesWhenStopped: bool=?,
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
    unit,
  );
