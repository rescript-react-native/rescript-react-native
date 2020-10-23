---
id: apis/PlatformColor
title: PlatformColor
officialDoc: https://reactnative.dev/docs/platformcolor
---

Functions to access native colors on the target platform by supplying the native color’s corresponding value.

## Types

The types are polymorphic variants.

### IOS.t

See: [UI Element Colors](https://developer.apple.com/documentation/uikit/uicolor/ui_element_colors)

### Android.t

#### Android.attrColor

See: [R.attr](https://developer.android.com/reference/android/R.attr)

#### Android.androidColor

See: [R.color](https://developer.android.com/reference/android/R.color)

## Methods

### IOS.get

`IOS.get` is used to get color information from UI Element Colors.

```reason
get: IOS.t => Color.t
```

### Android.getAttr

`Android.getAttr` is used to get color information from android attributes.

```reason
getAttr: Android.t => Color.t
```

### Android.getColor

`Android.getColor` is used to get color information from android colors.

```reason
getColor: Android.t => Color.t
```

### Android.unsafeGet

As some people use user-defined attrs for colors and this seems to be supported by React Native, this function is used for getting them using strings.

```reason
unsafeGet: string => Color.t
```

## Example

```reason
open ReactNative;
let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~color={
            switch (Platform.os) {
            | os when os == Platform.android =>
              PlatformColor.Android.getColor(`primary_text_dark)
            | os when os == Platform.ios => PlatformColor.IOS.get(`label)
            | _ => "black"
            };
          },
        ),
    })
  );
```
