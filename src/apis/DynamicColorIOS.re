type t = {
  dark: Color.t,
  light: Color.t,
};

[@bs.module "react-native"] external make: t => Color.t = "DynamicColorIOS";
