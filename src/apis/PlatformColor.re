[@bs.module "react-native"]
external unsafeGet: string => Color.t = "PlatformColor";

[@bs.module "react-native"]
external unsafeGet2: (string, string) => Color.t = "PlatformColor";

[@bs.module "react-native"]
external unsafeGet3: (string, string, string) => Color.t = "PlatformColor";

[@bs.module "react-native"]
external unsafeGet4: (string, string, string, string) => Color.t =
  "PlatformColor";

[@bs.module "react-native"]
external unsafeGet5: (string, string, string, string, string) => Color.t =
  "PlatformColor";

[@bs.module "react-native"]
external unsafeGet6:
  (string, string, string, string, string, string) => Color.t =
  "PlatformColor";

[@bs.module "react-native"]
external unsafeGet7:
  (string, string, string, string, string, string, string) => Color.t =
  "PlatformColor";

[@bs.module "react-native"] [@bs.variadic]
external unsafeGetMultiple: array(string) => Color.t = "PlatformColor";

module Ios = {
  type t = [
    | `clear
    | `darkText
    | `label
    | `lightText
    | `link
    | `opaqueSeparator
    | `placeholderText
    | `quaternaryLabel
    | `quaternarySystemFill
    | `secondaryLabel
    | `secondarySystemBackground
    | `secondarySystemFill
    | `secondarySystemGroupedBackground
    | `separator
    | `systemBackground
    | `systemFill
    | `systemGroupedBackground
    | `tertiaryLabel
    | `tertiarySystemBackground
    | `tertiarySystemFill
    | `tertiarySystemGroupedBackground
  ];
  [@bs.module "react-native"] external get: t => Color.t = "PlatformColor";
  [@bs.module "react-native"]
  external get2: (t, t) => Color.t = "PlatformColor";
  [@bs.module "react-native"]
  external get3: (t, t, t) => Color.t = "PlatformColor";
  [@bs.module "react-native"]
  external get4: (t, t, t, t) => Color.t = "PlatformColor";
  [@bs.module "react-native"]
  external get5: (t, t, t, t, t) => Color.t = "PlatformColor";
  [@bs.module "react-native"]
  external get6: (t, t, t, t, t, t) => Color.t = "PlatformColor";
  [@bs.module "react-native"]
  external get7: (t, t, t, t, t, t) => Color.t = "PlatformColor";
};

[@deprecated "Please PlatformColor.Ios instead of PlatformColor.IOS"]
module IOS = Ios;
module Android = {
  [@deprecated
    "Please use PlatformColor.unsafeGet instead of PlatformColor.Android.unsafeGet"
  ]
  [@bs.module "react-native"]
  external unsafeGet: string => Color.t = "PlatformColor";

  [@bs.module "react-native"]
  external getColor:
    (
    [@bs.string]
    [
      | [@bs.as "@android:color/background_dark"] `background_dark
      | [@bs.as "@android:color/background_light"] `background_light
      | [@bs.as "@android:color/black"] `black
      | [@bs.as "@android:color/darker_gray"] `darker_gray
      | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
      | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
      | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
      | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
      | [@bs.as "@android:color/holo_green_light"] `holo_green_light
      | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
      | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
      | [@bs.as "@android:color/holo_purple"] `holo_purple
      | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
      | [@bs.as "@android:color/holo_red_light"] `holo_red_light
      | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
      | [@bs.as "@android:color/primary_text_dark_nodisable"]
        `primary_text_dark_nodisable
      | [@bs.as "@android:color/primary_text_light"] `primary_text_light
      | [@bs.as "@android:color/primary_text_light_nodisable"]
        `primary_text_light_nodisable
      | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
      | [@bs.as "@android:color/secondary_text_dark_nodisable"]
        `secondary_text_dark_nodisable
      | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
      | [@bs.as "@android:color/secondary_text_light_nodisable"]
        `secondary_text_light_nodisable
      | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
      | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
      | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
      | [@bs.as "@android:color/transparent"] `transparent
      | [@bs.as "@android:color/white"] `white
      | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
    ]
    ) =>
    Color.t =
    "PlatformColor";

  [@bs.module "react-native"]
  external getAttr:
    (
    [@bs.string]
    [
      | [@bs.as "?android:attr/colorAccent"] `colorAccent
      | [@bs.as "?android:attr/colorActivatedHighlight"]
        `colorActivatedHighlight
      | [@bs.as "?android:attr/colorBackground"] `colorBackground
      | [@bs.as "?android:attr/colorBackgroundFloating"]
        `colorBackgroundFloating
      | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
      | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
      | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
      | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
      | [@bs.as "?android:attr/colorError"] `colorError
      | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
      | [@bs.as "?android:attr/colorForeground"] `colorForeground
      | [@bs.as "?android:attr/colorForegroundInverse"] `colorForegroundInverse
      | [@bs.as "?android:attr/colorLongPressedHighlight"]
        `colorLongPressedHighlight
      | [@bs.as "?android:attr/colorMultiSelectHighlight"]
        `colorMultiSelectHighlight
      | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
      | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
      | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
      | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
    ]
    ) =>
    Color.t =
    "PlatformColor";

  [@bs.module "react-native"]
  external get:
    (
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ]
    ) =>
    Color.t =
    "PlatformColor";

  [@bs.module "react-native"]
  external get2:
    (
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ]
    ) =>
    Color.t =
    "PlatformColor";

  [@bs.module "react-native"]
  external get3:
    (
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ]
    ) =>
    Color.t =
    "PlatformColor";

  [@bs.module "react-native"]
  external get4:
    (
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ]
    ) =>
    Color.t =
    "PlatformColor";

  [@bs.module "react-native"]
  external get5:
    (
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ]
    ) =>
    Color.t =
    "PlatformColor";

  [@bs.module "react-native"]
  external get6:
    (
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ]
    ) =>
    Color.t =
    "PlatformColor";
  [@bs.module "react-native"]
  external get7:
    (
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ],
      [@bs.string] [
        | [@bs.as "@android:color/background_dark"] `background_dark
        | [@bs.as "@android:color/background_light"] `background_light
        | [@bs.as "@android:color/black"] `black
        | [@bs.as "@android:color/darker_gray"] `darker_gray
        | [@bs.as "@android:color/holo_blue_bright"] `holo_blue_bright
        | [@bs.as "@android:color/holo_blue_dark"] `holo_blue_dark
        | [@bs.as "@android:color/holo_blue_light"] `holo_blue_light
        | [@bs.as "@android:color/holo_green_dark"] `holo_green_dark
        | [@bs.as "@android:color/holo_green_light"] `holo_green_light
        | [@bs.as "@android:color/holo_orange_dark"] `holo_orange_dark
        | [@bs.as "@android:color/holo_orange_light"] `holo_orange_light
        | [@bs.as "@android:color/holo_purple"] `holo_purple
        | [@bs.as "@android:color/holo_red_dark"] `holo_red_dark
        | [@bs.as "@android:color/holo_red_light"] `holo_red_light
        | [@bs.as "@android:color/primary_text_dark"] `primary_text_dark
        | [@bs.as "@android:color/primary_text_dark_nodisable"]
          `primary_text_dark_nodisable
        | [@bs.as "@android:color/primary_text_light"] `primary_text_light
        | [@bs.as "@android:color/primary_text_light_nodisable"]
          `primary_text_light_nodisable
        | [@bs.as "@android:color/secondary_text_dark"] `secondary_text_dark
        | [@bs.as "@android:color/secondary_text_dark_nodisable"]
          `secondary_text_dark_nodisable
        | [@bs.as "@android:color/secondary_text_light"] `secondary_text_light
        | [@bs.as "@android:color/secondary_text_light_nodisable"]
          `secondary_text_light_nodisable
        | [@bs.as "@android:color/tab_indicator_text"] `tab_indicator_text
        | [@bs.as "@android:color/tertiary_text_dark"] `tertiary_text_dark
        | [@bs.as "@android:color/tertiary_text_light"] `tertiary_text_light
        | [@bs.as "@android:color/transparent"] `transparent
        | [@bs.as "@android:color/white"] `white
        | [@bs.as "@android:color/widget_edittext_dark"] `widget_edittext_dark
        | [@bs.as "?android:attr/colorAccent"] `colorAccent
        | [@bs.as "?android:attr/colorActivatedHighlight"]
          `colorActivatedHighlight
        | [@bs.as "?android:attr/colorBackground"] `colorBackground
        | [@bs.as "?android:attr/colorBackgroundFloating"]
          `colorBackgroundFloating
        | [@bs.as "?android:attr/colorButtonNormal"] `colorButtonNormal
        | [@bs.as "?android:attr/colorControlHighlight"] `colorControlHighlight
        | [@bs.as "?android:attr/colorControlNormal"] `colorControlNormal
        | [@bs.as "?android:attr/colorEdgeEffect"] `colorEdgeEffect
        | [@bs.as "?android:attr/colorError"] `colorError
        | [@bs.as "?android:attr/colorFocusedHighlight"] `colorFocusedHighlight
        | [@bs.as "?android:attr/colorForeground"] `colorForeground
        | [@bs.as "?android:attr/colorForegroundInverse"]
          `colorForegroundInverse
        | [@bs.as "?android:attr/colorLongPressedHighlight"]
          `colorLongPressedHighlight
        | [@bs.as "?android:attr/colorMultiSelectHighlight"]
          `colorMultiSelectHighlight
        | [@bs.as "?android:attr/colorPressedHighlight"] `colorPressedHighlight
        | [@bs.as "?android:attr/colorPrimary"] `colorPrimary
        | [@bs.as "?android:attr/colorPrimaryDark"] `colorPrimaryDark
        | [@bs.as "?android:attr/colorSecondary"] `colorSecondary
      ]
    ) =>
    Color.t =
    "PlatformColor";
};
