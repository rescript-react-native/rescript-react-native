type options = {
  interfaceOnly?: bool,
  paperComponentName?: string,
  paperComponentNameDeprecated?: string,
  excludedPlatforms?: array<[#iOS | #android]>,
}

@module("react-native")
external codegenNativeComponent: (string, options) => React.component<'props> =
  "codegenNativeComponent"
