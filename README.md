# [BuckleScript](https://github.com/bloomberg/bucklescript) bindings for [React Native](https://github.com/facebook/react-native)
[![CircleCI](https://circleci.com/gh/callstack/rebolt.svg?style=svg)](https://circleci.com/gh/callstack/rebolt)

## Getting started

Great that you want to use Reason with React Native! To get everything running are just a couple of steps.
Let's assume that you already have a React Native project. Otherwise follow the React Native [instructions](http://facebook.github.io/react-native/docs/getting-started.html) until you have your app running.

1. Install [Bucklescript](https://github.com/bloomberg/bucklescript) (the Reason -> JS compiler), [Reason-React](https://github.com/reasonml/reason-react) and `bs-react-native`:
```sh
# substitute yarn with npm if you prefer
yarn add bs-platform reason-react bs-react-native
```

2. Create a `re` folder (there will be your Reason code)
3. Create a `bsconfig.json` with the following content file in your project root
```json
{
    "name": "my-awesome-app",
    "reason": {
        "react-jsx": 2
    },
    "bsc-flags": ["-bs-super-errors"],
    "bs-dependencies": ["bs-react-native", "reason-react"],
    "sources": [{
        "dir": "re"
    }],
    "refmt": 3
}
```
4. You are nearly done, the last configuration before we get to the fun stuff. In your `package.json` add to the `"scripts"` section two scripts:

```json
"scripts": {
  ...
  "build": "bsb -make-world -clean-world",
  "watch": "bsb -make-world -clean-world -w"
}
```

5. Now you can build all your (so far nonexsisting) Reason in two modes:
  - `yarn build` performs a single build
  - `yarn watch` enters the watch mode
6. Now we come to the fun stuff! Create a new file `re/app.re` and make it look like this:
```reason
open BsReactNative;

let app = () =>
  <View style=Style.(style([flex(1.), justifyContent(Center), alignItems(Center)]))>
    <Text value="Reason is awesome!" />
  </View>;
```
and start the watcher with `yarn run watch` if you haven't done it yet.

7. We are nearly done! We now have to adopt the `index.ios.js` / `index.android.js` to look like this
```js
import { app } from "./lib/js/re/app.js";
import React from "react";
import {
  AppRegistry
} from 'react-native';

AppRegistry.registerComponent('MyAwesomeProject', () => app);
```
**Note:** Make sure that the first argument to `AppRegistry.registerComponent` is **your** correct project name.

If you are using `react-native-scripts`, then you will need to modify `App.js` to be like this
```js
import { app } from "./lib/js/re/app.js";

export default app;
```

8. Now go to a new tab and start your app with `react-native run-ios` or `react-native run-android`.

9. Great you are all set up! Check the source of `bs-react-native` to find out more about the implemented APIs and Components. If you get stuck just ask on our [Discord Server](https://discord.gg/reasonml)! Happy Hacking!


Here are some more things which will be probably useful for you:
- [Reason-React Documentation](https://reasonml.github.io/reason-react/)
- [Bucklescript Manual](http://bucklescript.github.io/bucklescript/Manual.html)

## Can I really build my React Native app with Reason?
Yes! Check out the [Seattle JS Conf App](https://github.com/FormidableLabs/seattlejsconf-app) for a real world App written with Reason.

### Disclaimer

There are some components and APIs missing. You can find an overview of the implemented components and APIs [here](STATUS.md). Contributions of Components and APIs are very welcome! The bindings are targeted to React Native **0.46+**.

## Style
Since we have a proper type system we can make styles **typesafe**! Therefore styles are a little bit different declared than in JavaScript:
```reason
open BsReactNative;

/* inline styles */
<View
  style=(
    Style.style([
      Style.flexDirection(Column),
      Style.backgroundColor(String("#6698FF")),
      Style.marginTop(Pt(5.))
    ])
  )
/>;

/* inline styles with a local open */
<View style=Style.(style([flexDirection(Column), backgroundColor(String("#6698FF")), marginTop(Pt(5.))])) />;

/* StyleSheets with a local open */
let styles =
  StyleSheet.create(
    Style.({"wrapper": style([flexDirection(Column), backgroundColor(String("#6698FF")), marginTop(Pt(5.))])})
  );

<View style=styles##wrapper />;
```

### Animations

```reason
open BsReactNative;

[...]
type state = {animatedValue: Animated.Value.t};
let component = ReasonReact.reducerComponent("Example");

initialState: () => {animatedValue: Animated.Value.create((-100.))},

/* Start animation in method */
Animated.CompositeAnimation.start(
  Animated.Timing.animate(
    ~value=state.animatedValue,
    ~toValue=`raw(0.),
    ()
  ),
  ()
);
[...]

/* Styles with an animated value */

<Animated.View
  style=Style.(style([flexDirection(Column), backgroundColor("#6698FF"), top(Animated(state.animatedValue))]))
  )
/>;

```


## Troubleshooting

### `Native module cannot be null` with create-react-native-app

Currently BuckleScript can generate `import * as ReactNative from 'react-native'`, which breaks
create-react-native-app. To get around this you can force BuckleScript to generate CommonJS
modules instead of ES Modules using:

```json
/* bsconfig.json */
{
  /* ... */
  "package-specs": [
    {
      "module": "commonjs"
    }
  ]
}
```
