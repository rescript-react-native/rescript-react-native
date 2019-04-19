

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as Belt_List from "bs-platform/lib/es6/belt_List.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Internals$BsReactNative from "./Internals.bs.js";

function encode_pt_pct(param) {
  if (param.tag) {
    return Internals$BsReactNative.Encoder[/* pct */0](param[0]);
  } else {
    return param[0];
  }
}

function encode_pt_pct_auto(value) {
  if (typeof value === "number") {
    return "auto";
  } else if (value.tag) {
    return Internals$BsReactNative.Encoder[/* pct */0](value[0]);
  } else {
    return value[0];
  }
}

function encode_pt_pct_animated(param) {
  switch (param.tag | 0) {
    case 1 : 
        return Internals$BsReactNative.Encoder[/* pct */0](param[0]);
    case 0 : 
    case 2 : 
        return param[0];
    
  }
}

function encode_deg_animated(param) {
  if (param.tag) {
    return param[0];
  } else {
    return Internals$BsReactNative.Encoder[/* deg */1](param[0]);
  }
}

var style = Js_dict.fromList;

function flatten(prim) {
  return prim;
}

var concat = Belt_List.toArray;

function combine(a, b) {
  return Js_dict.fromArray($$Array.append(Js_dict.entries(a), Js_dict.entries(b)));
}

function alignContent(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "flex-start";
        break;
    case 1 : 
        tmp = "flex-end";
        break;
    case 2 : 
        tmp = "center";
        break;
    case 3 : 
        tmp = "stretch";
        break;
    case 4 : 
        tmp = "space-around";
        break;
    case 5 : 
        tmp = "space-between";
        break;
    
  }
  return /* tuple */[
          "alignContent",
          tmp
        ];
}

function alignItems(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "flex-start";
        break;
    case 1 : 
        tmp = "flex-end";
        break;
    case 2 : 
        tmp = "center";
        break;
    case 3 : 
        tmp = "stretch";
        break;
    case 4 : 
        tmp = "baseline";
        break;
    
  }
  return /* tuple */[
          "alignItems",
          tmp
        ];
}

function alignSelf(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "flex-start";
        break;
    case 1 : 
        tmp = "flex-end";
        break;
    case 2 : 
        tmp = "center";
        break;
    case 3 : 
        tmp = "stretch";
        break;
    case 4 : 
        tmp = "baseline";
        break;
    
  }
  return /* tuple */[
          "alignSelf",
          tmp
        ];
}

function aspectRatio(param) {
  return /* tuple */[
          "aspectRatio",
          param
        ];
}

function borderBottomWidth(param) {
  return /* tuple */[
          "borderBottomWidth",
          param
        ];
}

function borderLeftWidth(param) {
  return /* tuple */[
          "borderLeftWidth",
          param
        ];
}

function borderRightWidth(param) {
  return /* tuple */[
          "borderRightWidth",
          param
        ];
}

function borderTopWidth(param) {
  return /* tuple */[
          "borderTopWidth",
          param
        ];
}

function borderWidth(param) {
  return /* tuple */[
          "borderWidth",
          param
        ];
}

function display(v) {
  return /* tuple */[
          "display",
          v ? "none" : "flex"
        ];
}

function flex(param) {
  return /* tuple */[
          "flex",
          param
        ];
}

function flexBasis(value) {
  return /* tuple */[
          "flexBasis",
          encode_pt_pct_auto(value)
        ];
}

function flexDirection(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "row";
        break;
    case 1 : 
        tmp = "row-reverse";
        break;
    case 2 : 
        tmp = "column";
        break;
    case 3 : 
        tmp = "column-reverse";
        break;
    
  }
  return /* tuple */[
          "flexDirection",
          tmp
        ];
}

function flexGrow(param) {
  return /* tuple */[
          "flexGrow",
          param
        ];
}

function flexShrink(param) {
  return /* tuple */[
          "flexShrink",
          param
        ];
}

function flexWrap(v) {
  return /* tuple */[
          "flexWrap",
          v ? "nowrap" : "wrap"
        ];
}

function justifyContent(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "flex-start";
        break;
    case 1 : 
        tmp = "flex-end";
        break;
    case 2 : 
        tmp = "center";
        break;
    case 3 : 
        tmp = "space-around";
        break;
    case 4 : 
        tmp = "space-between";
        break;
    case 5 : 
        tmp = "space-evenly";
        break;
    
  }
  return /* tuple */[
          "justifyContent",
          tmp
        ];
}

