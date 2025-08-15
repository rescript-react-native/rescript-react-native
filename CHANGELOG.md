# Changelog of `rescript-react-native`

## 0.78.0 - 2025-08-15

- upgrade to `@rescript/react@0.14` and `react@19` for `react-native@0.78`

## 0.77.4 - 2025-06-25

- Fix ScrollView onContentSizeChange params [#837](https://github.com/rescript-react-native/rescript-react-native/pull/837) by @cknitt 

## 0.77.3 - 2025-04-28

- Add missing props for ScrollView [#834](https://github.com/rescript-react-native/rescript-react-native/pull/834) by @Freddy03h 
  - `automaticallyAdjustKeyboardInsets`
  - `automaticallyAdjustsScrollIndicatorInsets`
  - `onScrollAnimationEnd`
  - `onScrollToTop`
  - `persistentScrollbar`
  - `invertStickyHeaders`
  - `disableIntervalMomentum`
  - `disableScrollViewPanResponder`
  - `StickyHeaderComponent`

## 0.77.2 - 2025-03-14

- Add missing props for Image and Modal [#831](https://github.com/rescript-react-native/rescript-react-native/pull/831) by @namenu 
  - add `resizeMultiplier` Image prop
  - add `backdropColor` and `navigationBarTranslucent` Modal props

## 0.77.1 - 2025-03-05

- Use record for separatorComponentProps [#829](https://github.com/rescript-react-native/rescript-react-native/pull/829) by @cknitt 

## 0.77.0 - 2025-02-20

- 0.77 changes [#828](https://github.com/rescript-react-native/rescript-react-native/pull/828) by @Freddy03h
  - add `display: contents` style
  - add `mixBlendMode` and `isolation` styles
  - add `boxSizing` style
  - add `outlineColor`, `outlineOffset`, `outlineStyle` and `outlineWidth` styles

## 0.76.0 - 2025-02-02

- 0.76 changes [#826](https://github.com/rescript-react-native/rescript-react-native/pull/826) by @Freddy03h
  - add `boxShadow` and `filter` styles
  - update to rescript 11.1
  - remove unnecessary trailing unit

## 0.75.0 - 2025-01-17

- 0.75 changes [#818](https://github.com/rescript-react-native/rescript-react-native/pull/818) by [Freddy03h](https://github.com/Freddy03h)
  - change `gap`, `columnGap` and `rowGap` type to `size`
  - change `translateX` and `translateY` transform type to `size`
  - remove `UIManager` `showPopupMenu` and `dismissPopupMenu`
  - remove `PushNotificationIOS`
- Js.Promise.t -> promise [#819](https://github.com/rescript-react-native/rescript-react-native/pull/819) by [@cknitt](https://github.com/cknitt)
- Js.Dict.t -> dict [#822](https://github.com/rescript-react-native/rescript-react-native/pull/822) by [@cknitt](https://github.com/cknitt)
- Get rid of Js.t [#823](https://github.com/rescript-react-native/rescript-react-native/pull/823) by [@cknitt](https://github.com/cknitt)
- Remove deprecated functions [#824](https://github.com/rescript-react-native/rescript-react-native/pull/824) by [@cknitt](https://github.com/cknitt)
- deprecate other @obj [#825](https://github.com/rescript-react-native/rescript-react-native/pull/825) by [Freddy03h](https://github.com/Freddy03h)

## 0.74.2 - 2024-12-10

- Fix transformOrigin [#821](https://github.com/rescript-react-native/rescript-react-native/pull/821) by [Freddy03h](https://github.com/Freddy03h)
  - more precise type for transformOrigin
  - fix transformOrigin keywords not handled on array syntax

## 0.74.1 - 2024-10-31

- UIManager showPopupMenu and dismissPopupMenu are deprecated [6538dbb](https://github.com/rescript-react-native/rescript-react-native/commit/6538dbb) by [Freddy03h](https://github.com/Freddy03h)

## 0.74.0 - 2024-10-20

- 0.74 changes [#815](https://github.com/rescript-react-native/rescript-react-native/pull/815) by [Freddy03h](https://github.com/Freddy03h)
  - add `space-evenly` to `align-content`
  - add `static` to `position`
  - `PushNotificationIOS` is deprecated
- Fix onScrollToIndexFailedParams [#814](https://github.com/rescript-react-native/rescript-react-native/pull/814) by [@cknitt](https://github.com/cknitt)

## 0.73.1 - 2024-08-16

- fix : rescript.json instead of bsconfig.json for files release config [dec45bd](https://github.com/rescript-react-native/rescript-react-native/commit/dec45bd) by [Freddy03h](https://github.com/Freddy03h)

## 0.73.0 - 2024-08-15

- Upgrade to rescript 11 [38cc49d](https://github.com/rescript-react-native/rescript-react-native/commit/38cc49d) by [Freddy03h](https://github.com/Freddy03h)
  - upgrade to rescript 11, @rescript/react 12 and jsx 4
  - use record props for component to avoid repetition
  - `@obj` functions as deprecated
  - `edgeInsets` as deprecated
  - convert ActivityIndicator Size type to variant
  - binding to Animated components instead of recreating them
- Fix Keyboard bindings [9380611](https://github.com/rescript-react-native/rescript-react-native/commit/9380611) by [ashishsingh101](https://github.com/ashishsingh101)
- Remove deprecated stuff from PlatformColors [8daff8b](https://github.com/rescript-react-native/rescript-react-native/commit/8daff8b) by [@cknitt](https://github.com/cknitt)
- Remove modules that were removed from React Native [1153b72](https://github.com/rescript-react-native/rescript-react-native/commit/1153b72) by [@cknitt](https://github.com/cknitt)
- add transformOrigin [1d00148](https://github.com/rescript-react-native/rescript-react-native/commit/1d00148) by [Freddy03h](https://github.com/Freddy03h)
- add maintainVisibleContentPosition in scrollview [ba62517](https://github.com/rescript-react-native/rescript-react-native/commit/ba62517) by [Yummy-sk](https://github.com/Yummy-sk)

## 0.72.0 - 2023-08-04

- Remove deprecated Slider, DatePickerIOS & ProgressViewIOS [82dc6e1](https://github.com/rescript-react-native/rescript-react-native/commit/82dc6e1) by [@MoOx](https://github.com/MoOx)
- Add VirtualizedList `onStartReached` / `onStartReachedThreshold` props [d69aa1e](https://github.com/rescript-react-native/rescript-react-native/commit/d69aa1e) by [@MoOx](https://github.com/MoOx)
- Add Appearance `setColorScheme` method [878f426](https://github.com/rescript-react-native/rescript-react-native/commit/878f426) by [@MoOx](https://github.com/MoOx)
- Add Style `borderBlockColor` `borderBlockEndColor` `borderBlockStartCo… [a12bade](https://github.com/rescript-react-native/rescript-react-native/commit/a12bade) by [@MoOx](https://github.com/MoOx)
- Add Style `borderEndEndRadius``borderEndStartRadius` `borderStartEndRadi… [66b5cbd](https://github.com/rescript-react-native/rescript-react-native/commit/66b5cbd) by [@MoOx](https://github.com/MoOx)
- Add Style margin & padding CSS logical props [c91f345](https://github.com/rescript-react-native/rescript-react-native/commit/c91f345) by [@MoOx](https://github.com/MoOx)
- Add various Android accessibility roles values [7057d79](https://github.com/rescript-react-native/rescript-react-native/commit/7057d79) by [@MoOx](https://github.com/MoOx)

## 0.71.1 - 2023-04-24

Remove `package.json` `engine` section to avoid Yarn installation issue.

## 0.71.0 - 2023-04-24

This release requires @rescript/react 0.11.0 or later.
It contains various breaking changes to match React Native 0.71.

You can see [changelog by comparing 0.71 to 0.70](https://github.com/rescript-react-native/rescript-react-native/compare/0.70.0...0.71.0)

### Contributors

- [@reck753](https://github.com/reck753)
- [@MiryangJung](https://github.com/MiryangJung)
- [@Yummy-sk](https://github.com/Yummy-sk)
- [@cknitt](https://github.com/cknitt)
- [@fhammerschmidt](https://github.com/fhammerschmidt)
- [@MoOx](https://github.com/MoOx)

## 0.70.0 - 2022-11-01

This release requires ReScript 10.0.0 or later.
It contains various breaking changes.

### Breaking Changes

- `_end` is now `end` (not a reserved word anymore) [92e3c6f](https://github.com/rescript-react-native/rescript-react-native/commit/92e3c6f) by [@cknitt](https://github.com/cknitt)
- Camel cased polymorphic variants & `_` prefixed props when possible have been changed to reflect React Native original naming convention. Things like `#plainText`, `#boxNone` etc have been changed to what they should be (`#"plain-text"`, `#"box-none"` etc) [6495093](https://github.com/rescript-react-native/rescript-react-native/commit/6495093) & [6495093](https://github.com/rescript-react-native/rescript-react-native/commit/6495093) by [@cknitt](https://github.com/cknitt) & [4360933](https://github.com/rescript-react-native/rescript-react-native/commit/4360933) by [@MoOx](https://github.com/MoOx)
- Because a limitation with ReScript that doesn't handle correctly numeric string as polymorphic variant, `fontWeight` is now an abstract type. This means that `style(~fontWeight=#_600, ())` now becomes `style(~fontWeight=FontWeight._600, ())` [44885db](https://github.com/rescript-react-native/rescript-react-native/commit/44885db) by [@cknitt](https://github.com/cknitt)
- `@string` usage have been removed when possible. This means types that were inlined in bindings are now common. [6495093](https://github.com/rescript-react-native/rescript-react-native/commit/6495093) by [@cknitt](https://github.com/cknitt)
- `Platform.os` now use polymorphic variant. `if Platform.os === Platform.android` becomes `if Platform.os === #android`. Be careful: if used in a switch, you will lose metro bundler optimisation ! [b189fbc](https://github.com/rescript-react-native/rescript-react-native/commit/b189fbc) & [9964b13](https://github.com/rescript-react-native/rescript-react-native/commit/9964b13) by [@cknitt](https://github.com/cknitt)
- `PlatformColor` have been rewritten. Lots of deprecation & polymorphic variants changes (eg: for android, instead of `#background_dark` use `#"@android:color/background_dark"`) [036566e](https://github.com/rescript-react-native/rescript-react-native/commit/036566e) by [@MoOx](https://github.com/MoOx)
- `Appearance` now returns `option<t>` instead of `Js.Null.t<t>` thanks to `@nullable` [91f0a67](https://github.com/rescript-react-native/rescript-react-native/commit/91f0a67) by [@cknitt](https://github.com/cknitt)
- Deprecated `Style.pt` unit as been removed (use `dp` instead (density pixel)) [3df0fcf](https://github.com/rescript-react-native/rescript-react-native/commit/3df0fcf) by [@cknitt](https://github.com/cknitt)

### Others changes

- Most object types created using externals can now be created using objects with optional fields. This means that things like `ActionSheetIOS.showActionSheetWithOptions(ActionSheetIOS.shareOptions(~url,(), /*...*/)` can be written `ActionSheetIOS.showActionSheetWithOptions({url}, /*...*/)`. Previous `@obj` external helpers will be deprecated in the future, and then removed. Note that `Style.style()` now have a replacement `Style.s()` that accepts an object with optional keys ! [e606a03](https://github.com/rescript-react-native/rescript-react-native/commit/e606a03) by [@cknitt](https://github.com/cknitt)
- Lots of `react-native-web@0.17` View props have been added [bee39e5](https://github.com/rescript-react-native/rescript-react-native/commit/bee39e5) by [@MoOx](https://github.com/MoOx)
- Added `Style.empty` to avoid `Style.arrayOption` (so you can write things like `Style.array([style1, condition ? style2 : Style.empty])`) [762049d](https://github.com/rescript-react-native/rescript-react-native/commit/762049d) by [@cknitt](https://github.com/cknitt)

## 0.69.1 - 2022-10-05

- Fix `View.edgeInsets` & `HitSlop.rect` [e2847e7](https://github.com/rescript-react-native/rescript-react-native/commit/e2847e7) by [@cknitt](https://github.com/cknitt)

## 0.69.0 - 2022-10-04

### Breaking changes

- Update `PushNotificationIOS.checkPermissions` to include iOS 10+ notification settings [14212c0](https://github.com/rescript-react-native/rescript-react-native/commit/14212c0) by [@MoOx](https://github.com/MoOx)

### New bindings

- Add `dismissActionSheet` method to `ActionSheetIOS` [7e42b63](https://github.com/rescript-react-native/rescript-react-native/commit/7e42b63) by [@MoOx](https://github.com/MoOx)
- Add `accessibilityLanguage` prop to all the available components [a210356](https://github.com/rescript-react-native/rescript-react-native/commit/a210356) by [@MoOx](https://github.com/MoOx)
- Add `soundName` option for local push notifications in `PushNotificationIOS` [4f04d77](https://github.com/rescript-react-native/rescript-react-native/commit/4f04d77) by [@MoOx](https://github.com/MoOx)
- Create `HitSlop` & `Rect` module (don't use them directly yet, wait for 0.70 release...) [394bd60](https://github.com/rescript-react-native/rescript-react-native/commit/394bd60) by [@MoOx](https://github.com/MoOx)

## 0.68.1 - 2022-04-20

- Fix `Animated` `eventOptions` (`platformConfig` is optional) [8d128b9](https://github.com/rescript-react-native/rescript-react-native/commit/8d128b9) by [@MoOx](https://github.com/MoOx)

## 0.68.0 - 2022-04-16

- Add `Animated.Color` node [a761012](https://github.com/rescript-react-native/rescript-react-native/commit/a761012) by [@MoOx](https://github.com/MoOx)
- Add option to supply `platformConfig` to NativeAnimated [ff931ea](https://github.com/rescript-react-native/rescript-react-native/commit/ff931ea) by [@MoOx](https://github.com/MoOx)
- Add `TextInput` `setSelection` method [32c12da](https://github.com/rescript-react-native/rescript-react-native/commit/32c12da) by [@MoOx](https://github.com/MoOx)
- Add `accessibilityLabelledBy` Android View prop [35306c3](https://github.com/rescript-react-native/rescript-react-native/commit/35306c3) by [@MoOx](https://github.com/MoOx)
- Add `AccessibilityInfo.isAccessibilityServiceEnabled` [4fb9319](https://github.com/rescript-react-native/rescript-react-native/commit/4fb9319) by [@MoOx](https://github.com/MoOx)

## 0.67.1 - 2022-04-16

- Use more gentle peerDependencies range [75ecaa2](https://github.com/rescript-react-native/rescript-react-native/commit/75ecaa2) by [@MoOx](https://github.com/MoOx)

## 0.67.0 - 2022-03-08

This changes are just to follow [React Native 0.67 changes](https://github.com/facebook/react-native/blob/main/CHANGELOG.md#v0670).

- Add `ACCESS_MEDIA_LOCATION` permission to PermisionsAndroid library [5338327](https://github.com/rescript-react-native/rescript-react-native/commit/5338327) by [@MoOx](https://github.com/MoOx)
- Added `cancelButtonTintColor` prop for `ActionSheetIOS` to change only the text color of the cancel button [42dd7ee](https://github.com/rescript-react-native/rescript-react-native/commit/42dd7ee) by [@MoOx](https://github.com/MoOx)
- Add missing `Keyboard.removeListener` [05a5656](https://github.com/rescript-react-native/rescript-react-native/commit/05a5656) by [@MoOx](https://github.com/MoOx)
- Remove `#high` and `#balanced` as values for `android_hyphenationFrequency` on `Text` [d73c6d7](https://github.com/rescript-react-native/rescript-react-native/commit/d73c6d7) by [@MoOx](https://github.com/MoOx)
- Remove `DatePickerAndroid` [31549b1](https://github.com/rescript-react-native/rescript-react-native/commit/31549b1) by [@MoOx](https://github.com/MoOx)

## 0.66.1 - 2021-12-06

- Add missing `enabled` prop to `KeyboardAvoidingView` [dbe1bfc](https://github.com/rescript-react-native/rescript-react-native/commit/dbe1bfc) by [@barodeur](https://github.com/barodeur)

## 0.66.0 - 2021-10-25

### Breaking changes

- Remove Picker & PickerIOS (Use <https://github.com/react-native-picker/picker> & <https://github.com/rescript-react-native/picker> instead) [9e45fcd](https://github.com/rescript-react-native/rescript-react-native/commit/9e45fcd) by [@MoOx](https://github.com/MoOx)
- Update `TextInput` `autoCompleteType` prop to `autoComplete` [ee307e6](https://github.com/rescript-react-native/rescript-react-native/commit/ee307e6) by [@MoOx](https://github.com/MoOx)
- Change `TextInput` `autoComplete` prop values (add more & change some to quoted polymorphic variants)) [21e802d](https://github.com/rescript-react-native/rescript-react-native/commit/21e802d) by [@MoOx](https://github.com/MoOx)

### New features

- Add `#togglebutton` to `accessibilityRole` prop [0b4688b](https://github.com/rescript-react-native/rescript-react-native/commit/0b4688b) by [@MoOx](https://github.com/MoOx)
- Add `accessibilityRole` `#tabbar` value [7c8f283](https://github.com/rescript-react-native/rescript-react-native/commit/7c8f283) by [@MoOx](https://github.com/MoOx)
- Add `Button` `accessible`, `accessibilityActions` & `onAccessibilityAction` props [484e344](https://github.com/rescript-react-native/rescript-react-native/commit/484e344) by [@MoOx](https://github.com/MoOx)
- Add `PermissionsAndroid` `bluetoothAdvertise` permission [e1ca5e5](https://github.com/rescript-react-native/rescript-react-native/commit/e1ca5e5) by [@MoOx](https://github.com/MoOx)
- Add `PlatformColor` iOS missing standard colors [92e7d77](https://github.com/rescript-react-native/rescript-react-native/commit/92e7d77) by [@MoOx](https://github.com/MoOx)
- Add `Pressable` `foreground` option for ripple config for Android [9bd7499](https://github.com/rescript-react-native/rescript-react-native/commit/9bd7499) by [@MoOx](https://github.com/MoOx)
- Add `Text` `accessibilityActions` & `onAccessibilityActions` props [9b52e53](https://github.com/rescript-react-native/rescript-react-native/commit/9b52e53) by [@MoOx](https://github.com/MoOx)

## 0.65.0 - 2021-10-18

### Notable changes

- `rescript` package is now replacing `bs-platform`.
- Several `removeEventListener` calls were removed or deprecated in React Native 0.65.
  You might have to update your code to reflect this. Check the full list below (or just follow compilation warnings/errors).

### Breaking changes

- Use `rescript@^9.1.4` instead of `bs-platform@` as a peerDependency [a2ae907](https://github.com/rescript-react-native/rescript-react-native/commit/a2ae907) by [@MoOx](https://github.com/MoOx)
- Replace `EventSubscription.t` so you can call `.remove()` on `EventSubscription.t` instead of `->EventSubscription.remove()`[71399ce](https://github.com/rescript-react-native/rescript-react-native/commit/71399ce) by [@MoOx](https://github.com/MoOx)
- Remove `NativeEventEmitter.removeSubscription` in favor of `remove()` on subscription itself [df060f9](https://github.com/rescript-react-native/rescript-react-native/commit/df060f9) by [@MoOx](https://github.com/MoOx)
- Remove `Keyboard` `removeAllListeners` and `removeListener` (you should use `remove` on listener itself) [2091cb3](https://github.com/rescript-react-native/rescript-react-native/commit/2091cb3) by [@MoOx](https://github.com/MoOx)
- Remove `AppState.removeEventListener`. Instead, use the `remove()` method on the listener itself [84284e8](https://github.com/rescript-react-native/rescript-react-native/commit/84284e8) by [@MoOx](https://github.com/MoOx)
- Remove `NativeEventEmitter.Subscription` in favor of just calling `.remove()` method on listeners. [0e4bb2d](https://github.com/rescript-react-native/rescript-react-native/commit/0e4bb2d) by [@MoOx](https://github.com/MoOx)
- Change `Dimensions.addEventListener` (now returns an `EventSubscription.t` so you can call `remove()` on listener directly ) [1131382](https://github.com/rescript-react-native/rescript-react-native/commit/1131382) by [@MoOx](https://github.com/MoOx)

### Deprecations

- Deprecate `AccessibilityInfo.removeEventListener` in favor of `remove` method on the listener itself [44f4465](https://github.com/rescript-react-native/rescript-react-native/commit/44f4465) by [@MoOx](https://github.com/MoOx)
- Deprecate `EventEmitter#removeSubscription` in favor of `remove()` on subscription itself [a771dc8](https://github.com/rescript-react-native/rescript-react-native/commit/a771dc8) by [@MoOx](https://github.com/MoOx)
- Deprecate `Linking.removeEventListener`. Instead, call `remove()` on the listener itself [4b98e2b](https://github.com/rescript-react-native/rescript-react-native/commit/4b98e2b) by [@MoOx](https://github.com/MoOx)

### New features

- Add `AccessibilityInfo.getRecommendedTimeoutMillis` [a90fe94](https://github.com/rescript-react-native/rescript-react-native/commit/a90fe94) by [@MoOx](https://github.com/MoOx)
- Add `Appearance.addChangeListener` [2cda177](https://github.com/rescript-react-native/rescript-react-native/commit/2cda177) by [@MoOx](https://github.com/MoOx)
- Add `Button` `accessibilityState` prop [7573c50](https://github.com/rescript-react-native/rescript-react-native/commit/7573c50) by [@MoOx](https://github.com/MoOx)
- Add `Color.processColor` method [0c880f8](https://github.com/rescript-react-native/rescript-react-native/commit/0c880f8) by [@MoOx](https://github.com/MoOx)
- Add `DynamicColorIOS` `highContrastLight` & `highContrastDark` optional values (with new `DynamicColorIOS.dynamicColor()` since they are optional) [cc4132b](https://github.com/rescript-react-native/rescript-react-native/commit/cc4132b) by [@MoOx](https://github.com/MoOx)
- Add `Pressable` `onBlur` and `onFocus` props [575a634](https://github.com/rescript-react-native/rescript-react-native/commit/575a634) by [@MoOx](https://github.com/MoOx)
- Add `Pressable` `onHoverIn` and `onHoverOut` react-native-web 0.16 props [e625be2](https://github.com/rescript-react-native/rescript-react-native/commit/e625be2) by [@jfrolich](https://github.com/jfrolich)
- Add `Pressable` `unstable_pressDelay` prop [3d3bf2b](https://github.com/rescript-react-native/rescript-react-native/commit/3d3bf2b) & [0117e3e](https://github.com/rescript-react-native/rescript-react-native/commit/0117e3e) by [@jfrolich](https://github.com/jfrolich)
- Add `PushNotificationIOS.getAuthorizationStatus` method [ffc2f0c](https://github.com/rescript-react-native/rescript-react-native/commit/ffc2f0c) by [@MoOx](https://github.com/MoOx)
- Add `RefreshControl` `size` option [5678d16](https://github.com/rescript-react-native/rescript-react-native/commit/5678d16) by [@MoOx](https://github.com/MoOx)
- Add `stickyHeaderHiddenOnScroll` props to `ScrollView` & friends [d981203](https://github.com/rescript-react-native/rescript-react-native/commit/d981203) by [@MoOx](https://github.com/MoOx)
- Add `Text` `onPressIn` & `onPressOut` props [536ea0e](https://github.com/rescript-react-native/rescript-react-native/commit/536ea0e) by [@MoOx](https://github.com/MoOx)
- Add `TouchableHighlight` & `TouchableOpacity` react-native-web 0.16 View prop [fbf9571](https://github.com/rescript-react-native/rescript-react-native/commit/fbf9571) by [@jfrolich](https://github.com/jfrolich)

## 0.64.3 - 2021-05-02

🚨 Minor Breaking changes for React Native Web users only

- Remove `rel` & `target` View props
- Add React Native Web `hrefAttrs` prop for 0.16

## 0.64.2 - 2021-03-20

Ooopsy. Actually this release contains .res/.resi files.

## 0.64.1 - 2021-03-20

- `reason-react-native` -> `rescript-react-native`
- `peerDependencies` changed to
  - `"@rescript/react": "^0.10.0"`
  - `"bs-platform": "^9.0.0"`

## 0.64.0 - 2021-03-19

### Breaking Changes

- Removed `CheckBox` [76ef45c](https://github.com/rescript-react-native/rescript-react-native/commit/76ef45c) by [@MoOx](https://github.com/MoOx)
- `ImageLoadEvent.source.url` is now `ImageLoadEvent.source.uri` [ce21b74](https://github.com/rescript-react-native/rescript-react-native/commit/ce21b74) by [@MoOx](https://github.com/MoOx)
- Remove `UIManager.playTouchSound` (use `SoundManager.playTouchSound` instead) [cd03cfb](https://github.com/rescript-react-native/rescript-react-native/commit/cd03cfb) by [@MoOx](https://github.com/MoOx)
- `Pressable_` is now `Pressable` (to benefit of the full benefit of Pressable, following deprecation notice in 0.63.3) [421962f](https://github.com/rescript-react-native/rescript-react-native/commit/421962f) by [@MoOx](https://github.com/MoOx)
- Changed `ActionSheetIOS` `destructiveButtonIndex` to accept array instead of just int (as RN accepts `int | array<int>`) [81f4f18](https://github.com/rescript-react-native/rescript-react-native/commit/81f4f18) by [@MoOx](https://github.com/MoOx)
- Changed `Image` `uriSource` `headers` to be `Js.Dict.t(string)` [ca786f9](https://github.com/rescript-react-native/rescript-react-native/commit/ca786f9) by [@MoOx](https://github.com/MoOx)

### Added

- Added `PlatformColor` iOS `clear` color [b813ee9](https://github.com/rescript-react-native/rescript-react-native/commit/b813ee9) by [@MoOx](https://github.com/MoOx) + [b9e33c7](https://github.com/rescript-react-native/rescript-react-native/commit/b9e33c7)
- Added `Text` `android_hyphenationFrequency` prop [1864063](https://github.com/rescript-react-native/rescript-react-native/commit/1864063) by [@MoOx](https://github.com/MoOx)
- Added `Text` `dataDetectorTypes` prop [635066c](https://github.com/rescript-react-native/rescript-react-native/commit/635066c) by [@MoOx](https://github.com/MoOx)
- Added `Text` `disabled` prop [635066c](https://github.com/rescript-react-native/rescript-react-native/commit/635066c) by [@MoOx](https://github.com/MoOx)
- Added `Text` `maxFontSize…Multiplier` prop [635066c](https://github.com/rescript-react-native/rescript-react-native/commit/635066c) by [@MoOx](https://github.com/MoOx)
- Added `Text` `nativeID` prop [635066c](https://github.com/rescript-react-native/rescript-react-native/commit/635066c) by [@MoOx](https://github.com/MoOx)
- Added `Text` `onTextLayout` prop [635066c](https://github.com/rescript-react-native/rescript-react-native/commit/635066c) by [@MoOx](https://github.com/MoOx)
- Added `Text` gesture responder props [635066c](https://github.com/rescript-react-native/rescript-react-native/commit/635066c) by [@MoOx](https://github.com/MoOx)
- Added `TextInput` `onPressIn` & `onPressOut` [13b8e7f](https://github.com/rescript-react-native/rescript-react-native/commit/13b8e7f) by [@MoOx](https://github.com/MoOx)
- Added `NativeEventEmitter.listenerCount` [e88e336](https://github.com/rescript-react-native/rescript-react-native/commit/e88e336) by [@MoOx](https://github.com/MoOx)
- Added `ActionSheetIOS` `disabledButtonIndices` [74af1ab](https://github.com/rescript-react-native/rescript-react-native/commit/74af1ab) by [@MoOx](https://github.com/MoOx)

## 0.63.5 - 2021-03-10

Fix & change Android PlatformColor binding to use built-in selector [#737](https://github.com/rescript-react-native/rescript-react-native/pull/737) by [@diaozheng999](https://github.com/diaozheng999)

- Fixed `PlatformColor.Android.getAttr`: now use `"?android:attr/*` instead of `"?attr/*`
- Added `PlatformColor.Android.get{x}` (x being an integer from 2 to 7) so you can use `@android:color` & `@?android:attr` in the same call, as `PlatformColor` accepts multiple arguments as fallbacks.
- Added `PlatformColor.unsafeGet{x}` (x being an integer from 2 to 7) that allow you to pass unsafe values (string, which can be useful for user defined values).

Also:

- Added `PlatformColor.Android.get`
- Added `PlatformColor.Ios.get{x}` like Android
- `PlatformColor.IOS` is deprecated in favor of `PlatformColor.Ios`
- `PlatformColor.Android.unsafeGet` is deprecated in favor of `PlatformColor.unsafeGet`

## 0.63.4 - 2021-02-24

Fixed `measure` & `measureInWindow` functions types [#736](https://github.com/rescript-react-native/rescript-react-native/pull/736) by [@Freddy03h](https://github.com/Freddy03h)

## 0.63.3 - 2021-02-19

Added Pressable with child function and interaction states (as `Pressable_`) [#735](https://github.com/rescript-react-native/rescript-react-native/pull/735) by [@Freddy03h](https://github.com/Freddy03h)

## 0.63.2 - 2020-11-20

Breaking change, sorry: Reverting ActivityIndicator size as polymorphic variant so we can keep the exact option.

## 0.63.1 - 2020-11-17

Fix npm description

## 0.63.0 - 2020-11-06

### Breaking changes

- ⚠️ Changed minimal versions required [#722](https://github.com/rescript-react-native/rescript-react-native/pull/722) by [@cknitt](https://github.com/cknitt)
  - ReScript / bs-platform 8.2
  - rescript-react 0.9.1
- Switched solution to avoid warnings being throw as errors [b5038e9](https://github.com/rescript-react-native/rescript-react-native/commit/b5038e9) by [@MoOx](https://github.com/MoOx) with the help of [@Freddy03h](https://github.com/Freddy03h) and [@bobzhang](https://github.com/bobzhang) in [#718](https://github.com/rescript-react-native/safe-area-context/pull/4)
  This will help to avoid issue if ReScript introduce new warning that caused in the past impossibility to use our bindings (eg: ReScript 8.2 bs.string annontations).
- Switch to polymorphic variants instead of abstract types where possible
  [#724](https://github.com/rescript-react-native/rescript-react-native/pull/724) [#727](https://github.com/rescript-react-native/rescript-react-native/pull/727) by [@cknitt](https://github.com/cknitt)
- Removed superfluous bs.string attributes [#723](https://github.com/rescript-react-native/rescript-react-native/pull/723) by [@cknitt](https://github.com/cknitt)
  This change shouldn't impact your code if you are using ReScript 8.2 as required.
- Accessibility changes for react-native 0.63 [#728](https://github.com/rescript-react-native/rescript-react-native/pull/728) by [@cknitt](https://github.com/cknitt)
  - Removed `accessibilityComponentType`
  - Removed `accessibilityTraits`.
  - Added `AccessibilityActionEvent`
  - Added `onAccessibilityAction`.
  - Added `Accessibility.actionInfo` (already there, but broken - missing unit to terminate argument list).
  - Note that `Accessibility.role` was actually already up to date (except for the value "switch" which we can't add because it's a keyword). Feel free to open an issue if you need `switch` value.
- Removed `Global.unstable_enableLogBox` [#718](https://github.com/rescript-react-native/rescript-react-native/pull/718) by [@gedeagas](https://github.com/gedeagas)
  This is now enabled by default in React Native 0.63. See added `LogBox` bindings for more options.
- Removed `tintColor` prop from Switch component [#714](https://github.com/rescript-react-native/rescript-react-native/pull/714) by [@gedeagas](https://github.com/gedeagas)

### Fixes

- Fixed `VirtualizedListMethods.scrollToItemParams` [#715](https://github.com/rescript-react-native/rescript-react-native/pull/715) by [@cknitt](https://github.com/cknitt)

### New Features

- Added `DynamicColorIOS` [#717](https://github.com/rescript-react-native/rescript-react-native/pull/717) by [@celsobonutti](https://github.com/celsobonutti)
  Note that there is only 2 keys (`light` and `dark`) but React Native documentation mention they might be more in the future, without saying if they will be mandatory or not. If you want to protect yourself, you might want to make your own factory. In any case, we can still deprecate the `make` binding & create a new external binding with optional keys. So don't worry too much.
- Added `PlatformColor` binding [#730](https://github.com/rescript-react-native/rescript-react-native/pull/730) by [@rifaldhiaw](https://github.com/rifaldhiaw)
- Added `PermissionsAndroid.accessBackgroundLocation` [#729](https://github.com/rescript-react-native/rescript-react-native/pull/729) by [@cknitt](https://github.com/cknitt) + [b8392e3](https://github.com/rescript-react-native/rescript-react-native/commit/b8392e3) by [@MoOx](https://github.com/MoOx)
- Added `LogBox` [#711](https://github.com/rescript-react-native/rescript-react-native/pull/711) by [@idkjs](https://github.com/idkjs)
- Added `accessibilityActions` prop [#713](https://github.com/rescript-react-native/rescript-react-native/pull/713) by [@gedeagas](https://github.com/gedeagas)
- Added `Pressable` [#712](https://github.com/rescript-react-native/rescript-react-native/pull/712) by [@gedeagas](https://github.com/gedeagas)
- Added `AppState` values `unknown` and `extension` (iOS) [#726](https://github.com/rescript-react-native/rescript-react-native/pull/726) by [@cknitt](https://github.com/cknitt)

### Misc

- ReScript branding has been adopted in various places in all the repos of our organisation.
- More futur proof "files" patterns for npm (in case of interop files) [1a3b677](https://github.com/rescript-react-native/rescript-react-native/commit/1a3b677) by [@MoOx](https://github.com/MoOx)
- Simplify package.json files section [a9cacbd](https://github.com/rescript-react-native/rescript-react-native/commit/a9cacbd) by [@MoOx](https://github.com/MoOx)

## 0.62.3 - 2020-08-07

- Stop blocking compilation because of ReScript warnings (emitted as errors) [#708](https://github.com/rescript-react-native/rescript-react-native/pull/708) by [@jfrolich](https://github.com/jfrolich)  
  This is to ensure ReScript 8.2 compatibility & avoid similar problem in the future.

## 0.62.2 - 2020-07-27

- Fixed ScrollEvent type [5df7fb0](https://github.com/rescript-react-native/rescript-react-native/commit/5df7fb0ff5f7c1be2373347bc2ca1923e69ba112) by [@MoOx](https://github.com/MoOx)

## 0.62.1 - 2020-07-27

- Fixed View props for all components that use them (stay in sync) [e5adee0](https://github.com/rescript-react-native/rescript-react-native/commit/e5adee0a71fa189937d64b130fd45d0deac0b4e8) by [@MoOx](https://github.com/MoOx)
- Removed TabBarIOS (removed since RN 0.59) [13991e0](https://github.com/rescript-react-native/rescript-react-native/commit/13991e0f39cf04c9e0390e6bad3db759ac466e65) by [@MoOx](https://github.com/MoOx)
- Internal: removed duplicated code source in md files (website will produce the same result - no manual syncing required) [1524b87](https://github.com/rescript-react-native/rescript-react-native/commit/1524b87b077e9920a85786bd5e3f887991a7c723) by [@MoOx](https://github.com/MoOx)

## 0.62.0 - 2020-07-20

The release we all have been waiting for (thanks for you patience)!  
Huge thanks to [@sgny](https://github.com/sgny) which handled most of the
changes directly related to react-native 0.62.

**tl;dr**: this release includes

- breaking changes related to `rescript-react@0.8`
- breaking changes related to `bs-platform@7` (say bye to most `##` accessors in
  favor of `.`)
- breaking changes related to `react-native@0.62` (say bye to removed
  components)

So in order to upgrade to this release you need to upgrade all this dependencies
at the same time. Be sure to respect
[`peerDependencies`](https://github.com/rescript-react-native/rescript-react-native/blob/0.62.0/package.json#L4)
before reporting issue.

### 🚀 Upgrades & 💥 Breaking changes

- Upgraded rescript-react to 0.8.0 ([#689](https://github.com/rescript-react-native/rescript-react-native/issues/689)) by [@jfrolich](https://github.com/jfrolich)  
  See <https://rescript-lang.org/blog/rescript-react-0-8-0> for more informations
- Upgraded to bs-platform 7.3.0 ([#631](https://github.com/rescript-react-native/rescript-react-native/issues/631)) by [@idkjs](https://github.com/idkjs) ([#666](https://github.com/rescript-react-native/rescript-react-native/issues/666)) by [@Arnarkari93](https://github.com/Arnarkari93) ([#674](https://github.com/rescript-react-native/rescript-react-native/issues/674)) ([#693](https://github.com/rescript-react-native/rescript-react-native/issues/693)) ([#690](https://github.com/rescript-react-native/rescript-react-native/issues/690)) ([#694](https://github.com/rescript-react-native/rescript-react-native/issues/694)) by [@sgny](https://github.com/sgny) ([#695](https://github.com/rescript-react-native/rescript-react-native/issues/695)) by [@cknitt](https://github.com/cknitt)  
  We have converted `Js.t` objects to records where possible (we had to skipped objects that rely on `[@bs.meth]`). This means ou will have to change a lot of `##` notation to just a dot (`.`) to access properties.  
  See <https://rescript-lang.org/blog/whats-new-in-7-pt1> for more informations
- Removed some methods for FlatList, ScrollView, SectionList, VirtualizedList and VirtualizedSectionList ([#680](https://github.com/rescript-react-native/rescript-react-native/issues/680)) by [@sgny](https://github.com/sgny)  
  These components are interrelated in the sense of being based on each other and inheriting props, however, applicable methods are not inherited quite so consistently. We removed unavailable methods from each component.
- Removed `accessibilityStates` prop ([#656](https://github.com/rescript-react-native/rescript-react-native/issues/656)) by [@sgny](https://github.com/sgny)
- Removed `TextInput` `onTextInput` and `selectionState` props ([#658](https://github.com/rescript-react-native/rescript-react-native/issues/658)) by [@sgny](https://github.com/sgny)
- Animated: setting `useNativeDriver` prop is required ([#655](https://github.com/rescript-react-native/rescript-react-native/issues/655)) by [@sgny](https://github.com/sgny)
- Handle deprecated or removed components and APIs ([#668](https://github.com/rescript-react-native/rescript-react-native/issues/668)) by [@sgny](https://github.com/sgny)
  - Removed components: `ToolbarAndroid`, `ViewPagerAndroid`, `WebView`
  - Removed APIs: `AlertIOS`, `CameraRoll`, `GeoLocation`, `ImageEditor`,
    `NetInfo`, `TimePickerAndroid`
  - Some others components that have been deprecated in RN regarding "Lean Core" initiative have been documented as such and will be removed in future releases.
- Deprecated `Style.list` & `Style.listOption` for future bs-platform 8.0.0
  compatibility ([#700](https://github.com/rescript-react-native/rescript-react-native/issues/700)) by [@MoOx](https://github.com/MoOx)

### ⛑ Fixes

- Fixed `DatePickerIOS` `minuteInterval` type (int, not string) ([#648](https://github.com/rescript-react-native/rescript-react-native/issues/648)) by [@idkjs](https://github.com/idkjs)
- Fixed `Animated.ValueXY.getTranslateTransform(value)` binding ([#675](https://github.com/rescript-react-native/rescript-react-native/issues/675)) by [@benadamstyles](https://github.com/benadamstyles)
- Fixed `Global.hermesInternal` ([#703](https://github.com/rescript-react-native/rescript-react-native/issues/703)) by [@fa7ad](https://github.com/fa7ad)
- Fixed `TouchableNativeFeedback.Background.canUseNativeForeground` type ([#704](https://github.com/rescript-react-native/rescript-react-native/issues/704)) by [@phamhoaivu911](https://github.com/phamhoaivu911)

### 🚀 Additions

- Added support for callback refs ([#684](https://github.com/rescript-react-native/rescript-react-native/issues/684)) by [@cknitt](https://github.com/cknitt)
- Added `unstable_enableLogBox` ([#692](https://github.com/rescript-react-native/rescript-react-native/issues/692)) by [@MoOx](https://github.com/MoOx)
- Added `Appearance` module ([#654](https://github.com/rescript-react-native/rescript-react-native/issues/654)) ([#662](https://github.com/rescript-react-native/rescript-react-native/issues/662)) ([#677](https://github.com/rescript-react-native/rescript-react-native/issues/677)) by [@sgny](https://github.com/sgny)
- Added Modal `statusBarTranslucent` prop ([#660](https://github.com/rescript-react-native/rescript-react-native/issues/660)) by [@sgny](https://github.com/sgny)
- Added missing accessibility props to `Touchable*` components ([#659](https://github.com/rescript-react-native/rescript-react-native/issues/659)) by [@sgny](https://github.com/sgny)
- Added `accessibilityState` prop and constructor for related object ([#657](https://github.com/rescript-react-native/rescript-react-native/issues/657)) by [@sgny](https://github.com/sgny)
- Added `DevSettings` module ([#661](https://github.com/rescript-react-native/rescript-react-native/issues/661)) ([#664](https://github.com/rescript-react-native/rescript-react-native/issues/664)) by [@sgny](https://github.com/sgny)
- Added `fadingEdgeLength` prop to FlatList, ScrollView, SectionList etc ([#663](https://github.com/rescript-react-native/rescript-react-native/issues/663)) by [@sgny](https://github.com/sgny)
- Added `accessibilityValue` prop ([#665](https://github.com/rescript-react-native/rescript-react-native/issues/665))
- Added mouse event for `react-native-web` ([#646](https://github.com/rescript-react-native/rescript-react-native/issues/646)) by [@Naturalclar](https://github.com/Naturalclar)
- Added `onMouseEnter`, `onMouseLeave` props for View, Text, TextInput and more
  web props, press-event, href and target ([#650](https://github.com/rescript-react-native/rescript-react-native/issues/650)) by [@jfrolich](https://github.com/jfrolich)
- Updated Linking documentation ([#673](https://github.com/rescript-react-native/rescript-react-native/issues/673)) by [@sgny](https://github.com/sgny)
- Updated Event documentation ([#672](https://github.com/rescript-react-native/rescript-react-native/issues/672)) by [@sgny](https://github.com/sgny)

## 0.61.1 - 2020-01-26

### 🚀 Additions

- Add `NativeEventEmitter` [#642](https://github.com/rescript-react-native/rescript-react-native/pull/642) by [@cknitt](https://github.com/cknitt)
- New abstract type for Android Date/TimePicker `action` [#640](https://github.com/rescript-react-native/rescript-react-native/pull/640) by [@cknitt](https://github.com/cknitt)
- Add `accessibilityRole` web values and `arialLevel` web props ([#639](https://github.com/rescript-react-native/rescript-react-native/pull/639) by [@Naturalclar](https://github.com/Naturalclar)

### ⛑ Fixes

- Fix `autoCompleteType` prop for `TextInput` component (previously incorrectly
  named `autoComplete`) ([#639](https://github.com/rescript-react-native/rescript-react-native/pull/639) by [@Naturalclar](https://github.com/Naturalclar)
- Resolves all ReScript / BuckleScript inferred name warnings ([#628](https://github.com/rescript-react-native/rescript-react-native/pull/628) by [@idkjs](https://github.com/idkjs)

## 0.61.0 - 2019-11-20

### 💥 Breaking change

- Change type for `DrawerLayoutAndroid` `drawerPosition` prop [#626](https://github.com/rescript-react-native/rescript-react-native/pull/626) by [@sgny](https://github.com/sgny).  
  You need to replace `DrawerLayoutAndroid.left` & `DrawerLayoutAndroid.right` by [``](https://github.com/`) ` left `` & `` `right ``.

### 🚀 New bindings

- Add `SoundManager` + deprecate `UIManager.playTouchSound` [#616](https://github.com/rescript-react-native/rescript-react-native/pull/616) by [@sgny](https://github.com/sgny)
- Add `useWindowDimensions` hook [#615](https://github.com/rescript-react-native/rescript-react-native/pull/615) by [@sgny](https://github.com/sgny)
- Add `touchSoundDisabled` prop to `Button` and all Touchable components [#627](https://github.com/rescript-react-native/rescript-react-native/pull/627) by [@stuartkeith](https://github.com/stuartkeith)

## 0.60.1 - 2019-10-28

Probably the latest release for React Native 0.60. We will focus on 0.61.

### 💥 Breaking changes (minor)

Sorry, a mix of bugfixes & changes! This should be easy to handle for you.

- Add constructor for section type in `VirtualizedSectionList` [#614](https://github.com/rescript-react-native/rescript-react-native/pull/614) by [@sgny](https://github.com/sgny)
- Add `SectionList`/`VirtualizedSectionList` section data as parameterized type [#618](https://github.com/rescript-react-native/rescript-react-native/pull/618) by [@jfrolich](https://github.com/jfrolich)

### ⛑ Fixes

- Fix `AppState` (now return `unit`) [#568](https://github.com/rescript-react-native/rescript-react-native/pull/568) by [@cknitt](https://github.com/cknitt)
- Fix `Animated.event` type so it can be used in `Animated.ScrollView`
  `onScroll` props (& similar) [#584](https://github.com/rescript-react-native/rescript-react-native/pull/584) by [@MoOx](https://github.com/MoOx)
- Fix missing `[@bs.meth]` in methods of `Event`, `BackHandler` & `NetInfo` [#621](https://github.com/rescript-react-native/rescript-react-native/pull/621) by [@cknitt](https://github.com/cknitt)
- Fix `ScrollView` `scrollToItem`, `scrollToIndex` and `scrollToOffset` [#569](https://github.com/rescript-react-native/rescript-react-native/pull/569) by [@benadamstyles](https://github.com/benadamstyles)
- Fix `Webview` `contentInset` prop [#607](https://github.com/rescript-react-native/rescript-react-native/pull/607) by [@cem2ran](https://github.com/cem2ran)
- Fix `WebView` event types & add missing fields [#608](https://github.com/rescript-react-native/rescript-react-native/pull/608) by [@cem2ran](https://github.com/cem2ran)

### 🚀 New bindings

- Add `AccessibilityInfo` [#587](https://github.com/rescript-react-native/rescript-react-native/pull/587) by [@sgny](https://github.com/sgny)
- Add `Alert.prompt` [#617](https://github.com/rescript-react-native/rescript-react-native/pull/617) by by [@fhammerschmidt](https://github.com/fhammerschmidt)
- Add `Animated.SectionList` and `Animated.FlatList` [#600](https://github.com/rescript-react-native/rescript-react-native/pull/600) by [@sgny](https://github.com/sgny) + [#623](https://github.com/rescript-react-native/rescript-react-native/pull/623) by [@jfrolich](https://github.com/jfrolich)
- Add lots of `AppRegistry` methods [#567](https://github.com/rescript-react-native/rescript-react-native/pull/567) by [@sgny](https://github.com/sgny) + [#560](https://github.com/rescript-react-native/rescript-react-native/pull/560) by [@cknitt](https://github.com/cknitt)
- Add `Global.__DEV__` [#609](https://github.com/rescript-react-native/rescript-react-native/pull/609) by [@sgny](https://github.com/sgny)
- Add `Global.hermesInternal` [#613](https://github.com/rescript-react-native/rescript-react-native/pull/613) by [@MoOx](https://github.com/MoOx)
- Add `YellowBox` [#562](https://github.com/rescript-react-native/rescript-react-native/pull/562) by [@cknitt](https://github.com/cknitt)

### 📖 Documentation

We improved some part of the missing docs, thanks to contributions of @sgny,
@idkjs, @fhammerschmidt & @MoOx and maybe others we forgot to mention (but
`git log` doesn't)

## 0.60.0 - 2019-06-17

✨ Initial release for this new React Native bindings!

See
<https://rescript-react-native.github.io/en/blog/2019-06-17-hello-reason-react-native/>
for more information.
