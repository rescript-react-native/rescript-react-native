let share:
  (
    ~content: [< `text(string) | `url(string)],
    ~title: string=?,
    ~subject: string=?,
    ~tintColor: string=?,
    ~excludedActivityTypes: array(string)=?,
    ~dialogTitle: string=?,
    unit
  ) =>
  Js.Promise.t(bool);
