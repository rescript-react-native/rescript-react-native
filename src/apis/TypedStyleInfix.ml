external%private ofArray : 'a Style.typed_t array -> 'a Style.typed_t
  = "%identity"

let ( ^ ) a b = ofArray [| a; b |]
