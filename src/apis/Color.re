type t = string;

let rgb = (~r: int, ~g: int, ~b: int) => {j|rgb($r, $g, $b)|j};
let rgba = (~r: int, ~g: int, ~b: int, ~a: float) => {j|rgba($r, $g, $b, $a)|j};

let hsl = (~h: float, ~s: float, ~l: float) => {j|hsl($h, $s%, $l%)|j};
let hsla = (~h: float, ~s: float, ~l: float, ~a: float) => {j|hsl($h, $s%, $l%, $a)|j};

[@bs.inline]
let transparent = "transparent";

// Pre-defined colors
[@bs.inline]
let aliceblue = "aliceblue";

[@bs.inline]
let antiquewhite = "antiquewhite";

[@bs.inline]
let aqua = "aqua";

[@bs.inline]
let aquamarine = "aquamarine";

[@bs.inline]
let azure = "azure";

[@bs.inline]
let beige = "beige";

[@bs.inline]
let bisque = "bisque";

[@bs.inline]
let black = "black";

[@bs.inline]
let blanchedalmond = "blanchedalmond";

[@bs.inline]
let blue = "blue";

[@bs.inline]
let blueviolet = "blueviolet";

[@bs.inline]
let brown = "brown";

[@bs.inline]
let burlywood = "burlywood";

[@bs.inline]
let cadetblue = "cadetblue";

[@bs.inline]
let chartreuse = "chartreuse";

[@bs.inline]
let chocolate = "chocolate";

[@bs.inline]
let coral = "coral";

[@bs.inline]
let cornflowerblue = "cornflowerblue";

[@bs.inline]
let cornsilk = "cornsilk";

[@bs.inline]
let crimson = "crimson";

[@bs.inline]
let cyan = "cyan";

[@bs.inline]
let darkblue = "darkblue";

[@bs.inline]
let darkcyan = "darkcyan";

[@bs.inline]
let darkgoldenrod = "darkgoldenrod";

[@bs.inline]
let darkgray = "darkgray";

[@bs.inline]
let darkgreen = "darkgreen";

[@bs.inline]
let darkgrey = "darkgrey";

[@bs.inline]
let darkkhaki = "darkkhaki";

[@bs.inline]
let darkmagenta = "darkmagenta";

[@bs.inline]
let darkolivegreen = "darkolivegreen";

[@bs.inline]
let darkorange = "darkorange";

[@bs.inline]
let darkorchid = "darkorchid";

[@bs.inline]
let darkred = "darkred";

[@bs.inline]
let darksalmon = "darksalmon";

[@bs.inline]
let darkseagreen = "darkseagreen";

[@bs.inline]
let darkslateblue = "darkslateblue";

[@bs.inline]
let darkslategrey = "darkslategrey";

[@bs.inline]
let darkturquoise = "darkturquoise";

[@bs.inline]
let darkviolet = "darkviolet";

[@bs.inline]
let deeppink = "deeppink";

[@bs.inline]
let deepskyblue = "deepskyblue";

[@bs.inline]
let dimgray = "dimgray";

[@bs.inline]
let dimgrey = "dimgrey";

[@bs.inline]
let dodgerblue = "dodgerblue";

[@bs.inline]
let firebrick = "firebrick";

[@bs.inline]
let floralwhite = "floralwhite";

[@bs.inline]
let forestgreen = "forestgreen";

[@bs.inline]
let fuchsia = "fuchsia";

[@bs.inline]
let gainsboro = "gainsboro";

[@bs.inline]
let ghostwhite = "ghostwhite";

[@bs.inline]
let gold = "gold";

[@bs.inline]
let goldenrod = "goldenrod";

[@bs.inline]
let gray = "gray";

[@bs.inline]
let green = "green";

[@bs.inline]
let greenyellow = "greenyellow";

[@bs.inline]
let grey = "grey";

[@bs.inline]
let honeydew = "honeydew";

[@bs.inline]
let hotpink = "hotpink";

[@bs.inline]
let indianred = "indianred";

[@bs.inline]
let indigo = "indigo";

[@bs.inline]
let ivory = "ivory";

[@bs.inline]
let khaki = "khaki";

[@bs.inline]
let lavender = "lavender";

[@bs.inline]
let lavenderblush = "lavenderblush";

[@bs.inline]
let lawngreen = "lawngreen";

[@bs.inline]
let lemonchiffon = "lemonchiffon";

[@bs.inline]
let lightblue = "lightblue";

