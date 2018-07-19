---
title: Rebolt Navigation
---

## Installation

First make sure you have Rebolt added to your project. If you don't, see the [get started](/docs/get-started) guide.

### Add dependencies

Let's add `rebolt-navigation` and its peer dependency `react-native-gesture-handler`:

```sh
npm i -P rebolt-navigation react-native-gesture-handler
```

or using yarn:

```sh
yarn add rebolt-navigation react-native-gesture-handler
```

### react-native-gesture-handler

As `react-native-gesture-handler` uses native support it requires custom installation.

First we will link the library using `react-native link`:

```sh
react-native link react-native-gesture-handler
```

That's all we need for iOS, now we will add a few more things to make it work on Android as well:

Navigate to `android/app/src/main/java/com/YOUR_APP_NAME` and let's edit `MainActivity.java`:

Add a few imports:

```java
import com.facebook.react.ReactActivityDelegate;
import com.facebook.react.ReactRootView;
import com.swmansion.gesturehandler.react.RNGestureHandlerEnabledRootView;
```

and add a method in the MainActivity class:

```java
@Override
protected ReactActivityDelegate createReactActivityDelegate() {
  return new ReactActivityDelegate(this, getMainComponentName()) {
    @Override
    protected ReactRootView createRootView() {
      return new RNGestureHandlerEnabledRootView(MainActivity.this);
    }
  };
}
```

in the end your `MainActivity.java` should look like:

```java
package com.swmansion.gesturehandler.react.example;

import com.facebook.react.ReactActivity;

import com.facebook.react.ReactActivityDelegate;
import com.facebook.react.ReactRootView;
import com.swmansion.gesturehandler.react.RNGestureHandlerEnabledRootView;

public class MainActivity extends ReactActivity {

  @Override
  protected String getMainComponentName() {
    return "Example";
  }

  @Override
  protected ReactActivityDelegate createReactActivityDelegate() {
    return new ReactActivityDelegate(this, getMainComponentName()) {
      @Override
      protected ReactRootView createRootView() {
       return new RNGestureHandlerEnabledRootView(MainActivity.this);
      }
    };
  }
}
```

For more detailed installation please see the [React Native Gesture Handler docs](https://kmagiera.github.io/react-native-gesture-handler/docs/getting-started.html).

### add Rebolt Navigation to `bs-dependencies`:

Edit `bs-config.json` file, which is located in the root of your project:

```json
"bs-dependencies": [
  "reason-react",
  "rebolt",
  "rebolt-navigation"
]
```

#### Caveat

As per this [issue](https://github.com/callstackincubator/rebolt-navigation/issues/103), you might need to add the following to your `bsconfig.json`:

```json
"package-specs": {
  "module": "commonjs",
  "in-source": true
}
```

This generates output alongside source files. ([documentation](https://bucklescript.github.io/docs/en/build-configuration.html#package-specs))

## Usage

First we need to create the navigation based on our needs. In `Navigation.re` , we will create our `Config` module and pass it to a `CreateNavigation` functor:

**Navigation.re**:

```re
module Config = {
  type route =
    | Home
    | About
    | Contact;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
```

That's it! Now you are ready to use Rebolt Navigation in your application.

## Rebolt Navigation docs

For more guides and docs please check out [`rebolt-navigation` docs](https://rebolt-navigation.callstack.com/docs).
