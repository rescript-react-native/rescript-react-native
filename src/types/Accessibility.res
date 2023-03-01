type state
type checked<'a> = 'a

@inline
let checked = true

@inline
let unchecked = false

@inline
let mixed = "mixed"

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
