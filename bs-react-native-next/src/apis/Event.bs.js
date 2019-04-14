'use strict';


var NativeEvent = /* module */[];

var NativeLayoutEvent = /* module */[];

var ContentInset = /* module */[];

var ContentOffset = /* module */[];

var ContentSize = /* module */[];

var LayoutMeasurement = /* module */[];

var NativeScrollEvent = /* module */[
  /* ContentInset */ContentInset,
  /* ContentOffset */ContentOffset,
  /* ContentSize */ContentSize,
  /* LayoutMeasurement */LayoutMeasurement
];

var NativePressEvent = 0;

exports.NativeEvent = NativeEvent;
exports.NativePressEvent = NativePressEvent;
exports.NativeLayoutEvent = NativeLayoutEvent;
exports.NativeScrollEvent = NativeScrollEvent;
/* No side effect */
