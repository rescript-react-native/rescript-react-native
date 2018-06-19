---
id: get-started
title: Quick start
sidebar_label: Quick Start
---

_Note: If you are currently using [`bs-react-native`](https://github.com/reasonml-community/bs-react-native), these docs might also be useful for you; but Rebolt might have slight differences, so please be aware of that._

## Starting a fresh React Native project

You can create a new React Native project by running the following:

```sh
react-native init MyApp --template rebolt
```

This will create a fresh React Native project using `rebolt` template, giving you the already preconfigured Reason environment out of the box.

To better understand the integration between Reason and React Native, please see the following section that explains the manual integration step by step.

## Adding ReasonML to your existing React Native project

1.  Let's add the dependencies first:

```sh
npm i -P bs-platform reason-react rebolt
```

or if you use Yarn:

```sh
yarn add bs-platform reason-react rebolt
```

2.  Create a directory where the Reason code will be compiled from. In our case it will be `src` (but it could be any other directory, just remember to reference it in the `bsconfig.json` - see below):

```sh
mkdir src
```

3.  Now we will add the `bsconfig.json` BuckleScript configuration file, in the root of the project:

```sh
touch bsconfig.json
```

**bsconfig.json**

```json
{
  "name": "my-reason-react-native-app",
  "reason": {
    "react-jsx": 2
  },
  "bsc-flags": ["-bs-super-errors"],
  "bs-dependencies": ["rebolt", "reason-react"],
  "sources": [
    {
      "dir": "src"
    }
  ],
  "refmt": 3
}
```

4.  Last thing we need to do is to add a few scripts to already exisiting `package.json` file:

```sh
"scripts": {
  "start": "node node_modules/react-native/local-cli/cli.js start",
  "test": "jest",
  "build": "bsb -make-world -clean-world",
  "watch": "bsb -make-world -clean-world -w"
}
```

A bit of explanation to what both of the scripts do:

- `yarn build` - performs a single build
- `yarn watch` - enters the watch mode

5.  Now let's add our first component in Reason, add `App.re` in the `src` folder:

**App.re**

```reason
open Rebolt;

let app = () =>
  <View>
    <Text> (ReasonReact.string("Let's get this party started!")) </Text>
  </View>;
```

6.  We are going to use `App.re` as the entry point in the `index.js` file from the root of the project:

**index.js**

```js
import { app } from './lib/js/src/App.js';
import React from 'react';
import { AppRegistry } from 'react-native';

AppRegistry.registerComponent("MyReasonReactNativeApp", () => app);
```

In the first line we are referencing `app`, but it is not the one from `src/App.re`, this is because we are in the JavaScript world now, and we need to use compiled version of what we've written in Reason.

There is an option in the BuckleScript's config file (`bsconfig.json`) to compile files in source, so they will no longer be compiled to `lib/` (as that is what BuckleScript does by default), instead they will be compiled into the same directory where they Reason files are located.

When you add this to your `bsconfig.json`, you will get in source compilation that we just spoke about:

**bsconfig.json**

```json
"package-specs": {
  "module": "commonjs",
  "in-source": true
}
```

and then you can reference the files in the shorter way:

**index.js**

```js
import { app } from './src/App.js';
import React from 'react';
import { AppRegistry } from 'react-native';

AppRegistry.registerComponent("MyReasonReactNativeApp", () => app);
```

7. You can run your app now:

Run in one tab of your terminal `yarn run watch` to compile the ReasonML code,
and in the other start the React Native app in the simulator `react-native run-ios`

