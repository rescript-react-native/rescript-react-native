# bs-react-native - [BuckleScript](https://github.com/bloomberg/bucklescript) bindings for [React Native](https://github.com/facebook/react-native)

**WIP**

Contributions of Components and APIs are very welcomed!

## Status

**Components**
- [ ] ActivityIndicator
- [x] Button
- [ ] DatePickerIOS
- [ ] DrawerLayoutAndroid
- [ ] FlatList
- [ ] Image
- [ ] KeyboardAvoidingView
- [ ] ListView
- [ ] MapView
- [ ] Modal
- [ ] Navigator
- [ ] NavigatorIOS
- [ ] Picker
- [ ] PickerIOS
- [ ] ProgressBarAndroid
- [ ] ProgressViewIOS
- [ ] RefreshControl
- [x] ScrollView
- [ ] SectionList
- [ ] SegmentedControlIOS
- [ ] Slider
- [ ] SnapshotViewIOS
- [ ] StatusBar
- [ ] Switch
- [ ] TabBarIOS
- [ ] TabBarIOS.Item
- [x] Text
- [ ] TextInput
- [ ] ToolbarAndroid
- [x] TouchableHighlight
- [ ] TouchableNativeFeedback
- [x] TouchableOpacity
- [x] TouchableWithoutFeedback
- [x] View
- [ ] ViewPagerAndroid
- [ ] VirtualizedList
- [ ] WebView


**APIs**
- [ ] AccessibilityInfo
- [ ] ActionSheetIOS
- [ ] AdSupportIOS
- [ ] Alert
- [ ] AlertIOS
- [ ] Animated
- [ ] AppRegistry
- [ ] AppState
- [ ] AsyncStorage
- [ ] BackAndroid
- [ ] CameraRoll
- [ ] Clipboard
- [ ] DatePickerAndroid
- [ ] Dimensions
- [ ] Easing
- [ ] Geolocation
- [ ] ImageEditor
- [ ] ImagePickerIOS
- [ ] ImageStore
- [ ] InteractionManager
- [ ] Keyboard
- [ ] LayoutAnimation
- [ ] Linking
- [ ] NativeMethodsMixin
- [ ] NetInfo
- [ ] PanResponder
- [ ] PermissionsAndroid
- [ ] PixelRatio
- [ ] PushNotificationIOS
- [ ] Settings
- [ ] Share
- [ ] StatusBarIOS
- [x] StyleSheet
- [ ] Systrace
- [ ] TimePickerAndroid
- [ ] ToastAndroid
- [ ] Vibration
- [ ] VibrationIOS
- [ ] Layout Props
- [ ] Shadow Props



## Contribute
```sh
git clone https://github.com/BuckleTypes/bs-react-native.git
cd react-native
npm install
```

Then build with `npm start`.

## Development

### Generate Interface files

You can generate an interface file (`.rei`) with
```sh
./node_modules/bs-platform/bin/bsc.exe -pp 'refmt --print binary' -i -I /path/to/lib -impl /path/to/file.re
```
