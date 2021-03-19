---
id: apis/Packager
title: Packager
---

## `Packager.require`

`Packager.require` is the exact same `require()` you know in React Native. It
returns a type `Packager.required`.

```rescript
let asset = Packager.require("./some/asset.jpg")
```

You can use this for component like [Image](../../components/Image/).
