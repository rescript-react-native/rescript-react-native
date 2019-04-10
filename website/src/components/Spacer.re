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
  | Custom(float);

let styles =
  StyleSheet.create(
    Style.{
      "xxl":
        style(
          ~width=Size.pt(space *. 3.),
          ~height=Size.pt(space *. 3.),
          (),
        ),
      "xl":
        style(
          ~width=Size.pt(space *. 2.),
          ~height=Size.pt(space *. 2.),
          (),
        ),
      "l":
        style(
          ~width=Size.pt(space *. 1.5),
          ~height=Size.pt(space *. 1.5),
          (),
        ),
      "m":
        style(
          ~width=Size.pt(space *. 1.),
          ~height=Size.pt(space *. 1.),
          (),
        ),
      "s":
        style(
          ~width=Size.pt(space *. 3. /. 4.),
          ~height=Size.pt(space *. 3. /. 4.),
          (),
        ),
      "xs":
        style(
          ~width=Size.pt(space *. 2. /. 4.),
          ~height=Size.pt(space *. 2. /. 4.),
          (),
        ),
      "xxs":
        style(
          ~width=Size.pt(space *. 1. /. 4.),
          ~height=Size.pt(space *. 1. /. 4.),
          (),
        ),
    },
  );

[@react.component]
let make = (~size=M) =>
  <View
    style={
      switch (size) {
      | XXL => styles##xxl
      | XL => styles##xl
      | L => styles##l
      | M => styles##m
      | S => styles##s
      | XS => styles##xs
      | XXS => styles##xxs
      | Custom(value) =>
        Style.(style(~width=Size.pt(value), ~height=Size.pt(value), ()))
      }
    }
  />;
