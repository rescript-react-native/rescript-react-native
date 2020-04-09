---
id: apis/DevSettings
title: DevSettings
officialDoc: https://reactnative.dev/docs/devsettings
---

`DevSettings` provides methods for developers.

## Types

### `handler`

Alias for `unit => unit`.

### `reason`

Alias for `string`.

### `title`

Alias for `string`.

## Methods

### `addMenuItem`

To add a custom entry to the developer menu. As arguments, takes a `title` (of
type `string`) and a `handler` function (of type `unit => unit`) to be called
when the menu item is pressed.

```reason
addMenuItem: (title, handler) => unit
```

### `reload`

To trigger a reload of the application.

```reason
reload: unit => unit
```

### `reloadWithReason`

To trigger a reload of the application, with a `reason` (of type `string`) which
may be useful for debugging.

```reason
reloadWithReason: reason => unit
```
