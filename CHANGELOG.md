# Changelog of `reason-react-native`

## 0.62.0 - 2020-07-20

The release we all have been waiting for (thanks for you patience)!  
Huge thanks to [@sgny](https://github.com/sgny) which handled most of the
changes directly related to react-native 0.62.

**tl;dr**: this release includes

- breaking changes related to `reason-react@0.8`
- breaking changes related to `bs-platform@7` (say bye to most `##` accessors in
  favor of `.`)
- breaking changes related to `react-native@0.62` (say bye to removed
  components)

So in order to upgrade to this release you need to upgrade all this dependencies
at the same time. Be sure to respect
[`peerDependencies`](https://github.com/reason-react-native/reason-react-native/blob/0.62.0/package.json#L4)
before reporting issue.

### 🚀 Upgrades & 💥 Breaking changes

- Upgraded reason-react to 0.8.0
  ([#689](https://github.com/reason-react-native/reason-react-native/issues/689))
  [@jfrolich](https://github.com/jfrolich)  
  See <https://reasonml.org/blog/reason-react-0-8-0> for more informations
- Upgraded to bs-platform 7.3.0
  ([#631](https://github.com/reason-react-native/reason-react-native/issues/631))
  [@idkjs](https://github.com/idkjs)
  ([#666](https://github.com/reason-react-native/reason-react-native/issues/666))
  [@Arnarkari93](https://github.com/Arnarkari93)
  ([#674](https://github.com/reason-react-native/reason-react-native/issues/674))
  ([#693](https://github.com/reason-react-native/reason-react-native/issues/693))
  ([#690](https://github.com/reason-react-native/reason-react-native/issues/690))
  ([#694](https://github.com/reason-react-native/reason-react-native/issues/694))
  [@sgny](https://github.com/sgny)
  ([#695](https://github.com/reason-react-native/reason-react-native/issues/695))
  [@cknitt](https://github.com/cknitt)  
  We have converted `Js.t` objects to records where possible (we had to skipped
  objects that rely on `[@bs.meth]`). This means you will have to change a lot
  of `##` notation to just a dot (`.`) to access properties.  
  See <https://reasonml.org/blog/whats-new-in-7-pt1> for more informations
- Removed some methods for FlatList, ScrollView, SectionList, VirtualizedList
  and VirtualizedSectionList
  ([#680](https://github.com/reason-react-native/reason-react-native/issues/680))
  [@sgny](https://github.com/sgny)  
  These components are interrelated in the sense of being based on each other
  and inheriting props, however, applicable methods are not inherited quite so
  consistently. We removed unavailable methods from each component.
- Removed `accessibilityStates` prop
  ([#656](https://github.com/reason-react-native/reason-react-native/issues/656))
  [@sgny](https://github.com/sgny)
- Removed `TextInput` `onTextInput` and `selectionState` props
  ([#658](https://github.com/reason-react-native/reason-react-native/issues/658))
  [@sgny](https://github.com/sgny)
- Animated: setting `useNativeDriver` prop is required
  ([#655](https://github.com/reason-react-native/reason-react-native/issues/655))
  [@sgny](https://github.com/sgny)
- Handle deprecated or removed components and APIs
  ([#668](https://github.com/reason-react-native/reason-react-native/issues/668))
  [@sgny](https://github.com/sgny)
  - Removed components: `ToolbarAndroid`, `ViewPagerAndroid`, `WebView`
  - Removed APIs: `AlertIOS`, `CameraRoll`, `GeoLocation`, `ImageEditor`,
    `NetInfo`, `TimePickerAndroid`
  - Some others components that have been deprecated in RN regarding "Lean Core"
    initiative have been documented as such and will be removed in future
    releases.
- Deprecated `Style.list` & `Style.listOption` for future bs-platform 8.0.0
  compatibility
  ([#700](https://github.com/reason-react-native/reason-react-native/issues/700))
  [@MoOx](https://github.com/MoOx)

### ⛑ Fixes

- Fixed `DatePickerIOS` `minuteInterval` type (int, not string)
  ([#648](https://github.com/reason-react-native/reason-react-native/issues/648))
  [@idkjs](https://github.com/idkjs)
- Fixed `Animated.ValueXY.getTranslateTransform(value)` binding
  ([#675](https://github.com/reason-react-native/reason-react-native/issues/675))
  [@benadamstyles](https://github.com/benadamstyles)
- Fixed `Global.hermesInternal`
  ([#703](https://github.com/reason-react-native/reason-react-native/issues/703))
  [@fa7ad](https://github.com/fa7ad)
- Fixed `TouchableNativeFeedback.Background.canUseNativeForeground` type
  ([#704](https://github.com/reason-react-native/reason-react-native/issues/704))
  [@phamhoaivu911](https://github.com/phamhoaivu911)

### 🚀 Additions

- Added support for callback refs
  ([#684](https://github.com/reason-react-native/reason-react-native/issues/684))
  [@cknitt](https://github.com/cknitt)
- Added `unstable_enableLogBox`
  ([#692](https://github.com/reason-react-native/reason-react-native/issues/692))
  [@MoOx](https://github.com/MoOx)
- Added `Appearance` module
  ([#654](https://github.com/reason-react-native/reason-react-native/issues/654))
  ([#662](https://github.com/reason-react-native/reason-react-native/issues/662))
  ([#677](https://github.com/reason-react-native/reason-react-native/issues/677))
  [@sgny](https://github.com/sgny)
- Added Modal `statusBarTranslucent` prop
  ([#660](https://github.com/reason-react-native/reason-react-native/issues/660))
  [@sgny](https://github.com/sgny)
- Added missing accessibility props to `Touchable*` components
  ([#659](https://github.com/reason-react-native/reason-react-native/issues/659))
  [@sgny](https://github.com/sgny)
- Added `accessibilityState` prop and constructor for related object
  ([#657](https://github.com/reason-react-native/reason-react-native/issues/657))
  [@sgny](https://github.com/sgny)
- Added `DevSettings` module
  ([#661](https://github.com/reason-react-native/reason-react-native/issues/661))
  ([#664](https://github.com/reason-react-native/reason-react-native/issues/664))
  [@sgny](https://github.com/sgny)
- Added `fadingEdgeLength` prop to FlatList, ScrollView, SectionList etc
  ([#663](https://github.com/reason-react-native/reason-react-native/issues/663))
  [@sgny](https://github.com/sgny)
- Added `accessibilityValue` prop
  ([#665](https://github.com/reason-react-native/reason-react-native/issues/665))
- Added mouse event for `react-native-web`
  ([#646](https://github.com/reason-react-native/reason-react-native/issues/646))
  [@Naturalclar](https://github.com/Naturalclar)
- Added `onMouseEnter`, `onMouseLeave` props for View, Text, TextInput and more
  web props, press-event, href and target
  ([#650](https://github.com/reason-react-native/reason-react-native/issues/650))
  [@jfrolich](https://github.com/jfrolich)
- Updated Linking documentation
  ([#673](https://github.com/reason-react-native/reason-react-native/issues/673))
  [@sgny](https://github.com/sgny)
- Updated Event documentation
  ([#672](https://github.com/reason-react-native/reason-react-native/issues/672))
  [@sgny](https://github.com/sgny)

## 0.61.1 - 2020-01-26

### 🚀 Additions

- Add `NativeEventEmitter`
  [#642](https://github.com/reason-react-native/reason-react-native/pull/642) by
  @cknitt
- New abstract type for Android Date/TimePicker `action`
  [#640](https://github.com/reason-react-native/reason-react-native/pull/640) by
  @cknitt
- Add `accessibilityRole` web values and `arialLevel` web props
  ([#639](https://github.com/reason-react-native/reason-react-native/pull/639)
  by @Naturalclar

### ⛑ Fixes

- Fix `autoCompleteType` prop for `TextInput` component (previously incorrectly
  named `autoComplete`)
  ([#639](https://github.com/reason-react-native/reason-react-native/pull/639)
  by @Naturalclar
- Resolves all BuckleScript inferred name warnings
  ([#628](https://github.com/reason-react-native/reason-react-native/pull/628)
  by @idkjs

## 0.61.0 - 2019-11-20

### 💥 Breaking change

- Change type for `DrawerLayoutAndroid` `drawerPosition` prop
  [#626](https://github.com/reason-react-native/reason-react-native/pull/626) by
  @sgny.  
  You need to replace `DrawerLayoutAndroid.left` & `DrawerLayoutAndroid.right`
  by `` `left `` & `` `right ``.

### 🚀 New bindings

- Add `SoundManager` + deprecate `UIManager.playTouchSound`
  [#616](https://github.com/reason-react-native/reason-react-native/pull/616) by
  @sgny
- Add `useWindowDimensions` hook
  [#615](https://github.com/reason-react-native/reason-react-native/pull/615) by
  @sgny
- Add `touchSoundDisabled` prop to `Button` and all Touchable components
  [#627](https://github.com/reason-react-native/reason-react-native/pull/627) by
  @stuartkeith

## 0.60.1 - 2019-10-28

Probably the latest release for React Native 0.60. We will focus on 0.61.

### 💥 Breaking changes (minor)

Sorry, a mix of bugfixes & changes! This should be easy to handle for you.

- Add constructor for section type in `VirtualizedSectionList`
  [#614](https://github.com/reason-react-native/reason-react-native/pull/614) by
  @sgny
- Add `SectionList`/`VirtualizedSectionList` section data as parameterized type
  [#618](https://github.com/reason-react-native/reason-react-native/pull/618) by
  @jfrolich

### ⛑ Fixes

- Fix `AppState` (now return `unit`)
  [#568](https://github.com/reason-react-native/reason-react-native/pull/568) by
  @cknitt
- Fix `Animated.event` type so it can be used in `Animated.ScrollView`
  `onScroll` props (& similar)
  [#584](https://github.com/reason-react-native/reason-react-native/pull/584) by
  @MoOx
- Fix missing `[@bs.meth]` in methods of `Event`, `BackHandler` & `NetInfo`
  [#621](https://github.com/reason-react-native/reason-react-native/pull/621) by
  @cknitt
- Fix `ScrollView` `scrollToItem`, `scrollToIndex` and `scrollToOffset`
  [#569](https://github.com/reason-react-native/reason-react-native/pull/569) by
  @benadamstyles
- Fix `Webview` `contentInset` prop
  [#607](https://github.com/reason-react-native/reason-react-native/pull/607) by
  @cem2ran
- Fix `WebView` event types & add missing fields
  [#608](https://github.com/reason-react-native/reason-react-native/pull/608) by
  @cem2ran

### 🚀 New bindings

- Add `AccessibilityInfo`
  [#587](https://github.com/reason-react-native/reason-react-native/pull/587) by
  @sgny
- Add `Alert.prompt`
  [#617](https://github.com/reason-react-native/reason-react-native/pull/617) by
  by @fhammerschmidt
- Add `Animated.SectionList` and `Animated.FlatList`
  [#600](https://github.com/reason-react-native/reason-react-native/pull/600) by
  @sgny +
  [#623](https://github.com/reason-react-native/reason-react-native/pull/623) by
  @jfrolich
- Add lots of `AppRegistry` methods
  [#567](https://github.com/reason-react-native/reason-react-native/pull/567) by
  @sgny +
  [#560](https://github.com/reason-react-native/reason-react-native/pull/560) by
  @cknitt
- Add `Global.__DEV__`
  [#609](https://github.com/reason-react-native/reason-react-native/pull/609) by
  @sgny
- Add `Global.hermesInternal`
  [#613](https://github.com/reason-react-native/reason-react-native/pull/613) by
  @MoOx
- Add `YellowBox`
  [#562](https://github.com/reason-react-native/reason-react-native/pull/562) by
  @cknitt

### 📖 Documentation

We improved some part of the missing docs, thanks to contributions of @sgny,
@idkjs, @fhammerschmidt & @MoOx and maybe others we forgot to mention (but
`git log` doesn't)

## 0.60.0 - 2019-06-17

✨ Initial release for this new React Native bindings!

See
<https://reasonml-community.github.io/reason-react-native/en/blog/2019-06-17-hello-reason-react-native/>
for more information.
