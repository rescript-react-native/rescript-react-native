open Node;
open Belt;

let root = Process.cwd();

Lowlight.(lowlight->registerLanguage("reason", reason));

[@bs.module] external mdToJson: string => 'a = "@phenomic/markdown-as-json";

Js.log("Docs pages...");
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
            |> Js.String.replace(sourcePath ++ "/", "")
            |> Js.String.replace(".md", "");
          let mdJson = mdToJson(file.content);
          let content =
            {
              "filename": file.name |> Js.String.replace(root, "website"),
              "id": mdJson##id,
              "title": mdJson##title,
              "body": mdJson##body,
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

Js.log("Modules...");
let sourcePath = Path.join([|root, "..", "reason-react-native", "src"|]);
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
            |> Js.String.replace(sourcePath ++ "/", "")
            |> Js.String.replace(".md", "");
          let mdJson = mdToJson(file.content);
          let content =
            {
              "filename":
                file.name
                |> Js.String.replace(
                     Node.Path.resolve(root, "..") ++ "/",
                     "",
                   ),
              "id": mdJson##id,
              "title": mdJson##title,
              "wip": mdJson##wip,
              "autoLinkToOfficialDoc": mdJson##autoLinkToOfficialDoc,
              "officialDoc": mdJson##officialDoc,
              "body": mdJson##body,
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

Js.log("Blog post...");
type blogIndexEntry = {
  .
  "id": string,
  "title": string,
  "author": string,
  "date": string,
};
let sourcePath = Path.join([|root, "blog"|]);
let outputPath = Path.join([|root, "build", "blog-posts"|]);
Path.join([|sourcePath, "**/*.md"|])
->FsUtils.transform(files => {
    let newFiles: array(FsUtils.t) = [||];
    let index: ref(array(blogIndexEntry)) = ref([||]);
    let finalFiles =
      files->Array.reduce(
        newFiles,
        (files, file) => {
          let shortName =
            file.name
            |> Js.String.replace(sourcePath ++ "/", "")
            |> Js.String.replace(".md", "");
          let mdJson = mdToJson(file.content);
          let content =
            {
              "filename": file.name |> Js.String.replace(root, "website"),
              "id": mdJson##id,
              "title": mdJson##title,
              "author": mdJson##author,
              "date": shortName->Js.String.slice(~from=0, ~to_=10),
              "body": mdJson##body,
            }
            ->Js.Json.stringifyAny;
          if (content->Option.isNone) {
            Js.log2(file.name, "can't be transformed");
          };
          content
          ->Option.map(content => {
              index :=
                (index^)
                ->Array.concat([|
                    {
                      "id": mdJson##id,
                      "title": mdJson##title,
                      "author": mdJson##author,
                      "date": shortName->Js.String.slice(~from=0, ~to_=10),
                    },
                  |]);
              files->Array.concat([|
                {
                  name: Path.join([|outputPath, shortName ++ ".json"|]),
                  content,
                },
              |]);
            })
          ->Option.getWithDefault(files);
        },
      );
    finalFiles->Array.concat([|
      {
        name: Path.join([|outputPath, "__index__.json"|]),
        content:
          (index^ |> Js.Json.stringifyAny)->Option.getWithDefault("[]"),
      },
    |]);
  });
