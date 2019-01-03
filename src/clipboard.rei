/**
[Clipboard] gives you an interface for setting and getting content from Clipboard on both iOS and Android

You can read more on [Clipboard] API usage in official docs: {{:https://facebook.github.io/react-native/docs/alert}}

{3 Example of use }
{4 setString }
{[
  Clipboard.setString("Let's save some text to clipboard.");
]}
{4 getString }
{[
  Clipboard.getString()
    |> Js.Promise.then_(text => Js.Promise.resolve(Js.log(text)))
    |> ignore;
]}
{3 Function parameters }
{4 getString }
{[
  unit => Js.Promise.t(string);
]}
{4 setString }
{[
  string => unit;
]}
*/

let getString: unit => Js.Promise.t(string);

let setString: string => unit;
