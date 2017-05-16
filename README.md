# [BuckleScript](https://github.com/bloomberg/bucklescript) bindings for [React Native](https://github.com/facebook/react-native)

## Getting started

Great that you want to use Reason with React Native! To get everything running are just a couple of steps.
Let's assume that you already have a React Native project. Otherwise follow the React Native [instructions](http://facebook.github.io/react-native/docs/getting-started.html) until you have your app running.

1. Install [Bucklescript](https://github.com/bloomberg/bucklescript) (the Reason -> JS compiler), [Reason-React](https://github.com/reasonml/reason-react) and `bs-react-native`:
```sh
# substitute yarn with npm if you prefer
yarn add bs-platform reason-react https://github.com/BuckleTypes/bs-react-native.git
```

2. Create a `re` folder (there will be your Reason code)
3. Create a `bsconfig.json` with the following content file in your project root
```json
{
    "name": "my-awesome-app",
    "reason": {
        "react-jsx": true
    },
    "bs-dependencies": ["bs-react-native", "reason-react"],
    "sources": [{
        "dir": "re"
    }]
}
```
4. You are nearly done, the last configuration before we get to the fun stuff. In your `package.json` add to the `"scripts"` section two scripts:

```json
"scripts": {
  ...
  "build": "bsb -make-world -clean-world",
  "watch": "bsb -make-world -clean-world -w"
}
```

5. Now you can build all your (so far nonexsisting) Reason in two modes:
  - `yarn run build` performs a single build
  - `yarn run watch` enters the watch mode
6. Now we come to the fun stuff! Create a new file `re/app.re` and make it look like this:
```reason
open ReactNative;

let app () => 
  <View style=Style.(style [flex 1., justifyContent `center, alignItems `center])>
    <Text value="Reason is awesome!" />
  </View>;
```
and start the watcher with `yarn run watch` if you haven't done it yet.

7. We are nearly done! We now have to adopt the `index.ios.js` / `index.android.js` to look like this
```js
import { app } from "./lib/js/re/app.js";
import React from "react";
import {
  AppRegistry
} from 'react-native';

AppRegistry.registerComponent('MyAwesomeProject', () => app);
```
**Note:** Make sure that the first argument to `AppRegistry.registerComponent` is **your** correct project name.

8. Now go to a new tab and start your app with `react-native run-ios` or `react-native run-android`.

9. Great you are all set up! Check the source of `bs-react-native` to find out more about the implemented APIs and Components. If you get stuck just ask on our [Discord Server](https://discord.gg/reasonml)! Happy Hacking!


Here are some more things which will be proabbyl useful for you:
- [Reason-React Documentation](https://github.com/reasonml/reason-react/blob/master/documentation.md)
- [Bucklescript Manual](http://bloomberg.github.io/bucklescript/Manual.html)
- [Bindings to `react-navigation`](https://github.com/saschatimme/bs-react-navigation)

### Disclaimer

This is **work in progress**. There are many missing APIs and the existing ones are not guaranteed to work. Contributions of Components and APIs are very welcome!

The bindings are targeted to React Native 0.44.

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
- [x] SectionList
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
- [x] Dimensions
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
- [x] PanResponder
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
