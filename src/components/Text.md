---
id: components/Text
title: Text
wip: true
---

```reason
include NativeElement;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // Text props
    ~accessible: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityLabel: string=?,
    ~allowFontScaling: bool=?,
    ~accessibilityRole: [@bs.string] [
                          | `none
                          | `button
                          | `link
                          | `search
                          | `image
                          | `keyboardkey
                          | `text
                          | `adjustable
                          | `imagebutton
                          | `header
                          | `summary
                          | `alert
                          | `checkbox
                          | `combobox
                          | `menu
                          | `menubar
                          | `menuitem
                          | `progressbar
                          | `radio
                          | `radiogroup
                          | `scrollbar
                          | `spinbutton
                          | `tab
                          | `tablist
                          | `timer
                          | `toolbar
                          // below are additional roles added for react-native-web https://github.com/necolas/react-native-web/blob/36dacb2052efdab2a28655773dc76934157d9134/packages/react-native-web/src/modules/AccessibilityUtil/propsToAccessibilityComponent.js#L13-L23
                          | `article
                          | `banner
                          | `complementary
                          | `contentinfo
                          | `form
                          | `list
                          | `listItem
                          | `main
                          | `navigation
                          | `region
                        ]
                          =?,
    ~ariaLevel: int=?,
    ~ellipsizeMode: [@bs.string] [ | `clip | `head | `middle | `tail]=?,
    ~numberOfLines: int=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onLongPress: unit => unit=?,
    ~onPress: unit => unit=?,
    ~pressRetentionOffset: View.edgeInsets=?,
    ~selectable: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~selectionColor: string=?,
    ~textBreakStrategy: [@bs.string] [ | `simple | `highQuality | `balanced]=?,
    ~adjustsFontSizeToFit: bool=?,
    ~minimumFontScale: float=?,
    ~suppressHighlighting: bool=?,
    ~value: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Text";

```
