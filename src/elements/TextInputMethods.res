// Methods of text input elements (`[> #textInput]`)

@send external isFocused: DOMAPI.element<[> #textInput]> => bool = "isFocused"
@send external clear: DOMAPI.element<[> #textInput]> => unit = "clear"
@send external setSelection: (DOMAPI.element<[> #textInput]>, int, int) => unit = "setSelection"
