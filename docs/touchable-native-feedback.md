---
title: TouchableNativeFeedback
---

## Exampele of usage

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <TouchableNativeFeedback>
      <View style=Style.(style([backgroundColor(String("#03DAC5"))]))>
        <Text style=Style.(style([height(Pt(50.))]))>
          (ReasonReact.string("Press the button"))
        </Text>
      </View>
    </TouchableNativeFeedback>,
};
```

## Props

### TouchableWithoutFeedback props...

[props...](touchable-without-feedback.md)

### background

```reason
background: string=?
```

### useForeground

```reason
useForeground: bool=?
```

## Methods

[RN docs](https://facebook.github.io/react-native/docs/touchablenativefeedback.html#methods-1)

### selectableBackground

```reason
 unit => t;
```

### selectableBackgroundBorderless

```reason
  unit => t
```

### canUseNativeForeground

```reason
  unit => t
```

### ripple

```reason
(string, bool) => t;
``
```
