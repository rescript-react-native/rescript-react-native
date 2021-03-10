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

See: [UI Element Colors](https://developer.apple.com/documentation/uikit/uicolor/ui_element_colors)

### Android.getAttr

`Android.getAttr` is used to get color information from android attributes.

```reason
getAttr: Android.t => Color.t
```

See: [R.attr](https://developer.android.com/reference/android/R.attr)

### Android.getColor

`Android.getColor` is used to get color information from android colors.

```reason
getColor: Android.t => Color.t
```

See: [R.color](https://developer.android.com/reference/android/R.color)

### Android.unsafeGet

As some people use user-defined attrs for colors and this seems to be supported by React Native, this function is used for getting them using strings.

```reason
unsafeGet: string => Color.t
```

### Android.get{n}

Especially with Android, you may want to get multiple platform colors in case one is not supported by the system. In this case, you can use the `get{n}` function to retrieve the values. You can mix and match Android color and attributes in this call. The first value will be treated as default and rest will be treated as fallback.

Defined up to 7 arguments.

### Android.unsafeGet{n}

The unsafe version of `get{n}` where a string can be passed in. This can be any Android resource query, for example: `?attr/colorPrimary` or `?android:attr/colorPrimary`, even resources defined within your Android app. The first value will be treated as default and rest will be treated as fallback.

Defined up to 7 arguments.

### Android.unsafeGetMultiple

The array version of `unsafeGet{n}` supporting arbitrary number of fallbacks.

```reason
unsafeGetMultiple: array(string) => Color.t
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
              PlatformColor.Android.get2(`primary_text_dark, `colorPrimary)
            | os when os == Platform.ios => PlatformColor.IOS.get(`label)
            | _ => "black"
            };
          },
        ),
    })
  );
```
