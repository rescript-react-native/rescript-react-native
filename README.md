#### 🎟 [Reason Conf US](https://www.reason-conf.us) is happening October 7-8th in Chicago 🎉

Buy tickets or sponsor the event by visiting
[https://www.reason-conf.us](https://www.reason-conf.us)

---

# Reason bindings for React Native

[![Build Status](https://img.shields.io/circleci/project/github/reasonml-community/reason-react-native/master.svg)](https://circleci.com/gh/reasonml-community/reason-react-native)
[![Version](https://img.shields.io/npm/v/reason-react-native.svg)](https://www.npmjs.com/package/reason-react-native)
[![Chat](https://img.shields.io/discord/496273792503513089.svg?logo=discord&colorb=blue)](https://reasonml-community.github.io/reason-react-native/discord/)

[BuckleScript](https://bucklescript.github.io) bindings for
[React Native](https://github.com/facebook/react-native) allows to use
[ReasonML](https://reasonml.github.io) with
[ReasonReact](https://reasonml.github.io/reason-react/) to make your iOS,
Android and [Web](https://github.com/necolas/react-native-web) apps.

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

---

## 🚨 Usage from Git repo

If you use things unreleased from the git repo, you will need to link all
folders (packages) that you need at the root of node_modules. The easiest way is
to create the symlink you need in your `package.json` `prepare` step:

First add this repo as a dep

```console
yarn add https://github.com/reasonml-community/reason-react-native
```

Next, add this cross-platform symlink tool

```console
yarn add --dev symlink-dir
```

Then add to you `package.json`

```js
{
  "scripts": {
    "reason-react-native-monorepo-trick": "symlink-dir ./node_modules/reason-react-native-monorepo/reason-react-native node_modules/reason-react-native && symlink-dir ./node_modules/reason-react-native-monorepo/bs-react-native-jsx3-compat node_modules/bs-react-native-jsx3-compat",
    "prepare": "yarn reason-react-native-monorepo-trick"
  }
}
```

⚠️ In the example above, we only linked `reason-react-native` and
`bs-react-native-jsx3-compat`. Be sure to link all the package you have in your
`bsconfig.json` that need to be used from git.

👀 If you find a trick more easy to read/maintain (and still cross-platform),
please share it with us via Discord, an issue, or a PR!