function margin(value) {
  return /* tuple */[
          "margin",
          encode_pt_pct_auto(value)
        ];
}

function marginBottom(value) {
  return /* tuple */[
          "marginBottom",
          encode_pt_pct_auto(value)
        ];
}

function marginHorizontal(value) {
  return /* tuple */[
          "marginHorizontal",
          encode_pt_pct_auto(value)
        ];
}

function marginLeft(value) {
  return /* tuple */[
          "marginLeft",
          encode_pt_pct_auto(value)
        ];
}

function marginRight(value) {
  return /* tuple */[
          "marginRight",
          encode_pt_pct_auto(value)
        ];
}

function marginTop(value) {
  return /* tuple */[
          "marginTop",
          encode_pt_pct_auto(value)
        ];
}

function marginVertical(value) {
  return /* tuple */[
          "marginVertical",
          encode_pt_pct_auto(value)
        ];
}

function maxHeight(value) {
  return /* tuple */[
          "maxHeight",
          encode_pt_pct(value)
        ];
}

function maxWidth(value) {
  return /* tuple */[
          "maxWidth",
          encode_pt_pct(value)
        ];
}

function minHeight(value) {
  return /* tuple */[
          "minHeight",
          encode_pt_pct(value)
        ];
}

function minWidth(value) {
  return /* tuple */[
          "minWidth",
          encode_pt_pct(value)
        ];
}

function overflow(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "visible";
        break;
    case 1 : 
        tmp = "hidden";
        break;
    case 2 : 
        tmp = "scroll";
        break;
    
  }
  return /* tuple */[
          "overflow",
          tmp
        ];
}

function padding(value) {
  return /* tuple */[
          "padding",
          encode_pt_pct(value)
        ];
}

function paddingBottom(value) {
  return /* tuple */[
          "paddingBottom",
          encode_pt_pct(value)
        ];
}

function paddingHorizontal(value) {
  return /* tuple */[
          "paddingHorizontal",
          encode_pt_pct(value)
        ];
}

function paddingLeft(value) {
  return /* tuple */[
          "paddingLeft",
          encode_pt_pct(value)
        ];
}

function paddingRight(value) {
  return /* tuple */[
          "paddingRight",
          encode_pt_pct(value)
        ];
}

function paddingTop(value) {
  return /* tuple */[
          "paddingTop",
          encode_pt_pct(value)
        ];
}

function paddingVertical(value) {
  return /* tuple */[
          "paddingVertical",
          encode_pt_pct(value)
        ];
}

function position(v) {
  return /* tuple */[
          "position",
          v ? "relative" : "absolute"
        ];
}

function top(value) {
  return /* tuple */[
          "top",
          encode_pt_pct_animated(value)
        ];
}

function left(value) {
  return /* tuple */[
          "left",
          encode_pt_pct_animated(value)
        ];
}

function right(value) {
  return /* tuple */[
          "right",
          encode_pt_pct_animated(value)
        ];
}

function bottom(value) {
  return /* tuple */[
          "bottom",
          encode_pt_pct_animated(value)
        ];
}

function height(value) {
  return /* tuple */[
          "height",
          encode_pt_pct_animated(value)
        ];
}

function width(value) {
  return /* tuple */[
          "width",
          encode_pt_pct_animated(value)
        ];
}

function zIndex(value) {
  return /* tuple */[
          "zIndex",
          value
        ];
}

function direction(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "inherit";
        break;
    case 1 : 
        tmp = "ltr";
        break;
    case 2 : 
        tmp = "rtl";
        break;
    
  }
  return /* tuple */[
          "direction",
          tmp
        ];
}

function shadowColor(value) {
  return /* tuple */[
          "shadowColor",
          value[0]
        ];
}

function shadowOffset(height, width) {
  return /* tuple */[
          "shadowOffset",
          Js_dict.fromArray(/* array */[
                /* tuple */[
                  "height",
                  height
                ],
                /* tuple */[
                  "width",
                  width
                ]
              ])
        ];
}

function shadowOpacity(param) {
  return /* tuple */[
          "shadowOpacity",
          param
        ];
}

function shadowRadius(param) {
  return /* tuple */[
          "shadowRadius",
          param
        ];
}

