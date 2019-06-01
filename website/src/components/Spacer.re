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
      "xxl": style(~width=(space *. 3.)->dp, ~height=(space *. 3.)->dp, ()),
      "xl": style(~width=(space *. 2.)->dp, ~height=(space *. 2.)->dp, ()),
      "l": style(~width=(space *. 1.5)->dp, ~height=(space *. 1.5)->dp, ()),
      "m": style(~width=(space *. 1.)->dp, ~height=(space *. 1.)->dp, ()),
      "s":
        style(
          ~width=(space *. 3. /. 4.)->dp,
          ~height=(space *. 3. /. 4.)->dp,
          (),
        ),
      "xs":
        style(
          ~width=(space *. 2. /. 4.)->dp,
          ~height=(space *. 2. /. 4.)->dp,
          (),
        ),
      "xxs":
        style(
          ~width=(space *. 1. /. 4.)->dp,
          ~height=(space *. 1. /. 4.)->dp,
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
        Style.(style(~width=value->dp, ~height=value->dp, ()))
      }
    }
  />;
