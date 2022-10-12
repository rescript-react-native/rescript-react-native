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

@obj @deprecated("Directly create record instead")
external parallax: (
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
