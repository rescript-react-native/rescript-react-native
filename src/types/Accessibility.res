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

type ariaLive = [#polite | #assertive | #off]

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
  // `aria-*` props have precedence over the matching `accessibility*` props
  @as("aria-busy") ariaBusy?: bool,
  @as("aria-checked") ariaChecked?: checked,
  @as("aria-disabled") ariaDisabled?: bool,
  @as("aria-expanded") ariaExpanded?: bool,
  @as("aria-hidden") ariaHidden?: bool,
  @as("aria-label") ariaLabel?: string,
  @as("aria-selected") ariaSelected?: bool,
  @as("aria-valuemax") ariaValuemax?: float,
  @as("aria-valuemin") ariaValuemin?: float,
  @as("aria-valuenow") ariaValuenow?: float,
  @as("aria-valuetext") ariaValuetext?: string,
}

type iosProps = {
  accessibilityElementsHidden?: bool,
  accessibilityIgnoresInvertColors?: bool,
  accessibilityLanguage?: string,
  accessibilityViewIsModal?: bool,
  @as("aria-modal") ariaModal?: bool,
  onAccessibilityEscape?: unit => unit,
  onAccessibilityTap?: unit => unit,
  onMagicTap?: unit => unit,
}

type androidProps = {
  accessibilityLabelledBy?: array<string>,
  accessibilityLiveRegion?: liveRegion,
  @as("aria-labelledby") ariaLabelledby?: string,
  @as("aria-live") ariaLive?: ariaLive,
  importantForAccessibility?: importantForAccessibility,
}

type viewProps = {
  ...props,
  ...iosProps,
  ...androidProps,
}
