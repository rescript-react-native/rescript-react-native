# Reason bindings for React Native

[![Build Status](https://img.shields.io/circleci/project/github/reasonml-community/reason-react-native/master.svg)](https://circleci.com/gh/reasonml-community/reason-react-native)
[![Version](https://img.shields.io/npm/v/reason-react-native.svg)](https://www.npmjs.com/package/reason-react-native)
[![Chat](https://img.shields.io/discord/496273792503513089.svg?logo=discord&colorb=blue)](https://discord.gg/eau3z6q)

[BuckleScript](https://bucklescript.github.io) bindings for
[React Native](https://github.com/facebook/react-native) allows to use
[ReasonML](https://reasonml.github.io) with
[ReasonReact](https://reasonml.github.io/reason-react/) to make your iOS,
Android and [Web](https://github.com/necolas/react-native-web) apps.

## 🚨 Usage from Git repo

If you use this bindings from the git repo, be sure to use

```js
{
  // ...
  "bs-dependencies": [
    // bs-react-native, but compatible with jsx3
    "reason-react-native-monorepo/bs-react-native-jsx3-compat",
    // new ReactNative, WIP on zero-cost bindings
    "reason-react-native-monorepo/reason-react-native"
  },
  // When used from git with the following path, bs-platform will use path that won't be working
  // (because deps are pointing to folder in folder)`
  // Your bundler (metro or webpack) will say that it can find and/or `reason-react-native/whatever`
  // which is correct because it should be `reason-react-native-monorepo/reason-react-native/whatever`
  // the trick below will correct path in generated JavaScript files
  // and will just need to be removed when you won't use git directly anymore
  "js-post-build": {
    "cmd": "./node_modules/reason-react-native-monorepo/git-monorepo-usage-trick"
    // if this tricky script doesn't work for you correctly, try
    // "cmd": "./node_modules/reason-react-native-monorepo/git-monorepo-usage-trick-node"
  }
}
```

---

## Getting Started

Check our
[getting started](https://reasonml-community.github.io/reason-react-native/en/docs/)
guide for details.

## Documentation

See https://reasonml-community.github.io/reason-react-native.

## Contribute

Read the [contribution guidelines](./CONTRIBUTING.md) before contributing.

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[the full text](https://github.com/reasonml-community/reason-react-native/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.
