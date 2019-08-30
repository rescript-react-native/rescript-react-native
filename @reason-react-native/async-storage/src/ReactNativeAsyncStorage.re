[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external getItem: string => Js.Promise.t(Js.Null.t(string)) = "getItem";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external setItem: (string, string) => Js.Promise.t(unit) = "setItem";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external removeItem: string => Js.Promise.t(unit) = "removeItem";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external mergeItem: (string, string) => Js.Promise.t(unit) = "mergeItem";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external clear: unit => Js.Promise.t(unit) = "clear";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external getAllKeys: unit => Js.Promise.t(Js.Null.t(array(string))) =
  "getAllKeys";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external multiGet:
  array(string) => Js.Promise.t(array((string, Js.Null.t(string)))) =
  "multiGet";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external multiSet: array((string, string)) => Js.Promise.t(unit) =
  "multiSet";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external multiMerge: array((string, string)) => Js.Promise.t(unit) =
  "multiMerge";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external multiRemove: array(string) => Js.Promise.t(unit) = "multiRemove";

[@bs.scope "default"] [@bs.module "@react-native-community/async-storage"]
external flushGetRequests: unit => unit = "flushGetRequests";
