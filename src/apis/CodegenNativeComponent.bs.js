'use strict';

var ReactNative = require("react-native");

function make(componentName, options, param) {
  if (options !== undefined) {
    return ReactNative.codegenNativeComponent(componentName, options);
  } else {
    return ReactNative.codegenNativeComponent(componentName);
  }
}

function makeOptions(interfaceOnly, paperComponentName, paperComponentNameDeprecated, excludedPlatforms, param) {
  return {
          interfaceOnly: interfaceOnly,
          paperComponentName: paperComponentName,
          paperComponentNameDeprecated: paperComponentNameDeprecated,
          excludedPlatforms: excludedPlatforms
        };
}

exports.make = make;
exports.makeOptions = makeOptions;
/* react-native Not a pure module */
