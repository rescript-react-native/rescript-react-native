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
      "xxl": style(~width=pt(space *. 3.), ~height=pt(space *. 3.), ()),
      "xl": style(~width=pt(space *. 2.), ~height=pt(space *. 2.), ()),
      "l": style(~width=pt(space *. 1.5), ~height=pt(space *. 1.5), ()),
      "m": style(~width=pt(space *. 1.), ~height=pt(space *. 1.), ()),
      "s":
        style(
          ~width=pt(space *. 3. /. 4.),
          ~height=pt(space *. 3. /. 4.),
          (),
        ),
      "xs":
        style(
          ~width=pt(space *. 2. /. 4.),
          ~height=pt(space *. 2. /. 4.),
          (),
        ),
      "xxs":
        style(
          ~width=pt(space *. 1. /. 4.),
          ~height=pt(space *. 1. /. 4.),
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
        Style.(style(~width=pt(value), ~height=pt(value), ()))
      }
    }
  />;
