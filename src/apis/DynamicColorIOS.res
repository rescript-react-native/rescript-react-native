type t = {
  dark: Color.t,
  light: Color.t,
}

@module("react-native") external make: t => Color.t = "DynamicColorIOS"
