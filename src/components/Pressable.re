include NativeElement;

type rippleConfig;

[@bs.obj]
external rippleConfig:
  (~color: Color.t=?, ~borderless: bool=?, ~radius: float=?, unit) => rippleConfig;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // Accessibility props
    ~accessibilityActions: array(Accessibility.actionInfo)=?,
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
    ~accessibilityState: Accessibility.state=?,
    ~accessibilityValue: Accessibility.value=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~focusable: bool=?,
    ~importantForAccessibility: [@bs.string] [
                                  | `auto
                                  | `yes
                                  | `no
                                  | [@bs.as "no-hide-descendants"]
                                    `noHideDescendants
                                ]
                                  =?,
    ~children: React.element=?,
    ~delayLongPress: int=?,
    ~disabled: bool=?,
    ~hitSlop: View.edgeInsets=?,
    ~pressRetentionOffset: View.edgeInsets=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~android_disableSound: bool=?,
    ~android_ripple: rippleConfig=?,
    ~testOnly_pressed: bool=?
  ) =>
  React.element =
  "Pressable";
