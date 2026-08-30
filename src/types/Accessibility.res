@unboxed
type checked =
  | @as(false) False
  | @as(true) True
  | @as("mixed") Mixed

type actionInfo = {
  name: string,
  label?: string,
}

type actionEvent = AccessibilityActionEvent.t

type state = {
  disabled?: bool,
  selected?: bool,
  checked?: checked,
  busy?: bool,
  expanded?: bool,
}

type value

@obj external textValue: (~text: string) => value = ""

@obj external intValue: (~min: int, ~max: int, ~now: int) => value = ""

type liveRegion = [#none | #polite | #assertive]

type role = [
  | #adjustable
  | #alert
  | #article
  | #banner
  | #button
  | #checkbox
  | #combobox
  | #complementary
  | #contentinfo
  | #form
  | #header
  | #image
  | #imagebutton
  | #keyboardkey
  | #link
  | #list
  | #listitem
  | #main
  | #menu
  | #menubar
  | #menuitem
  | #navigation
  | #none
  | #progressbar
  | #radio
  | #radiogroup
  | #region
  | #scrollbar
  | #search
  | #spinbutton
  | #summary
  | #"switch"
  | #tab
  | #tabbar
  | #tablist
  | #text
  | #timer
  | #togglebutton
  | #toolbar
]

type importantForAccessibility = [
  | #auto
  | #yes
  | #no
  | #"no-hide-descendants"
]

type props = {
  accessible?: bool,
  accessibilityActions?: array<actionInfo>,
  accessibilityHint?: string,
  accessibilityLabel?: string,
  accessibilityRole?: role,
  // `role` has precedence over the accessibilityRole prop
  role?: Role.t,
  accessibilityState?: state,
  accessibilityValue?: value,
  onAccessibilityAction?: actionEvent => unit,
}

type iosProps = {
  accessibilityElementsHidden?: bool,
  accessibilityIgnoresInvertColors?: bool,
  accessibilityLanguage?: string,
  accessibilityViewIsModal?: bool,
  onAccessibilityEscape?: unit => unit,
  onAccessibilityTap?: unit => unit,
  onMagicTap?: unit => unit,
}

type androidProps = {
  accessibilityLabelledBy?: array<string>,
  accessibilityLiveRegion?: liveRegion,
  importantForAccessibility?: importantForAccessibility,
}

type viewProps = {
  ...props,
  ...iosProps,
  ...androidProps,
}
