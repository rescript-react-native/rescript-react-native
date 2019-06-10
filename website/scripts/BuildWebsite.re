open Node;
open Belt;

let root = Process.cwd();
let outputPath = Path.join([|root, "dist", Consts.baseUrl|]);

let docsIndexJsonString =
  Fs.readFileAsUtf8Sync(
    Path.join([|root, "build", "docs-src", "__index__.json"|]),
  );
let docsIndexJson =
  try (docsIndexJsonString->Js.Json.parseExn) {
  | _ => failwith("Error parsing JSON modules index")
  };
let docsIndex =
  docsIndexJson
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

let blogIndexJsonString =
  Fs.readFileAsUtf8Sync(
    Path.join([|root, "build", "blog-posts", "__index__.json"|]),
  );
let blogIndexJson =
  try (blogIndexJsonString->Js.Json.parseExn) {
  | _ => failwith("Error parsing JSON modules index")
  };
let blogIndex: array(PrepareMdToJson.blogIndexEntry) =
  blogIndexJson
  ->Js.Json.decodeArray
  ->Option.map(a =>
      a->Array.reduce([||], (acc, entry) =>
        entry
        ->Js.Json.decodeObject
        ->Option.map(decodedEntry =>
            acc->Array.concat([|decodedEntry->Obj.magic|])
          )
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
      let content =
        Prerender.file(
          ~file={name, content: file.content},
          ~docsIndex,
          ~blogIndex,
        );
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
      let content =
        Prerender.file(
          ~file={name, content: file.content},
          ~docsIndex,
          ~blogIndex,
        );
      let f: FsUtils.t = {name: Path.join([|outputPath, name|]), content};
      f;
    })
  );

// build blog posts
let sourcePath = Path.join([|root, "build", "blog-posts"|]);
Path.join([|sourcePath, "**/!(__index__).json"|])
->FsUtils.transform(files =>
    files->Array.map(file => {
      let name =
        file.name
        |> Js.String.replace(sourcePath, "en/blog")
        |> Js.String.replace("/index.json", "/index.html")
        |> Js.String.replace(".json", "/index.html");
      let content =
        Prerender.file(
          ~file={name, content: file.content},
          ~docsIndex,
          ~blogIndex,
        );
      let f: FsUtils.t = {name: Path.join([|outputPath, name|]), content};
      f;
    })
  );

// build urls
[|"", "en/blog"|]
->Array.map(url => {
    let f: FsUtils.t = {
      name: Path.join([|outputPath, url ++ "/index.html"|]),
      content: Prerender.make(~url, ~docsIndex, ~blogIndex, ~pageData=None),
    };
    f;
  })
->FsUtils.write;
