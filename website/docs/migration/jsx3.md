---
id: migration/jsx3
title: "How to migrate to reason-react 0.7 with full jsx3"
---

## Migrate your code to JSX3 using a script

Instead of using
[reason-react official upgrade path](https://reasonml.github.io/reason-react/docs/en/jsx.html#migrating-from-version-2-to-version-3),
that allow you to use jsx2 & jsx3 at the same time, which is nice but require an
effort from you to make components written in one version to work with the other
& vice-versa, we will follow an
[alternative upgrade path](https://bloodyowl.github.io/blog/2019-04-19-an-alternative-migration-path-for-reason-react/)
based on a
[reason react compat hook](https://github.com/bloodyowl/reason-react-compat)
coupled with our compatibility layer `bs-react-native-jsx3-compat`

So first,

- be sure that you use `bs-platform@^5.0.1`
- be sure to use `reason-react` master branch (until 0.7.1 or 0.8 is out) (at
  least commit
  [835b90c](https://github.com/reasonml/reason-react/commit/835b90c1c73827632a9819a353a404380724b1d2))
- use `react@^16.8.0`
- add `reason-react-compat@^0.4.0`
- (if needed, upgrade some deps (eg: `reason-apollo@^0.16.0`))
- use https://github.com/bloodyowl/upgrade-reason-react
  - **⚠ Note that if you use `->` operator a lot inside jsx, you will have a lot
    of bad surpise atm. We are working on improving the script.** Be warned.
  - if things breaks hard with `❗️️Errored on {somefile}`, that probably
    because something doesn't please the inlined version of refmt that's in the
    upgrade script. Things like this
  ```reason
    StyleSheet.create(
      Style.{
  ```
  will need to be replaced with
  ```reason
  Style.(StyleSheet.create({
  ```
  This also require you to adjust the other side of this StyleSheet declaration,
  so replace
  ```reason
      },
    );
  ```
  with
  ```reason
      },
    ));
  ```
  Same for very short declarations
  ```reason
  StyleSheet.create(Style.{
  ```
  will need to be replaced with
  ```reason
  Style.(StyleSheet.create({
  ```
  And don't forget on the other side... `});` with `}));` Same apply for similar
  patterns...

### Workaround for git usage

- `yarn add https://github.com/reasonml-community/bs-react-native.git#jsx3-migration`
- run a dirty command to get proper setup when using
  `bs-react-native-jsx3-compat`: add as a `prepare` script
  - `"prepare": "ln -sFf ../node_modules/bs-react-native-monorepo/reason-react-native/ ./node_modules",`
- run `yarn prepare` (this will be run each time you use yarn & will ensure that
  the trick is always around until you actually use released versions of this
  work)

Now you can try to compile your code but it's unecessarry. **You might have tons
of error because `bs-react-native` is full of jsx2** & we just migrated codebase
to jsx3.

So please:

- Ensure your project is full jsx3 (`bsconfig.json`:
  `"reason": {"react-jsx": 3},`)
- Replace `bs-react-native` by `bs-react-native-monorepo/bs-react-native-jsx3`
  in your `bsconfig.json` (**⚠️ check the
  [git monorepo trick](https://github.com/reasonml-community/bs-react-native#-usage-from-git-repo)**)

Compilation time! You should still have some errors, but probably not that much.

## Time to fix remaining errors before everything works™

We did our best here to avoid you having to update/fix your code but there might
still be some minor stuff to adjust

- you might find some weird error related to fast-pipe swapping code, this can
  be related to refmt issues, you will have to fix those by hand
  - eg: `{string_of_int(value)->ReasonReact.string}` turned into
    `{string_of_int;value->ReasonReact.string}`
- check `children` errors and remove
  `let children = React.Children.toArray(children);` that might have beed added
  without being necessary
- you can safely remove spread `...` for `children`
- you might need to tweak place where children are optional with
  `{children->Belt.Option.getWithDefault(React.null)}`

### Notes about `ReasonReact.wrapJsForReason` & `ReasonReact.wrapReasonForJs`

With reason-react 0.7 & new api, code produced is just normal react component.
So this things are not necessary anymore but are not handled by the script we
used.

So you might need to remove those things & replace them with vanilla React code

- Remove `ReasonReact.wrapJsForReason`
  ([example](https://github.com/MoOx/moox.io/commit/1c38aa5bb583ff8146fc7e8fea06446d8447249a#diff-2ed4f80b953266403fd687c51270ebfa))
- Remove `ReasonReact.wrapReasonForJs`
  ([example](https://github.com/MoOx/moox.io/commit/1c38aa5bb583ff8146fc7e8fea06446d8447249a#diff-fe8d8d6fb5aac7a6cb2657ff9de22d89L65),
  [another example](https://github.com/MoOx/moox.io/commit/1c38aa5bb583ff8146fc7e8fea06446d8447249a#diff-cad3bf1049ec571062e3ad1e8c8857aaL72)
  )

## Compilation time

When you don't have any errors, just compile & enjoy jsx3. You can even add
`reason-react-native` to your `bsconfig.json` `bs-dependencies` & use it right
away with
[awesome hooks](https://reasonml.github.io/reason-react/docs/en/components) 🥳

Here are some commits that might help you

- https://github.com/MoOx/moox.io/commit/1c38aa5bb583ff8146fc7e8fea06446d8447249a
- https://github.com/MoOx/dame.bio/commit/7bded4df4bf9309b7bd5ccac8f822c4fb7ff7e09

🙏 _Please do not hesitate to share your experience with the migration._ If the
source is open, post your commit here, it could help someone without you even
knowing 🤷‍♂️

## Need help to migrate?

If you struggle with it & have questions,
[reach us on our discord server](https://discord.gg/eaU3Z6Q)

---

**If you are reading this, you can assume you are done & ready to work on other
things, like feature & bugfix for your product.**

---

## But I have more time! I WANT MORE

You can do some easy stuff to cleanup your codebase now that everything is
working and that you are ready to use reason-react 0.7:

- Easy replacement
  - `ReasonReact.string` => `React.string`
  - `ReasonReact.array` => `React.array`
  - `ReasonReact.null` => `React.null`
  - `ReasonReact.reactElement` => `React.element`
  - ...
- More tricky ones: you can probably remove lot of unecessary wrapping for
  stateless component that don't use the lifecycle
  ```reason
    ReactCompat.useRecordApi({
        ...component,
        render: _self => {
  ```
  Can be replaced with
  ```reason
  ({{
  ```
  And
  ```reason
    ReactCompat.useRecordApi({
        ...component,
        render: _self =>
  ```
  Can be replaced with
  ```reason
  ({
  ```
  At this point, the 2 replacements above have generated syntax error, so you
  should try to replace
  ```reason
  ,
    });
  ```
  with
  ```reason
  });
  ```
  At this point, you should be able to drop some
  `let component = ReasonReact.statelessComponent...` too, since some won't be
  used anymore thanks to the last removal step we did.

Now rely on refmt to get a cleaner code and you are good to go!

Do not hesitate to share more tips & tricks to ease the migration! Don't be shy!
