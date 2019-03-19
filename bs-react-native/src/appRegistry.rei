/**
This API only works in projects made with react-native init or in those made with Create React Native App which have since ejected

[AppRegistry] is the JS entry point to running all React Native apps. App root components should register themselves with [AppRegistry.registerComponent], then the native system can load the bundle for the app and then actually run the app when it's ready by invoking [AppRegistry.runApplication].

You can read more on [AppRegistry] API usage in official docs: {{:https://facebook.github.io/react-native/docs/appregistry}}

*/
let registerComponent: (string, unit => ReasonReact.reactClass) => unit;
