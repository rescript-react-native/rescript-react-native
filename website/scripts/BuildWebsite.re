open Node;
open Belt;

let root = Process.cwd();
let outputPath = Path.join([|root, "dist"|]);

let buildOdoc = () => {
  let sourcePath = Path.join([|root, "build", "odoc"|]);
  Path.join([|sourcePath, "**/*.json"|])
  ->FsUtils.transform(files =>
      files->Array.map(file => {
        let name =
          file.name
          |> Js.String.replace(sourcePath, "en/docs")
          |> Js.String.replace("/index.json", "/index.html")
          |> Js.String.replace(".json", "/index.html");
        let content = Prerender.file({name, content: file.content});
        let f: FsUtils.t = {name: Path.join([|outputPath, name|]), content};
        f;
      })
    );
};

let buildMd = () => {
  let sourcePath = Path.join([|root, "build", "md"|]);
  Path.join([|sourcePath, "**/*.json"|])
  ->FsUtils.transform(files =>
      files->Array.map(file => {
        let name =
          file.name
          |> Js.String.replace(sourcePath, "en/docs")
          |> Js.String.replace("/index.json", "/index.html")
          |> Js.String.replace(".json", "/index.html");
        let content = Prerender.file({name, content: file.content});
        let f: FsUtils.t = {name: Path.join([|outputPath, name|]), content};
        f;
      })
    );
};

let buildUrl = urls => {
  urls
  ->Array.map(url => {
      let f: FsUtils.t = {
        name: Path.join([|outputPath, url ++ "/index.html"|]),
        content: Prerender.make(~url, ~pageData=None),
      };
      f;
    })
  ->FsUtils.write;
};

buildOdoc();
buildMd();
buildUrl([|""|]);
