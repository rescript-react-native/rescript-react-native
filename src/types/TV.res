type parallax = {
  enabled?: bool,
  shiftDistanceX?: float,
  shiftDistanceY?: float,
  tiltAngle?: float,
  magnification?: float,
  pressMagnification?: float,
  pressDuration?: float,
  pressDelay?: float,
}

@obj
external // @deprecated("Directly create record instead")
parallax: (
  ~enabled: bool=?,
  ~shiftDistanceX: float=?,
  ~shiftDistanceY: float=?,
  ~tiltAngle: float=?,
  ~magnification: float=?,
  ~pressMagnification: float=?,
  ~pressDuration: float=?,
  ~pressDelay: float=?,
  unit,
) => parallax = ""
