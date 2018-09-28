type response = {
  year: int,
  month: int,
  day: int,
};

type action =
  | Dismissed
  | Set(response);

type mode = [ | `calendar | `spinner | `default];

let open_:
  (
    ~date: Js.Date.t,
    ~minDate: Js.Date.t=?,
    ~maxDate: Js.Date.t=?,
    ~mode: mode=?,
    unit
  ) =>
  Js.Promise.t(action);
