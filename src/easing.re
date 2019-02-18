type t = float => float;
[@bs.module "react-native"] [@bs.scope "Easing"] external bounce: t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external circle: t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external cubic: t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external ease: t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external exp: t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external linear: t = "";
[@bs.module "react-native"] [@bs.scope "Easing"]
external poly: float => t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external quad: t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external sin: t = "";
[@bs.module "react-native"] [@bs.scope "Easing"]
external step0: float => int = "";
[@bs.module "react-native"] [@bs.scope "Easing"]
external step1: float => int = "";
[@bs.module "react-native"] [@bs.scope "Easing"]
external back: float => t = "";
[@bs.module "react-native"] [@bs.scope "Easing"]
external elastic: float => t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external in_: t => t = "in";
[@bs.module "react-native"] [@bs.scope "Easing"] external inOut: t => t = "";
[@bs.module "react-native"] [@bs.scope "Easing"] external out: t => t = "";
[@bs.module "react-native"] [@bs.scope "Easing"]
external bezier: (float, float, float, float) => t = "";
