---
title: MaskedViewIOS
---

Rendes the child view with a mask specified in the [`maskElement`](#maskelement) prop.

## Example of use

The following example demonstrates rendering a View with red background behind a mask, defined as a `Basic mask` string.

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <MaskedViewIOS
      maskElement={
        <View
          style=Style.(
                  style([
                    flex(1.),
                    justifyContent(Center),
                    alignItems(Center),
                    backgroundColor(String("transparent")),
                  ])
                )>
          <Text
            style=Style.(
                    style([
                      fontSize(Float(50.0)),
                      color(String("black")),
                      fontWeight(`_700),
                    ])
                  )>
            (ReasonReact.string("Basic mask"))
          </Text>
        </View>
      }>
        <View
          style=Style.(style([flex(1.), backgroundColor(String("red"))]))
        />
      </MaskedViewIOS>,
};
```

See more examples in [RN docs](https://facebook.github.io/react-native/docs/maskedviewios#example).

## Props

All [View](/docs/View.html#props) props are accepted.

### maskElement


