const p = require("fs");
const path = require("path");
const cwd = path.resolve(path.join(__dirname, ".."));
const esy_ppx_exe = [
  "build",
  "lib",
  "ppx_rescript_react_native_style",
  "lib",
  "ppx.exe",
];
p.copyFileSync(path.resolve(cwd, ...esy_ppx_exe), path.resolve(cwd, "ppx.exe"));
