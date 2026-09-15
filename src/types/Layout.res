type point = {
  x: float,
  y: float,
}

type size = {
  width: float,
  height: float,
}

type rectangle = {
  ...point,
  ...size,
}

type insets = {
  top: float,
  left: float,
  bottom: float,
  right: float,
}
