open Node;
open Belt;

let root = Process.cwd();
let sourcePath = Path.join([|root, "docs"|]);
let outputPath = Path.join([|root, "build/md"|]);

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

Path.join([|sourcePath, "**/*.md"|])
->FsUtils.transform(files => {
    let newFiles: array(FsUtils.t) = [||];
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
  }) /*->Future.map(files => {
         let names = files->Array.map(file => file.name);
         {"files": names}
         ->Js.Json.stringifyAny
         ->Option.map(jsonNames =>
             Fs.writeFileAsUtf8Sync(
               Path.join([|outputPath, "__index__" ++ ".json"|]),
               jsonNames,
             )
           )
         ->ignore;
       })*/;
