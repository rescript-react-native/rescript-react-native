# Changelog

## 4.1.0

### Breaking Changes

- Moved from
  [sgny/reason-react-native-netinfo](https://github.com/sgny/reason-react-native-netinfo#readme).
  `npm` package was previously named `reason-react-native-netinfo`. Please
  update your dependencies accordingly. You may update your existing code using
  the `NetInfo` module of `reason-react-native` by replacing references to the
  `ReactNative.NetInfo` module with `ReactNativeNetInfo.Legacy`. However, do
  note that the new API is more straightforward.

- The module is renamed to `ReactNativeNetInfo` (previously`CommunityNetInfo`).

- Releases require use of [jetifier](https://github.com/mikehardy/jetifier) for
  versions 0.59.x of React Native. You may continue to use
  [`reason-react-native-netinfo`](https://www.npmjs.com/package/reason-react-native-netinfo)
  version 3.2.x if you do not wish to use `jetifier`.

## 3.x

See
[sgny/reason-react-native-netinfo](https://github.com/sgny/reason-react-native-netinfo/tree/3.2.4])
