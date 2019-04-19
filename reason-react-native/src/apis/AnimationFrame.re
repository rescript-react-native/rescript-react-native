type requestID;

[@bs.val]
external request: (unit => unit) => requestID = "requestAnimationFrame";
[@bs.val] external cancel: requestID => unit = "cancelAnimationFrame";
