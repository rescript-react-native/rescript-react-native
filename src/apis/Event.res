// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

type registrationName = {registrationName: string}

// Synthetic event received by event handlers, generic over its `nativeEvent` payload.
// Fields are typed as they are while the handler runs: on the legacy event pooling path,
// reading them later (without `persist`) is a runtime error by design.
type syntheticEvent<'payload> = {
  bubbles: option<bool>,
  cancelable: option<bool>,
  // the native element the handler is attached to
  currentTarget: DOMAPI.anyElement,
  defaultPrevented: option<bool>,
  dispatchConfig: registrationName,
  eventPhase: option<float>,
  isTrusted: option<bool>,
  nativeEvent: 'payload,
  target: nullable<DOMAPI.anyElement>,
  timeStamp: float,
  \"type": option<string>,
}

type touchHistory = {
  indexOfSingleActiveTouch: float,
  mostRecentTimeStamp: float,
  numberActiveTouches: float,
  touchBank: array<
    {
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
    },
  >,
}

// Synthetic event of the responder system (`PressEvent`, `onResponder*`, …)
type responderSyntheticEvent<'payload> = {
  ...syntheticEvent<'payload>,
  touchHistory: touchHistory,
}

// Methods of `syntheticEvent` (included by `SyntheticEvent`)
module Methods = {
  @get @return(nullable)
  external bubbles: syntheticEvent<'payload> => option<bool> = "bubbles"
  @get @return(nullable)
  external cancelable: syntheticEvent<'payload> => option<bool> = "cancelable"
  @get external currentTarget: syntheticEvent<'payload> => DOMAPI.anyElement = "currentTarget"
  @get @return(nullable)
  external defaultPrevented: syntheticEvent<'payload> => option<bool> = "defaultPrevented"
  @get
  external dispatchConfig: syntheticEvent<'payload> => registrationName = "dispatchConfig"
  @get @return(nullable)
  external eventPhase: syntheticEvent<'payload> => option<float> = "eventPhase"
  @send external preventDefault: syntheticEvent<'payload> => unit = "preventDefault"
  @send
  external isDefaultPrevented: syntheticEvent<'payload> => bool = "isDefaultPrevented"
  @send external stopPropagation: syntheticEvent<'payload> => unit = "stopPropagation"
  @send
  external isPropagationStopped: syntheticEvent<'payload> => bool = "isPropagationStopped"
  @get @return(nullable)
  external isTrusted: syntheticEvent<'payload> => option<bool> = "isTrusted"
  @get external nativeEvent: syntheticEvent<'payload> => 'payload = "nativeEvent"
  @send external persist: syntheticEvent<'payload> => unit = "persist"
  @get @return(nullable)
  external target: syntheticEvent<'payload> => option<DOMAPI.anyElement> = "target"
  @get external timeStamp: syntheticEvent<'payload> => float = "timeStamp"
  @get @return(nullable)
  external _type: syntheticEvent<'payload> => option<string> = "type"
}

// Methods of `responderSyntheticEvent` (included by `ResponderSyntheticEvent`)
module ResponderMethods = {
  @get @return(nullable)
  external bubbles: responderSyntheticEvent<'payload> => option<bool> = "bubbles"
  @get @return(nullable)
  external cancelable: responderSyntheticEvent<'payload> => option<bool> = "cancelable"
  @get
  external currentTarget: responderSyntheticEvent<'payload> => DOMAPI.anyElement = "currentTarget"
  @get @return(nullable)
  external defaultPrevented: responderSyntheticEvent<'payload> => option<bool> = "defaultPrevented"
  @get
  external dispatchConfig: responderSyntheticEvent<'payload> => registrationName = "dispatchConfig"
  @get @return(nullable)
  external eventPhase: responderSyntheticEvent<'payload> => option<float> = "eventPhase"
  @send external preventDefault: responderSyntheticEvent<'payload> => unit = "preventDefault"
  @send
  external isDefaultPrevented: responderSyntheticEvent<'payload> => bool = "isDefaultPrevented"
  @send external stopPropagation: responderSyntheticEvent<'payload> => unit = "stopPropagation"
  @send
  external isPropagationStopped: responderSyntheticEvent<'payload> => bool = "isPropagationStopped"
  @get @return(nullable)
  external isTrusted: responderSyntheticEvent<'payload> => option<bool> = "isTrusted"
  @get external nativeEvent: responderSyntheticEvent<'payload> => 'payload = "nativeEvent"
  @send external persist: responderSyntheticEvent<'payload> => unit = "persist"
  @get @return(nullable)
  external target: responderSyntheticEvent<'payload> => option<DOMAPI.anyElement> = "target"
  @get external timeStamp: responderSyntheticEvent<'payload> => float = "timeStamp"
  @get @return(nullable)
  external _type: responderSyntheticEvent<'payload> => option<string> = "type"
  @get external touchHistory: responderSyntheticEvent<'payload> => touchHistory = "touchHistory"
}

