type t = {
  left: option<float>,
  right: option<float>,
  top: option<float>,
  bottom: option<float>,
}

// hitSlop prop accept number and edge inset object
external rect: (~left: float=?, ~right: float=?, ~top: float=?, ~bottom: float=?, unit) => t = ""
// @todo in 0.70
// external float: float => t = ""
let float = (value: float) => {
  left: Some(value),
  right: Some(value),
  top: Some(value),
  bottom: Some(value),
}
