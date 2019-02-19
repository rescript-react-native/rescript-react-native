/**
React Native provides a module that detects the platform in which the app is running. You can use the detection logic to implement platform-specific code. Use this option when only small parts of a component are platform-specific.

You can read more on [Platform] API usage in official docs: {{:https://facebook.github.io/react-native/docs/platform-specific-code}}

{3 Example of use }
{[
  marginTop(Pt(Platform.os() == Platform.Android ? 20.0 : 0.0))
]}

*/

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

type selectOptions('a) = {
  ios: 'a,
  android: 'a,
};

let select: selectOptions('a) => 'a;
