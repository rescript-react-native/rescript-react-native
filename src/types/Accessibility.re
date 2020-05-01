type state;
type checked('a) = 'a;

[@bs.inline]
let checked = true;

[@bs.inline]
let unchecked = false;

[@bs.inline]
let mixed = "mixed";

[@bs.obj]
external state:
  (
    ~disabled: bool=?,
    ~selected: bool=?,
    ~checked: checked('a)=?,
    ~busy: bool=?,
    ~expanded: bool=?,
    unit
  ) =>
  state;

type value;

[@bs.obj] external textValue: (~text: string) => value;

[@bs.obj] external intValue: (~min: int, ~max: int, ~now: int) => value;
