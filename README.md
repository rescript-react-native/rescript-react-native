# bs-react-native - [BuckleScript](https://github.com/bloomberg/bucklescript) bindings for [React Native](https://github.com/facebook/react-native)

**WIP**

The bindings are targeted to React Native 0.44.

Contributions of Components and APIs are very welcomed!

## Style
Since we have a proper type system we can make styles **typesafe**! Therefore styles are a little bit different declared than in JavaScript:
```reason
open ReactNative;

/* inline styles */
<View
  style=(
          Style.style [
            Style.flexDirection `column,
            Style.backgroundColor "#6698FF",
            Style.marginTop 5
          ]
        )
/>;

/* inline styles with a local open */
<View style=Style.(style [flexDirection `column, backgroundColor "#6698FF", marginTop 5]) />;

/* StyleSheets with a local open */
let styles =
  StyleSheet.create
    Style.({"wrapper": style [flexDirection `column, backgroundColor "#6698FF", marginTop 5]});

<View style=styles##wrapper />;
```

## Status

**Components**
- [x] ActivityIndicator
- [x] Button
- [x] DatePickerIOS
- [ ] DrawerLayoutAndroid
- [x] FlatList
- [x] Image
- [ ] KeyboardAvoidingView
- [ ] ListView
- [ ] MapView
- [x] Modal
- [ ] Navigator
- [ ] NavigatorIOS
- [x] Picker
- [ ] PickerIOS
- [ ] ProgressBarAndroid
- [ ] ProgressViewIOS
- [ ] RefreshControl
- [x] ScrollView
- [ ] SectionList
- [ ] SegmentedControlIOS
- [ ] Slider
- [ ] SnapshotViewIOS
- [x] StatusBar
- [ ] Switch
- [ ] TabBarIOS
- [ ] TabBarIOS.Item
- [x] Text
- [x] TextInput
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
- [x] Alert
- [x] AlertIOS
- [x] Animated
- [x] AppRegistry
- [x] AppState
- [x] AsyncStorage
- [x] BackHandler
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
- [x] Platform
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
- [x] Layout Props
- [x] Shadow Props



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
./node_modules/bs-platform/bin/bsc.exe -pp 'refmt --print binary' -i -I lib/bs/src/ -I lib/bs/src/components -I ./node_modules/reason-react/lib/bs/src/ -impl /path/to/your/file.re
```
This generates the OCaml variant of the interface file. To obtain a reason interface you can copy it into [Reason Tools](https://reasonml.github.io/reason-tools/popup.html).
