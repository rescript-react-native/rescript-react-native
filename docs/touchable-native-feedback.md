---
id: touchable-native-feedback
title: TouchableNativeFeedback
sidebar_label: TouchableNativeFeedback
---

## Exampele of usage

### default

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

# Props

[TouchableWithoutFeedback props...](touchable-without-feedback.md)

## background

```reason
background: string=?
```

## useForeground

```reason
useForeground: bool=?
```
