module Ios = {
  // Standard Colors <https://developer.apple.com/documentation/uikit/uicolor/standard_colors>
  type adaptableColors = [
    | #systemBlue
    | #systemBrown
    | #systemGreen
    | #systemIndigo
    | #systemOrange
    | #systemPink
    | #systemPurple
    | #systemRed
    | #systemTeal
    | #systemYellow
  ]
  type adaptableGrayColors = [
    | #systemGray
    | #systemGray2
    | #systemGray3
    | #systemGray4
    | #systemGray5
    | #systemGray6
  ]
  type transparentColors = [
    | #clear
  ]
  type fixedColors = [
    | #black
    | #blue
    | #brown
    | #cyan
    | #darkGray
    | #gray
    | #green
    | #lightGray
    | #magenta
    | #orange
    | #purple
    | #red
    | #white
    | #yellow
  ]

  // UI Element Colors https://developer.apple.com/documentation/uikit/uicolor/ui_element_colors
  type labelColors = [
    | #label
    | #secondaryLabel
    | #tertiaryLabel
    | #quaternaryLabel
  ]
  type fillColors = [
    | #systemFill
    | #secondarySystemFill
    | #tertiarySystemFill
    | #quaternarySystemFill
  ]
  type textColors = [
    | #placeholderText
  ]
  type standardContentBackgroundColors = [
    | #systemBackground
    | #secondarySystemBackground
    | #tertiarySystemBackground
  ]
  type groupedContentBackgroundColors = [
    | #systemGroupedBackground
    | #secondarySystemGroupedBackground
    | #tertiarySystemGroupedBackground
  ]
  type separatorColors = [
    | #separator
    | #opaqueSeparator
  ]
  type linkColors = [
    | #link
  ]
  type nonadaptableColors = [
    | #darkText
    | #lightText
  ]
  type t = [
    | adaptableColors
    | adaptableGrayColors
    | transparentColors
    | fixedColors
    | labelColors
    | fillColors
    | textColors
    | standardContentBackgroundColors
    | groupedContentBackgroundColors
    | separatorColors
    | linkColors
    | nonadaptableColors
  ]
}

module Android = {
  type color = [
    | #"@android:color/background_dark"
    | #"@android:color/background_light"
    | #"@android:color/black"
    | #"@android:color/darker_gray"
    | #"@android:color/holo_blue_bright"
    | #"@android:color/holo_blue_dark"
    | #"@android:color/holo_blue_light"
    | #"@android:color/holo_green_dark"
    | #"@android:color/holo_green_light"
    | #"@android:color/holo_orange_dark"
    | #"@android:color/holo_orange_light"
    | #"@android:color/holo_purple"
    | #"@android:color/holo_red_dark"
    | #"@android:color/holo_red_light"
    | #"@android:color/primary_text_dark"
    | #"@android:color/primary_text_dark_nodisable"
    | #"@android:color/primary_text_light"
    | #"@android:color/primary_text_light_nodisable"
    | #"@android:color/secondary_text_dark"
    | #"@android:color/secondary_text_dark_nodisable"
    | #"@android:color/secondary_text_light"
    | #"@android:color/secondary_text_light_nodisable"
    | #"@android:color/tab_indicator_text"
    | #"@android:color/tertiary_text_dark"
    | #"@android:color/tertiary_text_light"
    | #"@android:color/transparent"
    | #"@android:color/white"
    | #"@android:color/widget_edittext_dark"
  ]

  type attr = [
    | #"?android:attr/colorAccent"
    | #"?android:attr/colorActivatedHighlight"
    | #"?android:attr/colorBackground"
    | #"?android:attr/colorBackgroundFloating"
    | #"?android:attr/colorButtonNormal"
    | #"?android:attr/colorControlHighlight"
    | #"?android:attr/colorControlNormal"
    | #"?android:attr/colorEdgeEffect"
    | #"?android:attr/colorError"
    | #"?android:attr/colorFocusedHighlight"
    | #"?android:attr/colorForeground"
    | #"?android:attr/colorForegroundInverse"
    | #"?android:attr/colorLongPressedHighlight"
    | #"?android:attr/colorMultiSelectHighlight"
    | #"?android:attr/colorPressedHighlight"
    | #"?android:attr/colorPrimary"
    | #"?android:attr/colorPrimaryDark"
    | #"?android:attr/colorSecondary"
  ]

  type t = [
    | color
    | attr
  ]
}

@module("react-native") @variadic
external ios: array<Ios.t> => Color.t = "PlatformColor"

@module("react-native") @variadic
external android: array<Android.t> => Color.t = "PlatformColor"

@module("react-native") @variadic
external unsafe: array<string> => Color.t = "PlatformColor"
