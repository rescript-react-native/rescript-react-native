## v0.10.0 - 2018-09-17

Preview of upcoming version with goodies from Rebolt. We are working on migrating the documentation and last pieces of the information. Meanwhile, feel free to give this one a go.

Article raleted:

- [Announcing Rebolt](https://blog.callstack.io/announcing-rebolt-207a1686a242) (@grabbou)
- [Merging Rebolt v1 back to bs-react-native](https://github.com/reasonml-community/bs-react-native/issues/204) (@knowbody)

### Fixed 🔧

- Fix text input callbacks (@mciparelli)
- Fix `whileEditing` to use kebab case (@shritesh)
- Update `bs-platform` and `ReasonReact` (@eldh)
- Fix `WebView` event types (@Rikkiabb)

## v0.9.0 - 2018-08-21

### Added 🚀

- Friendly disclaimer about missing components (@wokalski)

### Fixed 🔧

- Fix text input callbacks (@mciparelli)
- Fix `whileEditing` to use kebab case (@shritesh)
- Update `bs-platform` and `ReasonReact` (@eldh)
- Fix `WebView` event types (@Rikkiabb)

## v0.8.0 - 2018-04-18

### Added 🚀

- Add more `WebView` bindings (@kristinns)
- Add `sourceHtml` and `sourceUri` in `WebView` (@kristinns)
- Fix README with new Styles API (@thavishp)

### Fixed 🔧

-Fix incorrect skew bindings (@medson10)
-Update `bs-platform` (@Gregoirevda)

## v0.7.0 - 2018-04-18

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

- Colors are now strings or interpolated which allows you to animate colors (@bjornj12)

## v0.6.0 - 2017-12-15

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

- Fix section type within `renderSectionHeader` and `renderSectionFooter` (@tonyhb) (#103)
- Support non-standard Platform.OS identifiers & iOS idioms (@ryanartecona) (#123)
- creating accessory type that includes section to match react-native s… (@bjornj12) (#130)

### Fixed 🔧

- Fix interface to `PanResponder.t` (@johannth)
- TextInput (returnKeyType) (@mobily)
- Fix `mimimumZoomScale` typo (=> minimumZoomScale) (@MoOx)
- Run RNTester 🎉 (@mobily)
- Make private types under TypesRN and Props public (@jamieparkinson)
- Fix `onEndReached` props on `FlatList` and `SectionList` (@maarekj)
- Add analytic spring parameters to AnimatedRe's Spring (@jamieparkinson)

## v0.5.0 - 2017-12-15

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
- New styles api (@wokalski) (@MoOx)
  The style API has been changed from using polymorphic variants so things like `flexDirection(`row)`are now`flexDirection(Row)`. It also changes stringly typed values like`padding`,`margin`,`height`,`width`, etc to have typesafe definitions like`margin(Pt(10.))`or`margin(Pct(10.))`.
- Modify `fontSize` to be able to animate it (@gunnigylfa)
  This changes `fontSize(14.)` to `fontSize(Float(14.))`

## v0.3.0 - 2017-10-28

- Bugfixes and missing props from components
- Fixing types of `maximumValue` and `minimumValue` from Slider component (#79) - @Denommus
- Makes `Animated.Scrollview.onScrollUpdate` use `NativeScrollEvent` (#78) - @alliannas
- Tab bar item bug (#84) - @wokalski
- Add missing props to `FlatList` (#83) - @arnarthor

## v0.2.1 - 2017-09-26

- multiple bug fixes from (@gunnigylfa), (@kristinns) , (@wokalski)

## v0.2.0 - 2017-09-03

- updates all components to be compatible with Reason React 0.2.4 thanks to (@ulrikstrid)
- several small bug fixes from @szymonzmyslony, @kristinns and (@mikkel)
- bumped `bs-platform` to `1.9.1` and enabled `bs-super-errors`

## v0.1.0 - 2017-08-04

- Initial NPM release
