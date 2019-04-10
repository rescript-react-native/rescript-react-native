open Node;
open Belt;

let namespace = "BsReactNative";
let root = Process.cwd();
let sourcePath = Path.join([|root, "build/odoc-html"|]);
let outputPath = Path.join([|root, "build/odoc"|]);

let splitMark = "</code></h1>";
let toRemove = "</body></html>";

type odocjson = {
  .
  "id": string,
  "body": string,
};

Path.join([|sourcePath, "**/*.html"|])
->FsUtils.transform(files => {
    let newFiles: array(FsUtils.t) = [||];
    files->Array.reduce(
      newFiles,
      (files, file) => {
        let splittedContent = file.content |> Js.String.split(splitMark);
        let content = splittedContent[1];
        if (content->Option.isNone) {
          Js.log2(file.name, "can't be transformed");
        };
        let shortName =
          file.name
          |> Js.String.replace(sourcePath, "")
          |> Js.String.replace("/" ++ namespace ++ "/", "")
          |> Js.String.replace("-" ++ namespace ++ "/", "/")
          |> Js.String.replace("/index.html", "");
        content
        ->Option.flatMap(content
            // remove end of html + fixup broken <header>
            =>
              {
                "id": shortName,
                "body":
                  "<div>"
                  ++ (content |> Js.String.replace(toRemove, ""))
                  |> Js.String.replace("</header>", "</div>"),
              }
              ->Js.Json.stringifyAny
            )
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
  });
