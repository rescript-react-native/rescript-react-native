// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js
type dispatchConfig = {registrationName: string};
type preventDefault = {. [@bs.meth] "preventDefault": unit => unit};
type isDefaultPrevented = {. [@bs.meth] "isDefaultPrevented": unit => bool};
type stopPropagation = {. [@bs.meth] "stopPropagation": unit => unit};
type isPropagationStopped = {
  .
  [@bs.meth] "isPropagationStopped": unit => bool,
};
type persist = {. [@bs.meth] "persist": unit => unit};
type syntheticEvent('a) = {
  bubbles: option(bool),
  cancelable: option(bool),
  currentTarget: float,
  defaultPrevented: option(bool),
  dispatchConfig,
  eventPhase: option(float),
  preventDefault,
  isDefaultPrevented,
  stopPropagation,
  isPropagationStopped,
  isTrusted: option(bool),
  nativeEvent: 'a,
  persist,
  target: option(float),
  timeStamp: float,
  _type: option(string),
};

type responderSyntheticEvent('a) = {
  // synthethicEvent keys
  bubbles: option(bool),
  cancelable: option(bool),
  currentTarget: float,
  defaultPrevented: option(bool),
  dispatchConfig,
  eventPhase: option(float),
  preventDefault,
  isDefaultPrevented,
  stopPropagation,
  isPropagationStopped,
  isTrusted: option(bool),
  nativeEvent: 'a,
  persist,
  target: option(float),
  timeStamp: float,
  _type: option(string),
  // responderSyntheticEvent additional key
  touchHistory,
}
and touchHistory = {
  indexOfSingleActiveTouch: float,
  mostRecentTimeStamp: float,
  numberActiveTouches: float,
  touchBank: array(touchBank),
}
and touchBank = {
  touchActive: bool,
  startPageX: float,
  startPageY: float,
  startTimeStamp: float,
  currentPageX: float,
  currentPageY: float,
  currentTimeStamp: float,
  previousPageX: float,
  previousPageY: float,
  previousTimeStamp: float,
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

/*
 // previously. not sure about this conversion.
 type switchChangeEvent = syntheticEvent({. "value": bool});

 type targetEvent = syntheticEvent({. "target": int}); */
type switchChangeEventParam = {value: bool};
type switchChangeEvent = syntheticEvent(switchChangeEventParam);
type targetEventParams = {target: int};
type targetEvent = syntheticEvent(targetEventParams);
