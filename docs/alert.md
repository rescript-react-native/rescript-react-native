---
title: Alert
---

## Example of use

```reason
Alert.alert(
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

### title

```reason
~title: string
```

### message

```reason
~message: string=?
```

### buttons

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

### options

```reason
~options: options=?
```

_reference:_

```reason
type options = {
  cancelable: option(bool),
  onDismiss: option((unit => unit))
};
```

### type\_

```reason
~type_: [< | `default | `loginPassword | `plainText | `secureText]=?
```

### non-labeled argument

```reason
unit
```
