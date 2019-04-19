/**
{3 Example of use}
You can read more on RefreshControl component usage in official docs: {{:https://facebook.github.io/react-native/docs/refreshcontrol}}

{3 Props}
{4 onRefresh}
{[
  onRefresh: unit => unit=?
]}
{4 refreshing}
{[
  ~refreshing: bool=?,
]}
{4 colors}
{[
  ~colors: array(string)=?,
]}
{4 enabled}
{[
  ~enabled: bool=?,
]}
{4 progressBackgroundColor}
{[
  ~progressBackgroundColor: string=?,
]}
{4 progressViewOffset}
{[
  ~progressViewOffset: float=?,
]}
{4 tintColor}
{[
  ~tintColor: string=?,
]}
{4 title}
{[
  ~title: string=?,
]}
{4 titleColor}
{[
  ~titleColor: string=?,
]}
All other {{:\BsReactNative/View-BsReactNative} [View] props}
*/

let make:
  (
    ~onRefresh: unit => unit=?,
    ~refreshing: bool=?,
    ~colors: array(string)=?,
    ~enabled: bool=?,
    ~progressBackgroundColor: string=?,
    ~progressViewOffset: float=?,
    ~tintColor: string=?,
    ~title: string=?,
    ~titleColor: string=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
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
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );