open Node;
open Belt;

let root = Process.cwd();

{
  HighlightJs.(hjs->registerLanguage("reason", reason));
};

let remarkable =
  Remarkable.make(
    "full",
    {
      "html": true,
      "linkify": true,
      "xhtmlOut": true,
      "langPrefix": "hljs language-",
      "highlight":
        Some(
          (code, lang) =>
            try (
              {
                HighlightJs.highlight(~lang, code)##value;
              }
            ) {
            | _ => ""
            },
        ),
    },
  );

Js.log("Pages...");
let sourcePath = Path.join([|root, "docs"|]);
let outputPath = Path.join([|root, "build", "docs-pages"|]);
Path.join([|sourcePath, "**/*.md"|])
->FsUtils.transform(files => {
    let newFiles: array(FsUtils.t) = [||];
    let finalFiles =
      files->Array.reduce(
        newFiles,
        (files, file) => {
          let shortName =
            file.name
            |> Js.String.replace(sourcePath, "")
            |> Js.String.replace(".md", "");
          let front = FrontMatter.parse(file.content);
          let content =
            {
              "id": front##attributes##id,
              "title": front##attributes##title,
              "body": Remarkable.render(remarkable, front##body),
            }
            ->Js.Json.stringifyAny;
          if (content->Option.isNone) {
            Js.log2(file.name, "can't be transformed");
          };
          content
          ->Option.map(content =>
              files->Array.concat([|
                {
                  name: Path.join([|outputPath, shortName ++ ".json"|]),
                  content,
                },
              |])
            )
          ->Option.getWithDefault(files);
        },
      );
    finalFiles->Array.concat([|
      {
        name: Path.join([|outputPath, "__index__.json"|]),
        content:
          (
            finalFiles->Array.map(file =>
              file.name
              |> Js.String.replace(outputPath ++ "/", "")
              |> Js.String.replace(".json", "")
            )
            |> Js.Json.stringifyAny
          )
          ->Option.getWithDefault("[]"),
      },
    |]);
  });

Js.log("Create missing markdown files (wip)...");
// create missing md for modules
[@bs.module "fs"] external existsSync: string => bool = "existsSync";
let createMissingMd = (sourcePath, outputPath, files) => {
  let newFiles: array(FsUtils.t) = [||];
  files->Array.reduce(
    newFiles,
    (files, file: FsUtils.t) => {
      let shortName =
        file.name
        |> Js.String.replace(sourcePath ++ "/", "")
        |> Js.String.replace(".rei", "")
        |> Js.String.replace(".re", "");
      let finalfilename = Path.join([|outputPath, shortName ++ ".md"|]);
      if (try (!existsSync(finalfilename)) {
          | _ => true
          }) {
        let name = shortName->Path.basename;
        let code = file.content;
        let content = {j|---
id: $shortName
title: $name
wip: true
---

```reason
$code
```
|j};
        files->Array.concat([|{name: finalfilename, content}|]);
      } else {
        files;
      };
    },
  );
};
let sourcePath = Path.join([|root, "..", "bs-react-native-next", "src"|]);
let outputPath = Path.join([|root, "..", "bs-react-native-next", "src"|]);
// create from rei first
Path.join([|sourcePath, "(apis|components)/*.rei"|])
->FsUtils.transform(createMissingMd(sourcePath, outputPath));
// fallback to re
Path.join([|sourcePath, "(apis|components)/*.re"|])
->FsUtils.transform(createMissingMd(sourcePath, outputPath));

Js.log("Modules...");
let sourcePath = Path.join([|root, "..", "bs-react-native-next", "src"|]);
let outputPath = Path.join([|root, "build", "docs-src"|]);
Path.join([|sourcePath, "**/*.md"|])
->FsUtils.transform(files => {
    let newFiles: array(FsUtils.t) = [||];
    let finalFiles =
      files->Array.reduce(
        newFiles,
        (files, file) => {
          let shortName =
            file.name
            |> Js.String.replace(sourcePath, "")
            |> Js.String.replace(".md", "");
          let front = FrontMatter.parse(file.content);
          let content =
            {
              "id": front##attributes##id,
              "title": front##attributes##title,
              "wip": front##attributes##wip,
              "autoLinkToOfficialDoc":
                front##attributes##autoLinkToOfficialDoc,
              "body": Remarkable.render(remarkable, front##body),
            }
            ->Js.Json.stringifyAny;
          if (content->Option.isNone) {
            Js.log2(file.name, "can't be transformed");
          };
          content
          ->Option.map(content =>
              files->Array.concat([|
                {
                  name: Path.join([|outputPath, shortName ++ ".json"|]),
                  content,
                },
              |])
            )
          ->Option.getWithDefault(files);
        },
      );
    finalFiles->Array.concat([|
      {
        name: Path.join([|outputPath, "__index__.json"|]),
        content:
          (
            finalFiles->Array.map(file =>
              file.name
              |> Js.String.replace(outputPath ++ "/", "")
              |> Js.String.replace(".json", "")
            )
            |> Js.Json.stringifyAny
          )
          ->Option.getWithDefault("[]"),
      },
    |]);
  });
