type t = float => float

@module("react-native") @scope("Easing")
external back: float => t = "back"
@module("react-native") @scope("Easing")
external bezier: (float, float, float, float) => t = "bezier"
@module("react-native") @scope("Easing") external bounce: t = "bounce"
@module("react-native") @scope("Easing") external circle: t = "circle"
@module("react-native") @scope("Easing") external cubic: t = "cubic"
@module("react-native") @scope("Easing") external ease: t = "ease"
@module("react-native") @scope("Easing")
external elastic: float => t = "elastic"
@module("react-native") @scope("Easing") external exp: t = "exp"
@module("react-native") @scope("Easing") external in_: t => t = "in"
@module("react-native") @scope("Easing")
external inOut: t => t = "inOut"
@module("react-native") @scope("Easing") external linear: t = "linear"
@module("react-native") @scope("Easing") external out: t => t = "out"
@module("react-native") @scope("Easing")
external poly: float => t = "poly"
@module("react-native") @scope("Easing") external quad: t = "quad"
@module("react-native") @scope("Easing") external sin: t = "sin"
@module("react-native") @scope("Easing")
external step0: float => int = "step0"
@module("react-native") @scope("Easing")
external step1: float => int = "step1"
