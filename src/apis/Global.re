[@bs.val] external __DEV__: bool = "__DEV__";

[@bs.scope "global"] [@bs.val]
external hermesInternal: option(Js.t('a)) = "hermesInternal";

[@bs.module "react-native"]
external unstable_enableLogBox: unit => unit = "unstable_enableLogBox";
