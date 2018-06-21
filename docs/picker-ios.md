---
id: picker-ios
title: PickerIOS
sidebar_label: PickerIOS
---

## Example of use

In order to render a PickerIOS component you will need to pass one or many PickerIOS.Item component(s) as children.

And PickerIOS.Item has a required label prop

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <View>
      <PickerIOS>
        <PickerIOS.Item label="ReasonML" value="reason" />
        <PickerIOS.Item label="Ocaml" value="ocaml" />
        <PickerIOS.Item label="JavaScript" value="js" />
      </PickerIOS>
    </View>,
};
```

### selectedValue and onValueChange

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <View>
      <PickerIOS selectedValue="ocaml" onValueChange=(value => Js.log(value))>
        <PickerIOS.Item label="ReasonML" value="reason" />
        <PickerIOS.Item label="Ocaml" value="ocaml" />
        <PickerIOS.Item label="JavaScript" value="js" />
      </PickerIOS>
    </View>,
};  
```

## Props

### itemStyle

```reason
itemStyle: Style.t=?
```

### onValueChange

```reason
onValueChange: 'value => unit=?
```

### selectedValue

```reason
selectedValue: 'value=?
```
