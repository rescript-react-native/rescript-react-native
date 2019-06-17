---
id: getting-started
title: Getting Started
---

_Reason React Native_ is a safe & simple way to build
[ReactNative](http://facebook.github.io/react-native/) apps, in
[Reason](http://reasonml.github.io/), using
[ReasonReact](https://reasonml.github.io/reason-react/).

## Why _Reason React Native_ ?

By leveraging the ReasonML great type system, expressive language features and
smooth interoperability with JavaScript (thanks to
[BuckleScript](https://bucklescript.github.io)), _Reason React Native_ provide
bindings for React Native features as components & APIs that are:

- Safe and statically typed
- Simple and lean
- Familiar and easy to insert into an existing React Native codebase

It is often said that writing ReactJS code feels like "just using JavaScript".
The same applies to _Reason React_ with _Reason React Native_: you will feel
like you are "just using Reason".

## How to use _Reason React Native_ ?

Like _ReasonReact_, _Reason React Native_ is a ReasonML package that exposes
bindings for React Native.

On your side, you write Reason code that use the `ReactNative` module exposed by
`reason-react-native` package that you will find on `npm`.

BuckleScript will compile this code to safe JavaScript that React Native can
consume like standard JavaScript.

![Introduction](/reason-react-native/schemas/introduction.svg)

If you are familiar with Flow or TypeScript, you can see Reason as the next
level of strongly typed JavaScript.

In short, you write safer code that will be compiled to safe JavaScript & end up
with a safer React Native app!

## Zero-Cost

What is awesome about _Reason React Native_ bindings is that they don't
introduce an additional cost. The JavaScript code produced by BuckleScript will
directly hit React & React Native JavaScript implementation, without any extra
runtime & bundle cost.

## Using Reason & Reason React

_Reason React Native_ is a package that works with
[Reason](https://reasonml.github.io/) & use
[Reason React](https://reasonml.github.io/reason-react/). For this reasons (!),
if you are unfamiliar on of this two, we encourage you to have a look to their
documentations as soon as you don't find an answer you might have here.

And one day or another, you will also have to look for answers on
[BuckleScript](https://bucklescript.github.io/docs/en/what-why), our
Reason-to-JavaScript compiler.

---

## Further reading

- [Installation](/reason-react-native/en/docs/install/)
- [Usage](/reason-react-native/en/docs/usage/)
- [Example](/reason-react-native/en/docs/example/)
- [Cheatsheet](/reason-react-native/en/docs/cheatsheet/)
- [Migration from `bs-react-native`](/reason-react-native/en/docs/migration/jsx3/)
