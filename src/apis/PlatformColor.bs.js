'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");
var ReactNative = require("react-native");

var IOS = { };

var jsMapperConstantArray = [
  /* tuple */[
    -933011898,
    "holo_blue_light"
  ],
  /* tuple */[
    -910341463,
    "white"
  ],
  /* tuple */[
    -681480529,
    "secondary_text_light"
  ],
  /* tuple */[
    -567076507,
    "holo_green_light"
  ],
  /* tuple */[
    -542335758,
    "holo_orange_dark"
  ],
  /* tuple */[
    -497565961,
    "secondary_text_light_nodisable"
  ],
  /* tuple */[
    -446800943,
    "holo_purple"
  ],
  /* tuple */[
    -442624943,
    "tertiary_text_light"
  ],
  /* tuple */[
    -399813945,
    "holo_green_dark"
  ],
  /* tuple */[
    -230337909,
    "primary_text_dark"
  ],
  /* tuple */[
    -137186086,
    "holo_orange_light"
  ],
  /* tuple */[
    -43808333,
    "holo_red_light"
  ],
  /* tuple */[
    -19681665,
    "darker_gray"
  ],
  /* tuple */[
    53352795,
    "tertiary_text_dark"
  ],
  /* tuple */[
    115741317,
    "background_light"
  ],
  /* tuple */[
    137823494,
    "holo_blue_dark"
  ],
  /* tuple */[
    210003011,
    "widget_edittext_dark"
  ],
  /* tuple */[
    225621181,
    "secondary_text_dark"
  ],
  /* tuple */[
    255430099,
    "primary_text_dark_nodisable"
  ],
  /* tuple */[
    354837125,
    "secondary_text_dark_nodisable"
  ],
  /* tuple */[
    582626130,
    "transparent"
  ],
  /* tuple */[
    624024999,
    "background_dark"
  ],
  /* tuple */[
    718857505,
    "primary_text_light"
  ],
  /* tuple */[
    720513095,
    "tab_indicator_text"
  ],
  /* tuple */[
    796649017,
    "holo_red_dark"
  ],
  /* tuple */[
    888264127,
    "black"
  ],
  /* tuple */[
    956987369,
    "primary_text_light_nodisable"
  ],
  /* tuple */[
    1055546570,
    "holo_blue_bright"
  ]
];

function androidColorToJs(param) {
  return Js_mapperRt.binarySearch(28, param, jsMapperConstantArray);
}

function androidColorFromJs(param) {
  return Js_mapperRt.revSearch(28, jsMapperConstantArray, param);
}

var jsMapperConstantArray$1 = [
  /* tuple */[
    -986766579,
    "colorAccent"
  ],
  /* tuple */[
    -907609711,
    "colorSecondary"
  ],
  /* tuple */[
    -899911325,
    "color"
  ],
  /* tuple */[
    -850961280,
    "colorFocusedHighlight"
  ],
  /* tuple */[
    -839548235,
    "colorPressedHighlight"
  ],
  /* tuple */[
    -659719526,
    "colorControlHighlight"
  ],
  /* tuple */[
    -531150842,
    "colorForeground"
  ],
  /* tuple */[
    -456193502,
    "colorMultiSelectHighlight"
  ],
  /* tuple */[
    -263680794,
    "colorActivatedHighlight"
  ],
  /* tuple */[
    -216581679,
    "colorLongPressedHighlight"
  ],
  /* tuple */[
    -177467460,
    "colorButtonNormal"
  ],
  /* tuple */[
    -175783119,
    "colorBackground"
  ],
  /* tuple */[
    -82651062,
    "colorForegroundInverse"
  ],
  /* tuple */[
    -49854185,
    "colorBackgroundFloating"
  ],
  /* tuple */[
    328339953,
    "colorEdgeEffect"
  ],
  /* tuple */[
    395699045,
    "colorError"
  ],
  /* tuple */[
    672543233,
    "colorControlNormal"
  ],
  /* tuple */[
    752040095,
    "colorPrimary"
  ],
  /* tuple */[
    1019344053,
    "colorPrimaryDark"
  ]
];

function attrColorToJs(param) {
  return Js_mapperRt.binarySearch(19, param, jsMapperConstantArray$1);
}

function attrColorFromJs(param) {
  return Js_mapperRt.revSearch(19, jsMapperConstantArray$1, param);
}

function get(color) {
  var tmp;
  tmp = color.tag ? "@android:color/" + Js_mapperRt.binarySearch(28, color[0], jsMapperConstantArray) : "?attr/" + Js_mapperRt.binarySearch(19, color[0], jsMapperConstantArray$1);
  return ReactNative.PlatformColor(tmp);
}

var Android = {
  androidColorToJs: androidColorToJs,
  androidColorFromJs: androidColorFromJs,
  attrColorToJs: attrColorToJs,
  attrColorFromJs: attrColorFromJs,
  get: get
};

exports.IOS = IOS;
exports.Android = Android;
/* react-native Not a pure module */
