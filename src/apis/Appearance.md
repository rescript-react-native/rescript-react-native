---
id: apis/Appearance
title: Appearance
officialDoc: https://reactnative.dev/docs/appearance
---

`Appearance` exposes information about the preferred color scheme (light or
dark).

## Types

### `t`

Returned from the `getColorScheme` method or `useColorScheme` hook, wrapped in
`Js.Null.t` to handle the allowed value `null`, which is returned when no
preference has been indicated. Other allowed values are `"dark"` and `"light"`,
encapsulated as

```rescript
Appearance.dark
Appearance.light
```

These values may be compared against what is returned by the method or hook, as
in the below example:

```rescript
Appearance.getColorScheme() === Js.Null.return(Appearance.dark)
```

## Methods

### `getColorScheme`

To query the current preferred color scheme. Note that the preference may be
updated later, either through user action or automatically (e.g. on a schedule
based on the time of day).

```rescript
getColorScheme: unit => Js.Null(t)
```

### `useColorScheme`

To query the current preferred color scheme and subscribe to color scheme
updates.

```rescript
useColorScheme: unit => Js.Null(t)
```
