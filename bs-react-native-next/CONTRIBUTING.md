# Contributing

Thanks for your help!

This document describes the philosophy behind the bs-react-native-next bindings.

## Zero Cost

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

## JS Objects Passed as Props

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

## JS Objects Returned in Callbacks

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
