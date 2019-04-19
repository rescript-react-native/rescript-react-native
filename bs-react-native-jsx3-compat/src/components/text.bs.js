

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";

function CreateComponent(Impl) {
  var make = function (accessible, accessibilityHint, accessibilityLabel, allowFontScaling, ellipsizeMode, numberOfLines, onLayout, onLongPress, onPress, pressRetentionOffset, selectable, style, testID, selectionColor, textBreakStrategy, adjustsFontSizeToFit, minimumFontScale, suppressHighlighting, value, children) {
    return ReasonReact.wrapJsForReason(Impl[/* view */0], {
                accessible: accessible,
                accessibilityHint: accessibilityHint,
                accessibilityLabel: accessibilityLabel,
                allowFontScaling: allowFontScaling,
                ellipsizeMode: Belt_Option.map(ellipsizeMode, (function (param) {
                        if (param >= -866200747) {
                          if (param >= -856246640) {
                            return "tail";
                          } else {
                            return "middle";
                          }
                        } else if (param >= -989124320) {
                          return "head";
                        } else {
                          return "clip";
                        }
                      })),
                numberOfLines: numberOfLines,
                onLayout: onLayout,
                onLongPress: onLongPress,
                onPress: onPress,
                pressRetentionOffset: pressRetentionOffset,
                selectable: selectable,
                style: style,
                testID: testID,
                selectionColor: selectionColor,
                textBreakStrategy: Belt_Option.map(textBreakStrategy, (function (param) {
                        if (param !== -128197688) {
                          if (param >= 947848242) {
                            return "simple";
                          } else {
                            return "highQuality";
                          }
                        } else {
                          return "balanced";
                        }
                      })),
                adjustsFontSizeToFit: adjustsFontSizeToFit,
                minimumFontScale: minimumFontScale,
                suppressHighlighting: suppressHighlighting
              }, value !== undefined ? $$Array.append(/* array */[value], children) : children);
  };
  return /* module */[/* make */make];
}

var Impl = /* module */[/* Text */ReactNative.Text];

function make(accessible, accessibilityHint, accessibilityLabel, allowFontScaling, ellipsizeMode, numberOfLines, onLayout, onLongPress, onPress, pressRetentionOffset, selectable, style, testID, selectionColor, textBreakStrategy, adjustsFontSizeToFit, minimumFontScale, suppressHighlighting, value, children) {
  return ReasonReact.wrapJsForReason(Impl[/* view */0], {
              accessible: accessible,
              accessibilityHint: accessibilityHint,
              accessibilityLabel: accessibilityLabel,
              allowFontScaling: allowFontScaling,
              ellipsizeMode: Belt_Option.map(ellipsizeMode, (function (param) {
                      if (param >= -866200747) {
                        if (param >= -856246640) {
                          return "tail";
                        } else {
                          return "middle";
                        }
                      } else if (param >= -989124320) {
                        return "head";
                      } else {
                        return "clip";
                      }
                    })),
              numberOfLines: numberOfLines,
              onLayout: onLayout,
              onLongPress: onLongPress,
              onPress: onPress,
              pressRetentionOffset: pressRetentionOffset,
              selectable: selectable,
              style: style,
              testID: testID,
              selectionColor: selectionColor,
              textBreakStrategy: Belt_Option.map(textBreakStrategy, (function (param) {
                      if (param !== -128197688) {
                        if (param >= 947848242) {
                          return "simple";
                        } else {
                          return "highQuality";
                        }
                      } else {
                        return "balanced";
                      }
                    })),
              adjustsFontSizeToFit: adjustsFontSizeToFit,
              minimumFontScale: minimumFontScale,
              suppressHighlighting: suppressHighlighting
            }, value !== undefined ? $$Array.append(/* array */[value], children) : children);
}

export {
  CreateComponent ,
  make ,
  
}
/* Impl Not a pure module */
