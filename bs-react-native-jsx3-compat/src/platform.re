type iosIdiom =
  | Phone
  | Pad
  | TV;

[@bs.module "react-native"] [@bs.scope "Platform"]
external _ios_isPad: bool = "isPad";

[@bs.module "react-native"] [@bs.scope "Platform"]
external _ios_isTVOS: bool = "isTVOS";

type os =
  | IOS(iosIdiom)
  | Android;

[@bs.module "react-native"] [@bs.scope "Platform"] external _os: string = "OS";

exception UnknownPlatform(string);

let os = () =>
  switch (_os) {
  | "ios" =>
    switch (_ios_isPad) {
    | true => IOS(Pad)
    | _ =>
      switch (_ios_isTVOS) {
      | true => IOS(TV)
      | _ => IOS(Phone)
      }
    }
  | "android" => Android
  | x => raise(UnknownPlatform(x))
  };

let equals = targetOs =>
  switch (os(), targetOs) {
  | (IOS(_), IOS(_)) => true
  | (Android, Android) => true
  | (Android, IOS(_)) => false
  | (IOS(_), Android) => false
  | exception (UnknownPlatform(_)) => false
  };

[@bs.module "react-native"] [@bs.scope "Platform"]
external _version: Js.undefined(int) = "Version";

exception UnknownVersion;

let version = () =>
  switch (Js.Undefined.toOption(_version)) {
  | Some(v) => v
  | None => raise(UnknownVersion)
  };

type selectOptions('a) = {
  ios: 'a,
  android: 'a,
};

[@bs.deriving abstract]
type _selectOptions('a) = {
  ios: 'a,
  android: 'a,
};
[@bs.module "react-native"] [@bs.scope "Platform"]
external _select: _selectOptions('a) => 'a = "select";

let select: selectOptions('a) => 'a =
  options => {
    let _options = _selectOptions(~android=options.android, ~ios=options.ios);
    _select(_options);
  };
