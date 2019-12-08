type t = float => float;

[@bs.module "react-native"] [@bs.scope "Easing"]
external back: float => t = "back";
[@bs.module "react-native"] [@bs.scope "Easing"]
external bezier: (float, float, float, float) => t = "bezier";
[@bs.module "react-native"] [@bs.scope "Easing"] external bounce: t = "bounce";
[@bs.module "react-native"] [@bs.scope "Easing"] external circle: t = "circle";
[@bs.module "react-native"] [@bs.scope "Easing"] external cubic: t = "cubic";
[@bs.module "react-native"] [@bs.scope "Easing"] external ease: t = "ease";
[@bs.module "react-native"] [@bs.scope "Easing"]
external elastic: float => t = "elastic";
[@bs.module "react-native"] [@bs.scope "Easing"] external exp: t = "exp";
[@bs.module "react-native"] [@bs.scope "Easing"] external in_: t => t = "in";
[@bs.module "react-native"] [@bs.scope "Easing"]
external inOut: t => t = "inOut";
[@bs.module "react-native"] [@bs.scope "Easing"] external linear: t = "linear";
[@bs.module "react-native"] [@bs.scope "Easing"] external out: t => t = "out";
[@bs.module "react-native"] [@bs.scope "Easing"]
external poly: float => t = "poly";
[@bs.module "react-native"] [@bs.scope "Easing"] external quad: t = "quad";
[@bs.module "react-native"] [@bs.scope "Easing"] external sin: t = "sin";
[@bs.module "react-native"] [@bs.scope "Easing"]
external step0: float => int = "step0";
[@bs.module "react-native"] [@bs.scope "Easing"]
external step1: float => int = "step1";
