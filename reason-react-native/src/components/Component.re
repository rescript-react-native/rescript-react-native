type element;

[@bs.send] external setNativeProps: (element, Js.t('a)) => unit = "";

[@bs.send] external focus: element => unit = "";
[@bs.send] external blur: element => unit = "";

/* TODO
   - measure
   - measureInWindow
   - measureLayout
   */