// Defines `t` and the event methods for a payload.
// Public API for event modules, here and in third-party bindings:
//
//   module MyEvent = {
//     type payload = {...}
//     include Event.SyntheticEvent({type _payload = payload})
//   }
module SyntheticEvent = (
  T: {
    type _payload
  },
) => {
  type t = syntheticEvent<T._payload>
  include Methods
}

// Same as `SyntheticEvent`, for events of the responder system
module ResponderSyntheticEvent = (
  T: {
    type _payload
  },
) => {
  type t = responderSyntheticEvent<T._payload>
  include ResponderMethods
}

module BlurEvent = {
  type payload = {target: float}
  include SyntheticEvent({type _payload = payload})
}
module FocusEvent = {
  type payload = {target: float}
  include SyntheticEvent({type _payload = payload})
}

module LayoutEvent = {
  type payload = {layout: Layout.rectangle}

  include SyntheticEvent({type _payload = payload})
}

module TextLayoutEvent = {
  type payload = {
    lines: array<
      {
        ...Layout.rectangle,
        ascender: float, // verify
        capHeight: float, // verify
        descender: float, // verify
        text: string,
        xHeight: float, // verify
      },
    >,
  }

  include SyntheticEvent({type _payload = payload})
}

module PressEvent = {
  type rec payload = {
    changedTouches: array<payload>,
    force: float,
    identifier: int,
    locationX: float,
    locationY: float,
    pageX: float,
    pageY: float,
    target: nullable<float>,
    timestamp: float,
    touches: array<payload>,
  }

  include ResponderSyntheticEvent({type _payload = payload})
}

module ScrollEvent = {
  type payload = {
    contentInset: Layout.insets,
    contentOffset: Layout.point,
    contentSize: Layout.size,
    layoutMeasurement: Layout.size,
  }

  include SyntheticEvent({type _payload = payload})
}

module SwitchChangeEvent = {
  type payload = {value: bool}

  include SyntheticEvent({type _payload = payload})
}

module TargetEvent = {
  type payload = {target: int}

  include SyntheticEvent({type _payload = payload})
}

module PointerEvent = {
  @unboxed
  type pointerType =
    | @as("mouse") Mouse
    | @as("pen") Pen
    | @as("touch") Touch
    | Other(string)

  type payload = {
    // UIEvent
    detail: float,
    // MouseEvent
    screenX: float,
    screenY: float,
    pageX: float,
    pageY: float,
    clientX: float,
    clientY: float,
    x: float,
    y: float,
    ctrlKey: bool,
    shiftKey: bool,
    altKey: bool,
    metaKey: bool,
    button: float,
    buttons: float,
    relatedTarget: nullable<float>,
    offsetX: float,
    offsetY: float,
    // PointerEvent
    pointerId: float,
    width: float,
    height: float,
    pressure: float,
    tangentialPressure: float,
    tiltX: float,
    tiltY: float,
    twist: float,
    pointerType: pointerType,
    isPrimary: bool,
  }

  include SyntheticEvent({type _payload = payload})
}

type blurEvent = BlurEvent.t
type focusEvent = FocusEvent.t
type layoutEvent = LayoutEvent.t
type pressEvent = PressEvent.t
type scrollEvent = ScrollEvent.t
type switchChangeEvent = SwitchChangeEvent.t
type targetEvent = TargetEvent.t
type textLayoutEvent = TextLayoutEvent.t
type pointerEvent = PointerEvent.t
