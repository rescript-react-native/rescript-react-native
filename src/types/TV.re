type parallax;

[@bs.obj]
external parallax:
  (
    ~shiftDistanceX: float,
    ~shiftDistanceY: float,
    ~tiltAngle: float,
    ~magnification: float,
    ~pressMagnification: float,
    ~pressDuration: float,
    ~pressDelay: float,
    unit
  ) =>
  parallax;

let parallaxDefault: parallax = true->Obj.magic;
