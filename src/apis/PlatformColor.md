---
id: apis/PlatformColor
title: PlatformColor
officialDoc: https://reactnative.dev/docs/platformcolor
---

Functions to access native colors on the target platform by supplying the native color’s corresponding string value.

> type signature

```

```

```reason
open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      // style may be defined inline
      "container":
        style(
          ~color={
            switch (Platform.os) {
            | os when os == Platform.android =>
              PlatformColor.Android.get(Color(`primary_text_dark))
            | os when os == Platform.ios => PlatformColor.IOS.get(`label)
            | _ => "black"
            };
          },
        ),
    })
  );
```
