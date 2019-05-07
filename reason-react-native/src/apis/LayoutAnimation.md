---
id: apis/LayoutAnimation
title: LayoutAnimation
wip: false
---

`LayoutAnimation` API offers a simpler alternative to `Animated` API. Instead of directly manipulating values for various style props, it suffices to specify the animation to be run before the next render. Specification of the animation should happen in the reducer, before `state` is updated.

## Methods

- `configureNext` is the method to specify the animation, takes an argument of type `layoutAnimationConfig`.

```reason
configureNext(layoutAnimationConfig)
```

- `configureNextWithEndCallback` is a convenience function, which allows specification of a callback function (of type `unit => unit`) to be run after the animation, in addition to `layoutAnimationConfig`.
```reason
configureNextWithEndCallback(layoutAnimationConfig, callback)
```


## Types

`layoutAnimationConfig` can be created with the `layoutAnimationConfig` constructor
```reason
layoutAnimationConfig:
  (
    ~duration: float,
    ~create: animationConfig=?,
    ~update: animationConfig=?,
    ~delete: animationConfig=?,
    unit
  )
```
or by means of the helper function `create`

```reason
create:
  (
    ~duration: float,
    ~_type: [@bs.string] [
              | `spring
              | `linear
              | `easeInEaseOut
              | `easeIn
              | `easeOut
              | `keyboard
            ],
    ~property: [@bs.string] [ | `opacity | `scaleX | `scaleY | `scaleXY]
  )
```



`animationConfig` can in turn be created with the `animationConfig` constructor

```reason
animationConfig:
  (
    ~duration: float=?,
    ~delay: float=?,
    ~springDamping: float=?,
    ~initialVelocity: float=?,
    ~_type: [@bs.string] [
              | `spring
              | `linear
              | `easeInEaseOut
              | `easeIn
              | `easeOut
              | `keyboard
            ]
              =?,
    ~property: [@bs.string] [ | `opacity | `scaleX | `scaleY | `scaleXY]=?,
    unit
  )
```



## Presets

There are presets for `linear`, `spring` and `easeInEaseOut` transitions which allow a very straightforward way to setup animation. Presets may either be passed as ready-made `layoutAnimationConfig` to `configureNext` and `configureNextWithEndCallback` as below

```reason
LayoutAnimation.configureNext(LayoutAnimation.Presets.spring)
```
or equivalently as already passed to `configureNext` as

```reason
LayoutAnimation.spring()

```



## Example

The example below illustrates animated transition (`spring`) between two views, such as registration and login forms. Animation is specified in the reducer, as below. Making use of `presets` is also illustrated (commented out).


```reason
open ReactNative;

let windowWidth = float_of_int(Dimensions.get(`window)##width);

type state = {register: bool};

type action =
  | ToggleRegister;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | ToggleRegister =>
          // Animation should be specified here, before state is updated:
          LayoutAnimation.configureNext(
            LayoutAnimation.create(
              ~duration=500.,
              ~_type=`spring,
              ~property=`opacity,
            ),
          );
          // update of the state happens below:
          {register: !state.register};
        },
      {register: false},
    );

  <View style={Style.style(~flex=1., ~flexDirection=`column, ())}>
    <View
      style={Style.style(
        ~flex=1.,
        ~width=Style.pt(2.0 *. windowWidth),
        ~left=
          Style.pt(
            if (state.register) {
              0.;
            } else {
              0. -. windowWidth;
            },
          ),
        ~flexDirection=`row,
        (),
      )}>
      <View style={Style.style(~width=Style.pt(windowWidth), ())}>
        <Register />
      </View>
      <View style={Style.style(~width=Style.pt(windowWidth), ())}>
        <Login />
      </View>
    </View>
    <Button onPress={_ => dispatch(ToggleRegister)} title={js|Toggle|js} />
  </View>;
};
```

Above animation specification is that of the `spring` preset. Accordingly, the animation could have been specified as
```reason
LayoutAnimation.configureNext(LayoutAnimation.Presets.spring);
```
or equivalently as
```reason
LayoutAnimation.spring();
```
