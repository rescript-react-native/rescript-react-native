


function layout(t) {
  var l = t.nativeEvent.layout;
  return /* record */[
          /* x */l.x,
          /* y */l.y,
          /* width */l.width,
          /* height */l.height
        ];
}

var NativeLayoutEvent = /* module */[/* layout */layout];

function contentOffset(t) {
  var co = t.nativeEvent.contentOffset;
  return /* record */[
          /* x */co.x,
          /* y */co.y
        ];
}

function contentSize(t) {
  var cs = t.nativeEvent.contentSize;
  return /* record */[
          /* width */cs.width,
          /* height */cs.height
        ];
}

function layoutMeasurement(t) {
  var lm = t.nativeEvent.layoutMeasurement;
  return /* record */[
          /* width */lm.width,
          /* height */lm.height
        ];
}

function contentInset(t) {
  var ci = t.nativeEvent.contentInset;
  return /* record */[
          /* bottom */ci.bottom,
          /* top */ci.top,
          /* left */ci.left,
          /* right */ci.right
        ];
}

function NativeEvent_000(prim) {
  return prim.changedTouches;
}

function NativeEvent_001(prim) {
  return prim.identifier;
}

function NativeEvent_002(prim) {
  return prim.locationX;
}

function NativeEvent_003(prim) {
  return prim.locationY;
}

function NativeEvent_004(prim) {
  return prim.pageX;
}

function NativeEvent_005(prim) {
  return prim.pageY;
}

function NativeEvent_006(prim) {
  return prim.target;
}

function NativeEvent_007(prim) {
  return prim.touches;
}

function NativeEvent_008(prim) {
  return prim.timestamp;
}

function NativeEvent_009(prim) {
  return prim.data;
}

var NativeEvent = [
  NativeEvent_000,
  NativeEvent_001,
  NativeEvent_002,
  NativeEvent_003,
  NativeEvent_004,
  NativeEvent_005,
  NativeEvent_006,
  NativeEvent_007,
  NativeEvent_008,
  NativeEvent_009
];

var NativePressEvent = 0;

var NativeScrollEvent = [
  contentOffset,
  contentSize,
  contentInset,
  layoutMeasurement
];

function nativeEvent(prim) {
  return prim.nativeEvent;
}

function nativeLayoutEvent(prim) {
  return prim.nativeEvent;
}

function nativeScrollEvent(prim) {
  return prim.nativeEvent;
}

export {
  NativeEvent ,
  NativePressEvent ,
  NativeScrollEvent ,
  NativeLayoutEvent ,
  nativeEvent ,
  nativeLayoutEvent ,
  nativeScrollEvent ,
  
}
/* No side effect */
