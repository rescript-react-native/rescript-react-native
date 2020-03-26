type state;
type checked = string;

[@bs.inline]
let mixed = "mixed";

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
