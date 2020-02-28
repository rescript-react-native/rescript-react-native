---
id: apis/Style
title: Style
officialDoc: https://reactnative.dev/docs/style
---

Styles accepted by most components (thanks to a `style` prop) are defined using
style functions that prepare required object for React Native. The style names
and values usually match how CSS works on the web, except names are written
using camel casing, e.g `backgroundColor` rather than `background-color`.

The `style` prop accepts values returned by the `style()` constructor. That's
the simplest way to pass styles. You can also pass an array or list of styles -
the last style in the array has precedence, so you can use this to mix & inherit
styles.

⚠️ _Note that when a component grows in complexity, it is often cleaner to use
[`StyleSheet.create`](../StyleSheet/#create) to define several styles in one
place_.

We have made different style constructors because React Native have various
components that accept different styles props. For example `View` doesn't accept
`color` (only `Text` does).

## Table of Contents

<!-- generated -->

## Style Example

Since an example is worth a thousand words...

```reason
open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        viewStyle(
          ~maxHeight=600.->dp,
          ~width=80.->pct,
          ~justifyContent=`flexStart,
          ~alignItems=`center,
          ~margin=auto,
          (),
        ),
      "cornerThing":
        viewStyle(
          ~position=`absolute,
          ~top=100.->dp,
          ~right=(-20.)->dp,
          ~transform=[|rotate(~rotate=4.->deg)|],
          (),
        ),
      "text": textStyle(~textTransform=`uppercase, ()),
    })
  );

[@react.component]
let make = (~isSomething) => {
  <View style=styles##container>
    <View style=styles##cornerThing>
      <Text
        style=Style.(
          arrayOption([|
            Some(styles##text),
            isSomething ? Some(style(~opacity=0.05, ())) : None,
          |])
        )
      />
    </View>
  </View>;
};
```

## Style Units

### `size`

`size` is required in various style props, to be specified as
density-independant pixels, (`dp` function - also known as logical pixels),
percentage (`pct` function) or also `auto` (inline string, edge case for
`margin`).

As soon as `Style` module is open, you can make `size` in various ways as you
can see in these random examples

- `~height=10.5->dp` (= `~height=dp(10.5)`)
- `~width=55.->pct` (= `~width=pct(55.)`)
- `~margin=auto`

### `offset`

`offset` is used for `shadowOffset` & `textShadowOffset`.

Eg: `~shadowOffset=offset(~height=2., ~width=4.)`

### `angle`

`angle` is used for transforms. It can be expressed in degrees (`deg` function)
or in radians (`rad` function):

- `20.->deg` (eg: `rotateX(~rotateX=20.->deg)`
- `0.5.->rad` (eg: `rotateZ(~rotateZ=0.5->rad)`

## Style Functions

### `Style.style`

For convenience, this function allows you to prepare a style object with all
styles available in React Native. The nice side of this is that you can use this
function & not think about what component is going to use it. On the other hand,
this function can trigger React Native error screen (eg: if you pass `color` to
a `View` component).

`style` accepts all the Style Props:

- [Layout style props](#layout-style-props)
- [Shadow style props](#shadow-style-props)
- [Transform style props](#transform-style-props)
- [View style props](#view-style-props)
- [Text style props](#text-style-props)
- [Image style props](#image-style-props)

⚠️ _Internally, React Native codebase types for this function are called
`____DangerouslyImpreciseStyle_Internal`. That's why we created new functions:
[`viewStyle`](#style-viewstyle), [`textStyle`](#style-textstyle) &
[`imageStyle`](#style-imagestyle)_.

### `Style.viewStyle`

This function accepts all React Native styles below:

- [Layout style props](#layout-style-props)
- [Shadow style props](#shadow-style-props)
- [Transform style props](#transform-style-props)
- [View style props](#view-style-props)

### `Style.textStyle`

This function accepts all React Native styles below:

- [Layout style props](#layout-style-props)
- [Shadow style props](#shadow-style-props)
- [Transform style props](#transform-style-props)
- [Text style props](#text-style-props)

### `Style.imageStyle`

This function accepts all React Native styles below:

- [Layout style props](#layout-style-props)
- [Shadow style props](#shad@ow-style-props)
- [Transform style props](#transform-style-props)
- [Image style props](#image-style-props)

## Style Props

### Layout Style Props

[Official documentation](https://reactnative.dev/docs/layout-props)

#### `alignContent`

Accepts one of the following values:

- `` `flexStart `` (default)
- `` `flexEnd ``
- `` `center ``
- `` `stretch ``
- `` `spaceAround ``
- `` `spaceBetween ``

Controls how rows align in the cross direction, overriding the `alignContent` of
the parent.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/align-content)
- [Yoga reference](https://yogalayout.com/docs/align-content/)

#### `alignItems`

Accepts one of the following values:

- `` `flexStart ``
- `` `flexEnd ``
- `` `center ``
- `` `stretch `` (default)
- `` `baseline ``

Aligns children in the cross direction. For example, if children are flowing
vertically, `alignItems` controls how they align horizontally.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/align-items)
- [Yoga reference](https://yogalayout.com/docs/align-items/)

#### `alignSelf`

Accepts one of the following values:

- `` `auto `` (default)
- `` `flexStart ``
- `` `flexEnd ``
- `` `center ``
- `` `stretch ``
- `` `baseline ``

Controls how a child aligns in the cross direction, overriding the `alignItems`
of the parent.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/align-self)
- [Yoga reference](https://yogalayout.com/docs/align-items/)

#### `aspectRatio`

Accepts a `float`.

Aspect ratio controls the size of the undefined dimension of a node. _Aspect
ratio is a non-standard property only available in react native and not CSS._

- On a node with a set width/height, aspect ratio controls the size of the unset
  dimension
- On a node with a set flex basis, aspect ratio controls the size of the node in
  the cross axis if unset
- On a node with a measure function, aspect ratio works as though the measure
  function measures the flex basis
- On a node with flex grow/shrink, aspect ratio controls the size of the node in
  the cross axis if unset
- Aspect ratio takes min/max dimensions into account

* [Yoga reference](https://yogalayout.com/docs/aspect-ratio/)

#### `bottom`

Accepts a `size`.

Number of logical pixels to offset the bottom edge of this component.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/bottom)
- [Yoga reference](https://yogalayout.com/docs/absolute-relative-layout)

#### `direction`

Accepts one of the following values:

- `` `inherit_ `` (default)
- `` `ltr ``
- `` `rtl ``

`direction` specifies the directional flow of the user interface. The default is
`` `inherit_ ``, except for root node which will have value based on the current
locale.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/bottom)
- [Yoga reference](https://yogalayout.com/docs/layout-direction)

Only for

- iOS

#### `display`

Accepts one of the following values:

- `` `flex `` (default)
- `` `none ``

Sets the display type of this component. It works similarly to `display` in CSS,
but only supports `flex` and `none`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/display)

#### `_end`

Accepts a `size`

When the direction is `ltr`, `end` is equivalent to `right`. When the direction
is `rtl`, `end` is equivalent to `left`. This style takes precedence over the
`left` and `right` styles.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/end)
- [Yoga reference](https://yogalayout.com/docs/layout-direction)

#### `flex`

Accepts a `float`.

In React Native `flex` does not work the same way that it does in CSS. `flex` is
a number rather than a string, and it works according to the Yoga
implementation.

When `flex` is a positive number, it makes the component flexible and it will be
sized proportional to its flex value. So a component with `flex` set to 2 will
take twice the space as a component with `flex` set to 1.

When `flex` is 0, the component is sized according to `width` and `height` and
it is inflexible.

When `flex` is -1, the component is normally sized according `width` and
`height`. However, if there's not enough space, the component will shrink to its
`minWidth` and `minHeight`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/flex)
- [Yoga reference](https://yogalayout.com/docs/flex)

#### `flexBasis`

Accepts a `margin`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/flex-basis)
- [Yoga reference](https://yogalayout.com/docs/flex)

#### `flexDirection`

Accepts one of the following values:

- `` `row ``
- `` `rowReverse ``
- `` `column `` (default)
- `` `columnReverse ``

`flexDirection` controls which directions children of a container go. `row` goes
left to right, `column` goes top to bottom, and you may be able to guess what
the other two do.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/flex-direction)
- [Yoga reference](https://yogalayout.com/docs/flex-direction)

#### `flexGrow`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/flex-grow)
- [Yoga reference](https://yogalayout.com/docs/flex)

#### `flexShrink`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/flex-shrink)
- [Yoga reference](https://yogalayout.com/docs/flex)

#### `flexWrap`

Accepts one of the following values:

- `` `wrap `` (default)
- `` `nowrap ``

`flexWrap` controls whether children can wrap around after they hit the end of a
flex container.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/flex-wrap)
- [Yoga reference](https://yogalayout.com/docs/flex-wrap)

#### `height`

Accepts a `size`.

sets the height of this component.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/height)
- [Yoga reference](https://yogalayout.com/docs/width-height)

#### `justifyContent`

Accepts one of the following values:

- `` `flexStart `` (default)
- `` `flexEnd ``
- `` `center ``
- `` `spaceAround ``
- `` `spaceBetween ``
- `` `spaceEvenly ``

`justifyContent` aligns children in the main direction. For example, if children
are flowing vertically, `justifyContent` controls how they align vertically.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/justify-content)
- [Yoga reference](https://yogalayout.com/docs/justify-content)

#### `left`

Accepts a `size`.

number of logical pixels to offset the left edge of this component.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/left)
- [Yoga reference](https://yogalayout.com/docs/absolute-relative-layout)

#### `margin`

Accepts a `margin`.

Setting `margin` has the same effect as setting each of `marginTop`,
`marginLeft`, `marginBottom`, and `marginRight`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/margin)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `marginBottom`

Accepts a `margin`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/margin-bottom)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `marginEnd`

Accepts a `margin`.

When direction is `ltr`, `marginEnd` is equivalent to `marginRight`. When
direction is `rtl`, `marginEnd` is equivalent to `marginLeft`.

- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `marginHorizontal`

Accepts a `margin`.

Setting `marginHorizontal` has the same effect as setting both `marginLeft` and
`marginRight`.

- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `marginLeft`

Accepts a `margin`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/margin-left)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `marginRight`

Accepts a `margin`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/margin-right)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `marginStart`

Accepts a `margin`.

When direction is `ltr`, `marginStart` is equivalent to `marginLeft`. When
direction is `rtl`, `marginStart` is equivalent to `marginRight`.

- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `marginTop`

Accepts a `margin`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/margin-top)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `marginVertical`

Accepts a `margin`.

Setting `marginVertical` has the same effect as setting both `marginTop` and
`marginBottom`.

- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `maxHeight`

Accepts a `size`.

maximum height for this component, in logical pixels.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/max-height)
- [Yoga reference](https://yogalayout.com/docs/min-max)

#### `maxWidth`

Accepts a `size`.

Maximum width for this component, in logical pixels.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/margin)
- [Yoga reference](https://yogalayout.com/docs/min-max)

#### `minHeight`

Accepts a `size`.

Minimum height for this component, in logical pixels.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/min-height)
- [Yoga reference](https://yogalayout.com/docs/min-max)

#### `minWidth`

Accepts a `size`.

Minimum width for this component, in logical pixels.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/min-width)
- [Yoga reference](https://yogalayout.com/docs/min-max)

#### `overflow`

Accepts one of the following values:

- `` `visible `` (default)
- `` `hidden ``
- `` `scroll ``

`overflow` controls how children are measured and displayed. `` `hidden ``
causes views to be clipped while `` `scroll `` causes views to be measured
independently of their parents main axis.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/overflow)

#### `padding`

Accepts a `size`.

Setting `padding` has the same effect as setting each of `paddingTop`,
`paddingBottom`, `paddingLeft`, and `paddingRight`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/padding)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `paddingBottom`

Accepts a `size`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/padding-bottom)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `paddingEnd`

Accepts a `size`.

When direction is `ltr`, `paddingEnd` is equivalent to `paddingRight`. When
direction is `rtl`, `paddingEnd` is equivalent to `paddingLeft`.

- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `paddingHorizontal`

Accepts a `size`.

Setting `paddingHorizontal` is like setting both of `paddingLeft` and
`paddingRight`.

- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `paddingLeft`

Accepts a `size`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/padding-left)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `paddingRight`

Accepts a `size`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/padding-right)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `paddingStart`

Accepts a `size`.

When direction is `ltr`, `paddingStart` is equivalent to `paddingLeft`. When
direction is `rtl`, `paddingStart` is equivalent to `paddingRight`.

- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `paddingTop`

Accepts a `size`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/padding-top)
- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `paddingVertical`

Accepts a `size`.

Setting `paddingVertical` is like setting both of `paddingTop` and
`paddingBottom`.

- [Yoga reference](https://yogalayout.com/docs/margins-paddings-borders)

#### `position`

Accepts one of the following values:

- `` `absolute ``
- `` `relative `` (default)

`position` in React Native is similar to regular CSS, but everything is set to
`relative` by default, so `absolute` positioning is always just relative to the
parent.

If you want to position a child using specific numbers of logical pixels
relative to its parent, set the child to have `absolute` position.

If you want to position a child relative to something that is not its parent,
just don't use styles for that. Use the component tree.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/position)
- [Yoga reference](https://yogalayout.com/docs/absolute-relative-layout)

#### `right`

Accepts a `size`.

Number of logical pixels to offset the right edge of this component.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/right)
- [Yoga reference](https://yogalayout.com/docs/absolute-relative-layout)

#### `start`

Accepts a `size`.

When the direction is `ltr`, `start` is equivalent to `left`. When the direction
is `rtl`, `start` is equivalent to `right`.

This style takes precedence over the `left`, `right`, and `end` styles.

- [Yoga reference](https://yogalayout.com/docs/absolute-relative-layout)

#### `top`

Accepts a `size`.

Number of logical pixels to offset the top edge of this component.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/top)
- [Yoga reference](https://yogalayout.com/docs/absolute-relative-layout)

#### `width`

Accepts a `size`.

Sets the width of this component.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/width)
- [Yoga reference](https://yogalayout.com/docs/width-height)

#### `zIndex`

Accepts an `int`.

`zIndex` controls which components display on top of others. Normally, you don't
use `zIndex`. Components render according to their order in the document tree,
so later components draw over earlier ones. `zIndex` may be useful if you have
animations or custom modal interfaces where you don't want this behavior.

It works like the CSS `z-index` property - components with a larger `zIndex`
will render on top. Think of the z-direction like it's pointing from the phone
into your eyeball.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/z-index)

### Shadow Style Props

[Official documentation](https://reactnative.dev/docs/shadow-props)

Use `elevation` style props for Android.

#### `shadowColor`

Accepts a `Color.t` (`string`).

Sets the drop shadow color

Only for

- iOS

You can see it as CSS `box-shadow` color

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/box-shadow)

#### `shadowOffset`

Accepts an `offset`.

Sets the drop shadow offset

Only for

- iOS

You can see it as CSS `box-shadow` offsets

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/box-shadow)

#### `shadowOpacity`

Accepts a `float`.

Sets the drop shadow opacity (multiplied by the color's alpha component)

Only for

- iOS

You can see it as CSS `box-shadow` color alpha value

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/box-shadow)

#### `shadowRadius`

Accepts a `float`.

Sets the drop shadow blur radius

Only for

- iOS

You can see it as CSS `box-shadow` blur radius

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/box-shadow)

### Transform Style Props

[Official documentation](https://reactnative.dev/docs/transforms)

⚠️ _We only included `transform` prop as other have been deprecated._

#### `transform`

Accepts an array of `transform`.

Keep in mind that order or transformation matters.

- `perspective(~perspective=float)`
- `rotate(~rotate=angle)`
- `rotateX(~rotateX=angle)`
- `rotateY(~rotateY=angle)`
- `rotateZ(~rotateZ=angle)`
- `scale(~scale=float)`
- `scaleX(~scaleX=float)`
- `scaleY(~scaleY=float)`
- `translateX(~translateX=float)`
- `translateY(~translateY=float)`
- `skewX(~skewX=angle)`
- `skewY(~skewY=angle)`

##### Transform Examples

###### Transform with multiple transform

```reason
Style.(style(
  ~transform=[|
    perspective(~perspective=1000.),
    rotateX(~rotateX=20.->deg),
    rotateZ(~rotateZ=0.5->rad),
    scale(~scale=0.95),
  |],
  ()
))
```

###### Transform with an animated value

```reason
Style.(style(
  ~transform=[|
    rotateY(
      ~rotateY=
        Animated.Interpolation.(
          scrollYAnimatedValue->interpolate(
            config(
              ~inputRange=[|0., 200.|],
              ~outputRange=
                [|"-10deg", "-14deg"|]->fromStringArray,
              ~extrapolateLeft=`clamp,
              ~extrapolate=`identity,
              ~extrapolateRight=`extend,
              (),
            ),
          )
        )
        ->Animated.StyleProp.angle,
    ),
    scale(
      ~scale=
        Animated.Interpolation.(
          scrollYAnimatedValue->interpolate(
            config(
              ~inputRange=[|0., 200.|],
              ~outputRange=[|0.8, 0.75|]->fromFloatArray,
              (),
            ),
          )
        )
        ->Animated.StyleProp.float,
    ),
  |],
  (),
))
```

If you need something unsupported by this binding, you can use
`unsafeTransform`.

```reason
Style.(style(
  ~transform=[|
    unsafeTransform({"translateZ": "0"}),
  |],
  (),
))
```

### View Style Props

[Official documentation](https://reactnative.dev/docs/view-style-props)

#### `backfaceVisibility`

Accepts one of the following values:

- `` `visible ``
- `` `hidden ``

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/backface-visibility)

#### `backgroundColor`

Accepts a `Color.t` (`string`).

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/background-color)

#### `borderBottomColor`

Accepts a `Color.t` (`string`).

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-bottom-color)

#### `borderBottomEndRadius`

Accepts a `float`.

When direction is `ltr`, `borderBottomEndRadius` is equivalent to
`borderBottomRightRadius`. When direction is `rtl`, `borderBottomEndRadius` is
equivalent to `borderBottomLeftRadius`.

#### `borderBottomLeftRadius`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-bottom-left-radius)

#### `borderBottomRightRadius`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-bottom-right-radius)

#### `borderBottomStartRadius`

Accepts a `float`.

When direction is `ltr`, `borderBottomStartRadius` is equivalent to
`borderBottomLeftRadius`. When direction is `rtl`, `borderBottomStartRadius` is
equivalent to `borderBottomRightRadius`.

#### `borderBottomWidth`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-bottom-width)

#### `borderColor`

Accepts a `Color.t` (`string`).

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-color)

#### `borderEndColor`

Accepts a `Color.t` (`string`).

When direction is `ltr`, `borderEndColor` is equivalent to `borderRightColor`.
When direction is `rtl`, `borderEndColor` is equivalent to `borderLeftColor`.

#### `borderEndWidth`

Accepts a `float`.

When direction is `ltr`, `borderEndWidth` is equivalent to `borderRightWidth`.
When direction is `rtl`, `borderEndWidth` is equivalent to `borderLeftWidth`.

#### `borderLeftColor`

Accepts a `Color.t` (`string`).

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-left-color)

#### `borderLeftWidth`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-left-width)

#### `borderRadius`

Accepts a `float`.

Rounds the corners of an element's outer border edge.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-radius)

#### `borderRightColor`

Accepts a `Color.t` (`string`).

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-right-color)

#### `borderRightWidth`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-right-width)

#### `borderStartColor`

Accepts a `Color.t` (`string`).

When direction is `ltr`, `borderStartColor` is equivalent to `borderLeftColor`.
When direction is `rtl`, `borderStartColor` is equivalent to `borderRightColor`.

#### `borderStartWidth`

Accepts a `float`.

When direction is `ltr`, `borderStartWidth` is equivalent to `borderLeftWidth`.
When direction is `rtl`, `borderStartWidth` is equivalent to `borderRightWidth`.

#### `borderStyle`

Accepts one of the following values:

- `` `solid `` (default)
- `` `dotted ``

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-style)

#### `borderTopColor`

Accepts a `Color.t` (`string`).

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-top-color)

#### `borderTopEndRadius`

Accepts a `float`.

When direction is `ltr`, `borderTopEndRadius` is equivalent to
`borderTopRightRadius`. When direction is `rtl`, `borderTopEndRadius` is
equivalent to `borderTopLeftRadius`.

#### `borderTopLeftRadius`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-top-left-radius)

#### `borderTopRightRadius`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-top-right-radius)

#### `borderTopStartRadius`

Accepts a `float`.

When direction is `ltr`, `borderTopStartRadius` is equivalent to
`borderTopLeftRadius`. When direction is `rtl`, `borderTopStartRadius` is
equivalent to `borderTopRightRadius`.

#### `borderTopWidth`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-top-width)

#### `borderWidth`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/border-width)

#### `elevation`

Accepts a `float`.

Sets the elevation of a view, using Android's underlying
[elevation API](https://developer.android.com/training/material/shadows-clipping.html#Elevation).
This adds a drop shadow to the item and affects z-order for overlapping views.
Only supported on Android 5.0+, has no effect on earlier versions.

Only for

- Android

Use `shadow*` style props for iOS.

#### `opacity`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/opacity)

### Text Style Props

#### `color`

Accepts a `Color.t` (`string`).

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/color)

#### `fontFamily`

Accepts a `string`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/font-family)

#### `fontSize`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/font-size)

#### `fontStyle`

Accepts one of the following values:

- `` `normal `` (default)
- `` `italic ``

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/font-style)

#### `fontVariant`

Accepts an array of `FontVariant.t`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/font-variant)

#### `fontWeight`

Accepts one of the following values:

- `` `normal `` (default)
- `` `bold ``
- `` `_100 ``
- `` `_200 ``
- `` `_300 ``
- `` `_400 ``
- `` `_500 ``
- `` `_600 ``
- `` `_700 ``
- `` `_800 ``
- `` `_900 ``

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/font-weight)

#### `includeFontPadding`

Accepts a `bool`.

#### `letterSpacing`

Accepts a `float`.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/letter-spacing)

#### `lineHeight`

Accepts a `float`.

Only accepts logical pixels.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/letter-spacing)

#### `textAlign`

Accepts one of the following values:

- `` `auto `` (default)
- `` `left ``
- `` `right ``
- `` `center ``
- `` `justify ``

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/text-align)

#### `textAlignVertical`

Accepts one of the following values:

- `` `auto `` (default)
- `` `top ``
- `` `bottom ``
- `` `center ``

#### `textDecorationColor`

Accepts a `Color.t` (`string`).

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/text-decoration-color)

#### `textDecorationLine`

Accepts one of the following values:

- `` `none `` (default)
- `` `underline ``
- `` `lineThrough ``
- `` `underlineLineThrough ``

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/text-decoration-line)

#### `textDecorationStyle`

Accepts one of the following values:

- `` `solid ``
- `` `double ``
- `` `dotted ``
- `` `dashed ``

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/text-decoration-style)

#### `textShadowColor`

Accepts a `Color.t` (`string`).

You can see it as CSS `text-shadow` blur radius.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow)

#### `textShadowOffset`

Accepts an `offset`.

You can see it as CSS `text-shadow` offsets.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow)

#### `textShadowRadius`

Accepts a `float`.

You can see it as CSS `text-shadow` blur radius.

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow)

#### `textTransform`

Accepts one of the following values:

- `` `none `` (default)
- `` `uppercase ``
- `` `lowercase ``
- `` `capitalize ``

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/text-transform)

#### `writingDirection`

Accepts one of the following values:

- `` `auto `` (default)
- `` `ltr ``
- `` `rtl ``

### Image Style Props

#### `resizeMode`

Accepts one of the following values:

- `` `cover ``
- `` `contain ``
- `` `stretch ``
- `` `repeat ``
- `` `center ``

Similar to CSS `background-size` values

- [Web reference](https://developer.mozilla.org/en-US/docs/Web/CSS/background-size)

#### `overlayColor`

Accepts a `Color.t` (`string`).

#### `tintColor`

Accepts a `Color.t` (`string`).

### Unsafe Style Props

⚠️ _Use only as an escape hatch. Don't overuse these functions._

In case you want to use something unsupported by this binding, you can use
`unsafeAddStyle` & `unsafeStyle`.

For example, if you want to use `position: fixed` on the web, you can do the
following

```reason
Style.(unsafeStyle({"position": "fixed", "top": "5em", "left": 0, "right": 0}))
```

If you only want to add some properties to a safe style, you can also do

```reason
Style.(
  style(
    ~left=0.->dp,
    ~right=0.->dp,
    ()
  )
  ->unsafeAddStyle({"position": "fixed", "top": "5em"})
)
```

---

## Style Helpers

### `Style.array`

Accepts an array of styles as a single style.

```reason
<View style=Style.(array([|
  styles##thing,
  styles##whatever,
|]))>
```

### `Style.arrayOption`

Accepts an array of optional styles as a single style.

```reason
<View style=Style.(arrayOption([|
  Some(styles##thing),
  Some(styles##whatever),
  optionalStyle,
  cond ? Some(style(~prop=value, ()) : None
|]))>
```

### `Style.list`

Accepts a list of styles as a single style.

```reason
<View style=Style.(list([
  styles##thing,
  styles##whatever,
]))>
```

### `Style.listOption`

Accepts a list of optional styles as a single style.

```reason
<View style=Style.(listOption([
  Some(styles##thing),
  Some(styles##whatever),
  optionalStyle,
  cond ? Some(style(~prop=value, ()) : None
]))>
```
