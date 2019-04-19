/**
  The purpose of [SafeAreaView] is to render content within the safe area boundaries of a device. It is currently only applicable to iOS devices with iOS version 11 or later.

  [SafeAreaView] renders nested content and automatically applies paddings to reflect the portion of the view that is not covered by navigation bars, tab bars, toolbars, and other ancestor views. Moreover, and most importantly,Safe Area's paddings reflect the physical limitation of the screen, such as rounded corners or camera notches (i.e. the sensor housing area on iPhone X).
  You can read more on SafeAreaView component usage in official docs: {{:https://facebook.github.io/react-native/docs/maskedviewios}}

  {{:\BsReactNative/View-BsReactNative} [View] props}
 */
include View.ViewComponent;
