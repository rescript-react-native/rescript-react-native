// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

type syntheticEvent('a, 'b) = {
  bubbles: Js.Nullable.t(bool),
  cancelable: Js.Nullable.t(bool),
  currentTarget: float,
  defaultPrevented: Js.Nullable.t(bool),
  dispatchConfig: registrationName,
  eventPhase: Js.Nullable.t(float),
  isTrusted: Js.Nullable.t(bool),
  nativeEvent: 'a,
  target: Js.Nullable.t(float),
  timeStamp: float,
  [@bs.as "type"]
  _type: Js.Nullable.t(string),
  touchHistory: 'b // this field can be omitted, making 'b a phantom type
}
and registrationName = {registrationName: string};

// type responderSyntheticEvent('a) defined as type syntheticEvent('a, touchHistory)

type touchHistory = {
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

[@bs.get] [@bs.return nullable]
external bubbles: syntheticEvent('a, 'b) => option(bool) = "bubbles";
[@bs.get] [@bs.return nullable]
external cancelable: syntheticEvent('a, 'b) => option(bool) = "cancelable";
[@bs.get]
external currentTarget: syntheticEvent('a, 'b) => float = "currentTarget";
[@bs.get] [@bs.return nullable]
external defaultPrevented: syntheticEvent('a, 'b) => option(bool) =
  "defaultPrevented";
[@bs.get]
external dispatchConfig: syntheticEvent('a, 'b) => registrationName =
  "dispatchConfig";
[@bs.get] [@bs.return nullable]
external eventPhase: syntheticEvent('a, 'b) => option(float) = "eventPhase";
[@bs.send]
external preventDefault: syntheticEvent('a, 'b) => unit = "preventDefault";
[@bs.send]
external isDefaultPrevented: syntheticEvent('a, 'b) => bool =
  "isDefaultPrevented";
[@bs.send]
external stopPropagation: syntheticEvent('a, 'b) => unit = "stopPropagation";
[@bs.send]
external isPropagationStopped: syntheticEvent('a, 'b) => bool =
  "isPropagationStopped";
[@bs.get] [@bs.return nullable]
external isTrusted: syntheticEvent('a, 'b) => option(bool) = "isTrusted";
[@bs.get] external nativeEvent: syntheticEvent('a, 'b) => 'a = "nativeEvent";
[@bs.send] external persist: syntheticEvent('a, 'b) => unit = "persist";
[@bs.get] [@bs.return nullable]
external target: syntheticEvent('a, 'b) => option(float) = "target";
[@bs.get] external timeStamp: syntheticEvent('a, 'b) => float = "timeStamp";
[@bs.get] [@bs.return nullable]
external _type: syntheticEvent('a, 'b) => option(string) = "type";
[@bs.get]
external touchHistory: syntheticEvent('a, touchHistory) => touchHistory =
  "touchHistory";

module TextLayout = {
  type line = {
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
  type t = {lines: array(line)};
};

module Layout = {
  type t = {
    x: float,
    y: float,
    width: float,
    height: float,
  };
};

module LayoutEvent = {
  type layout = Layout.t;
  type t = {layout};
};

type layout = LayoutEvent.t;
type layoutEvent = syntheticEvent(layout, unit);

type textLayout = TextLayout.line;
type textLayouts = TextLayout.t;
type textLayoutEvent = syntheticEvent(textLayouts, unit);

module PressEvent = {
  type t = {
    changedTouches: array(t),
    force: float,
    identifier: int,
    locationX: float,
    locationY: float,
    pageX: float,
    pageY: float,
    target: Js.Nullable.t(float),
    timestamp: float,
    touches: array(t),
  };
};
type pressEventPayload = PressEvent.t;
type pressEvent = syntheticEvent(pressEventPayload, touchHistory);

module Dimensions = {
  type t = {
    height: float,
    width: float,
  };
};

type dimensions = Dimensions.t;

module ScrollEvent = {
  type contentOffset = {
    x: float,
    y: float,
  };

  type contentInset = {
    bottom: float,
    left: float,
    right: float,
    top: float,
  };

  type t = {
    contentInset: contentOffset,
    contentOffset: contentInset,
    contentSize: dimensions,
    layoutMeasurement: dimensions,
  };
};

type contentOffset = ScrollEvent.contentOffset;
type contentInset = ScrollEvent.contentInset;
type scrollEventPayload = ScrollEvent.t;
type scrollEvent = syntheticEvent(scrollEventPayload, unit);

module SwitchChangePayload = {
  type t = {value: bool};
};

type switchChangePayload = SwitchChangePayload.t;
type switchChangeEvent = syntheticEvent(switchChangePayload, unit);

module TargetEvent = {
  type t = {target: int};
};

type targetPayload = TargetEvent.t;
type targetEvent = syntheticEvent(targetPayload, unit);
