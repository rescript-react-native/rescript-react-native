/**

You can read more on [Dimensions] API usage in official docs: {{:https://facebook.github.io/react-native/docs/dimensions}}

{3 Example of use }
{4 get(`window) }
{[
  let windowDimensions = Dimensions.get(`window);
  Js.log(windowDimensions##width);
  Js.log(windowDimensions##height);
  Js.log(windowDimensions##scale);
  Js.log(windowDimensions##fontScale);
]}
{4 get(`screen) }
{[
  let screenDimensions = Dimensions.get(`screen);
  Js.log(screenDimensions##width);
  Js.log(screenDimensions##height);
  Js.log(screenDimensions##scale);
  Js.log(screenDimensions##fontScale);
]}
{4 addEventListener and removeEventListener }
{[
  let handler = dimensions => Js.log(dimensions##screen##width);

  Dimensions.addEventListener("change", handler);
  Dimensions.removeEventListener("change", handler);
]}
{3 Function parameters }
{4 get }
{[
  [< | `screen | `window] => dimensions
]}
reference:

{[

type dimensions = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};

]}

{4 addEventListener }
{[
  (
    string,
    {
      .
      "screen": dimensions,
      "window": dimensions,
    } => unit
  ) => unit
]}
reference:

{[

  type dimensions = {
    .
    "width": int,
    "height": int,
    "scale": float,
    "fontScale": float,
  };
]}

{4 removeEventListener }
{[
  (
    string,
    {
      .
      "screen": dimensions,
      "window": dimensions,
    } => unit
  ) => unit
]}

reference:
{[

type dimensions = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};

]}
*/

type dimensions = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};

let get: [< | `screen | `window] => dimensions;

[@bs.scope "Dimensions"] [@bs.module "react-native"]
external addEventListener:
  (
    string,
    {
      .
      "screen": dimensions,
      "window": dimensions,
    } =>
    unit
  ) =>
  unit =
  "";

[@bs.scope "Dimensions"] [@bs.module "react-native"]
external removeEventListener:
  (
    string,
    {
      .
      "screen": dimensions,
      "window": dimensions,
    } =>
    unit
  ) =>
  unit =
  "";
