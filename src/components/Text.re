include NativeElement;

module Make = (T: {type t;}) => {
  [@react.component] [@bs.module "react-native"]
  external make:
    (
      ~ref: T.t=?,
      // Text props
      ~accessible: bool=?,
      ~accessibilityHint: string=?,
      ~accessibilityLabel: string=?,
      // `accessibilityRole` communicates the purpose of a component to the user of an assistive technology.
      // roles that are specific for react-native-web are also included:
      // article, banner, complementary, contentinfo, form, list, listItem, main, navigation, region
      ~accessibilityRole: [@bs.string] [
                            | `none
                            | `adjustable
                            | `alert
                            | `article
                            | `banner
                            | `button
                            | `checkbox
                            | `combobox
                            | `complementary
                            | `contentinfo
                            | `form
                            | `header
                            | `image
                            | `imagebutton
                            | `keyboardkey
                            | `link
                            | `list
                            | `listItem
                            | `search
                            | `summary
                            | `text
                            | `main
                            | `menu
                            | `menubar
                            | `menuitem
                            | `navigation
                            | `progressbar
                            | `radio
                            | `radiogroup
                            | `region
                            | `scrollbar
                            | `spinbutton
                            | `tab
                            | `tablist
                            | `timer
                            | `toolbar
                          ]
                            =?,
      ~ariaLevel: int=?,
      ~allowFontScaling: bool=?,
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
      ~textBreakStrategy: [@bs.string] [ | `simple | `highQuality | `balanced]
                            =?,
      ~adjustsFontSizeToFit: bool=?,
      ~minimumFontScale: float=?,
      ~suppressHighlighting: bool=?,
      ~value: string=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Text";
};

include Make({
  type t = ref;
});
