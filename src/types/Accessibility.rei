type state;
type checked;

[@bs.inline true]
let checked: checked;

[@bs.inline false]
let unchecked: checked;

let mixed: checked;

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

type value;

[@bs.obj] external textValue: (~text: string) => value = "";

[@bs.obj] external intValue: (~min: int, ~max: int, ~now: int) => value = "";
