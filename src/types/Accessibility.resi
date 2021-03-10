type state
type actionInfo
type checked<'a>

@bs.inline(true)
let checked: checked<bool>

@bs.inline(false)
let unchecked: checked<bool>

@bs.inline("mixed")
let mixed: checked<string>

@obj
external actionInfo: (~name: string, ~label: string=?, unit) => actionInfo = ""

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
  | #none
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
  | #search
  | #summary
  | #text
  | #main
  | #menu
  | #menubar
  | #menuitem
  | #navigation
  | #progressbar
  | #radio
  | #radiogroup
  | #region
  | #scrollbar
  | #spinbutton
  | #tab
  | #tablist
  | #timer
  | #toolbar
]
