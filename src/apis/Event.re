// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

type syntheticEvent('a) = {
  .
  "bubbles": Js.Nullable.t(bool),
  "cancelable": Js.Nullable.t(bool),
  "currentTarget": float,
  "defaultPrevented": Js.Nullable.t(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": Js.Nullable.t(float),
  [@bs.meth] "preventDefault": unit => unit,
  [@bs.meth] "isDefaultPrevented": unit => bool,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "isPropagationStopped": unit => bool,
  "isTrusted": Js.Nullable.t(bool),
  "nativeEvent": 'a,
  [@bs.meth] "persist": unit => unit,
  "target": Js.Nullable.t(float),
  "timeStamp": float,
  "_type": Js.Nullable.t(string),
};

type responderSyntheticEvent('a) = {
  .
  // synthethicEvent keys
  "bubbles": Js.Nullable.t(bool),
  "cancelable": Js.Nullable.t(bool),
  "currentTarget": float,
  "defaultPrevented": Js.Nullable.t(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": Js.Nullable.t(float),
  [@bs.meth] "preventDefault": unit => unit,
  [@bs.meth] "isDefaultPrevented": unit => bool,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "isPropagationStopped": unit => bool,
  "isTrusted": Js.Nullable.t(bool),
  "nativeEvent": 'a,
  [@bs.meth] "persist": unit => unit,
  "target": Js.Nullable.t(float),
  "timeStamp": float,
  "_type": Js.Nullable.t(string),
  // responderSyntheticEvent additional key
  "touchHistory": {
    .
    "indexOfSingleActiveTouch": float,
    "mostRecentTimeStamp": float,
    "numberActiveTouches": float,
    "touchBank":
      array({
        .
        "touchActive": bool,
        "startPageX": float,
        "startPageY": float,
        "startTimeStamp": float,
        "currentPageX": float,
        "currentPageY": float,
        "currentTimeStamp": float,
        "previousPageX": float,
        "previousPageY": float,
        "previousTimeStamp": float,
      }),
  },
};

type textLayout = {
  x: float,
  y: float,
  width: float,
  height: float,
  ascender: float, // verify
  capHeight: float, // verify
  descender: float, // verify
  text: string,
  xHeight: float // verify
};

type layoutEvent = syntheticEvent(layout)
and layout = {
  x: float,
  y: float,
  width: float,
  height: float,
};

type textLayoutEvent = syntheticEvent(textLayouts)
and textLayouts = {lines: array(textLayout)};

type pressEventPayload = {
  changedTouches: array(pressEventPayload),
  force: float,
  identifier: int,
  locationX: float,
  locationY: float,
  pageX: float,
  pageY: float,
  target: Js.Nullable.t(float),
  timestamp: float,
  touches: array(pressEventPayload),
};

type pressEvent = responderSyntheticEvent(pressEventPayload);

type contentOffset = {
  x: float,
  y: float,
};

type dimensions = {
  height: float,
  width: float,
};

type scrollEvent = syntheticEvent(scrollEventPayload)
and scrollEventPayload = {
  contentInset,
  contentOffset,
  contentSize: dimensions,
  layoutMeasurement: dimensions,
}
and contentInset = {
  bottom: float,
  left: float,
  right: float,
  top: float,
};

type switchChangeEvent = syntheticEvent(switchChangePayload)
and switchChangePayload = {value: bool};

type targetEvent = syntheticEvent(targetPayload)
and targetPayload = {target: int};
