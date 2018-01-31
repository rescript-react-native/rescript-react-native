type subscription;

type event('a) = 'a
constraint 'a =
  Js.t(
    {
      ..
      endCoordinates: {
        .
        "height": float,
        "screenX": float,
        "screenY": float,
        "width": float
      }
    } as 'b
  );

type listener('a) = event('a) => unit
constraint 'a =
  Js.t(
    {
      ..
      endCoordinates: {
        .
        "height": float,
        "screenX": float,
        "screenY": float,
        "width": float
      }
    } as 'b
  );

type keyboardEvent = [
  | `keyboardDidChangeFrame
  | `keyboardDidHide
  | `keyboardDidShow
  | `keyboardWillChangeFrame
  | `keyboardWillHide
  | `keyboardWillShow
];

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external dismiss : unit => unit = "";

let remove: (unit, subscription) => unit;

let addListener:
  (
    [<
      | `keyboardDidChangeFrame
      | `keyboardDidHide
      | `keyboardDidShow
      | `keyboardWillChangeFrame
      | `keyboardWillHide
      | `keyboardWillShow
    ],
    listener(
      {
        ..
        "endCoordinates": {
          .
          "height": float,
          "screenX": float,
          "screenY": float,
          "width": float
        }
      }
    )
  ) =>
  subscription;

let removeAllListeners:
  [<
    | `keyboardDidChangeFrame
    | `keyboardDidHide
    | `keyboardDidShow
    | `keyboardWillChangeFrame
    | `keyboardWillHide
    | `keyboardWillShow
  ] =>
  unit;

let removeListener:
  (
    [<
      | `keyboardDidChangeFrame
      | `keyboardDidHide
      | `keyboardDidShow
      | `keyboardWillChangeFrame
      | `keyboardWillHide
      | `keyboardWillShow
    ],
    listener(
      {
        ..
        "endCoordinates": {
          .
          "height": float,
          "screenX": float,
          "screenY": float,
          "width": float
        }
      }
    )
  ) =>
  unit;
