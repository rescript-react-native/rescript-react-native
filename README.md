# BuckleScript bindings for React Native

[![Build Status][build-badge]][build] [![Version][version-badge]][package]
[![React Native][react-native-badge]][react-native]
[![All Contributors][all-contributors-badge]][contributors]
[![Chat][chat-badge]][chat]

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
    // BsReactNative, current "stable" bindings
    "bs-react-native/bs-react-native",
    // ReactNative, WIP on zero-cost bindings (require bs-platform 5.0.0 & and reason-react hooks branch)
    "bs-react-native/bs-react-native-next"
  },
  // When used from git with the following path, bs-platform will use path that won't be working
  // (because deps are pointing to folder in folder)`
  // Your bundler (metro or webpack) will say that it can find `bs-react-native/whatever` and/or
  // `bs-react-native-next/whatever`
  // which is correct because it should be `bs-react-native/bs-react-native/whatever` / `bs-react-native/bs-react-native-next/whatever`
  // the trick below will correct path in generated JavaScript files
  // and will just need to be removed when you won't use git directly anymore
  "js-post-build": {
    "cmd": "./node_modules/bs-react-native/git-monorepo-usage-trick"
  }
}
```

Did you notice that this way, you can use both bindings to slowly migrate?

_Next ReactNative zero-cost bindings are still WIP, so use carefully at your own
risk._

## ⚠️ ReactNative zero-cost bindings setup with Reason React hooks

Things you need

- `package.json` dep: `"bs-platform": "^5.0.1-beta.1",`
- `package.json` dep:
  `"reason-react": "https://github.com/reasonml/reason-react.git#0.7.0",`
- `bsconfig.json`: `"reason": { "react-jsx": 3 }`

---

## Getting Started

Check our
[getting started](https://reasonml-community.github.io/bs-react-native/BsReactNative/gettingstarted.html)
guide for details.

You can run the [playground](./example) with Expo:
https://expo.io/@grabbou/bs-react-native.

## Documentation

See https://reasonml-community.github.io/bs-react-native.

## Usage

See https://github.com/reasonml-community/bs-react-native/tree/master/example

## Contribute

Read the [contribution guidelines](./CONTRIBUTING.md) before contributing.

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[the full text](https://github.com/reasonml-community/bs-react-native/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.

<!-- badges -->

[build-badge]:
  https://img.shields.io/circleci/project/github/reasonml-community/bs-react-native/master.svg
[build]: https://circleci.com/gh/reasonml-community/bs-react-native
[version-badge]: https://img.shields.io/npm/v/bs-react-native.svg
[package]: https://www.npmjs.com/package/bs-react-native
[all-contributors-badge]:
  https://img.shields.io/badge/all_contributors-68-blue.svg
[contributors]:
  https://github.com/reasonml-community/bs-react-native/blob/master/CONTRIBUTORS.md
[chat-badge]:
  https://img.shields.io/discord/496273792503513089.svg?logo=discord&colorB=blue
[chat]: https://discord.gg/q8GQD34
[react-native-badge]:
  https://img.shields.io/badge/react--native-%5E0.53.3-green.svg
[react-native]: https://github.com/facebook/react-native
