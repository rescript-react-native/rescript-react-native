type iosIdiom =
  | Phone
  | Pad
  | TV;

type os =
  | IOS(iosIdiom)
  | Android;

exception UnknownPlatform(string);

/**
 Raises UnknownPlatform for non-standard platforms such as "web"
 from react-native-web
 */
let os: unit => os;

let equals: os => bool;

exception UnknownVersion;

/**
 Raises UnknownVersion if version is undefined, i.e. in react-native-web
 */
let version: unit => int;