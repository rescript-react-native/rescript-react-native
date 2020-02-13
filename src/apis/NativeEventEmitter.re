type t;

type subscription;

[@bs.new] [@bs.module "react-native"]
external make: 'nativeModule => t = "NativeEventEmitter";

[@bs.send]
external addListener: (t, string, 'a => unit) => subscription = "addListener";

[@bs.send]
external removeAllListeners: (t, string) => unit = "removeAllListeners";

[@bs.send]
external removeSubscription: (t, subscription) => unit = "removeSubscription";

module Subscription = {
  [@bs.send] external remove: (subscription, unit) => unit = "remove";
};
