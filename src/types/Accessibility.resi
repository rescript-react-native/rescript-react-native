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
@deprecated("Directly create record instead") @obj
external state: (
  ~disabled: bool=?,
  ~selected: bool=?,
  ~checked: checked=?,
  ~busy: bool=?,
  ~expanded: bool=?,
  unit,
) => state = ""

type value

@obj external textValue: (~text: string) => value = ""

@obj external intValue: (~min: int, ~max: int, ~now: int) => value = ""

type liveRegion = [#none | #polite | #assertive]

// `accessibilityRole` communicates the purpose of a component to the user of an assistive technology.
// roles that are specific for react-native-web are also included:
// article, banner, complementary, contentinfo, form, list, listItem, main, navigation, region
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