function transform(listyle) {
  return /* tuple */[
          "transform",
          Belt_List.toArray(Belt_List.map(listyle, (function (ts) {
                      return Js_dict.fromList(/* :: */[
                                  ts,
                                  /* [] */0
                                ]);
                    })))
        ];
}

function perspective(value) {
  return /* tuple */[
          "perspective",
          value[0]
        ];
}

function translateX(value) {
  return /* tuple */[
          "translateX",
          value[0]
        ];
}

function translateY(value) {
  return /* tuple */[
          "translateY",
          value[0]
        ];
}

function scaleX(value) {
  return /* tuple */[
          "scaleX",
          value[0]
        ];
}

function scaleY(value) {
  return /* tuple */[
          "scaleY",
          value[0]
        ];
}

function scale(value) {
  return /* tuple */[
          "scale",
          value[0]
        ];
}

function rotate(value) {
  return /* tuple */[
          "rotate",
          encode_deg_animated(value)
        ];
}

function rotateX(value) {
  return /* tuple */[
          "rotateX",
          encode_deg_animated(value)
        ];
}

function rotateY(value) {
  return /* tuple */[
          "rotateY",
          encode_deg_animated(value)
        ];
}

function rotateZ(value) {
  return /* tuple */[
          "rotateZ",
          encode_deg_animated(value)
        ];
}

function skewX(value) {
  return /* tuple */[
          "skewX",
          encode_deg_animated(value)
        ];
}

function skewY(value) {
  return /* tuple */[
          "skewY",
          encode_deg_animated(value)
        ];
}

function create_(encoder, rotationEncoder, perspective, rotate, rotateX, rotateY, rotateZ, scaleX, scaleY, translateX, translateY, skewX, skewY) {
  var opt_values = /* array */[
    /* tuple */[
      "perspective",
      encoder(perspective)
    ],
    /* tuple */[
      "rotate",
      rotationEncoder(rotate)
    ],
    /* tuple */[
      "rotateX",
      rotationEncoder(rotateX)
    ],
    /* tuple */[
      "rotateY",
      rotationEncoder(rotateY)
    ],
    /* tuple */[
      "rotateZ",
      rotationEncoder(rotateZ)
    ],
    /* tuple */[
      "scaleX",
      encoder(scaleX)
    ],
    /* tuple */[
      "scaleY",
      encoder(scaleY)
    ],
    /* tuple */[
      "translateX",
      encoder(translateX)
    ],
    /* tuple */[
      "translateY",
      encoder(translateY)
    ],
    /* tuple */[
      "skewX",
      rotationEncoder(skewX)
    ],
    /* tuple */[
      "skewY",
      rotationEncoder(skewY)
    ]
  ];
  var values = $$Array.fold_right((function (x, acc) {
          var match = x[1];
          if (match !== undefined) {
            var val_ = Js_dict.fromArray(/* array */[/* tuple */[
                    x[0],
                    Caml_option.valFromOption(match)
                  ]]);
            return /* :: */[
                    val_,
                    acc
                  ];
          } else {
            return acc;
          }
        }), opt_values, /* [] */0);
  return /* tuple */[
          "transform",
          $$Array.of_list(values)
        ];
}

function make(perspective, rotate, rotateX, rotateY, rotateZ, scaleX, scaleY, translateX, translateY, skewX, skewY, param) {
  return create_((function (value) {
                return Belt_Option.map(value, (function (prim) {
                              return prim;
                            }));
              }), (function (value) {
                return Belt_Option.map(value, (function (prim) {
                              return prim;
                            }));
              }), perspective, rotate, rotateX, rotateY, rotateZ, scaleX, scaleY, translateX, translateY, skewX, skewY);
}

function makeAnimated(perspective, rotate, rotateX, rotateY, rotateZ, scaleX, scaleY, translateX, translateY, skewX, skewY, param) {
  return create_((function (value) {
                return Belt_Option.map(value, (function (prim) {
                              return prim;
                            }));
              }), (function (value) {
                return Belt_Option.map(value, (function (prim) {
                              return prim;
                            }));
              }), perspective, rotate, rotateX, rotateY, rotateZ, scaleX, scaleY, translateX, translateY, skewX, skewY);
}

function backfaceVisibility(v) {
  return /* tuple */[
          "backfaceVisibility",
          v ? "hidden" : "visible"
        ];
}

function backgroundColor(value) {
  return /* tuple */[
          "backgroundColor",
          value[0]
        ];
}

