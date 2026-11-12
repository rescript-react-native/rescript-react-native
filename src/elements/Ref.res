// Type of the `ref` prop: an object ref, as returned by `React.useRef(Nullable.null)`
// or the typed `useRef` of each element module (`TextInput.useRef()`)
type t<'element> = React.ref<nullable<'element>>

// React also accepts a callback for the `ref` prop
type callbackRef<'element> = nullable<'element> => unit
external callback: callbackRef<'element> => t<'element> = "%identity"

// React 19: a callback ref can return a cleanup function, called when the element
// is detached (the callback is then never called with `null`)
external callbackWithCleanup: ('element => unit => unit) => t<'element> = "%identity"

@deprecated("An object ref is already a `Ref.t`, use `Ref.t` instead.")
type valueRef<'element> = t<'element>

@deprecated("An object ref is already a `Ref.t`, pass it directly: `ref=myRef`.")
external value: t<'element> => t<'element> = "%identity"
