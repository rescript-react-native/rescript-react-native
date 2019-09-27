# Contributing Guide to `@reason-react-native/__template__`

We love your input! We want to make contributing to this project as easy and
transparent as possible, whether it's:

- Reporting a bug
- Discussing the current state of the code
- Submitting a fix
- Proposing new features
- Becoming a maintainer

We use GitHub to

- host code
- track issues and feature requests
- accept pull requests.
- tag & publish release as well as pushing those to npm.

## Reporting bugs or requesting a feature

We use GitHub issues to track public bugs or discuss about new features. Please
write bug reports or feature requests with detail, background, and sample code
if necessary.

Just try to
[open a new issue](https://github.com/reason-react-native/__template__/issues/new/choose)
& follow the instructions that should be prefilled for
[bug](.github/ISSUE_TEMPLATE/bug.md) or
[feature request](.github/ISSUE_TEMPLATE/feature.md).

People _love_ thorough bug reports. Not even kidding.

## Fixing bugs & implementing features

We use [Github flow](https://guides.github.com/introduction/flow/index.html), so
most code changes happen through Pull Requests.

[Pull Requests](https://help.github.com/en/articles/about-pull-requests) are the
best way to propose changes to the codebase since they notify watchers & allow
contributors to discuss about changes.

We actively welcome your pull requests.

To make a pull request, you need to:

1. [Fork the repo](https://help.github.com/en/articles/fork-a-repo)
2. Clone it and install dependencies

```console
git clone https://github.com/reason-react-native/__template__
cd __template__
yarn
```

3. Create a local branch, from `master` (unless specified differently)

```console
git checkout -b <name-of-your-branch>
```

4. Add your changes!

- If you've added code that should be tested, add tests.
- If you've changed APIs, update the documentation.

5. Ensure the everything is still fine.

```console
yarn test
```

6. Commit & push your branch online

```console
git add -A .
git commit -m "Your commit message"
```

7. [Create a pull request](https://help.github.com/en/articles/creating-a-pull-request)

_If you are new to Git or GitHub, we encourage you to have a look to
[makeapullrequest.com](http://makeapullrequest.com)._

## Code styling

Everything as been automated: as soon as you commit, everything should be
automatically reformated if necessary (thanks to a transparent git hook) so we
don't have to think about it!

## Licensing

By contributing, you agree that your contributions will be licensed under our
MIT License.

When you submit code changes, your submissions are understood to be under the
same [MIT License](./LICENSE) that covers the project. Feel free to contact the
maintainers if that's a concern.

---

## Implementation details

### Zero Cost

Following the spirit of the new hooks-based reason-react 0.7.0, we aim for the
bindings to be as close to the ideal of zero cost as possible.

This means that, as far as possible, we strive to avoid any bundle size increase
or performance penalty caused by the usage of these bindings.

Sometimes, this can come at the cost of usability. For example, a variant might
provide a nicer interface than inlined string constants because it enables
exhaustiveness checks on pattern matching. But as converting to and from the
variant comes with extra cost, we will stay with the inlined string constants.

After all, any abstractions on top of our bindings may still be added in user
code if required.

Also, avoiding abstractions avoid us for introducing bugs.

#### How to make zero-cost bindings

##### JS Objects Passed as Props

We use `[@bs.obj]` to model JS objects passed as props to components or as
parameters to api functions. This enables us to:

- have optional fields
- use `[@bs.string]` to map polymorphic variants to strings without extra cost
- use `[@bs.int]` to map polymorphic variants to strings without extra cost

Example (`Alert` options):

```re
[@bs.obj]
external options:
  (~cancelable: bool=?, ~onDismiss: unit => unit=?, unit) => options =
  "";
```

##### JS Objects Returned in Callbacks

We model JS objects returned in callbacks or promises as some `Js.t` type, e.g.

```re
type t = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};

[@bs.module "react-native"] [@bs.scope "Dimensions"]
external get: ([@bs.string] [ | `window | `screen]) => t = "";
```

This way, the fields of the returned `dimensions` object can be easily accessed
as `dimensions##width` etc. (whereas using e.g. `[@bs.deriving abstract]` would
require the user to use a getter function like `dimensions->Dimensions.width`).
