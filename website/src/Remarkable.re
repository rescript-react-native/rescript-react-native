type config = {
  .
  "highlight": option((string, string) => string),
  "html": bool,
  "xhtmlOut": bool,
  "linkify": bool,
};

type remarkable;

[@bs.new] [@bs.module]
external make: (string, config) => remarkable = "remarkable";

[@bs.send] external render: (remarkable, string) => string = "render";

type plugin;

[@bs.module] external meta: plugin = "remarkable-meta";

[@bs.send] external use: (remarkable, plugin) => unit = "use";
