type t = {
  dark: Color.t,
  light: Color.t,
  highContrastLight?: Color.t,
  highContrastDark?: Color.t,
}

@deprecated("Directly create record instead") @obj
external dynamicColor: (
  ~dark: Color.t,
  ~light: Color.t,
  ~highContrastLight: option<Color.t>=?,
  ~highContrastDark: option<Color.t>=?,
  unit,
) => t = ""

@module("react-native") external make: t => Color.t = "DynamicColorIOS"
