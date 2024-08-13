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

@deprecated("Directly create record instead") @obj
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
