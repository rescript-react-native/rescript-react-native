---
id: getting-started
title: Getting Started
---

_Reason React Native_ is a safe & simple way to build
[ReactNative](http://facebook.github.io/react-native/) apps, in
[Reason](http://reasonml.github.io/), using
[ReasonReact](https://reasonml.github.io/reason-react/).

By leveraging the ReasonML great type system, expressive language features and
smooth interoperability with JS (thanks to
[BuckleScript](https://bucklescript.github.io)), _Reason React Native_ provide
bindings for React Native features as components & APIs that are:

- Safe and statically typed
- Simple and lean
- Familiar and easy to insert into an existing React Native codebase

It is often said that writing ReactJS code feels like "just using JavaScript".
The same applies to _Reason React_ with _Reason React Native_: you will feel
like you are "just using Reason".

![Introduction](/reason-react-native/schemas/introduction.svg)

## Zero-Cost

What is awesome about _Reason React Native_ bindings is that they don't
introduce an additional cost. The JavaScript code produced by BuckleScript will
directly hit React & React Native JavaScript implementation, without any extra
runtime & bundle cost.
