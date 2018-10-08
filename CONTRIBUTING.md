# Contributing guide

It's great of you to consider contributing to the BuckleScript bindings for React Native. **Every contribution is greatly appreciated!**
There are many ways to contribute. Besides implementing new features and fixing bugs, you can give advice in issues, create and improve documentation, etc.

## I want to contribute a missing component or API

That's awesome!. If you have a specific one in mind go for it, otherwise just pick one of your choice.
If you expect that it would take you a while (which is no problem) you can open a PR with your working progress to let everybody know you are working on it.
To add component (or API) you should do the following steps:

- Implement your component in a file `myComponentRe.re`
- Add an interface `myComponentRe.rei` and think about which things should be exposed.
- Add your new component to `reactNative.re` following the existing components / APIs.

Some things to keep in mind:

- We strive for more heavy bindings, i.e. we try to hide things like `Js.t` objects, but sometimes this is not possible.
- String enums, which are an argument to a function, are represented through polymorphic variants.
- You should format your code with `refmt`.

## I got stuck

Well, that happens. But don't give up! Just join the [Discord Server](https://discord.gg/reasonml) and ask your questions in #react or #bucklescript. Everybody is really welcoming and helpful!

## Setup Development

```sh
git clone https://github.com/BuckleTypes/bs-react-native.git
cd bs-react-native
yarn
```

Then build with `yarn start`.

## Running example

Example app is written in Expo. Please check their documentation for any additional details. Before running the app, make sure to build the Reason code.

```sh
cd ./example
yarn build
```

Next, start Expo and follow on-screen instructions:

```sh
yarn start
```

## Running docs

Documentation is generated from the Reason interface and comments that are included there.

To start working with documentation:

- Ensure that have the odoc installed [odoc](https://github.com/ocaml/odoc)
  > if you have the problem during installing the odoc with OCaml dependencies, try: `opam pin add odoc.dev git+https://github.com/ocaml/odoc`
- build code with: `yarn clean-build` or if you want to build with watch then use: `yarn start`
- start docs server using: `yarn start-docs`. Script will run the HTTP server and reload after something will change.
- To build documentation from ReasonMl interfaces to HTML file run: `yarn build-docs`

### Tips and Tricks

## Generate Interface files

You can generate an interface file (`.rei`) with

```sh
./node_modules/bs-platform/bin/bsc.exe -pp 'refmt --print binary' -i -I lib/bs/src/ -I lib/bs/src/components -I ./node_modules/reason-react/lib/bs/src/ -impl /path/to/your/file.re
```

This generates the OCaml variant of the interface file. To obtain a reason interface you can copy it into [Reason Tools](https://reasonml.github.io/reason-tools/popup.html) or pipe it to `refmt` with

```sh
refmt --parse ml --interface true
```

## Useful resources

- [Bucklescript Manual](https://bucklescript.github.io/docs/en/installation)
- The [React Native docs](https://facebook.github.io/react-native/)
- The [TypeScript definitions](https://github.com/DefinitelyTyped/DefinitelyTyped/blob/master/types/react-native/index.d.ts) are really useful if the docs aren't that clear about the signature of an API.
