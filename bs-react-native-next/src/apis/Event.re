type t;

module NativeEvent = {
  type t;
  [@bs.get] external changedTouches: t => array(Js.t({..})) = "";
  [@bs.get] external identifier: t => int = "";
  [@bs.get] external locationX: t => float = "";
  [@bs.get] external locationY: t => float = "";
  [@bs.get] external pageX: t => float = "";
  [@bs.get] external pageY: t => float = "";
  [@bs.get] external target: t => Js.t({..}) = "";
  [@bs.get] external touches: t => array(Js.t({..})) = "";
  [@bs.get] external timestamp: t => int = "";
  [@bs.get] external data: t => string = "";
};

/*
 fixme rename NativeEvent to NativePressEvent when necessary
 see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js
 */
module NativePressEvent = NativeEvent;

module NativeLayoutEvent = {
  type t;
  [@bs.get] external x: t => float = "";
  [@bs.get] external y: t => float = "";
  [@bs.get] external width: t => float = "";
  [@bs.get] external height: t => float = "";
};

module NativeScrollEvent = {
  type t;

  module ContentInset = {
    type t;

    [@bs.get] external bottom: t => float = "";
    [@bs.get] external left: t => float = "";
    [@bs.get] external right: t => float = "";
    [@bs.get] external top: t => float = "";
  };

  module ContentOffset = {
    type t;

    [@bs.get] external y: t => float = "";
    [@bs.get] external x: t => float = ""
  };
  
  module ContentSize = {
    type t;

    [@bs.get] external height: t => float = "";
    [@bs.get] external width: t => float = "";
  };

  module LayoutMeasurement = {
    type t;

    [@bs.get] external height: t => float = "";
    [@bs.get] external width: t => float = "";
  };
  
  [@bs.get] external contentInset: t => ContentInset.t = "";
  [@bs.get] external contentOffset: t => ContentOffset.t = "";
  [@bs.get] external contentSize: t => ContentSize.t = "";
  [@bs.get] external layoutMeasurement: t => LayoutMeasurement.t = "";
};

[@bs.get] external nativeEvent: t => NativeEvent.t = "";

[@bs.get] external nativeLayoutEvent: t => NativeLayoutEvent.t = "nativeEvent";

[@bs.get] external nativeScrollEvent: t => NativeScrollEvent.t = "nativeEvent";
