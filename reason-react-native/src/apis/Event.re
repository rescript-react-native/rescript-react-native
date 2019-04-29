// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

type syntheticEvent('a) = {
  .
  "bubbles": Js.Nullable.t(bool),
  "cancelable": Js.Nullable.t(bool),
  "currentTarget": float,
  "defaultPrevented": Js.Nullable.t(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": Js.Nullable.t(float),
  "preventDefault": unit => unit,
  "isDefaultPrevented": unit => bool,
  "stopPropagation": unit => unit,
  "isPropagationStopped": unit => bool,
  "isTrusted": Js.Nullable.t(bool),
  "nativeEvent": 'a,
  "persist": unit => unit,
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
  "preventDefault": unit => unit,
  "isDefaultPrevented": unit => bool,
  "stopPropagation": unit => unit,
  "isPropagationStopped": unit => bool,
  "isTrusted": Js.Nullable.t(bool),
  "nativeEvent": 'a,
  "persist": unit => unit,
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
  .
  "x": float,
  "y": float,
  "width": float,
  "height": float,
  "ascender": float, // verify
  "capHeight": float, // verify
  "descender": float, // verify
  "text": string,
  "xHeight": float // verify
};

type layoutEvent =
  syntheticEvent({
    .
    "layout": {
      .
      "x": float,
      "y": float,
      "width": float,
      "height": float,
    },
  });

type textLayoutEvent = syntheticEvent({. "lines": array(textLayout)});

type pressEventPayload = {
  .
  "changedTouches": array(pressEventPayload),
  "force": float,
  "identifier": int,
  "locationX": float,
  "locationY": float,
  "pageX": float,
  "pageY": float,
  "target": Js.Nullable.t(float),
  "timestamp": float,
  "touches": array(pressEventPayload),
};

type pressEvent = responderSyntheticEvent(pressEventPayload);

type position = {
  .
  "y": float,
  "x": float,
};

type dimensions = {
  .
  "height": float,
  "width": float,
};

type scrollEvent =
  syntheticEvent({
    .
    "contentInset": {
      .
      "bottom": float,
      "left": float,
      "right": float,
      "top": float,
    },
    "contentOffset": position,
    "contentSize": dimensions,
    "layoutMeasurement": dimensions,
  });

type switchChangeEvent = syntheticEvent({. "value": bool});

type targetEvent = syntheticEvent({. "target": int});
