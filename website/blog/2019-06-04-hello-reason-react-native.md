---
id: 2019-06-04-hello-reason-react-native
title: Hello Reason React Native
---

Today is a big day for the ReasonML community as we are releasing the fruits of
a long effort started about 3 months ago.

As more and more people were starting to use ReasonML on production apps using
React Native, we wanted to make the BuckleScript bindings for React Native,
known has `bs-react-native`, more accessible. This would have involved several
breaking changes in order to simplify some APIs that have been designed with a
high level of security in mind, but at some costs. The cost of being harder to
start with (for newcomers to ReasonML) as well as the cost in terms of code size
and performance.

While some of us were thinking about some simplifications, some others, involved
in Reason React incoming changes, directly started a new approach for this
bindings, following
[the zero-cost approach offered by reason-react 0.7.0](https://reasonml.github.io/reason-react/blog/2019/04/10/react-hooks).

[CCA](https://www.cca.io) started this effort on what is now know as the new
`reason-react-native` bindings, that eliminates a huge part of the additional
JavaScript code produced by the bindings.

## Zero-cost

By zero-cost, we means zero additional cost. The JavaScript code BuckleScript
produces using this bindings will most of the time directly hit React Native
JavaScript code without creating an unnecessary abstraction above it 🙌.

Here are some random examples:

- [`bs-react-native` `View`](https://github.com/reasonml-community/reason-react-native/blob/958cd4e3a5ffa303304a0b2404cd53b5f49e649f/bs-react-native/src/components/ViewProps.bs.js)
  vs
  [`reason-react-native` `View`](https://github.com/reasonml-community/reason-react-native/blob/958cd4e3a5ffa303304a0b2404cd53b5f49e649f/reason-react-native/src/components/View.bs.js)
- [`bs-react-native` `Style`](https://github.com/reasonml-community/reason-react-native/blob/958cd4e3a5ffa303304a0b2404cd53b5f49e649f/bs-react-native/src/style.bs.js)
  vs
  [`reason-react-native` `Style`](https://github.com/reasonml-community/reason-react-native/blob/958cd4e3a5ffa303304a0b2404cd53b5f49e649f/reason-react-native/src/apis/Style.bs.js)
- [`bs-react-native` `Platform`](https://github.com/reasonml-community/reason-react-native/blob/958cd4e3a5ffa303304a0b2404cd53b5f49e649f/bs-react-native/src/platform.bs.js)
  vs
  [`reason-react-native` `Platform`](https://github.com/reasonml-community/reason-react-native/blob/958cd4e3a5ffa303304a0b2404cd53b5f49e649f/reason-react-native/src/apis/Platform.bs.js)

Some modules are even empty or with some minor `require()` that can be
themselves almost empty and easily removed by some JavaScript bundlers.

How cool is that?

## But why`reason-react-native` ?

`bs-react-native` already had multiple breaking changes in the past and we
didn't really want to offer a poor experience by creating a new release with
tons of changes that won't be easy to codemod (or would require much more work
from us).

On top of that, `reason-react` latest release already added an important
breaking change with
[JSX 3](https://reasonml.github.io/reason-react/docs/en/jsx).

That's why we had this idea about offering an easy and smooth transition by
offering 2 packages to say goodbye to `bs-react-native` without pain.

- `bs-react-native-jsx3-compat`
- `reason-react-native`

## Wait, what is `bs-react-native-jsx3-compat` ?

`bs-react-native` is using JSX 2 so in order to use it with JSX 3 we would have
to create an additional layer on top of the current bindings to offer both JSX 2
and 3 bindings. And since we wanted to do away with some current APIs of
`bs-react-native` we started to think about a new approach.

We knew that we wanted to:

- offer to `bs-react-native` users a migration plan, so they can start very
  easily to use JSX 3 and new `reason-react` (so they can use hooks),
- offer new `reason-react-native` bindings, more accessible and with a zero cost
  approach.
- offer a smooth transition between these two packages so people can slowly
  upgrade their codebase without having to make an insane PR that switches from
  one to the other.

We don't want your co-workers to hate you with a PR that comes directly from
hell 😅.

That's where we thought about offering `bs-react-native-jsx3-compat`. It's a
package that has the same APIs `bs-react-native` has but that uses
`reason-react-native` under the hood.

**This means you will have to make a migration from JSX 2 to 3**. That's the
only thing you will have to do, then with a single change from `bs-react-native`
with `bs-react-native-jsx3-compat` in your `bs-dependencies` you will be ready
to use hooks and directly benefit of (almost) zero-cost bindings!

And since we care about you and don't want you to upgrade from JSX 2 to 3 by
hand, we got you covered with a script made with love to help you with that.

[You will find all the required instructions to migrate from `bs-react-native` to `bs-react-native-jsx3-compat` in our documentation](/reason-react-native/en/docs/migration/jsx3/).

## tl;dr

- `bs-react-native` has now entered a frozen state and won't receive any upgrade
- `bs-react-native-jsx3-compat` allows you to use existing code based on
  `bs-react-native` with `reason-react` 0.7.0 and JSX 3
- `reason-react-native` package contains the new bindings for React Native, that
  offers more accessible APIs and that is almost zero-cost
- [We offer you an easy and smooth migration plan so you can start using `reason-react-native` and slowly say bye to `bs-react-native`](/reason-react-native/en/docs/migration/jsx3/).

## Thanks

This required effort has been keeping us busy for weeks and wouldn't have been
possible without the following people:

- CCA team and especially @cknitt for leading us to the right direction for the
  new zero-cost bindings and all the contributions that come with this move
- @sgny for all his contributions to the new bindings
- @MoOx for leading the effort, the compat layer and the new website you are
  seeing here
- @bloodyowl for his magical
  [reason-react-compat](https://github.com/bloodyowl/reason-react-compat) layer
  and
  [the alternate JSX 3 upgrade path](https://bloodyowl.github.io/blog/2019-04-19-an-alternative-migration-path-for-reason-react/)
  that goes with it
- all the people that helped us on Discord and GitHub in various code reviews
  and improvements like the react native template (thanks @dawee)

## What's next?

Now that `reason-react-native` is ready to be used and that our migration plan
is usable, we will probably be focused on documentation as lots of APIs and
Components need to be documented. We really want to offer the best developer
experience possible and that's definitely part of it.
