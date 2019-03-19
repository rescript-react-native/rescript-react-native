/**
The Vibration API is exposed at [Vibration.vibrate()]. The vibration is asynchronous so this method will return immediately.

You can read more on [Vibration] API usage in official docs: {{:https://facebook.github.io/react-native/docs/vibration}}

{3 Methods }
{4 vibrate }
Trigger vibration with specific pattern by providing array of numbers Default to 400ms.
{[
  let vibrate: (~pattern: array(int), ~repeat: bool) => unit;
]}
{4 cancel}
Cancel vibration
{[
  let cancel: unit => unit;
]}
*/

let vibrate: (~pattern: array(int), ~repeat: bool) => unit;

let cancel: unit => unit;
