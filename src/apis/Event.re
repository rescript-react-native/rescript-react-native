// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

type syntheticEvent('a) = {
  .
  "bubbles": option(bool),
  "cancelable": option(bool),
  "currentTarget": float,
  "defaultPrevented": option(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": option(float),
  [@bs.meth] "preventDefault": unit => unit,
  [@bs.meth] "isDefaultPrevented": unit => bool,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "isPropagationStopped": unit => bool,
  "isTrusted": option(bool),
  "nativeEvent": 'a,
  [@bs.meth] "persist": unit => unit,
  "target": option(float),
  "timeStamp": float,
  "_type": option(string),
};

type responderSyntheticEvent('a) = {
  .
  // synthethicEvent keys
  "bubbles": option(bool),
  "cancelable": option(bool),
  "currentTarget": float,
  "defaultPrevented": option(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": option(float),
  [@bs.meth] "preventDefault": unit => unit,
  [@bs.meth] "isDefaultPrevented": unit => bool,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "isPropagationStopped": unit => bool,
  "isTrusted": option(bool),
  "nativeEvent": 'a,
  [@bs.meth] "persist": unit => unit,
  "target": option(float),
  "timeStamp": float,
  "_type": option(string),
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
type textLayoutEvent = syntheticEvent({. "lines": array(textLayout)});

type pressEventPayload = {
  changedTouches: array(pressEventPayload),
  force: float,
  identifier: int,
  locationX: float,
  locationY: float,
  pageX: float,
  pageY: float,
  target: option(float),
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

type scrollEvent = syntheticEvent(value)
and value = {
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

type switchChangeEvent = syntheticEvent({. "value": bool});

type targetEvent = syntheticEvent({. "target": int});
