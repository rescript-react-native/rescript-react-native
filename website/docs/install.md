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

```console
react-native init MyApp --template reason
```

💖 Now that you project is setup, you can just check
[how to use _Reason React Native_](#using-reason-react-native) right away!

---

⚠️ We don't provide yet instructions for _Expo_ users. _If you are familiar with
Expo, feel free to open
[an issue](https://github.com/reasonml-community/reason-react-native/issues/new?title=Expo+template)
so we can discuss about that_.

## Add _Reason React Native_ to an existing project

If you already have an existing project, it's really fast to get all the thing
you need to start using Reason React Native right away!

Got into your project root & then install the requirements

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

👀 _For details about this file, please refer to
[BuckleScript Configuration documentation](https://bucklescript.github.io/docs/en/build-configuration)._

When it's done, you are ready to use Reason React Native !

---

## Using Reason React Native

@todo move here
[what's in the template readme](https://github.com/reasonml-community/reason-react-native/tree/master/react-native-template-reason#react-native-helloworld)

### Using JavaScript components from Reason

@todo check out
[Reason React interop page](https://reasonml.github.io/reason-react/docs/en/components#interop).

You can also browse the source of
[reason-react-native](https://github.com/reasonml-community/reason-react-native/tree/master/reason-react-native/src)
because that's exactly what this project is doing!

### Using Reason React Native components from JavaScript

@todo Meanwhile, check out
[Reason React interop page](https://reasonml.github.io/reason-react/docs/en/components#interop)

---

👉 At this step, you should check our in-depth
[Example](/reason-react-native/en/docs/example/) or our
[Cheatsheet](/reason-react-native/en/docs/cheatsheet/)

---

## Further reading

- [Example](/reason-react-native/en/docs/example/)
- [Cheatsheet](/reason-react-native/en/docs/cheatsheet/)

## In case you missed it

- [Getting Started](/reason-react-native/en/docs/)
