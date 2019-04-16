

import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";
import * as Text$BsReactNative from "./text.bs.js";
import * as View$BsReactNative from "./view.bs.js";
import * as Image$BsReactNative from "./image.bs.js";
import * as FlatList$BsReactNative from "./flatList.bs.js";
import * as AnimatedRe$BsReactNative from "../animatedRe.bs.js";
import * as ScrollView$BsReactNative from "./scrollView.bs.js";

var view = ReactNative.Animated.View;

var View = View$BsReactNative.CreateComponent(/* module */[/* view */view]);

var view$1 = ReactNative.Animated.Image;

var $$Image = Image$BsReactNative.CreateComponent(/* module */[/* view */view$1]);

var view$2 = AnimatedRe$BsReactNative.createAnimatedComponent(ReactNative.FlatList);

var FlatList = FlatList$BsReactNative.CreateComponent(/* module */[/* view */view$2]);

var view$3 = ReactNative.Animated.Text;

var $$Text = Text$BsReactNative.CreateComponent(/* module */[/* view */view$3]);

function onScrollUpdater(x, y, $staropt$star, param) {
  var $$native = $staropt$star !== undefined ? $staropt$star : false;
  return AnimatedRe$BsReactNative.$$event(/* array */[{
                nativeEvent: {
                  contentOffset: {
                    x: Js_undefined.fromOption(x),
                    y: Js_undefined.fromOption(y)
                  }
                }
              }], {
              useNativeDriver: $$native
            });
}

var view$4 = ReactNative.Animated.ScrollView;

var include = ScrollView$BsReactNative.CreateComponent(/* module */[/* view */view$4]);

var ScrollView_001 = /* scrollTo */include[0];

var ScrollView_002 = /* scrollToEnd */include[1];

var ScrollView_003 = /* make */include[2];

var ScrollView = /* module */[
  /* onScrollUpdater */onScrollUpdater,
  ScrollView_001,
  ScrollView_002,
  ScrollView_003
];

export {
  View ,
  $$Image ,
  $$Text ,
  FlatList ,
  ScrollView ,
  
}
/* View Not a pure module */
