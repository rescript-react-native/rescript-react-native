# BuckleScript bindings to `@react-native-community/netinfo`

[![Version](https://img.shields.io/npm/v/@reason-react-native/netinfo.svg)](https://www.npmjs.com/@reason-react-native/netinfo)

Reason / BuckleScript bindings for
[`@react-native-community/netinfo`](https://github.com/react-native-community/react-native-netinfo)
(exposed as `ReactNativeNetInfo`).

## Support

`@reason-react-native/netinfo` X.y._ means it's compatible with
`@react-native-community/netinfo` X.y._

| version | react-native version |
| ------- | -------------------- |
| 4.1.0+  | 0.60.0+              |

For 0.59-, you should use
[`jetify -r`](https://github.com/mikehardy/jetifier/blob/master/README.md#to-reverse-jetify--convert-node_modules-dependencies-to-support-libraries).

## Installation

With `yarn`:

```console
yarn add @reason-react-native/netinfo
```

With `npm`:

```console
npm install @reason-react-native/netinfo
```

If you use React Native 0.60, `@react-native-community/netinfo` should be linked
to your project:

```console
react-native link @react-native-community/netinfo
```

Finally, `@reason-react-native/netinfo` should be added to `bs-dependencies` in
`BuckleScript` configuration of the project (`bsconfig.json`). For example:

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
+    "@reason-react-native/netinfo"
  ],
  //...
}
```

## Usage

### Types

#### `netInfoStateType`

Kind of the current network connection. Valid values are:

| Value       | Platforms             | Connection State |
| ----------- | --------------------- | ---------------- |
| `none`      | Android, iOS, Windows | Not active       |
| `unknown`   | Android, iOS, Windows | Undetermined     |
| `cellular`  | Android, iOS, Windows | Active           |
| `wifi`      | Android, iOS, Windows | Active           |
| `bluetooth` | Android               | Active           |
| `ethernet`  | Android, Windows      | Active           |
| `wimax`     | Android               | Active           |
| `vpn`       | Android               | Active           |
| `other`     | Android, iOS, Windows | Active           |

#### `netInfoCellularGeneration`

Cellular generation of the current network connection. Valid values are:

| Value   | Notes                                                                               |
| ------- | ----------------------------------------------------------------------------------- |
| `net2g` | Inlined as "2g". Returned for CDMA, EDGE, GPRS and IDEN connections                 |
| `net3g` | Inlined as "3g". Returned for EHRPD, EVDO, HSPA, HSUPA, HSDPA and UTMS connections. |
| `net4g` | Inlined as "4g". Returned for HSPAP and LTE connections                             |

#### `details`

```reason
type details = {
  .
  "isConnectionExpensive": bool,
  "cellularGeneration": Js.Nullable.t(netInfoCellularGeneration),
};
```

#### `netInfoState`

```reason
type netInfoState = {
  .
  "_type": netInfoStateType,
  "isConnected": bool,
  "details": Js.Null.t(details),
};
```

`details` key will have value `Js.Null.empty` (`null`) when `_type` is `null` or
`unknown`.

If the `details` objects is not `null`, the `cellularGeneration` key within will

- have value `Js.Nullable.undefined` when `_type` is `wifi`, `bluetooth`,
  `ethernet`, `wimax`, `vpn` or `other`.
- have value `Js.Nullable.null` if the connection is not cellular or its
  generation cannot be determined.
- be of type `netInfoCellularGeneration` only when `_type` is `cellular` and its
  generation can be determined.

### Methods

#### `fetch`

To query the connection state, returns `netInfoState` wrapped in a `Promise`.

```reason
fetch: unit => Js.Promise.t(netInfoState) = "";
```

Below example demonstrates determination of the cellular connection generation,
using this method.

```reason
React.useEffect0(() => {
  Js.Promise.(
    ReactNativeNetInfo.fetch()
    |> then_(w =>
         {
           switch (w##details->Js.Null.toOption) {
           | None => "Connection type is none or unknown"->Js.Console.warn
           | Some(x) =>
             let y = x##cellularGeneration;
             switch (y->Js.Nullable.toOption) {
             | None =>
               if (y == Js.Nullable.undefined) {
                 "Connection type is wifi, bluetooth, ethernet, wimax, vpn or other"
                 ->Js.Console.warn;
               } else {
                 "Connection generation unknown"->Js.Console.warn;
               }
             | Some(z) =>
               if (z == ReactNativeNetInfo.net2G) {
                 "2G connection"->Js.Console.warn;
               } else if (z == ReactNativeNetInfo.net3G) {
                 "3G connection"->Js.Console.warn;
               } else {
                 "4G connection"->Js.Console.warn;
               }
             };
           };
         }
         ->resolve
       )
    |> catch(err => "error"->Js.Console.warn->resolve)
    |> ignore
  );
  None;
});
```

#### `addEventListener`

To subscribe to the connection state; accepts a listener of type
`netInfoState => unit` and returns an unsubscribe method of type `unit => unit`.
The listener will be called once following subscription and each time connection
state changes.

```reason
addEventListener: (netInfoState => unit) => t;
```

where

```reason
type t = unit => unit
```

Below example demonstrates subscribing to changes in connection state:

```reason
React.useEffect0(() => {
  let remove =
    ReactNativeNetInfo.addEventListener(w =>
      (
        switch (w##details->Js.Null.toOption) {
        | None => "Connection type is none or unknown"
        | Some(x) =>
          let y = x##cellularGeneration;
          switch (y->Js.Nullable.toOption) {
          | None =>
            if (y == Js.Nullable.undefined) {
              "Connection type is wifi, bluetooth, ethernet, wimax, vpn or other";
            } else {
              "Connection generation unknown";
            }
          | Some(z) =>
            if (z == ReactNativeNetInfo.net2G) {
              "2G connection";
            } else if (z == ReactNativeNetInfo.net3G) {
              "3G connection";
            } else {
              "4G connection";
            }
          };
        }
      )
      ->Js.Console.warn
    );
  Js.Console.warn(remove);
  Some(() => remove());
});
```

#### `useNetInfo`

This method returns a React Hook with type `netInfoState`

```reason
useNetInfo: unit => netInfoState
```

Below example demonstrates its use within a `Text` component:

```reason
<Text>
  (
    switch (ReactNativeNetInfo.useNetInfo()##details->Js.Null.toOption) {
    | None => "Connection type is none or unknown"
    | Some(x) =>
      let y = x##cellularGeneration;
      switch (y->Js.Nullable.toOption) {
      | None =>
        if (y == Js.Nullable.undefined) {
          "Connection type is wifi, bluetooth, ethernet, wimax, vpn or other";
        } else {
          "Connection generation unknown";
        }
      | Some(z) =>
        if (z == ReactNativeNetInfo.net2G) {
          "2G connection";
        } else if (z == ReactNativeNetInfo.net3G) {
          "3G connection";
        } else {
          "4G connection";
        }
      };
    }
  )
  ->React.string
</Text>
```