function borderColor(value) {
  return /* tuple */[
          "borderColor",
          value[0]
        ];
}

function borderTopColor(value) {
  return /* tuple */[
          "borderTopColor",
          value[0]
        ];
}

function borderRightColor(value) {
  return /* tuple */[
          "borderRightColor",
          value[0]
        ];
}

function borderBottomColor(value) {
  return /* tuple */[
          "borderBottomColor",
          value[0]
        ];
}

function borderLeftColor(value) {
  return /* tuple */[
          "borderLeftColor",
          value[0]
        ];
}

function borderRadius(param) {
  return /* tuple */[
          "borderRadius",
          param
        ];
}

function borderTopLeftRadius(param) {
  return /* tuple */[
          "borderTopLeftRadius",
          param
        ];
}

function borderTopRightRadius(param) {
  return /* tuple */[
          "borderTopRightRadius",
          param
        ];
}

function borderBottomLeftRadius(param) {
  return /* tuple */[
          "borderBottomLeftRadius",
          param
        ];
}

function borderBottomRightRadius(param) {
  return /* tuple */[
          "borderBottomRightRadius",
          param
        ];
}

function borderStyle(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "solid";
        break;
    case 1 : 
        tmp = "dotted";
        break;
    case 2 : 
        tmp = "dashed";
        break;
    
  }
  return /* tuple */[
          "borderStyle",
          tmp
        ];
}

function opacity(value) {
  return /* tuple */[
          "opacity",
          value[0]
        ];
}

function elevation(param) {
  return /* tuple */[
          "elevation",
          param
        ];
}

function color(value) {
  return /* tuple */[
          "color",
          value[0]
        ];
}

function fontFamily(param) {
  return /* tuple */[
          "fontFamily",
          param
        ];
}

function fontSize(value) {
  return /* tuple */[
          "fontSize",
          value[0]
        ];
}

function fontStyle(v) {
  return /* tuple */[
          "fontStyle",
          v ? "italic" : "normal"
        ];
}

function fontWeight(v) {
  return /* tuple */[
          "fontWeight",
          v >= 1056105525 ? (
              v >= 1056204983 ? (
                  v >= 1056304441 ? (
                      v >= 1056354170 ? "900" : "800"
                    ) : (
                      v >= 1056254712 ? "700" : "600"
                    )
                ) : (
                  v >= 1056155254 ? "500" : "400"
                )
            ) : (
              v !== 737455525 ? (
                  v >= 1056006067 ? (
                      v >= 1056055796 ? "300" : "200"
                    ) : (
                      v >= 1055956338 ? "100" : "normal"
                    )
                ) : "bold"
            )
        ];
}

function lineHeight(param) {
  return /* tuple */[
          "lineHeight",
          param
        ];
}

function textAlign(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "auto";
        break;
    case 1 : 
        tmp = "left";
        break;
    case 2 : 
        tmp = "right";
        break;
    case 3 : 
        tmp = "center";
        break;
    case 4 : 
        tmp = "justify";
        break;
    
  }
  return /* tuple */[
          "textAlign",
          tmp
        ];
}

function textDecorationLine(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "none";
        break;
    case 1 : 
        tmp = "underline";
        break;
    case 2 : 
        tmp = "line-through";
        break;
    case 3 : 
        tmp = "underline line-through";
        break;
    
  }
  return /* tuple */[
          "textDecorationLine",
          tmp
        ];
}

function textShadowColor(value) {
  return /* tuple */[
          "textShadowColor",
          value[0]
        ];
}

function textShadowOffset(height, width) {
  return /* tuple */[
          "textShadowOffset",
          Js_dict.fromArray(/* array */[
                /* tuple */[
                  "height",
                  height
                ],
                /* tuple */[
                  "width",
                  width
                ]
              ])
        ];
}

function textShadowRadius(param) {
  return /* tuple */[
          "textShadowRadius",
          param
        ];
}

function includeFontPadding(value) {
  return /* tuple */[
          "includeFontPadding",
          value
        ];
}

function textAlignVertical(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "auto";
        break;
    case 1 : 
        tmp = "top";
        break;
    case 2 : 
        tmp = "bottom";
        break;
    case 3 : 
        tmp = "center";
        break;
    
  }
  return /* tuple */[
          "textAlignVertical",
          tmp
        ];
}

