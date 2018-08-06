type makeContent;
type makeOptions;
type title = string;
type message = string;
type url = string;
type content =
  | Message(message, option(title))
  | URL(url, option(title));
let makeContent:
  (~title: string=?, ~message: string, ~url: string) => makeContent;
let makeOptions:
  (
    ~subject: string=?,
    ~tintColor: string=?,
    ~excludedActivityTypes: array(string)=?,
    ~dialogTitle: string=?
  ) =>
  makeOptions;
let _share: (makeContent, makeOptions) => Js.Promise.t(bool);
let share:
  (
    ~content: content,
    ~subject: string=?,
    ~tintColor: string=?,
    ~excludedActivityTypes: array(string)=?,
    ~dialogTitle: string=?,
    unit
  ) =>
  Js.Promise.t(bool);