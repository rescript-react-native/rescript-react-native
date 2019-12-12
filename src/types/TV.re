type parallax = {
  shiftDistanceX: float,
  shiftDistanceY: float,
  tiltAngle: float,
  magnification: float,
  pressMagnification: float,
  pressDuration: float,
  pressDelay: float,
};

let parallaxDefault: parallax = true->Obj.magic;
