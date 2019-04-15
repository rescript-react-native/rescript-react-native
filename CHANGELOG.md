# v0.11.0 - 2019-04-15

Good news, maintenance of this bindings have been taken by a new crew. While we
are working hard on new, zero-cost & more straight forward bindings that will
works nicely with
[reason-react 0.7.0](https://reasonml.github.io/reason-react/blog/2019/04/10/react-hooks)
(stay tuned for more soon), we are publishing is a new release that will brings
you some latest things before we start to breaks things a little bit (but don’t
worry we have a migration plan, just because, like everybody, we have to migrate
various codebases).

This release mostly add some missing stuffs, and fixes some.

## Changelog

> We have highlighted most significant changes below. You can see the full list
> of commits
> [here](https://github.com/reasonml-community/bs-react-native/compare/v0.10.0...v0.11.0).

### Notable changes

- Fully compatible with bs-platform 4.0.18 & reason-react 0.6.0
- A lots of things has been documented
- Deprecate & replace Style.(flatten|concat) with
  (array|arrayOption|list|listOption)
- Deprecate Style.combine as it's unsafe
- New `Style.transform` function so you can choose transform order & deprecate
  `Style.Transform` methods
- View props: support `accessibilityRole`, `accessibilityStates`,
  `accessibilityHint`, `accessibilityIgnoresInvertColors` on lots of components

### More in details

- ActionSheetIOS: fix options conversion
- Animated: fix annotations
- FlatList: add `listEmptyComponent`, `refreshControl`, `stickyHeaderIndices`,
  `contentInsetAdjustmentBehavior`, `scrollEventThrottle`,
  `listFooterComponentStyle` & `listHeaderComponentStyle`
- Image: `resolveAssetSource`
- InteractionManager
- Platform: add `select`
- ScrollView: remove `onScrollAnimationEnd`, add `snapToInterval`,
  `onScrollBeginDrag`, `onScrollEndDrag`, `onMomentumScrollBegin`,
  `onMomentumScrollEnd`, `contentInsetAdjustmentBehavior`
- Style: remove `justifyContent(Stretch)` (unsupported by Yoga), add
  `justifyContent(SpaceEvenly)`, `flexBasis(Auto)`, new `transform` function
- Switch: remove `onTintColor`, `thumbTintColor` & `tintColor`, add `trackColor`
  (via `trackColorTrue` & `trackColorFalse` props), `thumbColor` and
  `iosBackgroundColor`
- Text: add `accessibilityHint`, `accessibilityLabel`
- TextInput: fixes `onChange`, `onEndEditing`, `autoComplete`
- Touchables: add `testID`, fix `on(Long)Press(In|Out)` events
- TabBarIOS: fix systemIcon `bookmarks`
- View: `accessibilityRole`, `accessibilityStates`, `accessibilityHint`,
  `accessibilityIgnoresInvertColors`
- react-native-template-reason: Enhance the react native template so you don't
  have a weird black screen. Looks more like standard RN hello world

# v0.10.0 - 2018-09-17

This is the biggest release we have done in a while. It is a result of hard work
done by
[`bs-react-native`](https://github.com/reasonml-community/bs-react-native/graphs/contributors)
and [`rebolt`](https://github.com/callstackincubator/rebolt/graphs/contributors)
teams.

We have worked really hard on bringing you lots of missing components (e.g.
`TouchableNativeFeedback`, `ProgressBarAndroid` and more), improving existing
APIs (e.g. type-safe `Animated` API) and adding documentation to make your
getting started experience even smoother. We hope you will like the changes and
the direction the project is moving! There are many companies looking into
adopting Reason within their existing React & React Native projects right now.
Our focus is to address the use cases and needs of early users to increase the
overall adoption across the ecosystem.

I also would like to thank all contributors that made this project possible. Due
to the complicated nature of merging `rebolt` and `bs-react-native` together,
some of the contribution attributions were lost in the process. Make sure to
check the
[full list our contributors](https://github.com/reasonml-community/bs-react-native/blob/master/CONTRIBUTORS.md)
for details.

Meanwhile, see the changelog below for a full list of new features and breaking
changes.

## Changelog

> We have highlighted most significant changes below. You can see the full list
> of commits
> [here](https://github.com/reasonml-community/bs-react-native/compare/v0.9.0...v0.10.0).

- Added missing bindings to the following:
  [`ToastAndroid`](https://github.com/reasonml-community/bs-react-native/commit/c00f02fe224fffc28fa7bb722a4bfcdbc262fd5f),
  [`TimePickerAndroid`](https://github.com/reasonml-community/bs-react-native/pull/233),
  [`PermissionsAndroid`](https://github.com/reasonml-community/bs-react-native/pull/230),
  [`PickerIOS`](https://github.com/reasonml-community/bs-react-native/pull/215),
  [`ViewPagerAndroid`](https://github.com/reasonml-community/bs-react-native/pull/220),
  [`TouchableNativeFeedback`](https://github.com/reasonml-community/bs-react-native/pull/219),
  [`SnapshotViewIOS`](https://github.com/reasonml-community/bs-react-native/pull/218),
  [`ProgressBarAndroid`](https://github.com/reasonml-community/bs-react-native/pull/217),
  [`MaskedView`](https://github.com/reasonml-community/bs-react-native/pull/216),
  [`ProgressViewIOS`](https://github.com/reasonml-community/bs-react-native/pull/221),
- Added a brand new documentation, available
  [here](http://reasonml-community.github.io/bs-react-native). We are working
  hard on adding more any more examples. So far,
  [`Animated`](https://reasonml-community.github.io/bs-react-native/BsReactNative/AnimatedRe-BsReactNative/)
  module is the one that is most documented,
- Created [Discord server](https://discord.gg/7XddYP6) dedicated to
  `bs-react-native` and using Reason for writing mobile apps in general. Feel
  free to join if you would like to take an active part in this project's
  development or have any questions regarding using it in production,
- Improved typing in many modules to be more accurate with what React Native
  expects, including
  [`focus` and `blur` method on `TextInput`](https://github.com/reasonml-community/bs-react-native/commit/fd0ffc78ccc4e86ce9278d7a457db32cb0856dbf),
  [`FlatList`'s `scrollToOffset`](https://github.com/reasonml-community/bs-react-native/commit/875605480825630daaa4445171a156b5f6e9a84c),
  [`WebView`'s `onMessage`](https://github.com/reasonml-community/bs-react-native/commit/f65edea9ac0b84e7c956caecc7148ab90f46a491)
  and
  [more](https://github.com/reasonml-community/bs-react-native/commit/65af108bbcd9b8a98056e3ca4245bcfbed52b5e0),
- Created a brand new
  [React Native generator](https://github.com/reasonml-community/bs-react-native/commit/bac87534cd78e73ae8f452414fe5fa69b4100202)
  for easier experience getting started,
- Added
  [Code of Conduct](https://github.com/reasonml-community/bs-react-native/blob/master/CONTRIBUTORS.md)

## Breaking changes

> All of the breaking changes happened inside `Animated` module. If you are not
> using it, you can safely upgrade and expect little to no changes required.

- `Easing` is now exported as a top-level module,
- `CompositeAnimation` is now an `Animation` module,
- There is no `Timing`, `Spring` and `Decay` module exported at a top-level. Use
  `Animated.timing`, `Animated.spring` and `Animated.decay` instead,
- You no longer need to write `Animated.CompositeAnimation.start`. All methods
  or this module are now available under `Animated` module. For example, you can
  start an animation by writing `Animated.start`. This change aligns the API
  with React Native.

See
[`Animated` guide](https://reasonml-community.github.io/bs-react-native/BsReactNative/AnimatedRe-BsReactNative/)
for details on how to use it.

## What happens with `Rebolt`?

Nothing. Rebolt development will continue under this project umbrella, together,
with the community. We are discussing the `v2` version that plans to deliver
first-class Reason APIs instead of bindings. There are many exciting
opportunities and challenges ahead. If you'd like to get involved, let us know
on Discord (linked above). As soon as any plans or decisions are made, we will
be publishing them here and on Twitter.

# v0.10.0-rc0 - 2018-09-17

Preview of upcoming version with goodies from Rebolt. We are working on
migrating the documentation and last pieces of the information. Meanwhile, feel
free to give this one a go.

Article releted:

- [Announcing Rebolt](https://blog.callstack.io/announcing-rebolt-207a1686a242)
  (@grabbou)
- [Merging Rebolt v1 back to bs-react-native](https://github.com/reasonml-community/bs-react-native/issues/204)
  (@knowbody)

### Fixed 🔧

- Fix text input callbacks (@mciparelli)
- Fix `whileEditing` to use kebab case (@shritesh)
- Update `bs-platform` and `ReasonReact` (@eldh)
- Fix `WebView` event types (@Rikkiabb)

# v0.9.0 - 2018-08-21

### Added 🚀

- Friendly disclaimer about missing components (@wokalski)

### Fixed 🔧

- Fix text input callbacks (@mciparelli)
- Fix `whileEditing` to use kebab case (@shritesh)
- Update `bs-platform` and `ReasonReact` (@eldh)
- Fix `WebView` event types (@Rikkiabb)

# v0.8.0 - 2018-04-18

### Added 🚀

- Add more `WebView` bindings (@kristinns)
- Add `sourceHtml` and `sourceUri` in `WebView` (@kristinns)
- Fix README with new Styles API (@thavishp)

### Fixed 🔧

-Fix incorrect skew bindings (@medson10) -Update `bs-platform` (@Gregoirevda)

# v0.7.0 - 2018-04-18

### Added 🚀

- Geolocation module (@mobily)
- Changed `marginTop` from `integer` to `float` (@arthur31416)
- Fix typo in CONTRIBUTING.md (@maarekj)
- Updated docs (@grsabreu) (@Gregoirevda)

### Fixed 🔧

- Supported orientation now takes list of orientations (@leomayleomay)
- `Animated.Easing.in` fix (@mcanobbio)
- Missing props on `Flatlist` (@mcanobbio)
- Missing props on `TouchableOpacity` (@laynor)
- Missing props on `SectionList` (@bjornj12) (@johannth)

### Breaking changes 💥

- Colors are now strings or interpolated which allows you to animate colors
  (@bjornj12)

# v0.6.0 - 2017-12-15

### Added 🚀

- Upgrade examples following to the SDK changes (@bohdan-hulha)
- Changed margin top from integer to float (@arthur31416)
- Fix typo in CONTRIBUTING.md (@maarekj)
- Add `DatePickerAndroid` API (@tonyhb)
- `ActionSheetIOS` — bindings (@mobily)
- `Clipboard` — bindings (@mobily)
- `CameraRoll` — bindings (@mobily)
- Add `NetInfo` bindings (@mobily)
- Add `Animated.Easing` bindings (@gilbert)
- Add CI for RNTester (@mobily)
- Update `bs-platform` to `2.2.0` (@flash-gordon)

### Breaking changes 💥

- Fix section type within `renderSectionHeader` and `renderSectionFooter`
  (@tonyhb) (#103)
- Support non-standard Platform.OS identifiers & iOS idioms (@ryanartecona)
  (#123)
- creating accessory type that includes section to match react-native s…
  (@bjornj12) (#130)

### Fixed 🔧

- Fix interface to `PanResponder.t` (@johannth)
- TextInput (returnKeyType) (@mobily)
- Fix `mimimumZoomScale` typo (=> minimumZoomScale) (@MoOx)
- Run RNTester 🎉 (@mobily)
- Make private types under TypesRN and Props public (@jamieparkinson)
- Fix `onEndReached` props on `FlatList` and `SectionList` (@maarekj)
- Add analytic spring parameters to AnimatedRe's Spring (@jamieparkinson)

# v0.5.0 - 2017-12-15

### Added 🚀

- Docs updated to Reason 3 (@Mikk36)
- Add `refmt: 3` to bsconfig to silent warning (@MarcelCutts)
- Troubleshooting section in docs (@rrdelaney)
- Add `onLongPress` to `touchableWithoutFeedback` (@kristinns)
- Make RNEvent API public (@gunnigylfa)
- Document gotcha for `react-native-scripts` (@RobertPaul01)
- Add accessibility labels to touchables (@gunnigylfa)
- Update guide

### Breaking changes 💥

- `reason-react` is now a peerDependency (@arnarthor)
- Namespaces (open ReactNative becomes open BsReactNative)(@arnarthor)
- New styles api (@wokalski) (@MoOx) The style API has been changed from using
  polymorphic variants so things like
  `flexDirection(`row)`are now`flexDirection(Row)`. It also changes stringly typed values like`padding`,`margin`,`height`,`width`, etc to have typesafe definitions like`margin(Pt(10.))`or`margin(Pct(10.))`.
- Modify `fontSize` to be able to animate it (@gunnigylfa) This changes
  `fontSize(14.)` to `fontSize(Float(14.))`

# v0.3.0 - 2017-10-28

- Bugfixes and missing props from components
- Fixing types of `maximumValue` and `minimumValue` from Slider component
  (#79) - @Denommus
- Makes `Animated.Scrollview.onScrollUpdate` use `NativeScrollEvent` (#78) -
  @alliannas
- Tab bar item bug (#84) - @wokalski
- Add missing props to `FlatList` (#83) - @arnarthor

# v0.2.1 - 2017-09-26

- multiple bug fixes from (@gunnigylfa), (@kristinns) , (@wokalski)

# v0.2.0 - 2017-09-03

- updates all components to be compatible with Reason React 0.2.4 thanks to
  (@ulrikstrid)
- several small bug fixes from @szymonzmyslony, @kristinns and (@mikkel)
- bumped `bs-platform` to `1.9.1` and enabled `bs-super-errors`

# v0.1.0 - 2017-08-04

- Initial NPM release
