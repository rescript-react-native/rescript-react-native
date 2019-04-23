/**
  You can read more on [TabBatIOS] component usage in official docs: {{:https://facebook.github.io/react-native/docs/tabbarios}}

  {3 Props}

  {{:\BsReactNative/View-BsReactNative} [View] props}

  {4 barStyle}
  {[
    ~barStyle: [
       | `default
       | `black
    ],
  ]}
  {4 barTintColor}
  {[
    ~barTintColor: ReactNative.Color.t=?
  ]}
  {4 itemPositioning}
  {[
    ~itemPositioning: [
      | `fill
      | `center
      | `auto
    ]=?,
  ]}
  {4 tintColor}
  {[
    ~tintColor: ReactNative.Color.t=?
  ]}
  {4 translucent}
  {[
    ~translucent: bool=?
  ]}
  {4 unselectedItemTintColor}
  {[
    ~unselectedItemTintColor: ReactNative.Color.t=?
  ]}
  {4 unselectedTintColor}
  {[
    ~unselectedTintColor: ReactNative.Color.t=?
  ]}
 */
[@react.component]
let make:
  (
    ~barStyle: [ | `default | `black]=?,
    ~barTintColor: ReactNative.Color.t=?,
    ~itemPositioning: [ | `fill | `center | `auto]=?,
    ~tintColor: ReactNative.Color.t=?,
    ~translucent: bool=?,
    ~unselectedItemTintColor: ReactNative.Color.t=?,
    ~unselectedTintColor: ReactNative.Color.t=?,
    // view props
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
    ~children: React.element=?,
    unit
  ) =>
  React.element;

module Item: {
  /**
  You can read more on [TabBatIOS.Item] component usage in official docs: {{:https://facebook.github.io/react-native/docs/tabbarios-item}}

  {3 Props}

  {{:\BsReactNative/View-BsReactNative} [View] props}

  {4 selected}
  {[
    ~selected: bool=?
  ]}
  {4 badge}
  {[
    ~badge: string=?
  ]}
  {4 icon}
  {[
    ~icon: Image.imageSource=?
  ]}
  reference:
  {[
    type imageSource = [
      | `URI(_imageURISource)
      | `Required(Packager.required)
      | `Multiple(list(_imageURISource))
    ];
  ]}
  {4 onPress}
  {[
    ~onPress: unit => unit=?
  ]}
  {4 renderAsOriginal}
  {[
    ~renderAsOriginal: bool=?
  ]}
  {4 badgeColor}
  {[
    ~badgeColor: ReactNative.Color.t=?
  ]}
  {4 selectedIcon}
  {[
    ~selectedIcon: Image.imageSource=?
  ]}
  {4 style}
  {[
    ~style: Style.t=?
  ]}
  {4 systemIcon}
  {[
    ~systemIcon: [
      | `bookmarks
      | `contacts
      | `downloads
      | `favourites
      | `featured
      | `history
      | `more
      | `mostRecent
      | `mostViewed
      | `recents
      | `search
      | `topRated
    ]=?
  ]}
  {4 title}
  {[
    ~title: string=?,
  ]}
  {4 style}
  {[
    ~isTVSelectable: bool=?
  ]}
 */

  [@react.component]
  let make:
    (
      ~selected: bool=?,
      ~badge: string=?,
      ~icon: Image.imageSource=?,
      ~onPress: unit => unit=?,
      ~renderAsOriginal: bool=?,
      ~badgeColor: ReactNative.Color.t=?,
      ~selectedIcon: Image.imageSource=?,
      ~systemIcon: [
                     | `bookmarks
                     | `contacts
                     | `downloads
                     | `favourites
                     | `featured
                     | `history
                     | `more
                     | `mostRecent
                     | `mostViewed
                     | `recents
                     | `search
                     | `topRated
                   ]
                     =?,
      ~title: string=?,
      ~isTVSelectable: bool=?,
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
};
