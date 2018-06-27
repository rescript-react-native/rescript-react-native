---
title: ProgressBarAndroid
---

## Example of use

### Horizontal

```reason
 let component = ReasonReact.statelessComponent("ExampleInverse");

  let make = _children => {
    ...component,
    render: _children =>
      <View>
        <ProgressBarAndroid styleAttr=`Horizontal />
        <ProgressBarAndroid styleAttr=`Horizontal color="#2196F3" />
        <ProgressBarAndroid styleAttr=`Horizontal progress=0.5 />
      </View>,
  };
```

### Inverse

```reason
 let component = ReasonReact.statelessComponent("ExampleInverse");

  let make = _children => {
    ...component,
    render: _children =>
      <View>
        <ProgressBarAndroid styleAttr=`Inverse />
        <ProgressBarAndroid styleAttr=`Inverse color="#2196F3" />
      </View>,
  };
```

## Props

[View props...](view.html)

### color

```reason
~color: string=?,
```

### animating

```reason
~animating: bool=?,
```

### indeterminate

Aviable only if StyleAttr=`Horizontal

```reason
~indeterminate: bool=?,
```

### progress

Value between 0 and 1

```reason
~progress: float=?,
```

### styleAttr

```reason
~styleAttr: [
                | `Horizontal
                | `Normal (default)
                | `Small
                | `Large
                | `Inverse
                | `SmallInverse
                | `LargeInverse
            ]
                =?,
```

### testID

```reason
~testID: string=?,
```
