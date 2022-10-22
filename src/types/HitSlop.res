type t = {
  left?: float,
  right?: float,
  top?: float,
  bottom?: float,
}

// hitSlop prop accept number and edge inset object
@obj // @deprecated("Directly create record instead")
external rect: (~left: float=?, ~right: float=?, ~top: float=?, ~bottom: float=?, unit) => t = ""

external float: float => t = "%identity"
