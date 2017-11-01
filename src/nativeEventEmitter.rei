type t;

type emitterSubscription;

let create: NativeModules.t('a) => t;

let addListener: (t, string, 'a => unit) => emitterSubscription;

let removeAllListeners: (t, string) => unit;

let removeSubscription: (t, emitterSubscription) => unit;

module Subscription: {let remove: (emitterSubscription, unit) => unit;};