function fontVariant(fontVariants) {
  return /* tuple */[
          "fontVariant",
          $$Array.map((function (prim) {
                  return prim;
                }), $$Array.of_list(fontVariants))
        ];
}

function letterSpacing(param) {
  return /* tuple */[
          "letterSpacing",
          param
        ];
}

function textDecorationColor(value) {
  return /* tuple */[
          "textDecorationColor",
          value[0]
        ];
}

function textDecorationStyle(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "solid";
        break;
    case 1 : 
        tmp = "double";
        break;
    case 2 : 
        tmp = "dotted";
        break;
    case 3 : 
        tmp = "dashed";
        break;
    
  }
  return /* tuple */[
          "textDecorationStyle",
          tmp
        ];
}

function writingDirection(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "auto";
        break;
    case 1 : 
        tmp = "ltr";
        break;
    case 2 : 
        tmp = "rtl";
        break;
    
  }
  return /* tuple */[
          "writingDirection",
          tmp
        ];
}

function resizeMode(v) {
  var tmp;
  switch (v) {
    case 0 : 
        tmp = "cover";
        break;
    case 1 : 
        tmp = "contain";
        break;
    case 2 : 
        tmp = "stretch";
        break;
    case 3 : 
        tmp = "repeat";
        break;
    case 4 : 
        tmp = "center";
        break;
    
  }
  return /* tuple */[
          "resizeMode",
          tmp
        ];
}

function tintColor(value) {
  return /* tuple */[
          "tintColor",
          value[0]
        ];
}

function overlayColor(value) {
  return /* tuple */[
          "overlayColor",
          value[0]
        ];
}

function array(prim) {
  return prim;
}

function arrayOption(prim) {
  return prim;
}

function list(prim) {
  return prim;
}

function listOption(prim) {
  return prim;
}

var Transform = [
  perspective,
  translateX,
  translateY,
  scaleX,
  scaleY,
  scale,
  rotate,
  rotateX,
  rotateY,
  rotateZ,
  skewX,
  skewY,
  make,
  makeAnimated
];

export {
  style ,
  array ,
  arrayOption ,
  list ,
  listOption ,
  flatten ,
  concat ,
  combine ,
  alignContent ,
  alignItems ,
  alignSelf ,
  aspectRatio ,
  borderBottomWidth ,
  borderLeftWidth ,
  borderRightWidth ,
  borderTopWidth ,
  borderWidth ,
  display ,
  flex ,
  flexBasis ,
  flexDirection ,
  flexGrow ,
  flexShrink ,
  flexWrap ,
  justifyContent ,
  margin ,
  marginBottom ,
  marginHorizontal ,
  marginLeft ,
  marginRight ,
  marginTop ,
  marginVertical ,
  maxHeight ,
  maxWidth ,
  minHeight ,
  minWidth ,
  overflow ,
  padding ,
  paddingBottom ,
  paddingHorizontal ,
  paddingLeft ,
  paddingRight ,
  paddingTop ,
  paddingVertical ,
  position ,
  top ,
  left ,
  right ,
  bottom ,
  height ,
  width ,
  zIndex ,
  direction ,
  shadowColor ,
  shadowOffset ,
  shadowOpacity ,
  shadowRadius ,
  transform ,
  perspective ,
  translateX ,
  translateY ,
  scaleX ,
  scaleY ,
  scale ,
  rotate ,
  rotateX ,
  rotateY ,
  rotateZ ,
  skewX ,
  skewY ,
  Transform ,
  backfaceVisibility ,
  backgroundColor ,
  borderColor ,
  borderTopColor ,
  borderRightColor ,
  borderBottomColor ,
  borderLeftColor ,
  borderRadius ,
  borderTopLeftRadius ,
  borderTopRightRadius ,
  borderBottomLeftRadius ,
  borderBottomRightRadius ,
  borderStyle ,
  opacity ,
  elevation ,
  color ,
  fontFamily ,
  fontSize ,
  fontStyle ,
  fontWeight ,
  lineHeight ,
  textAlign ,
  textDecorationLine ,
  textShadowColor ,
  textShadowOffset ,
  textShadowRadius ,
  includeFontPadding ,
  textAlignVertical ,
  fontVariant ,
  letterSpacing ,
  textDecorationColor ,
  textDecorationStyle ,
  writingDirection ,
  resizeMode ,
  tintColor ,
  overlayColor ,
  
}
/* No side effect */
