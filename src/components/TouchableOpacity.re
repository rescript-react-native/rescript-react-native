include TouchableOpacityElement;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    ~activeOpacity: float=?,
    ~focusedOpacity: float=?,
    ~hasTVPreferredFocus: bool=?,
    ~style: Style.t=?,
    ~tvParallaxProperties: TV.parallax=?,
    // TouchableWithoutFeedback props
    ~accessible: bool=?,
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: string=?,
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
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: View.edgeInsets=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~pressRetentionOffset: View.edgeInsets=?,
    ~testID: string=?,
    ~touchSoundDisabled: bool=?,
    ~children: React.element=?,
    // React Native Web Props
    ~rel: [@bs.string] [
            | `alternate
            | `author
            | [@bs.as "dns-prefetch"] `dnsPrefetch
            | `icon
            | `license
            | `next
            | `pingback
            | `preconnect
            | `prefetch
            | `preload
            | `prerender
            | `prev
            | `search
            | `stylesheet
          ]
            =?,
    ~href: string=?,
    ~target: [@bs.string] [ | `_blank | `_self | `_parent | `_top]=?
  ) =>
  React.element =
  "TouchableOpacity";
