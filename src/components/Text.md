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
                          | `heading
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
                        ]
                          =?,
    ~accessibilityLevel: int=?,
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
