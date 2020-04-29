type state;
type checked('a);

[@bs.inline true]
let checked: checked(bool);

[@bs.inline false]
let unchecked: checked(bool);

[@bs.inline "mixed"]
let mixed: checked(string);

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
