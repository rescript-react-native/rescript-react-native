/**
You can read more on [ToastAndroid] API usage in official docs: {{:https://facebook.github.io/react-native/docs/toastandroid}}

ToastAndroid module provides simple feedback in the small popup.

{3 Example of use }
{4 default }
{[ ToastAndroid.show("A pikachu appeared nearby !", ToastAndroid.SHORT); ]}
{4 show with gravity }
{[
  ToastAndroid.showWithGravity(
    "All Your Base Are Belong To Us",
    ToastAndroid.SHORT,
    ToastAndroid.CENTER
  );
]}

{4 show with gravity and add offset }

{[
  ToastAndroid.showWithGravityAndOffset(
    "A wild toast appeared!",
    ToastAndroid.LONG,
    ToastAndroid.BOTTOM,
    25,
    50
  );
]}
{3 Methods }
{4 show }
{[
  type duration =
  | BOTTOM
  | CENTER;
  | LONG
  | SHORT
  | TOP

  (string, duration) => unit;
]}

{4 showWithGravity }
{[
type gravity =
  | BOTTOM
  | CENTER;
  | TOP

let showWithGravity: (string, duration, gravity) => unit;
]}

{4 showGravityAndOffset }
{[
type gravity =
 | BOTTOM
 | CENTER;
 | TOP

let showWithGravityAndOffset: (string, duration, gravity, int, int) => unit;
]}
{3 Properties }
- BOTTOM
  {[ ToastAndroid.BOTTOM ]}
- CENTER
  {[ ToastAndroid.CENTER ]}
- LONG
  {[ ToastAndroid.LONG ]}
- SHORT
  {[ ToastAndroid.SHORT ]}
- TOP
  {[ ToastAndroid.TOP ]}
*/

type duration =
  | LONG
  | SHORT;

type gravity =
  | BOTTOM
  | CENTER
  | TOP;

let show:
  (
    string,
    ~duration: duration,
    ~gravity: gravity=?,
    ~offset: (int, int)=?,
    unit
  ) =>
  unit;
