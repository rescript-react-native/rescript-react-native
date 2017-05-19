# Reason RNTesterApp

The Reason RNTester showcases React Native views and modules.

## Running this app

Before running the app, make sure you ran:

    # in this folder
    npm install

### Running on iOS

Mac OS and Xcode are required.

- Open a new tab in your terminal and start the bucklescript watcher with `npm run watch`
- Open `RNTester/RNTester.xcodeproj` in Xcode
- Hit the Run button

See [Running on device](https://facebook.github.io/react-native/docs/running-on-device.html) if you want to use a physical device.

### Running on Android

You'll need to have all the [prerequisites](https://github.com/facebook/react-native/tree/master/ReactAndroid#prerequisites) (SDK, NDK) for Building React Native installed.

Start an Android emulator ([Genymotion](https://www.genymotion.com) is recommended).

- Open a new tab in your terminal and start the bucklescript watcher with `npm run watch`
- `./gradlew :RNTester:android:app:installDebug`
`
_Note: Building for the first time can take a while._

Open the RNTester app in your emulator.

See [Running on Device](https://facebook.github.io/react-native/docs/running-on-device.html) in case you want to use a physical device.
