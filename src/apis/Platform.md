---
id: apis/Platform
title: Platform
officialDoc: https://reactnative.dev/docs/platform-specific-code
---

## `Platform.os`

React Native provides a module that detects the platform in which the app is
running. You can use the detection logic to implement platform-specific code.
Use this option when only small parts of a component are platform-specific.

```rescript
if Platform.os === Platform.ios {
  // your code
}
```

`Platform.os` can be

- `Platform.ios` when running on iOS
- `Platform.android` when running on Android.
- `Platform.web` when running on the web (via
  [`react-native-web`](https://github.com/necolas/react-native-web)).

If you need an unsupported platform, you can use `Platform.unsafe(string)`.

For conditional style depending on the platform, you can do the following:

```rescript
let styles = StyleSheet.create({
  open Style
  {
    "wrapper": style(~width=pct(Platform.os == Platform.ios ? 100. : 200.), ()),
  }
})
```

## `Platform.select`

_⚠️ Unsupported._

This feature isn't relevant with ReScript. Instead you can do the following:

```rescript
open Style
let styles = {
  "wrapper": style(
    ~width=switch Platform.os {
    | os if os == Platform.ios => 100.
    | os if os == Platform.android => 200.
    | os if os == Platform.web => 250.
    | os if os == Platform.unsafe("windows") => 300.
    | _ => 150.
    }->pct,
    (),
  ),
}->StyleSheet.create
```

Also since spreading things in ReScript is not supported (because of the
unsafety aspect), it's even less relevant to have this binding.
