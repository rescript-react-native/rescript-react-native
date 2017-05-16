type t;

type emitterSubscription;

let create: NativeModules.t => t;

let addListener: t => string => (Js.Dict.t 'a => unit) => emitterSubscription;

let removeAllListeners: t => string => unit;

let removeSubscription: t => emitterSubscription => unit;

module Subscription: {let remove: emitterSubscription => unit => unit;};
