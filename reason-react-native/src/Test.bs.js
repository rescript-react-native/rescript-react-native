'use strict';

var React = require("react");
var ReactNative = require("react-native");

var textInputRef = React.useRef(null);

var clearText = React.useCallback((function (param) {
        var match = textInputRef.current;
        if (match == null) {
          return /* () */0;
        } else {
          match.setNativeProps({
                test: 42
              });
          match.focus();
          return /* () */0;
        }
      }));

var make = React.createElement(ReactNative.View, {
      children: null
    }, React.createElement(ReactNative.TextInput, {
          ref: textInputRef
        }), React.createElement(ReactNative.TouchableOpacity, {
          onPress: clearText,
          children: React.createElement(ReactNative.Text, {
                children: "Clear text"
              })
        }));

exports.make = make;
/* textInputRef Not a pure module */
