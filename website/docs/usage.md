---
id: usage
title: Usage
---

When `reason-react-native`, `reason-react` and `bs-platform` are installed, you
can run the following command

```console
yarn bsb -make-world
```

⚠️ _If this process looks fast to you, don't be surprised, that's because
ReasonML & BuckleScript are fast!_

This command should compile all `.re` files to their `.bs.js` counterparts.

This means if you have an `src/App.re` file, you should now have `src/App.bs.js`
file too.

You may also notice some compilation artifacts:

- `.bsb.lock`
- `.merlin`
- `lib/bs`

You may want to gitignore all of these:

```
*.bs.js
.bsb.lock
.merlin
lib/bs
```

_If you used our template, it should be done already_.

## Automate compilation of `*.re` files

You have multipes way to not have to think about compilation for your daily
workflow

## Compile ReasonML files via IDE

To get the best development experience possible, we recommend you to use
[VSCode](https://code.visualstudio.com) with
[Reason Language Server](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode)
extension. Optionally you can add
[Flow Language Server](https://marketplace.visualstudio.com/items?itemName=flowtype.flow-for-vscode)
extension if you have existing JavaScript covered by Flow.

⚠️ If you won't want to use VSCode, we still recommend you to
[get a ReasonML editor plugin](https://reasonml.github.io/docs/en/editor-plugins/).

By having an IDE that handle ReasonML compilation, you will not have to run a
command in the terminal to handle this & will just have to follow the standard
React Native workflow, your ReasonML files being compiled to JavaScript.

You will also have inline errors & much more feature that won't be provided by
using a CLI workflow.

## Vscode workflow

When you open VSCode with the Reason Language Server plugin (RLS), you won't
have to do anything. The plugin will detect `bs-platform` & will handle the
compilation/watching process for you.

In case you are facing something weird, you can always trigger a cleanup by
doing `Cmd + Shift + P` and look for `Restart Reason Language Server`.

⛑ _Even if you decide to use Vscode or a smiliar IDE to ease your day to day
development workflow, you should have a look to CLI workflow so you how it
works._

### Compile ReasonML files via CLI

When you use React Native, you usually always have a terminal opened around with
Metro Bundler running, which bundle the JavaScript files.

Now you need to also have a process watching for your ReasonML files to compile
then to JavaScript. The easiest way is to rely on BuckleScript `bsb` watch
option `-w`:

```console
yarn bsb -make-world -w
```

If you are not familiar with BuckleScript `bsb` you should know that you might
sometimes have weird compilation errors due to outdated build artifacts. This
should not happen often but in case you are facing something weird, you can try
using `bsb` `-clean-world` option

```console
yarn bsb -clean-world
```

On a daily basis, you can use this complete command that will clean, build &
watch for changes

```console
yarn bsb -clean-world -make-world -w
```

You might want to add this two commands in your `package.json` scripts:

```json
  "scripts": {
    "re:build": "bsb -clean-world -make-world",
    "re:watch": "bsb -clean-world -make-world -w",
    "start": "node node_modules/react-native/local-cli/cli.js start",
    "start:ios": "react-native run-ios",
    "start:android": "react-native run-android",
  }
```

_Note: you probably have `start` already._

If you are doing this change in your scripts, you can now use this development
workflow

#### CLI Development workflow

**In one terminal:**

```console
yarn re:watch
```

As soon as `.re` files are being compiled to `.bs.js`, you can either start the
project on _iOS Simulator_ (included in _Xcode_) or an Android Emulator (if you
are unfamiliar with _Android Studio_, you might be interested by
[Genymotion](https://www.genymotion.com)).

**In another terminal:**

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

**Note: as soon as you have the app installed in a simulator/emulator, you can
just run**

```console
yarn start
```

This avoid rebuilding the entire native parts & will just start React Native
metro bundler.

---

## Interoperability with JavaScript

### Using JavaScript components from Reason

@todo

Meanwhile, check out
[Reason React interop page](https://reasonml.github.io/reason-react/docs/en/components#interop).

You can also browse the source of
[reason-react-native](https://github.com/reasonml-community/reason-react-native/tree/master/reason-react-native/src)
because that's exactly what this project is doing!

### Using Reason React Native components from JavaScript

@todo

Meanwhile, check out
[Reason React interop page](https://reasonml.github.io/reason-react/docs/en/components#interop)

---

👉 At this step, you should check our in-depth
[Example](/reason-react-native/en/docs/example/) or go directly check our
[Cheatsheet](/reason-react-native/en/docs/cheatsheet/)

---

## Further reading

- [Example](/reason-react-native/en/docs/example/)
- [Cheatsheet](/reason-react-native/en/docs/cheatsheet/)

## In case you missed it

- [Getting Started](/reason-react-native/en/docs/)
- [Install](/reason-react-native/en/docs/install/)
