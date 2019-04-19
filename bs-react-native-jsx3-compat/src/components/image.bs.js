

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";

function CreateComponent(Impl) {
  var encode_pt_only = function (value) {
    return value[0];
  };
  var imageURISource = function (uri, bundle, method_, headers, body, cache, scale, width, height, unit) {
    var tmp = {
      uri: uri,
      width: Belt_Option.map(width, encode_pt_only),
      height: Belt_Option.map(height, encode_pt_only)
    };
    if (bundle !== undefined) {
      tmp.bundle = Caml_option.valFromOption(bundle);
    }
    if (method_ !== undefined) {
      tmp.method = Caml_option.valFromOption(method_);
    }
    if (headers !== undefined) {
      tmp.headers = Caml_option.valFromOption(headers);
    }
    if (body !== undefined) {
      tmp.body = Caml_option.valFromOption(body);
    }
    if (cache !== undefined) {
      tmp.cache = (function () {
            switch (Caml_option.valFromOption(cache)) {
              case 465819841 : 
                  return "default";
              case 64967513 : 
                  return "reload";
              case -672562089 : 
                  return "force-cache";
              case -74546901 : 
                  return "only-if-cached";
              
            }
          })();
    }
    if (scale !== undefined) {
      tmp.scale = Caml_option.valFromOption(scale);
    }
    return tmp;
  };
  var defaultURISource = function (uri, scale, width, height, unit) {
    var tmp = {
      uri: uri,
      width: Belt_Option.map(width, encode_pt_only),
      height: Belt_Option.map(height, encode_pt_only)
    };
    if (scale !== undefined) {
      tmp.scale = Caml_option.valFromOption(scale);
    }
    return tmp;
  };
  var $$Event = /* module */[];
  var encodeResizeMode = function (param) {
    if (param !== -162316795) {
      if (param >= 108828507) {
        if (param >= 427065300) {
          return "contain";
        } else {
          return "repeat";
        }
      } else if (param >= 98248149) {
        return "center";
      } else {
        return "cover";
      }
    } else {
      return "stretch";
    }
  };
  var encodeSource = function (x) {
    if (x[0] >= 4245324) {
      return x[1];
    } else {
      return $$Array.of_list(x[1]);
    }
  };
  var encodeResizeMethod = function (param) {
    if (param !== -120664438) {
      if (param >= 142301684) {
        return "resize";
      } else {
        return "auto";
      }
    } else {
      return "scale";
    }
  };
  var encodeDefaultSource = function (x) {
    return x[1];
  };
  var make = function (onError, onLayout, onLoad, onLoadEnd, onLoadStart, resizeMode, source, style, testID, resizeMethod, accessibilityLabel, accessible, blurRadius, capInsets, defaultSource, onPartialLoad, onProgress) {
    var partial_arg = {
      onLayout: onLayout,
      onError: onError,
      onLoad: onLoad,
      onLoadEnd: onLoadEnd,
      onLoadStart: onLoadStart,
      resizeMode: Belt_Option.map(resizeMode, encodeResizeMode),
      source: encodeSource(source),
      style: style,
      testID: testID,
      resizeMethod: Belt_Option.map(resizeMethod, encodeResizeMethod),
      accessibilityLabel: accessibilityLabel,
      accessible: accessible,
      blurRadius: blurRadius,
      capInsets: capInsets,
      defaultSource: Belt_Option.map(defaultSource, encodeDefaultSource),
      onPartialLoad: onPartialLoad,
      onProgress: Belt_Option.map(onProgress, (function (x, y) {
              return Curry._1(x, y.nativeEvent);
            }))
    };
    var partial_arg$1 = Impl[/* view */0];
    return (function (param) {
        return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
      });
  };
  return /* module */[
          (function (prim, prim$1, prim$2, prim$3, prim$4, prim$5, prim$6, prim$7, prim$8, prim$9) {
              var tmp = {
                uri: prim
              };
              if (prim$1 !== undefined) {
                tmp.bundle = Caml_option.valFromOption(prim$1);
              }
              if (prim$2 !== undefined) {
                tmp.method = Caml_option.valFromOption(prim$2);
              }
              if (prim$3 !== undefined) {
                tmp.headers = Caml_option.valFromOption(prim$3);
              }
              if (prim$4 !== undefined) {
                tmp.body = Caml_option.valFromOption(prim$4);
              }
              if (prim$5 !== undefined) {
                tmp.cache = (function () {
                      switch (Caml_option.valFromOption(prim$5)) {
                        case 465819841 : 
                            return "default";
                        case 64967513 : 
                            return "reload";
                        case -672562089 : 
                            return "force-cache";
                        case -74546901 : 
                            return "only-if-cached";
                        
                      }
                    })();
              }
              if (prim$6 !== undefined) {
                tmp.scale = Caml_option.valFromOption(prim$6);
              }
              if (prim$7 !== undefined) {
                tmp.width = Caml_option.valFromOption(prim$7);
              }
              if (prim$8 !== undefined) {
                tmp.height = Caml_option.valFromOption(prim$8);
              }
              return tmp;
            }),
          /* imageURISource */imageURISource,
          (function (prim, prim$1, prim$2, prim$3, prim$4) {
              var tmp = {
                uri: prim
              };
              if (prim$1 !== undefined) {
                tmp.scale = Caml_option.valFromOption(prim$1);
              }
              if (prim$2 !== undefined) {
                tmp.width = Caml_option.valFromOption(prim$2);
              }
              if (prim$3 !== undefined) {
                tmp.height = Caml_option.valFromOption(prim$3);
              }
              return tmp;
            }),
          /* defaultURISource */defaultURISource,
          /* Event */$$Event,
          /* make */make,
          (function (prim) {
              return ReactNative.Image.resolveAssetSource(prim);
            })
        ];
}

