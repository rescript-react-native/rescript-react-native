---
id: apis/PlatformColor
title: PlatformColor
officialDoc: https://reactnative.dev/docs/platformcolor
---

Functions to access native colors on the target platform by supplying the native color’s corresponding value.

## Ios

### Ios.get

`Ios.get` is used to get color information from UI Element Colors.

```reason
get: Ios.t => Color.t
```

#### Ios.get{n}

Methods to send fallbacks.

## Android

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

### Android.get

Allow to get color or attr.

#### Android.get{n}

You may want to get multiple platform colors in case one is not supported by the system. In this case, you can use the `get{n}` function to retrieve the values. You can mix and match Android color and attributes in this call. The first value will be treated as default and rest will be treated as fallback.

Defined up to 7 arguments.

## unsafeGet

Depending on platform & OS version (and for Android you can have user-defined attrs for colors), this function is used for getting platform colors from strings.

```reason
unsafeGet: string => Color.t
```

### unsafeGet{n}

The unsafe version of `get{n}` where a string can be passed in. This can be any Android resource query, for example: `?attr/colorPrimary` or `?android:attr/colorPrimary`, even resources defined within your Android app. The first value will be treated as default and rest will be treated as fallback.

Defined up to 7 arguments.

### unsafeGetMultiple

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
            | os when os == Platform.ios => PlatformColor.Ios.get(`label)
            | _ => "black"
            };
          },
        ),
    })
  );
```
