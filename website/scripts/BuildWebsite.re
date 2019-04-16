open Node;
open Belt;

let root = Process.cwd();
let outputPath = Path.join([|root, "dist", Consts.baseUrl|]);

let indexJsonString =
  Fs.readFileAsUtf8Sync(
    Path.join([|root, "build", "docs-src", "__index__.json"|]),
  );
let indexJson =
  try (indexJsonString->Js.Json.parseExn) {
  | _ => failwith("Error parsing JSON modules index")
  };
let index =
  indexJson
  ->Js.Json.decodeArray
  ->Option.map(a =>
      a->Array.reduce([||], (acc, s) =>
        s
        ->Js.Json.decodeString
        ->Option.map(s => acc->Array.concat([|s|]))
        ->Option.getWithDefault(acc)
      )
    )
  ->Option.getWithDefault([||]);

// build docs pages
let sourcePath = Path.join([|root, "build", "docs-pages"|]);
Path.join([|sourcePath, "**/!(__index__).json"|])
->FsUtils.transform(files =>
    files->Array.map(file => {
      let name =
        file.name
        |> Js.String.replace(sourcePath, "en/docs")
        |> Js.String.replace("/index.json", "/index.html")
        |> Js.String.replace(".json", "/index.html");
      let content = Prerender.file({name, content: file.content}, index);
      let f: FsUtils.t = {name: Path.join([|outputPath, name|]), content};
      f;
    })
  );

// build docs src
let sourcePath = Path.join([|root, "build", "docs-src"|]);
Path.join([|sourcePath, "**/!(__index__).json"|])
->FsUtils.transform(files =>
    files->Array.map(file => {
      let name =
        file.name
        |> Js.String.replace(sourcePath, "en/docs")
        |> Js.String.replace("/index.json", "/index.html")
        |> Js.String.replace(".json", "/index.html");
      let content = Prerender.file({name, content: file.content}, index);
      let f: FsUtils.t = {name: Path.join([|outputPath, name|]), content};
      f;
    })
  );

// build urls
[|""|]
->Array.map(url => {
    let f: FsUtils.t = {
      name: Path.join([|outputPath, url ++ "/index.html"|]),
      content: Prerender.make(~url, ~pageData=None),
    };
    f;
  })
->FsUtils.write;
