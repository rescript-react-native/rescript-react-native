@module("react-native")
external unsafeGet: string => Color.t = "PlatformColor"

@module("react-native")
external unsafeGet2: (string, string) => Color.t = "PlatformColor"

@module("react-native")
external unsafeGet3: (string, string, string) => Color.t = "PlatformColor"

@module("react-native")
external unsafeGet4: (string, string, string, string) => Color.t = "PlatformColor"

@module("react-native")
external unsafeGet5: (string, string, string, string, string) => Color.t = "PlatformColor"

@module("react-native")
external unsafeGet6: (string, string, string, string, string, string) => Color.t = "PlatformColor"

@module("react-native")
external unsafeGet7: (string, string, string, string, string, string, string) => Color.t =
  "PlatformColor"

@module("react-native") @variadic
external unsafeGetMultiple: array<string> => Color.t = "PlatformColor"

module Ios = {
  type t = [
    | #clear
    | #darkText
    | #label
    | #lightText
    | #link
    | #opaqueSeparator
    | #placeholderText
    | #quaternaryLabel
    | #quaternarySystemFill
    | #secondaryLabel
    | #secondarySystemBackground
    | #secondarySystemFill
    | #secondarySystemGroupedBackground
    | #separator
    | #systemBackground
    | #systemFill
    | #systemGroupedBackground
    | #tertiaryLabel
    | #tertiarySystemBackground
    | #tertiarySystemFill
    | #tertiarySystemGroupedBackground
  ]
  @module("react-native") external get: t => Color.t = "PlatformColor"
  @module("react-native")
  external get2: (t, t) => Color.t = "PlatformColor"
  @module("react-native")
  external get3: (t, t, t) => Color.t = "PlatformColor"
  @module("react-native")
  external get4: (t, t, t, t) => Color.t = "PlatformColor"
  @module("react-native")
  external get5: (t, t, t, t, t) => Color.t = "PlatformColor"
  @module("react-native")
  external get6: (t, t, t, t, t, t) => Color.t = "PlatformColor"
  @module("react-native")
  external get7: (t, t, t, t, t, t) => Color.t = "PlatformColor"
}

@deprecated("Please PlatformColor.Ios instead of PlatformColor.IOS")
module IOS = Ios
module Android = {
  @deprecated("Please use PlatformColor.unsafeGet instead of PlatformColor.Android.unsafeGet")
  @module("react-native")
  external unsafeGet: string => Color.t = "PlatformColor"

  @module("react-native")
  external getColor: @string
  [
    | @as("@android:color/background_dark") #background_dark
    | @as("@android:color/background_light") #background_light
    | @as("@android:color/black") #black
    | @as("@android:color/darker_gray") #darker_gray
    | @as("@android:color/holo_blue_bright") #holo_blue_bright
    | @as("@android:color/holo_blue_dark") #holo_blue_dark
    | @as("@android:color/holo_blue_light") #holo_blue_light
    | @as("@android:color/holo_green_dark") #holo_green_dark
    | @as("@android:color/holo_green_light") #holo_green_light
    | @as("@android:color/holo_orange_dark") #holo_orange_dark
    | @as("@android:color/holo_orange_light") #holo_orange_light
    | @as("@android:color/holo_purple") #holo_purple
    | @as("@android:color/holo_red_dark") #holo_red_dark
    | @as("@android:color/holo_red_light") #holo_red_light
    | @as("@android:color/primary_text_dark") #primary_text_dark
    | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
    | @as("@android:color/primary_text_light") #primary_text_light
    | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
    | @as("@android:color/secondary_text_dark") #secondary_text_dark
    | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
    | @as("@android:color/secondary_text_light") #secondary_text_light
    | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
    | @as("@android:color/tab_indicator_text") #tab_indicator_text
    | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
    | @as("@android:color/tertiary_text_light") #tertiary_text_light
    | @as("@android:color/transparent") #transparent
    | @as("@android:color/white") #white
    | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
  ] => Color.t = "PlatformColor"

