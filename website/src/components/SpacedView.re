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
        | XXL => Some(style(~paddingVertical=Size.pt(space *. 4.), ()))
        | XL => Some(style(~paddingVertical=Size.pt(space *. 3.), ()))
        | L => Some(style(~paddingVertical=Size.pt(space *. 2.), ()))
        | M => Some(style(~paddingVertical=Size.pt(space *. 1.), ()))
        | S => Some(style(~paddingVertical=Size.pt(space *. 3. /. 4.), ()))
        | XS => Some(style(~paddingVertical=Size.pt(space *. 2. /. 4.), ()))
        | XXS =>
          Some(style(~paddingVertical=Size.pt(space *. 1. /. 4.), ()))
        | Custom(value) => Some(style(~paddingVertical=Size.pt(value), ()))
        | None => None
        },
        switch (horizontal) {
        | XXL => Some(style(~paddingHorizontal=Size.pt(space *. 4.), ()))
        | XL => Some(style(~paddingHorizontal=Size.pt(space *. 3.), ()))
        | L => Some(style(~paddingHorizontal=Size.pt(space *. 2.), ()))
        | M => Some(style(~paddingHorizontal=Size.pt(space *. 1.), ()))
        | S =>
          Some(style(~paddingHorizontal=Size.pt(space *. 3. /. 4.), ()))
        | XS =>
          Some(style(~paddingHorizontal=Size.pt(space *. 2. /. 4.), ()))
        | XXS =>
          Some(style(~paddingHorizontal=Size.pt(space *. 1. /. 4.), ()))
        | Custom(value) =>
          Some(style(~paddingHorizontal=Size.pt(value), ()))
        | None => None
        },
        s,
      |])
    )
    pointerEvents>
    ...children
  </View>;
