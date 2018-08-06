---
title: Clipboard
---

## Example of use

### setString

```reason
Clipboard.setString("Let's save some text to clipboard.");
```

### getString

```reason
Clipboard.getString()
|> Js.Promise.then_(text => Js.Promise.resolve(Js.log(text)))
|> ignore;
```

## Function parameters

### getString

```reason
unit => Js.Promise.t(string);
```

### setString

```reason
string => unit;
```
