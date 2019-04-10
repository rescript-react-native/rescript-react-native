/**
A StyleSheet is an abstraction similar to CSS StyleSheets

You can read more on [Stylesheet] API usage in official docs: {{:https://facebook.github.io/react-native/docs/stylesheet}}

{3 Example of use }
{[
  let styles =
  StyleSheet.create(
    Style.{
      "box":
        style([
          backgroundColor(String("#527FE4")),
          borderColor(String("#000033")),
          borderWidth(1.),
        ]),
      "zIndex":
        style([
          justifyContent(SpaceAround),
          width(Pt(100.)),
          height(Pt(50.)),
          marginTop(Pt(-10.)),
        ]),
    },
  );
]}
{3 Methods}
{4 create}
{[
  let create: Js.t('a) => Js.t('a);
]}
{4 flatten}
{[
  let flatten: list(Style.t) => Style.t;
]}
{4 processColor}
{[
  let processColor: [ | `String(string) | `Number(int)] => string;
]}

{3 Utils}
{4 hairlineWidth}
This constant will always be a round number of pixels (so a line defined by it can look crisp) and will try to match the standard width of a thin line on the underlying platform. However, you should not rely on it being a constant size, because on different platforms and screen densities its value may be calculated differently.

A line with hairline width may not be visible if your simulator is downscaled.
{[
  let hairlineWidth: float;
]}
{4 absoluteFill}
A very common pattern is to create overlays with position absolute and zero positioning, so [absoluteFill] can be used for convenience and to reduce duplication of these repeated styles.
{[
  let absoluteFill: Style.t;
]}
{4 absoluteFillObject}
Sometimes you may want absoluteFill but with a couple tweaks - [absoluteFillObject] can be used to create a customized entry in a StyleSheet, e.g.:
{[
  let absoluteFillObject: Style.t;
]}

*/

type t;

[@bs.module "react-native"] external t: t = "StyleSheet";

/**
 Method to create a StyleSheet
 Eg:
 {[
 let styles =
   StyleSheet.create(
     Style.{
       "box":
         style([
           backgroundColor(String("#527FE4")),
         ]),
     },
   );
  ]}
 */
let create: Js.t('a) => Js.t('a);

let hairlineWidth: float;

let absoluteFill: Style.t;

let absoluteFillObject: Style.t;

let flatten: list(Style.t) => Style.t;

let processColor: [ | `String(string) | `Number(int)] => string;
