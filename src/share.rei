/**
You can read more on [Share] API usage in official docs: {{:https://facebook.github.io/react-native/docs/share}}

{3 Example of use }
{[
  Share.share(
    ~content=URL("https://callstack.com", Some("Callstack Home Page")),
    (),
  );
]}
{[
  Share.share(
    ~content=Message("Sharing something", Some("The title for my message")),
    (),
  );
]}

{3 Function parameters }
{4 content }
{[ content: content ]}
reference:

{[
type content =
  | Message(message, option(title))
  | URL(url, option(title));
]}
{4 subject }
{[ subject: string=? ]}

{4 tintColor }
{[ tintColor: string=? ]}
{4 excludedActivityTypes }
{[ excludedActivityTypes: array(string)=? ]}
{4 dialogTitle }
{[ dialogTitle: string=? ]}
{4 non-labeled argument }
{[ unit ]}

*/

let share:
  (
    ~content: [< | `text(string) | `url(string)],
    ~title: string=?,
    ~subject: string=?,
    ~tintColor: string=?,
    ~excludedActivityTypes: array(string)=?,
    ~dialogTitle: string=?,
    unit
  ) =>
  Js.Promise.t(bool);
