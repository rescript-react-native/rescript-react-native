'use strict';


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

exports.NativeLayoutEvent = NativeLayoutEvent;
/* No side effect */
