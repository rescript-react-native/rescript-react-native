/*
 `ErrorUtils` global, installed by React Native
 */

// receives the error (usually a JS `Error`, but anything can be thrown) and `isFatal`
type handler = (JsExn.t, bool) => unit

@val @scope("ErrorUtils")
external setGlobalHandler: handler => unit = "setGlobalHandler"

@val @scope("ErrorUtils")
external getGlobalHandler: unit => handler = "getGlobalHandler"

@val @scope("ErrorUtils")
external reportError: JsExn.t => unit = "reportError"

@val @scope("ErrorUtils")
external reportFatalError: JsExn.t => unit = "reportFatalError"
