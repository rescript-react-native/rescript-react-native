// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

module EventMethods = (T: {
                         type target('a);
                         type r;
                       }) => {
  [@bs.get] [@bs.return nullable]
  external bubbles: T.target('a) => option(bool) = "bubbles";
  [@bs.get] [@bs.return nullable]
  external cancelable: T.target('a) => option(bool) = "cancelable";
  [@bs.get] external currentTarget: T.target('a) => float = "currentTarget";
  [@bs.get] [@bs.return nullable]
  external defaultPrevented: T.target('a) => option(bool) =
    "defaultPrevented";
  [@bs.get] external dispatchConfig: T.target('a) => T.r = "dispatchConfig";
  [@bs.get] [@bs.return nullable]
  external eventPhase: T.target('a) => option(float) = "eventPhase";
  [@bs.send] external preventDefault: T.target('a) => unit = "preventDefault";
  [@bs.send]
  external isDefaultPrevented: T.target('a) => bool = "isDefaultPrevented";
  [@bs.send]
  external stopPropagation: T.target('a) => unit = "stopPropagation";
  [@bs.send]
  external isPropagationStopped: T.target('a) => bool =
    "isPropagationStopped";
  [@bs.get] [@bs.return nullable]
  external isTrusted: T.target('a) => option(bool) = "isTrusted";
  [@bs.get] external nativeEvent: T.target('a) => 'a = "nativeEvent";
  [@bs.send] external persist: T.target('a) => unit = "persist";
  [@bs.get] [@bs.return nullable]
  external target: T.target('a) => option(float) = "target";
  [@bs.get] external timeStamp: T.target('a) => float = "timeStamp";
  [@bs.get] [@bs.return nullable]
  external _type: T.target('a) => option(string) = "type";
};

module SyntheticEvent = {
  type t_('a) = {
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
  }
  and registrationName = {registrationName: string};

  include EventMethods({
    type target('a) = t_('a);
    type r = registrationName;
  });
};

module ResponderSyntheticEvent = {
  type t_('a) = {
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
    touchHistory,
  }
  and registrationName = {registrationName: string}
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

  include EventMethods({
    type target('a) = t_('a);
    type r = registrationName;
  });

  [@bs.get] external touchHistory: t_('a) => touchHistory = "touchHistory";
};

module LayoutEvent = {
  include SyntheticEvent;

  type t = t_(payload)
  and payload = {layout}
  and layout = {
    x: float,
    y: float,
    width: float,
    height: float,
  };
};

module TextLayoutEvent = {
  include SyntheticEvent;

  type t = t_(payload)
  and payload = {lines: array(line)}
  and line = {
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
};

module PressEvent = {
  include ResponderSyntheticEvent;

  type t = t_(payload)
  and payload = {
    changedTouches: array(payload),
    force: float,
    identifier: int,
    locationX: float,
    locationY: float,
    pageX: float,
    pageY: float,
    target: Js.Nullable.t(float),
    timestamp: float,
    touches: array(payload),
  };
};

module ScrollEvent = {
  include SyntheticEvent;

  type t = t_(payload)
  and payload = {
    contentInset: contentOffset,
    contentOffset: contentInset,
    contentSize: dimensions,
    layoutMeasurement: dimensions,
  }
  and contentOffset = {
    x: float,
    y: float,
  }
  and contentInset = {
    bottom: float,
    left: float,
    right: float,
    top: float,
  }
  and dimensions = {
    height: float,
    width: float,
  };
};

module SwitchChangeEvent = {
  include SyntheticEvent;

  type t = t_(payload)
  and payload = {value: bool};
};

module TargetEvent = {
  include SyntheticEvent;

  type t = t_(payload)
  and payload = {target: int};
};

type layoutEvent = LayoutEvent.t;
type textLayoutEvent = TextLayoutEvent.t;
type pressEvent = PressEvent.t;
type scrollEvent = ScrollEvent.t;
type switchChangeEvent = SwitchChangeEvent.t;
type targetEvent = TargetEvent.t;
