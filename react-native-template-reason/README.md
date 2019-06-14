# React Native HelloWorld

> This is a React Native application developed in Reason.

Please carefully read instructions below in order to enjoy ReasonML development
experience.

## Setup

## Start a Reason React Native project with this template

```console
react-native init MyApp --template reason
```

### Command line

Install BuckleScript with the following command:

```sh
yarn add bs-platform --dev
```

### IDE

To get the best development experience possible, we recommend you to use
[VSCode](https://code.visualstudio.com) with
[Reason Language Server](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode)
extension & optionally
[Flow Language Server](https://marketplace.visualstudio.com/items?itemName=flowtype.flow-for-vscode)
extension if you have JavaScript covered by Flow.

If you won't want to use VSCode, at least
[get a ReasonML editor plugin](https://reasonml.github.io/docs/en/editor-plugins/).

### `package.json`

To get started, add the following scripts to your `package.json`:

```json
"scripts": {
  "re:watch": "bsb -clean-world -make-world -w",
  "re:build": "bsb -clean-world -make-world",
  "start": "node node_modules/react-native/local-cli/cli.js start",
  "start:ios": "react-native run-ios",
  "start:android": "react-native run-android",
}
```

Note: you probably have `start` already.

### Development workflow

_Note: `yarn` can be replaced by `npm run` in all commands below._

Depending on your editor &
[its ReasonML integration](https://reasonml.github.io/docs/en/editor-plugins/)
you might need to use:

```console
yarn re:watch
```

**Reminder: this step might be unecessary if your editor can handle ReasonML
compilation by its own.**
[Read more](https://github.com/jaredly/reason-language-server#installation).

As soon as `.re` files are being compiled to `.bs.js`, you can either start the
project on _iOS Simulator_ (included in _Xcode_) or an Android Emulator (if you
are unfamiliar with _Android Studio_, you might be interested by
[Genymotion](https://www.genymotion.com)).

```console
yarn start:ios
```

or

```console
yarn start:android
```

This commands should open up a virtual device & start React Native
[metro bundler](https://github.com/facebook/metro). This packager will serves
the compiled Reason code to the React Native client.

Now you can start coding by editing files in `src/`!

[Read more about starting the project in your environment of choice](http://facebook.github.io/react-native/docs/getting-started).

**Note: as soon as you have the app installed in a simulator/emulator, you could
just run**

```console
yarn start
```

This avoid rebuilding the entire native parts & will just start React Native
metro bundler.

## Breakdown of existing files

The `react-native init` command generates a lot of boilerplate with files that
might be not needed for your particular use case. Below is a breakdown of all
top-level files to help you decide:

- `.babelrc` - required, for transpiling Javascript files to supported by the
  mobile engine Javascript version
- `.buckconfig` - optional, configuration files for `Buck`. Can be safely
  removed in most cases unless you are planning on using it
- `.flowconfig` - optional, used to configure `Flow`, which is a type checker
  for Javascript. Can be removed as you are writing our code in Reason
- `.watchmanconfig` - optional, configuration for `Watchman`, which is a
  Facebook tool for listening to file system changes. This file is not needed,
  unless you plan on extending its configuration
