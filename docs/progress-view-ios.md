---
id: progress-view-ios
title: ProgressViewIOS
sidebar_label: ProgressViewIOS
---

## Example of use

### default

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self => <ProgressViewIOS progress=0.4 progressTintColor="tomato" />,
};
```

## Props

### progress

```reason
progress: float=?
```

### progressImage

```reason
progressImage: Image.imageSource=?
```

### progressTintColor

```reason
progressTintColor: string=?
```

### progressViewStyle

```reason
progressViewStyle: Style.t=?
```

### trackImage

```reason
trackImage: Image.imageSource=?
```

### trackTintColor

```reason
trackTintColor: string=?
```
