---
id: apis/StyleSheet
title: StyleSheet
officialDoc: https://reactnative.dev/docs/stylesheet
---

`StyleSheet` mainly has a method to [create](#create) an object containing many
styles, similar to a CSS StyleSheet. This is helpful to keep style definitions
at fewer locations, away from the render function. Separating concerns in your
code in this manner should help readability. Named styles might also help
differentiate between your components. Finally, allowing components to refer to
styles by ID, it also reduces the amount of data transferred over the JS bridge.

There is also a [`flatten`](#flatten) method to merge multiple styles into a
single style and several [constants](#constants) for commonly used style
definitions.

## Methods

### `create`

Takes and returns `Js.t('a)` objects, with `string` keys and `Style.t` values.
Individual styles can be accessed using `##`, followed by the name specified as
the key.

Note that using `Style.array` or `Style.list` to pass `array(Style.t)` or
`list(Style.t)` is illegal within a `StyleSheet`, even those are valid `style`
props for components. You may, howevever, use the [`flatten`](#flatten) method
to convert `array(Style.t)` into a valid `Style.t` object.

```reason
create: Js.t('a) => Js.t('a)
```

### `flatten`

Takes an array of styles (of type `Style.t`) and returns a single style (also of
type `Style.t`). Creates a `Style.t` object which is valid in a `StyleSheet`.

```reason
flatten: array(Style.t) => Style.t
```

## Constants

### `hairlineWidth`

To ensure the resulting line will look sharp, this specifies an integer number
of pixels which should approximate the standard thickness of a thin line on the
platform given the screen density.

```reason
hairlineWidth: float
```

### `absoluteFill`

This is the style

```js
{
  position: 'absolute',
  left: 0,
  right: 0,
  top: 0,
  bottom: 0
}
```

which is frequently used to create overlays. A common use is to add these props
to a style using the spread operator (`...`), but as ReasonML does not allow the
operator when fields are not explicitly set, you may use the `flatten` method
instead.

```reason
absoluteFill: Style.t
```

### `absoluteFillObject`

This is identical to `absoluteFill` when used with pure functions.

```reason
absoluteFillObject: Style.t
```

## Example

Please also see the [example](../Style/#style-example) in documentation of the
`Style` API.

```reason
open ReactNative;

let borderStyle = Style.(style(~borderWidth=StyleSheet.hairlineWidth, ()));

let styles =
  Style.(
    StyleSheet.create({
      // style may be defined inline
      "container": style(~flex=1., ~flexDirection=`column, ()),
      "screen": style(~width=windowWidth->dp, ()),
      // or already defined elsewhere
      "borderStyle": borderStyle,
      "overlay": StyleSheet.absoluteFill,
    })
  );

let flatStyle = StyleSheet.flatten([|styles##container, styles##screen|]);
```
