type makeContent;
type makeOptions;
type title = string;
type message = string;
type url = string;
type content =
  | Message(message, option(title))
  | URL(url, option(title));

[@bs.obj]
external makeContent :
  (~title: string=?, ~message: string, ~url: string) => makeContent =
  "";
[@bs.obj]
external makeOptions :
  (
    ~subject: string=?,
    ~tintColor: string=?,
    ~excludedActivityTypes: array(string)=?,
    ~dialogTitle: string=?
  ) =>
  makeOptions =
  "";

[@bs.module "react-native"] [@bs.scope "Share"]
external _share : (makeContent, makeOptions) => Js.Promise.t(bool) = "share";

let share =
    (
      ~content,
      ~subject=?,
      ~tintColor=?,
      ~excludedActivityTypes=?,
      ~dialogTitle=?,
      (),
    ) =>
  switch (content) {
  | Message(message, title) =>
    _share(
      makeContent(~message, ~title?, ~url=""),
      makeOptions(
        ~subject?,
        ~tintColor?,
        ~excludedActivityTypes?,
        ~dialogTitle?,
      ),
    )
  | URL(url, title) =>
    _share(
      makeContent(~url, ~title?, ~message=""),
      makeOptions(
        ~subject?,
        ~tintColor?,
        ~excludedActivityTypes?,
        ~dialogTitle?,
      ),
    )
  };