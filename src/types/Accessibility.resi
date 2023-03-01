type state
type checked<'a>

@inline(true)
let checked: checked<bool>

@inline(false)
let unchecked: checked<bool>

@inline("mixed")
let mixed: checked<string>

type actionInfo = {
  name: string,
  label?: string,
}

@obj
external // @deprecated("Directly create record instead")
actionInfo: (~name: string, ~label: string=?, unit) => actionInfo = ""

type actionEvent = AccessibilityActionEvent.t

@obj
external state: (
  ~disabled: bool=?,
  ~selected: bool=?,
  ~checked: checked<'a>=?,
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
  | #alertdialog
  | #application
  | #article
  | #banner
  | #button
  | #cell
  | #checkbox
  | #columnheader
  | #combobox
  | #complementary
  | #contentinfo
  | #definition
  | #dialog
  | #directory
  | #document
  | #feed
  | #figure
  | #form
  | #grid
  | #group
  | #header
  | #heading
  | #image
  | #imagebutton
  | #img
  | #keyboardkey
  | #link
  | #list
  | #listitem
  | #log
  | #main
  | #marquee
  | #math
  | #menu
  | #menubar
  | #menuitem
  | #meter
  | #navigation
  | #none
  | #note
  | #option
  | #presentation
  | #progressbar
  | #radio
  | #radiogroup
  | #region
  | #row
  | #rowgroup
  | #rowheader
  | #scrollbar
  | #search
  | #searchbox
  | #separator
  | #slider
  | #spinbutton
  | #status
  | #summary
  | #"switch"
  | #tab
  | #tabbar
  | #table
  | #tablist
  | #tabpanel
  | #term
  | #text
  | #timer
  | #togglebutton
  | #toolbar
  | #tooltip
  | #tree
  | #treegrid
  | #treeitem
]
