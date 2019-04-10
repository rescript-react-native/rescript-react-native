[@bs.module "highlight.js"]
external highlightAuto: string => {. "value": string} = "highlightAuto";

[@bs.module "highlight.js"]
external highlight: (~lang: string, string) => {. "value": string} =
  "highlight";

type hjs;
type language;

[@bs.module] external hjs: hjs = "highlight.js";
[@bs.module] external reason: language = "reason-highlightjs";

[@bs.send]
external registerLanguage: (hjs, string, language) => unit =
  "registerLanguage";
