type t;

type emitterSubscription;

[@bs.new] [@bs.module "react-native"]
external create: NativeModules.t('a) => t = "NativeEventEmitter";

[@bs.send]
external addListener: (t, string, 'a => unit) => emitterSubscription = "";

[@bs.send] external removeAllListeners: (t, string) => unit = "";

[@bs.send] external removeSubscription: (t, emitterSubscription) => unit = "";

module Subscription = {
  [@bs.send] external remove: (emitterSubscription, unit) => unit = "";
};
