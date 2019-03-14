/**
Container that allows to flip left and right between child views. Each child view of the [ViewPagerAndroid] will be treated as a separate page and will be stretched to fill the [ViewPagerAndroid].

It is important all children are [<View>]s and not composite components. You can set style properties like [padding] or [backgroundColor] for each child. It is also important that each child have a key prop.
You can read more on [ViewPagerAndroid] component usage in official docs: {{:https://facebook.github.io/react-native/docs/viewpagerandroid}}


{3 Example of use}
{[
  let styles =
  StyleSheet.create(
    Style.(
      {
        "pageStyle": style([flex(1.), flexGrow(1.)]),
        "viewPager":
          style([
            alignItems(Center),
            padding(Pt(20.)),
            backgroundColor(String("red")),
          ]),
      }
    ),
  );

  let component = ReasonReact.statelessComponent("MyComponent");

  let make = _children => {
    ...component,
    render: _self =>
      <ViewPagerAndroid
          initialPage=0
          style=styles##viewPager
          <View style=styles##pageStyle key="1">
            <Text> (ReasonReact.string("First page")) </Text>
          </View>
          <View style=styles##pageStyle key="2">
            <Text> (ReasonReact.string("Second page")) </Text>
          </View>
        </ViewPagerAndroid>,
  };
]}

  {3 Props}

  {{:\BsReactNative/View-BsReactNative} [View] props}

  {4 initialPage}
  Index of initial page that should be selected
  {[
    ~initialPage: int=?
  ]}
  {4 keyboardDismissMode}
  Determines whether the keyboard gets dismissed in response to a drag. Possible values:

  - [`none (default)] - drags do not dismiss the keyboard.
  - [`onDrag] - the keyboard is dismissed when a drag begins.
  {[
    ~keyboardDismissMode: [
      | `none
      | `onDrag
    ]=?
  ]}
  {4 onPageScroll}
  Executed when transitioning between pages either because of animation for the requested page change or when user is swiping/dragging between pages. The event##nativeEvent object for this callback will carry following data:

  -[position] - index of first page from the left that is currently visible
  -[offset] - value from range (0,1) describing stage between page transitions. Value x means that (1 - x) fraction of the page at "position" index is visible, and x fraction of the next page is visible.
  {[
    onPageScroll: {
      .
      "nativeEvent": {
        .
        "position": int,
        "offset": int,
      },
    } =>
    unit=?
  ]}
  {4 onPageScrollStateChanged}
  Called when the page scrolling state has changed. The page scrolling state can be in 3 states:

  - [idle] - there is no interaction with the page scroller happening at the time
  - [dragging] - there is currently an interaction with the page scroller
  - [settling]- there was an interaction with the page scroller, and the page scroller is now finishing it's closing or opening animation
  {[
    ~onPageScrollStateChanged: string => unit=?
  ]}
  {4 onPageSelected}
  This callback will be called once ViewPager finishes navigating to selected page (when user swipes between pages). The event.nativeEvent object passed to this callback will have following fields:

  - [position] - index of page that has been selected
  {[
    ~onPageSelected: {. "nativeEvent": {. "position": int}} => unit=?
  ]}
  {4 pageMargin}
  Blank space to show between pages. This is only visible while scrolling, pages are still edge-to-edge.
  {[
    pageMargin: int=?
  ]}
  {4 peekEnabled}
  Whether enable showing peekFraction or not. If this is true, the preview of last and next page will show in current screen.
  default: [false]
  {[
    peekEnabled: bool=?
  ]}
  {4 scrollEnabled}
  When [false], the content does not scroll.

  default: [true]
  {[
    ~peekEnabled: bool=?
  ]}

  {3 Methods}
  {4 setPage(int)}
  You can use this method to manually set page at given index.
 */

let make:
  (
    ~initialPage: int=?,
    ~keyboardDismissMode: [ | `none | `onDrag]=?,
    ~onPageScroll: {
                     .
                     "nativeEvent": {
                       .
                       "position": int,
                       "offset": int,
                     },
                   } =>
                   unit
                     =?,
    ~onPageScrollStateChanged: string => unit=?,
    ~onPageSelected: {. "nativeEvent": {. "position": int}} => unit=?,
    ~pageMargin: int=?,
    ~peekEnabled: bool=?,
    ~scrollEnabled: bool=?,
    /* view props: */
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
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );

/**
  {4 Example with methods}
  To use {b [setPage]} method you have to call them on [DrawerLayoutAndroid] [ref]. See {{:https://reasonml.github.io/reason-react/docs/en/react-ref.html} ReasonReact docs} to learn more about using refs.
   */

let setPage: (ReasonReact.reactRef, int) => unit;