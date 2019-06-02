open ReactNative;

let space = 20.;

type size =
  | XXL
  | XL
  | L
  | M
  | S
  | XS
  | XXS
  | Custom(float)
  | None;

[@react.component]
let make =
    (
      ~vertical=M,
      ~horizontal=M,
      ~style as s=?,
      ~pointerEvents=`auto,
      ~children,
    ) =>
  <View
    style=Style.(
      arrayOption([|
        switch (vertical) {
        | XXL => Some(style(~paddingVertical=(space *. 4.)->dp, ()))
        | XL => Some(style(~paddingVertical=(space *. 3.)->dp, ()))
        | L => Some(style(~paddingVertical=(space *. 2.)->dp, ()))
        | M => Some(style(~paddingVertical=(space *. 1.)->dp, ()))
        | S => Some(style(~paddingVertical=(space *. 3. /. 4.)->dp, ()))
        | XS => Some(style(~paddingVertical=(space *. 2. /. 4.)->dp, ()))
        | XXS => Some(style(~paddingVertical=(space *. 1. /. 4.)->dp, ()))
        | Custom(value) => Some(style(~paddingVertical=value->dp, ()))
        | None => None
        },
        switch (horizontal) {
        | XXL => Some(style(~paddingHorizontal=(space *. 4.)->dp, ()))
        | XL => Some(style(~paddingHorizontal=(space *. 3.)->dp, ()))
        | L => Some(style(~paddingHorizontal=(space *. 2.)->dp, ()))
        | M => Some(style(~paddingHorizontal=(space *. 1.)->dp, ()))
        | S => Some(style(~paddingHorizontal=(space *. 3. /. 4.)->dp, ()))
        | XS => Some(style(~paddingHorizontal=(space *. 2. /. 4.)->dp, ()))
        | XXS => Some(style(~paddingHorizontal=(space *. 1. /. 4.)->dp, ()))
        | Custom(value) => Some(style(~paddingHorizontal=value->dp, ()))
        | None => None
        },
        s,
      |])
    )
    pointerEvents>
    ...children
  </View>;
