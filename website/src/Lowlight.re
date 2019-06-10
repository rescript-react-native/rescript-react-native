type t;
type language;

[@bs.module] external lowlight: t = "lowlight";
[@bs.module] external reason: language = "reason-highlightjs";

[@bs.send]
external registerLanguage: (t, string, language) => unit = "registerLanguage";
