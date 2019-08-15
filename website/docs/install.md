---
id: install
title: Installation
---

Depending on how you want to start with _Reason React Native_, you have
different options to install it:

- [Create a new project with _Reason React Native_](#create-a-new-project-with-reason-react-native)
- [Add _Reason React Native_ to an existing project](#add-reason-react-native-to-an-existing-project)
- [Migrating from `bs-react-native` to _Reason React Native_](/reason-react-native/en/docs/migration/jsx3/)

All options will basically help you to have :

- [BuckleScript](https://bucklescript.github.io/) (`bs-platform` - includes
  [ReasonML](https://reasonml.github.io)!)
- [Reason React](https://reasonml.github.io/reason-react/) (`reason-react`)
- _Reason React Native_ (`reason-react-native`)

Below we assume you are already familiar with React Native. If you are new to
React Native, please have a quick look to
[React Native Getting Started documentation](https://facebook.github.io/react-native/docs/getting-started.html)
in order to get the minimal requirements.

## Create a new project with _Reason React Native_

React Native allows to create new project from a template, so we made one. By
choosing this option you will get an hello world project that will already have
all the requirements included.

When you have correctly
[`react-native-cli`](http://facebook.github.io/react-native/docs/getting-started#the-react-native-cli)
installed, you can run the following command:

```console
npx react-native init MyApp --template reason-react-native-template
cd MyApp
```

⚠️ In case you got an error saying it's looking for
`react-native-template-reason-react-native-template`, be sure to have
uninstalled any previous react-native-cli version & rely on `npx`

```console
npm -g uninstall react-native
npm -g uninstall react-native-cli
yarn global remove react-native
yarn global remove react-native-cli
```

💖 Your project is setup, you can just check
[how to use _Reason React Native_](/reason-react-native/en/docs/usage/) right
away!

---

⚠️ We don't provide yet instructions for _Expo_ users. _If you are familiar with
Expo, feel free to open
[an issue](https://github.com/reasonml-community/reason-react-native/issues/new?title=Expo+template)
so we can discuss about that_.

_If you are an Expo user, just have a look at the instructions below when your
Expo app is ready_.

## Add _Reason React Native_ to an existing project

If you already have an existing project, it's really fast to get all the thing
you need to start using Reason React Native right away!

👉 **You can decide to use Reason React Native for certain components only** as
the compilation process generate normal JavaScript.

Go into your project root & then install the requirements:

```console
yarn add bs-platform --dev
yarn add reason-react reason-react-native
```

Then create a file named `bsconfig.json` at the same level at your
`package.json` with the following content

```json
{
  "name": "my-reason-react-native-app",
  "refmt": 3,
  "reason": {
    "react-jsx": 3
  },
  "package-specs": {
    "module": "es6",
    "in-source": true
  },
  "suffix": ".bs.js",
  "sources": [
    {
      "dir": "src",
      "subdirs": true
    }
  ],
  "bs-dependencies": ["reason-react", "reason-react-native"]
}
```

The main things you should notice here:

- JavaScript generated will be using `import` & `export` (_es6_).
- JavaScript generated files will have `.bs.js` extension (easy to find)
- ReasonML code will be compiled from `src` folder.
- ReasonML will use `reason-react` & `reason-react-native` packages as
  dependencies.

👀 _For details about this file, please refer to
[BuckleScript Configuration documentation](https://bucklescript.github.io/docs/en/build-configuration)
if needed._

When it's done, you are ready to
[use Reason React Native](/reason-react-native/en/docs/usage/) !

---

## Note about `reason-react-native` version number

We decided to try something simple for you:

⚛️ `reason-react-native` `0.60.*` means it should work with `react-native`
`^0.60.0`.

We keep patch number for bindings fixes. `react-native` patches should not
affect our bindings. This means last digit don't need to match each others:

- `react-native@0.60.8` should work with `reason-react-native@0.60.0`
- `react-native@0.60.2` should work with `reason-react-native@0.60.4`

👉 In short: **`reason-react-native` `0.x.*` means it should work with
`react-native@^0.x.*`**.

---

## Further reading

- [Usage](/reason-react-native/en/docs/usage/)
- [Example](/reason-react-native/en/docs/example/)
- [Cheatsheet](/reason-react-native/en/docs/cheatsheet/)

## In case you missed it

- [Getting Started](/reason-react-native/en/docs/)
