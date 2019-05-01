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
        | XXL => Some(style(~paddingVertical=pt(space *. 4.), ()))
        | XL => Some(style(~paddingVertical=pt(space *. 3.), ()))
        | L => Some(style(~paddingVertical=pt(space *. 2.), ()))
        | M => Some(style(~paddingVertical=pt(space *. 1.), ()))
        | S => Some(style(~paddingVertical=pt(space *. 3. /. 4.), ()))
        | XS => Some(style(~paddingVertical=pt(space *. 2. /. 4.), ()))
        | XXS => Some(style(~paddingVertical=pt(space *. 1. /. 4.), ()))
        | Custom(value) => Some(style(~paddingVertical=pt(value), ()))
        | None => None
        },
        switch (horizontal) {
        | XXL => Some(style(~paddingHorizontal=pt(space *. 4.), ()))
        | XL => Some(style(~paddingHorizontal=pt(space *. 3.), ()))
        | L => Some(style(~paddingHorizontal=pt(space *. 2.), ()))
        | M => Some(style(~paddingHorizontal=pt(space *. 1.), ()))
        | S => Some(style(~paddingHorizontal=pt(space *. 3. /. 4.), ()))
        | XS => Some(style(~paddingHorizontal=pt(space *. 2. /. 4.), ()))
        | XXS => Some(style(~paddingHorizontal=pt(space *. 1. /. 4.), ()))
        | Custom(value) => Some(style(~paddingHorizontal=pt(value), ()))
        | None => None
        },
        s,
      |])
    )
    pointerEvents>
    ...children
  </View>;
