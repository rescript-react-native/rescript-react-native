---
title: AlertIOS
---

## Example of use

### alert

```reason
AlertIOS.alert(
  ~title="This is an alert",
  ~message="Do something about it",
  ~buttons=[
    {
      text: Some("Agree"),
      onPress: Some(() => Js.log("You pressed the default button")),
      style: Some(`default),
    },
    {
      text: Some("Cancel"),
      onPress: Some(() => Js.log("You pressed the cancel button")),
      style: Some(`cancel),
    },
    {
      text: Some("Disagree"),
      onPress:
        Some(() => Js.log("You pressed the destructive button")),
      style: Some(`destructive),
    },
  ],
  (),
);
```

### prompt

```reason
AlertIOS.prompt(
  ~title="This is an alert",
  ~message="Do something about it",
  ~type_=`secureText,
  ~buttons=[
    {
      text: Some("Something bad will happen"),
      onPress: Some(() => Js.log("Bad happened")),
      style: Some(`destructive),
    },
  ],
  (),
);
```

## Function parameters

### alert

#### title

```reason
~title: string
```

#### message

```reason
~message: string=?
```

#### buttons

```reason
~buttons: list(button)=?
```

_reference:_

```reason
type button = {
  text: option(string),
  onPress: option((unit => unit)),
  style: option([ | `cancel | `default | `destructive])
};
```

#### type\_

```reason
~type_: [< | `default | `loginPassword | `plainText | `secureText]=?
```

#### non-labeled argument

```reason
unit
```

### prompt

#### title

```reason
~title: string
```

#### message

```reason
~message: string=?
```

#### buttons

```reason
~buttons: list(button)=?
```

#### type\_

```reason
~type_: [< | `default | `loginPassword | `plainText | `secureText]=?
```

#### defaultValue

```reason
~defaultValue: string=?
```

#### keyboardType

```reason
~keyboardType: [<
                  | `asciiCapable
                  | `decimalPad
                  | `default
                  | `emailAddress
                  | `namePhonePad
                  | `numberPad
                  | `numbersAndPunctuation
                  | `numeric
                  | `phonePad
                  | `twitter
                  | `url
                  | `webSearch
                ]
                  =?
```

#### non-labeled argument

```reason
unit
```
