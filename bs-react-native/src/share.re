type content;
type options;

[@bs.obj]
external makeContent:
  (~title: string=?, ~message: string=?, ~url: string=?, unit) => content =
  "";

[@bs.obj]
external makeOptions:
  (
    ~subject: string=?,
    ~tintColor: string=?,
    ~excludedActivityTypes: array(string)=?,
    ~dialogTitle: string=?
  ) =>
  options =
  "";

[@bs.module "react-native"] [@bs.scope "Share"]
external _share: (content, options) => Js.Promise.t(bool) = "share";

let share =
    (
      ~content,
      ~title=?,
      ~subject=?,
      ~tintColor=?,
      ~excludedActivityTypes=?,
      ~dialogTitle=?,
      (),
    ) =>
  switch (content) {
  | `text(message) =>
    _share(
      makeContent(~message, ~title?, ()),
      makeOptions(
        ~subject?,
        ~tintColor?,
        ~excludedActivityTypes?,
        ~dialogTitle?,
      ),
    )
  | `url(url) =>
    _share(
      makeContent(~url, ~title?, ()),
      makeOptions(
        ~subject?,
        ~tintColor?,
        ~excludedActivityTypes?,
        ~dialogTitle?,
      ),
    )
  };
