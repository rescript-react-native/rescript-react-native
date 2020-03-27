type state;
type checked = bool;

[@bs.inline]
let checked = true;

[@bs.inline]
let unchecked = false;

let mixed: checked = "mixed"->Obj.magic;

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
