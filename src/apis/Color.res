type t = string

let rgb = (~r: int, ~g: int, ~b: int) => j`rgb($r, $g, $b)`
let rgba = (~r: int, ~g: int, ~b: int, ~a: float) => j`rgba($r, $g, $b, $a)`

let hsl = (~h: float, ~s: float, ~l: float) => j`hsl($h, $s%, $l%)`
let hsla = (~h: float, ~s: float, ~l: float, ~a: float) => j`hsl($h, $s%, $l%, $a)`

@inline
let transparent = "transparent"

// Pre-defined colors
@inline
let aliceblue = "aliceblue"

@inline
let antiquewhite = "antiquewhite"

@inline
let aqua = "aqua"

@inline
let aquamarine = "aquamarine"

@inline
let azure = "azure"

@inline
let beige = "beige"

@inline
let bisque = "bisque"

@inline
let black = "black"

@inline
let blanchedalmond = "blanchedalmond"

@inline
let blue = "blue"

@inline
let blueviolet = "blueviolet"

@inline
let brown = "brown"

@inline
let burlywood = "burlywood"

@inline
let cadetblue = "cadetblue"

@inline
let chartreuse = "chartreuse"

@inline
let chocolate = "chocolate"

@inline
let coral = "coral"

@inline
let cornflowerblue = "cornflowerblue"

@inline
let cornsilk = "cornsilk"

@inline
let crimson = "crimson"

@inline
let cyan = "cyan"

@inline
let darkblue = "darkblue"

@inline
let darkcyan = "darkcyan"

@inline
let darkgoldenrod = "darkgoldenrod"

@inline
let darkgray = "darkgray"

@inline
let darkgreen = "darkgreen"

@inline
let darkgrey = "darkgrey"

@inline
let darkkhaki = "darkkhaki"

@inline
let darkmagenta = "darkmagenta"

@inline
let darkolivegreen = "darkolivegreen"

@inline
let darkorange = "darkorange"

@inline
let darkorchid = "darkorchid"

@inline
let darkred = "darkred"

@inline
let darksalmon = "darksalmon"

@inline
let darkseagreen = "darkseagreen"

@inline
let darkslateblue = "darkslateblue"

@inline
let darkslategrey = "darkslategrey"

@inline
let darkturquoise = "darkturquoise"

@inline
let darkviolet = "darkviolet"

@inline
let deeppink = "deeppink"

@inline
let deepskyblue = "deepskyblue"

@inline
let dimgray = "dimgray"

@inline
let dimgrey = "dimgrey"

@inline
let dodgerblue = "dodgerblue"

@inline
let firebrick = "firebrick"

@inline
let floralwhite = "floralwhite"

@inline
let forestgreen = "forestgreen"

@inline
let fuchsia = "fuchsia"

@inline
let gainsboro = "gainsboro"

@inline
let ghostwhite = "ghostwhite"

@inline
let gold = "gold"

@inline
let goldenrod = "goldenrod"

@inline
let gray = "gray"

@inline
let green = "green"

@inline
let greenyellow = "greenyellow"

@inline
let grey = "grey"

@inline
let honeydew = "honeydew"

@inline
let hotpink = "hotpink"

@inline
let indianred = "indianred"

@inline
let indigo = "indigo"

@inline
let ivory = "ivory"

@inline
let khaki = "khaki"

@inline
let lavender = "lavender"

@inline
let lavenderblush = "lavenderblush"

@inline
let lawngreen = "lawngreen"

@inline
let lemonchiffon = "lemonchiffon"

@inline
let lightblue = "lightblue"

@inline
let lightcoral = "lightcoral"

@inline
let lightcyan = "lightcyan"

@inline
let lightgoldenrodyellow = "lightgoldenrodyellow"

@inline
let lightgray = "lightgray"

@inline
let lightgreen = "lightgreen"

@inline
let lightgrey = "lightgrey"

@inline
let lightpink = "lightpink"

@inline
let lightsalmon = "lightsalmon"

@inline
let lightseagreen = "lightseagreen"

@inline
let lightskyblue = "lightskyblue"

@inline
let lightslategrey = "lightslategrey"

@inline
let lightsteelblue = "lightsteelblue"

@inline
let lightyellow = "lightyellow"

@inline
let lime = "lime"

@inline
let limegreen = "limegreen"

@inline
let linen = "linen"

@inline
let magenta = "magenta"

@inline
let maroon = "maroon"

@inline
let mediumaquamarine = "mediumaquamarine"

@inline
let mediumblue = "mediumblue"

@inline
let mediumorchid = "mediumorchid"

@inline
let mediumpurple = "mediumpurple"

@inline
let mediumseagreen = "mediumseagreen"

@inline
let mediumslateblue = "mediumslateblue"

@inline
let mediumspringgreen = "mediumspringgreen"

@inline
let mediumturquoise = "mediumturquoise"

@inline
let mediumvioletred = "mediumvioletred"

@inline
let midnightblue = "midnightblue"

@inline
let mintcream = "mintcream"

@inline
let mistyrose = "mistyrose"

@inline
let moccasin = "moccasin"

@inline
let navajowhite = "navajowhite"

@inline
let navy = "navy"

@inline
let oldlace = "oldlace"

@inline
let olive = "olive"

@inline
let olivedrab = "olivedrab"

@inline
let orange = "orange"

@inline
let orangered = "orangered"

@inline
let orchid = "orchid"

@inline
let palegoldenrod = "palegoldenrod"

@inline
let palegreen = "palegreen"

@inline
let paleturquoise = "paleturquoise"

@inline
let palevioletred = "palevioletred"

@inline
let papayawhip = "papayawhip"

@inline
let peachpuff = "peachpuff"

@inline
let peru = "peru"

@inline
let pink = "pink"

@inline
let plum = "plum"

@inline
let powderblue = "powderblue"

@inline
let purple = "purple"

@inline
let rebeccapurple = "rebeccapurple"

@inline
let red = "red"

@inline
let rosybrown = "rosybrown"

@inline
let royalblue = "royalblue"

@inline
let saddlebrown = "saddlebrown"

@inline
let salmon = "salmon"

@inline
let sandybrown = "sandybrown"

@inline
let seagreen = "seagreen"

@inline
let seashell = "seashell"

@inline
let sienna = "sienna"

@inline
let silver = "silver"

@inline
let skyblue = "skyblue"

@inline
let slateblue = "slateblue"

@inline
let slategray = "slategray"

@inline
let snow = "snow"

@inline
let springgreen = "springgreen"

@inline
let steelblue = "steelblue"

@inline
let tan = "tan"

@inline
let teal = "teal"

@inline
let thistle = "thistle"

@inline
let tomato = "tomato"

@inline
let turquoise = "turquoise"

@inline
let violet = "violet"

@inline
let wheat = "wheat"

@inline
let white = "white"

@inline
let whitesmoke = "whitesmoke"

@inline
let yellow = "yellow"

@inline
let yellowgreen = "yellowgreen"
