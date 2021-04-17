open Ppxlib

let () =
  Driver.register_transformation
    ~rules:[ Style.rule; Stylesheet.rule ]
    ~impl:Stylesheet.impl "rn"
