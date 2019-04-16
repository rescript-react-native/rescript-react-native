---
id: apis/Event
title: Event
wip: true
---

```reason
// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

type event('a) = {. "nativeEvent": 'a};

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
  "touches": array(pressEventPayload)
};

type pressEvent = event(pressEventPayload);

type t;

module NativeLayoutEvent = {
  type t;
  type layout = {
    x: float,
    y: float,
    width: float,
    height: float,
  };
  [@bs.get] external _layout: t => Js.t('a) = "nativeEvent";
  let layout = (t: t) => {
    let l = _layout(t)##layout;
    {x: l##x, y: l##y, width: l##width, height: l##height};
  };
};

module NativeScrollEvent = {
  type t;
  type point = {
    x: float,
    y: float,
  };
  type size = {
    width: float,
    height: float,
  };
  type contentInset = {
    bottom: float,
    top: float,
    left: float,
    right: float,
  };
  [@bs.get] external _nativeEvent: t => Js.t('a) = "nativeEvent";
  let contentOffset = (t: t) => {
    let co = _nativeEvent(t)##contentOffset;
    {x: co##x, y: co##y};
  };
  let contentSize = (t: t) => {
    let cs = _nativeEvent(t)##contentSize;
    {width: cs##width, height: cs##height};
  };
  let layoutMeasurement = (t: t) => {
    let lm = _nativeEvent(t)##layoutMeasurement;
    {width: lm##width, height: lm##height};
  };
  let contentInset = (t: t) => {
    let ci = _nativeEvent(t)##contentInset;
    {bottom: ci##bottom, top: ci##top, left: ci##left, right: ci##right};
  };
};

[@bs.get] external nativeLayoutEvent: t => NativeLayoutEvent.t = "nativeEvent";

[@bs.get] external nativeScrollEvent: t => NativeScrollEvent.t = "nativeEvent";

```
