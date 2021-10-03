type t = {
  dark: Color.t,
  light: Color.t,
  highContrastLight: option<Color.t>,
  highContrastDark: option<Color.t>,
}

@obj
external dynamicColor: (
  ~dark: Color.t,
  ~light: Color.t,
  ~highContrastLight: option<Color.t>=?,
  ~highContrastDark: option<Color.t>=?,
  unit,
) => t = ""

@module("react-native") external make: t => Color.t = "DynamicColorIOS"
