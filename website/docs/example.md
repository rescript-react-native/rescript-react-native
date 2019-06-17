---
id: example
title: Example
---

As soon as you
[installed Reason React Native](/reason-react-native/en/docs/install/) properly
and have you `./package.json` and `./bsconfig.json` ready, you can create two
files:

- [`./App.js`](#appjs): a proxy for React Native to reference Reason compiled
  app component
- [`./src/App.re`](#srcappre): the actual React Native entry point, using Reason

_If you used our template as explained in th installation guide, you should
already have these files._

No worries, you can copy paste this if needed without understanding the content
for now. Documentation will explain everything 😇.

## `./App.js`

This can be you only JavaScript file if you want to be full ReasonML! It's just
a proxy to `App.re` application wrapper.

```javascript
/**
 * Do not modify this file - it is a proxy to your `App.re` file
 * located in the `src/` folder.
 */
export { app as default } from "./src/App.bs.js";
```

## `./src/App.re`

```reason
open ReactNative;

/*
 Here is StyleSheet that is using Style module to define styles for your components
 The main different with JavaScript components you may encounter in React Native
 is the fact that they **must** be defined before being referenced
 (so before actual component definitions)
 More at https://reasonml-community.github.io/reason-react-native/en/docs/apis/Style/
 */
let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#F5FCFF",
          (),
        ),
      "welcome":
        style(~fontSize=20., ~textAlign=`center, ~margin=10.->dp, ()),
      "instructions":
        style(~textAlign=`center, ~color="#333333", ~marginBottom=5.->dp, ()),
    })
  );

[@react.component]
let app = () =>
  <View style=styles##container>
    <Text style=styles##welcome>
      "Welcome to (Reason) React Native!"->React.string
    </Text>
    <Text style=styles##instructions>
      "To get started, edit src/App.re"->React.string
    </Text>
    <Text style=styles##instructions>
      {switch (Platform.os) {
       /*
        Instructions depends on the platform this code will run on
        More at https://reasonml-community.github.io/reason-react-native/en/docs/apis/Platform/
        */
       | os when os == Platform.ios =>
         "Press Cmd+R to reload,\n" ++ "Cmd+D or shake for dev menu"
       | os when os == Platform.android =>
         "Double tap R on your keyboard to reload,\n"
         ++ "Shake or press menu button for dev menu"
       | os when os == Platform.web => "Press Cmd+R to reload."
       | _ => ""
       }}
      ->React.string
    </Text>
  </View>;
```

### Differences with React Native JavaScript

Beside Reason syntax that is a bit different with JavaScript, you may have
noticed this major differences:

- Modules are not imported, but opened instead (without reference to the
  filesystem file) and this is due to
  [how modules work in ReasonML](https://reasonml.github.io/docs/en/module)
  (**filename must be unique**),
- Component definition must be preceded with `[@react.component]`,
- `const` is not a thing in Reason, & `let` is the default as ReasonML have a
  specific way to allow mutable variables,
- String in JSX must be quoted and explicitely referenced as `React.string` (you
  will find similar specific `React.*` to specify null value (`React.null`),
  children from an array `React.array`...)
- References to `styles` keys aren't using dot notation like in JavaScript but
  `##` instead thanks to BuckleScript syntax sugar for
  [direct JavaScript object access](https://bucklescript.github.io/docs/en/object-2#accessors)
- You won't see any explicit `export` like in JavaScript. By default every
  variables defined in a ReasonML module is exposed.

## Start this example

Now let's run this example.

In comparison with standard React Native development, the only thing you need to
be sure that you have successfully compiled `App.re` as `App.bs.js` like we
explained in the [usage](/reason-react-native/en/docs/usage/) section.

As soon as ReasonML compilation is successful, nothing should change for your
development process. You can normally start your React Native app via
`react-native run-ios`, `react-native run-android` or your classic web workflow
if you use `react-native-web`!

---

## Further reading

- [Cheatsheet](/reason-react-native/en/docs/cheatsheet/)

## In case you missed it

- [Getting Started](/reason-react-native/en/docs/)
- [Install](/reason-react-native/en/docs/install/)
- [Usage](/reason-react-native/en/docs/usage/)
