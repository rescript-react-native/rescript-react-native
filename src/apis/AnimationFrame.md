---
id: apis/AnimationFrame
title: AnimationFrame
autoLinkToOfficialDoc: false
---

## `request`

`AnimationFrame.request` is just the well known
[`requestAnimationFrame`](https://developer.mozilla.org/en-US/docs/Web/API/window/requestAnimationFrame).

[In React Native, `requestAnimationFrame` has been polyfilled](https://reactnative.dev/docs/timers#timers)
from the browser. It accepts a function as its only argument and calls that
function before the next repaint.

Note that calback doesn't receive an argument unlike the
`window.requestAnimationFrame` implementation.

This method returns a `requestID` so you can cancel if needed. If you don't need
it, you can just `ignore` the result.

```reason
AnimationFrame.request(() => {
  // do whatever you need on next paint
})->ignore;
```

## `cancel`

`AnimationFrame.cancel` method cancels an animation frame request previously
scheduled. It's just calling
[`cancelAnimationFrame`](https://developer.mozilla.org/en-US/docs/Web/API/window/cancelAnimationFrame).

```reason
let requestID = AnimationFrame.request(() => {
  // do whatever you need on next paint
});

// elsewhere or later
if (whatever) {
  AnimationFrame.cancel(requestID);
};
```
