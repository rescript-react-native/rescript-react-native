

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

function make(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, autoCapitalize, autoComplete, autoCorrect, autoFocus, blurOnSubmit, caretHidden, defaultValue, editable, keyboardType, maxLength, multiline, onBlur, onChangeText, onChange, onEndEditing, onSubmitEditing, onContentSizeChange, onFocus, onScroll, onSelectionChange, placeholder, placeholderTextColor, returnKeyType, secureTextEntry, selectTextOnFocus, selection, selectionColor, value, disableFullscreenUI, inlineImageLeft, inlineImagePadding, numberOfLines, returnKeyLabel, textBreakStrategy, underlineColorAndroid, clearButtonMode, clearTextOnFocus, dataDetectorTypes, enablesReturnKeyAutomatically, keyboardAppearance, onKeyPress, selectionState, spellCheck, inputAccessoryViewID) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        autoCapitalize: Belt_Option.map(autoCapitalize, (function (param) {
                if (param >= -707897174) {
                  if (param >= 57776752) {
                    return "sentences";
                  } else {
                    return "characters";
                  }
                } else if (param >= -832270487) {
                  return "words";
                } else {
                  return "none";
                }
              })),
        autoComplete: Belt_Option.map(autoComplete, (function (param) {
                if (param >= -283518991) {
                  if (param >= 5791195) {
                    if (param >= 435943994) {
                      if (param >= 552306198) {
                        return "username";
                      } else {
                        return "cc-exp-year";
                      }
                    } else if (param >= 157157769) {
                      return "cc-number";
                    } else {
                      return "tel";
                    }
                  } else if (param !== -271659236) {
                    if (param >= 5542767) {
                      return "off";
                    } else {
                      return "street-address";
                    }
                  } else {
                    return "email";
                  }
                } else if (param >= -1034923555) {
                  if (param >= -925883621) {
                    if (param >= -922783157) {
                      return "name";
                    } else {
                      return "password";
                    }
                  } else if (param >= -987328488) {
                    return "postal-code";
                  } else {
                    return "cc-exp";
                  }
                } else if (param >= -1035024141) {
                  return "cc-csc";
                } else {
                  return "cc-exp-month";
                }
              })),
        autoCorrect: autoCorrect,
        autoFocus: autoFocus,
        blurOnSubmit: blurOnSubmit,
        caretHidden: caretHidden,
        defaultValue: defaultValue,
        editable: editable,
        keyboardType: Belt_Option.map(keyboardType, (function (param) {
                if (param >= 511059466) {
                  if (param >= 734061261) {
                    if (param >= 965330242) {
                      if (param >= 1008346616) {
                        return "email-address";
                      } else {
                        return "decimal-pad";
                      }
                    } else if (param >= 776586867) {
                      return "twitter";
                    } else {
                      return "numeric";
                    }
                  } else if (param >= 568483612) {
                    return "web-search";
                  } else {
                    return "number-pad";
                  }
                } else if (param >= -324562960) {
                  if (param >= 217673051) {
                    if (param >= 465819841) {
                      return "default";
                    } else {
                      return "ascii-capable";
                    }
                  } else if (param >= 5843823) {
                    return "url";
                  } else {
                    return "name-phone-pad";
                  }
                } else if (param >= -444948859) {
                  return "phone-pad";
                } else {
                  return "numbers-and-punctuation";
                }
              })),
        maxLength: maxLength,
        multiline: multiline,
        onBlur: onBlur,
        onChangeText: onChangeText,
        onChange: onChange,
        onEndEditing: onEndEditing,
        onSubmitEditing: onSubmitEditing,
        onContentSizeChange: onContentSizeChange,
        onFocus: onFocus,
        onScroll: onScroll,
        onSelectionChange: onSelectionChange,
        placeholder: placeholder,
        placeholderTextColor: placeholderTextColor,
        returnKeyType: Belt_Option.map(returnKeyType, (function (param) {
                if (param >= -487088280) {
                  if (param >= 23080) {
                    if (param >= 598785079) {
                      if (param >= 939679119) {
                        return "emergencyCall";
                      } else {
                        return "previous";
                      }
                    } else if (param >= 465819841) {
                      return "default";
                    } else {
                      return "go";
                    }
                  } else if (param !== -337039680) {
                    if (param >= -312083063) {
                      return "route";
                    } else {
                      return "search";
                    }
                  } else {
                    return "yahoo";
                  }
                } else if (param >= -922086728) {
                  if (param >= -574324323) {
                    if (param >= -504773703) {
                      return "google";
                    } else {
                      return "done";
                    }
                  } else if (param >= -867136184) {
                    return "send";
                  } else {
                    return "none";
                  }
                } else if (param >= -922581773) {
                  return "next";
                } else {
                  return "join";
                }
              })),
        secureTextEntry: secureTextEntry,
        selectTextOnFocus: selectTextOnFocus,
        selection: selection,
        selectionColor: selectionColor,
        value: value,
        disableFullscreenUI: disableFullscreenUI,
        inlineImageLeft: inlineImageLeft,
        inlineImagePadding: inlineImagePadding,
        numberOfLines: numberOfLines,
        returnKeyLabel: returnKeyLabel,
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
        underlineColorAndroid: underlineColorAndroid,
        clearButtonMode: Belt_Option.map(clearButtonMode, (function (param) {
                if (param >= -894774937) {
                  if (param >= 422592140) {
                    return "never";
                  } else {
                    return "while-editing";
                  }
                } else if (param >= -958984497) {
                  return "always";
                } else {
                  return "unless-editing";
                }
              })),
        clearTextOnFocus: clearTextOnFocus,
        dataDetectorTypes: Belt_Option.map(dataDetectorTypes, (function (param) {
                return $$Array.map((function (param) {
                              if (param !== -940571433) {
                                if (param >= -119363460) {
                                  if (param >= 4847905) {
                                    return "all";
                                  } else {
                                    return "calendarEvent";
                                  }
                                } else if (param >= -922086728) {
                                  return "none";
                                } else {
                                  return "link";
                                }
                              } else {
                                return "phoneNumber";
                              }
                            }), param);
              })),
        enablesReturnKeyAutomatically: enablesReturnKeyAutomatically,
        keyboardAppearance: Belt_Option.map(keyboardAppearance, (function (param) {
                if (param !== -184774442) {
                  if (param >= 465819841) {
                    return "never";
                  } else {
                    return "dark";
                  }
                } else {
                  return "light";
                }
              })),
        onKeyPress: onKeyPress,
        selectionState: selectionState,
        spellCheck: spellCheck,
        inputAccessoryViewID: inputAccessoryViewID
      });
  var partial_arg$1 = ReactNative.TextInput;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

function isFocused(prim) {
  return prim.isFocused();
}

function clear(prim) {
  prim.clear();
  return /* () */0;
}

function focus(prim) {
  prim.focus();
  return /* () */0;
}

function blur(prim) {
  prim.blur();
  return /* () */0;
}

export {
  make ,
  isFocused ,
  clear ,
  focus ,
  blur ,
  
}
/* ReasonReact Not a pure module */
