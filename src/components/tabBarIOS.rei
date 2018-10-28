
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
    ~barTintColor: string=?
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
    ~tintColor: string=?
  ]}
  {4 translucent}
  {[
    ~translucent: bool=?
  ]}
  {4 unselectedItemTintColor}
  {[
    ~unselectedItemTintColor: string=?
  ]}
  {4 unselectedTintColor}
  {[
    ~unselectedTintColor: string=?
  ]}
 */
let make:
  (
    ~barStyle: [ | `default | `black ]=?,
    ~barTintColor: string=?,
    ~itemPositioning: [ | `fill | `center | `auto]=?,
    ~tintColor: string=?,
    ~translucent: bool=?,
    ~unselectedItemTintColor: string=?,
    ~unselectedTintColor: string=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~testID: string=?,
    ~style: Style.t=?,
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
    ~badgeColor: string=?
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

  let make:
    (
      ~selected: bool=?,
      ~badge: string=?,
      ~icon: Image.imageSource=?,
      ~onPress: unit => unit=?,
      ~renderAsOriginal: bool=?,
      ~badgeColor: string=?,
      ~selectedIcon: Image.imageSource=?,
      ~style: Style.t=?,
      ~systemIcon: [ | `bookmarks | `contacts | `downloads | `favourites | `featured | `history | `more | `mostRecent | `mostViewed | `recents | `search | `topRated ]=?,
      ~title: string=?,  
      ~isTVSelectable: bool=?,
      ~accessibilityLabel: ReasonReact.reactElement=?,
      ~accessible: bool=?,
      ~hitSlop: Types.insets=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
      ~onMagicTap: unit => unit=?,
      ~responderHandlers: Types.touchResponderHandlers=?,
      ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
      ~removeClippedSubviews: bool=?,
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
      ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]
                                    =?,
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
};
