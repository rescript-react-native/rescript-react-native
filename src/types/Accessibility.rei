type state;
type checked;

[@bs.inline "mixed"]
let mixed: checked;

external setChecked: bool => checked = "%identity";

[@bs.obj]
external state:
  (
    ~disabled: bool=?,
    ~selected: bool=?,
    ~checked: checked=?,
    ~busy: bool=?,
    ~expanded: bool=?,
    unit
  ) =>
  state =
  "";