  @module("react-native")
  external getAttr: @string
  [
    | @as("?android:attr/colorAccent") #colorAccent
    | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
    | @as("?android:attr/colorBackground") #colorBackground
    | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
    | @as("?android:attr/colorButtonNormal") #colorButtonNormal
    | @as("?android:attr/colorControlHighlight") #colorControlHighlight
    | @as("?android:attr/colorControlNormal") #colorControlNormal
    | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
    | @as("?android:attr/colorError") #colorError
    | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
    | @as("?android:attr/colorForeground") #colorForeground
    | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
    | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
    | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
    | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
    | @as("?android:attr/colorPrimary") #colorPrimary
    | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
    | @as("?android:attr/colorSecondary") #colorSecondary
  ] => Color.t = "PlatformColor"

  @module("react-native")
  external get: (
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
  ) => Color.t = "PlatformColor"

  @module("react-native")
  external get2: (
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
  ) => Color.t = "PlatformColor"

  @module("react-native")
  external get3: (
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
  ) => Color.t = "PlatformColor"

  @module("react-native")
  external get4: (
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
  ) => Color.t = "PlatformColor"

  @module("react-native")
  external get5: (
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
  ) => Color.t = "PlatformColor"

  @module("react-native")
  external get6: (
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
  ) => Color.t = "PlatformColor"
  @module("react-native")
  external get7: (
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
    @string
    [
      | @as("@android:color/background_dark") #background_dark
      | @as("@android:color/background_light") #background_light
      | @as("@android:color/black") #black
      | @as("@android:color/darker_gray") #darker_gray
      | @as("@android:color/holo_blue_bright") #holo_blue_bright
      | @as("@android:color/holo_blue_dark") #holo_blue_dark
      | @as("@android:color/holo_blue_light") #holo_blue_light
      | @as("@android:color/holo_green_dark") #holo_green_dark
      | @as("@android:color/holo_green_light") #holo_green_light
      | @as("@android:color/holo_orange_dark") #holo_orange_dark
      | @as("@android:color/holo_orange_light") #holo_orange_light
      | @as("@android:color/holo_purple") #holo_purple
      | @as("@android:color/holo_red_dark") #holo_red_dark
      | @as("@android:color/holo_red_light") #holo_red_light
      | @as("@android:color/primary_text_dark") #primary_text_dark
      | @as("@android:color/primary_text_dark_nodisable") #primary_text_dark_nodisable
      | @as("@android:color/primary_text_light") #primary_text_light
      | @as("@android:color/primary_text_light_nodisable") #primary_text_light_nodisable
      | @as("@android:color/secondary_text_dark") #secondary_text_dark
      | @as("@android:color/secondary_text_dark_nodisable") #secondary_text_dark_nodisable
      | @as("@android:color/secondary_text_light") #secondary_text_light
      | @as("@android:color/secondary_text_light_nodisable") #secondary_text_light_nodisable
      | @as("@android:color/tab_indicator_text") #tab_indicator_text
      | @as("@android:color/tertiary_text_dark") #tertiary_text_dark
      | @as("@android:color/tertiary_text_light") #tertiary_text_light
      | @as("@android:color/transparent") #transparent
      | @as("@android:color/white") #white
      | @as("@android:color/widget_edittext_dark") #widget_edittext_dark
      | @as("?android:attr/colorAccent") #colorAccent
      | @as("?android:attr/colorActivatedHighlight") #colorActivatedHighlight
      | @as("?android:attr/colorBackground") #colorBackground
      | @as("?android:attr/colorBackgroundFloating") #colorBackgroundFloating
      | @as("?android:attr/colorButtonNormal") #colorButtonNormal
      | @as("?android:attr/colorControlHighlight") #colorControlHighlight
      | @as("?android:attr/colorControlNormal") #colorControlNormal
      | @as("?android:attr/colorEdgeEffect") #colorEdgeEffect
      | @as("?android:attr/colorError") #colorError
      | @as("?android:attr/colorFocusedHighlight") #colorFocusedHighlight
      | @as("?android:attr/colorForeground") #colorForeground
      | @as("?android:attr/colorForegroundInverse") #colorForegroundInverse
      | @as("?android:attr/colorLongPressedHighlight") #colorLongPressedHighlight
      | @as("?android:attr/colorMultiSelectHighlight") #colorMultiSelectHighlight
      | @as("?android:attr/colorPressedHighlight") #colorPressedHighlight
      | @as("?android:attr/colorPrimary") #colorPrimary
      | @as("?android:attr/colorPrimaryDark") #colorPrimaryDark
      | @as("?android:attr/colorSecondary") #colorSecondary
    ],
  ) => Color.t = "PlatformColor"
}
