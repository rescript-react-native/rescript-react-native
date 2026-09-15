type t<'element>

type valueRef<'element> = React.ref<nullable<'element>>
type callbackRef<'element> = nullable<'element> => unit

external value: valueRef<'element> => t<'element> = "%identity"
external callback: callbackRef<'element> => t<'element> = "%identity"
