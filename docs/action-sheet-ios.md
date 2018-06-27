---
title: ActionSheetIOS
---

## Example of use

### showActionSheetWithOptions

```reason
ActionSheetIOS.showActionSheetWithOptions(
  ~options=[|"Agree", "Disagree", "Leave"|],
  ~cancelButtonIndex=2,
  ~destructiveButtonIndex=1,
  buttonIndex =>
    Js.log(
      "You pressed button with index: " ++ string_of_int(buttonIndex),
    ),
  (),
);
```

### showShareActionSheetWithOptions

```reason
ActionSheetIOS.showShareActionSheetWithOptions(
  ~subject="New app",
  ~message="Hello, welcome to my new ReasonML app",
  ~url="https://blog.callstack.com",
  error => Js.log(error),
  (hasSucceeded, methodOfSharing) =>
    Js.log(
      "Has sharing succeeded: "
      ++ string_of_bool(hasSucceeded)
      ++ ", with method: "
      ++ methodOfSharing,
    ),
  (),
);
```

## Funtion parameters

### showActionSheetWithOptions

#### options

```reason
~options: array(string)
```

#### cancelButtonIndex

```reason
~cancelButtonIndex: int=?
```

#### destructiveButtonIndex

```reason
~destructiveButtonIndex: int=?
```

#### title

```reason
~title: string=?
```

#### message

```reason
~message: string=?
```

#### tintColor

```reason
~tintColor: string=?
```

#### callback

```reason
int => unit
```

#### non-labeled argument

```reason
unit
```

### showShareActionSheetWithOptions

#### message

```reason
~message: string=?
```

#### url

```reason
~url: string=?
```

#### subject

```reason
~subject: string=?
```

#### excludedActivityTypes

```reason
~excludedActivityTypes: array(string)=?
```

#### failureCallback

```reason
error => unit
```

#### successCallback

```reason
(bool, string) => unit
```

#### non-labeled argument

```reason
unit
```
