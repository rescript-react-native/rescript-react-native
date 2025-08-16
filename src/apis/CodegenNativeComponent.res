type options = {
  interfaceOnly?: bool,
  paperComponentName?: string,
  paperComponentNameDeprecated?: string,
  excludedPlatforms?: array<[#iOS | #android]>,
}

type hostComponent<'props> = React.component<'props>
type nativeComponentType<'props> = hostComponent<'props>

@module("react-native")
external codegenNativeComponent: (string, ~options: options=?) => nativeComponentType<'props> =
  "codegenNativeComponent"

let make = (componentName: string, ~options: option<options>=?, ()): nativeComponentType<'props> => {
  switch options {
  | Some(opts) => codegenNativeComponent(componentName, ~options=opts)
  | None => codegenNativeComponent(componentName)
  }
}

let makeOptions = (
  ~interfaceOnly: option<bool>=?,
  ~paperComponentName: option<string>=?,
  ~paperComponentNameDeprecated: option<string>=?,
  ~excludedPlatforms: option<array<[#iOS | #android]>>=?,
  (),
): options => {
  {
    ?interfaceOnly,
    ?paperComponentName,
    ?paperComponentNameDeprecated,
    ?excludedPlatforms,
  }
}