var Impl = /* module */[/* Image */ReactNative.Image];

function encode_pt_only(value) {
  return value[0];
}

function imageURISource(uri, bundle, method_, headers, body, cache, scale, width, height, unit) {
  var tmp = {
    uri: uri,
    width: Belt_Option.map(width, encode_pt_only),
    height: Belt_Option.map(height, encode_pt_only)
  };
  if (bundle !== undefined) {
    tmp.bundle = Caml_option.valFromOption(bundle);
  }
  if (method_ !== undefined) {
    tmp.method = Caml_option.valFromOption(method_);
  }
  if (headers !== undefined) {
    tmp.headers = Caml_option.valFromOption(headers);
  }
  if (body !== undefined) {
    tmp.body = Caml_option.valFromOption(body);
  }
  if (cache !== undefined) {
    tmp.cache = (function () {
          switch (Caml_option.valFromOption(cache)) {
            case 465819841 : 
                return "default";
            case 64967513 : 
                return "reload";
            case -672562089 : 
                return "force-cache";
            case -74546901 : 
                return "only-if-cached";
            
          }
        })();
  }
  if (scale !== undefined) {
    tmp.scale = Caml_option.valFromOption(scale);
  }
  return tmp;
}

function defaultURISource(uri, scale, width, height, unit) {
  var tmp = {
    uri: uri,
    width: Belt_Option.map(width, encode_pt_only),
    height: Belt_Option.map(height, encode_pt_only)
  };
  if (scale !== undefined) {
    tmp.scale = Caml_option.valFromOption(scale);
  }
  return tmp;
}

var $$Event = /* module */[];

function encodeResizeMode(param) {
  if (param !== -162316795) {
    if (param >= 108828507) {
      if (param >= 427065300) {
        return "contain";
      } else {
        return "repeat";
      }
    } else if (param >= 98248149) {
      return "center";
    } else {
      return "cover";
    }
  } else {
    return "stretch";
  }
}

function encodeSource(x) {
  if (x[0] >= 4245324) {
    return x[1];
  } else {
    return $$Array.of_list(x[1]);
  }
}

function encodeResizeMethod(param) {
  if (param !== -120664438) {
    if (param >= 142301684) {
      return "resize";
    } else {
      return "auto";
    }
  } else {
    return "scale";
  }
}

function encodeDefaultSource(x) {
  return x[1];
}

function make(onError, onLayout, onLoad, onLoadEnd, onLoadStart, resizeMode, source, style, testID, resizeMethod, accessibilityLabel, accessible, blurRadius, capInsets, defaultSource, onPartialLoad, onProgress) {
  var partial_arg = {
    onLayout: onLayout,
    onError: onError,
    onLoad: onLoad,
    onLoadEnd: onLoadEnd,
    onLoadStart: onLoadStart,
    resizeMode: Belt_Option.map(resizeMode, encodeResizeMode),
    source: encodeSource(source),
    style: style,
    testID: testID,
    resizeMethod: Belt_Option.map(resizeMethod, encodeResizeMethod),
    accessibilityLabel: accessibilityLabel,
    accessible: accessible,
    blurRadius: blurRadius,
    capInsets: capInsets,
    defaultSource: Belt_Option.map(defaultSource, encodeDefaultSource),
    onPartialLoad: onPartialLoad,
    onProgress: Belt_Option.map(onProgress, (function (x, y) {
            return Curry._1(x, y.nativeEvent);
          }))
  };
  var partial_arg$1 = Impl[/* view */0];
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

function _imageURISource(prim, prim$1, prim$2, prim$3, prim$4, prim$5, prim$6, prim$7, prim$8, prim$9) {
  var tmp = {
    uri: prim
  };
  if (prim$1 !== undefined) {
    tmp.bundle = Caml_option.valFromOption(prim$1);
  }
  if (prim$2 !== undefined) {
    tmp.method = Caml_option.valFromOption(prim$2);
  }
  if (prim$3 !== undefined) {
    tmp.headers = Caml_option.valFromOption(prim$3);
  }
  if (prim$4 !== undefined) {
    tmp.body = Caml_option.valFromOption(prim$4);
  }
  if (prim$5 !== undefined) {
    tmp.cache = (function () {
          switch (Caml_option.valFromOption(prim$5)) {
            case 465819841 : 
                return "default";
            case 64967513 : 
                return "reload";
            case -672562089 : 
                return "force-cache";
            case -74546901 : 
                return "only-if-cached";
            
          }
        })();
  }
  if (prim$6 !== undefined) {
    tmp.scale = Caml_option.valFromOption(prim$6);
  }
  if (prim$7 !== undefined) {
    tmp.width = Caml_option.valFromOption(prim$7);
  }
  if (prim$8 !== undefined) {
    tmp.height = Caml_option.valFromOption(prim$8);
  }
  return tmp;
}

function _defaultURISource(prim, prim$1, prim$2, prim$3, prim$4) {
  var tmp = {
    uri: prim
  };
  if (prim$1 !== undefined) {
    tmp.scale = Caml_option.valFromOption(prim$1);
  }
  if (prim$2 !== undefined) {
    tmp.width = Caml_option.valFromOption(prim$2);
  }
  if (prim$3 !== undefined) {
    tmp.height = Caml_option.valFromOption(prim$3);
  }
  return tmp;
}

function resolveAssetSource(prim) {
  return ReactNative.Image.resolveAssetSource(prim);
}

export {
  CreateComponent ,
  _imageURISource ,
  imageURISource ,
  _defaultURISource ,
  defaultURISource ,
  $$Event ,
  make ,
  resolveAssetSource ,
  
}
/* Impl Not a pure module */