[@bs.inline]
let lightcoral = "lightcoral";

[@bs.inline]
let lightcyan = "lightcyan";

[@bs.inline]
let lightgoldenrodyellow = "lightgoldenrodyellow";

[@bs.inline]
let lightgray = "lightgray";

[@bs.inline]
let lightgreen = "lightgreen";

[@bs.inline]
let lightgrey = "lightgrey";

[@bs.inline]
let lightpink = "lightpink";

[@bs.inline]
let lightsalmon = "lightsalmon";

[@bs.inline]
let lightseagreen = "lightseagreen";

[@bs.inline]
let lightskyblue = "lightskyblue";

[@bs.inline]
let lightslategrey = "lightslategrey";

[@bs.inline]
let lightsteelblue = "lightsteelblue";

[@bs.inline]
let lightyellow = "lightyellow";

[@bs.inline]
let lime = "lime";

[@bs.inline]
let limegreen = "limegreen";

[@bs.inline]
let linen = "linen";

[@bs.inline]
let magenta = "magenta";

[@bs.inline]
let maroon = "maroon";

[@bs.inline]
let mediumaquamarine = "mediumaquamarine";

[@bs.inline]
let mediumblue = "mediumblue";

[@bs.inline]
let mediumorchid = "mediumorchid";

[@bs.inline]
let mediumpurple = "mediumpurple";

[@bs.inline]
let mediumseagreen = "mediumseagreen";

[@bs.inline]
let mediumslateblue = "mediumslateblue";

[@bs.inline]
let mediumspringgreen = "mediumspringgreen";

[@bs.inline]
let mediumturquoise = "mediumturquoise";

[@bs.inline]
let mediumvioletred = "mediumvioletred";

[@bs.inline]
let midnightblue = "midnightblue";

[@bs.inline]
let mintcream = "mintcream";

[@bs.inline]
let mistyrose = "mistyrose";

[@bs.inline]
let moccasin = "moccasin";

[@bs.inline]
let navajowhite = "navajowhite";

[@bs.inline]
let navy = "navy";

[@bs.inline]
let oldlace = "oldlace";

[@bs.inline]
let olive = "olive";

[@bs.inline]
let olivedrab = "olivedrab";

[@bs.inline]
let orange = "orange";

[@bs.inline]
let orangered = "orangered";

[@bs.inline]
let orchid = "orchid";

[@bs.inline]
let palegoldenrod = "palegoldenrod";

[@bs.inline]
let palegreen = "palegreen";

[@bs.inline]
let paleturquoise = "paleturquoise";

[@bs.inline]
let palevioletred = "palevioletred";

[@bs.inline]
let papayawhip = "papayawhip";

[@bs.inline]
let peachpuff = "peachpuff";

[@bs.inline]
let peru = "peru";

[@bs.inline]
let pink = "pink";

[@bs.inline]
let plum = "plum";

[@bs.inline]
let powderblue = "powderblue";

[@bs.inline]
let purple = "purple";

[@bs.inline]
let rebeccapurple = "rebeccapurple";

[@bs.inline]
let red = "red";

[@bs.inline]
let rosybrown = "rosybrown";

[@bs.inline]
let royalblue = "royalblue";

[@bs.inline]
let saddlebrown = "saddlebrown";

[@bs.inline]
let salmon = "salmon";

[@bs.inline]
let sandybrown = "sandybrown";

[@bs.inline]
let seagreen = "seagreen";

[@bs.inline]
let seashell = "seashell";

[@bs.inline]
let sienna = "sienna";

[@bs.inline]
let silver = "silver";

[@bs.inline]
let skyblue = "skyblue";

[@bs.inline]
let slateblue = "slateblue";

[@bs.inline]
let slategray = "slategray";

[@bs.inline]
let snow = "snow";

[@bs.inline]
let springgreen = "springgreen";

[@bs.inline]
let steelblue = "steelblue";

[@bs.inline]
let tan = "tan";

[@bs.inline]
let teal = "teal";

[@bs.inline]
let thistle = "thistle";

[@bs.inline]
let tomato = "tomato";

[@bs.inline]
let turquoise = "turquoise";

[@bs.inline]
let violet = "violet";

[@bs.inline]
let wheat = "wheat";

[@bs.inline]
let white = "white";

[@bs.inline]
let whitesmoke = "whitesmoke";

[@bs.inline]
let yellow = "yellow";

[@bs.inline]
let yellowgreen = "yellowgreen";
