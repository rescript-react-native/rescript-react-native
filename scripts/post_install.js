const { execSync } = require("child_process");
const { unlinkSync } = require("fs");
const { resolve } = require("path");

function exec(f) {
  console.log(">", f);
  execSync(f, {
    stdio: "inherit",
  });
}

function resolvePlatform() {
  if (process.platform === "win32") {
    const elevated = process.argv[2] === "-elevated";
    return {
      platform: "win32",
      elevated,
      cwd: elevated ? process.argv[3] : process.cwd(),
    };
  }
  return { platform: process.platform };
}

const ctx = resolvePlatform();

function elevateInWindows(f, reason) {
  if (ctx.platform === "win32" && !ctx.elevated) {
    if (reason) {
      console.log(reason);
    }
    exec(`cscript.exe "${resolve(__dirname, "post_install.vbs")}"`);
  } else {
    if (ctx.platform === "win32") {
      process.chdir(resolve(ctx.cwd));
    }
    f();
    if (ctx.platform === "win32") {
      unlinkSync("__esy_elevated_prompt.lock");
    }
  }
}

function main() {
  elevateInWindows(() => {
    exec("npx esy install");
    exec("npx esy build");
    exec("npx esy dune install --prefix build");
  }, "Esy requires elevated prompt to create symlinks.");
  require("./copy_ppx.js");
}

main();
