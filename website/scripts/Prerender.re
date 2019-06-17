[@bs.val] [@bs.module "react-dom/server"]
external renderToString: React.element => string = "renderToString";

[@bs.val] [@bs.module "react-dom/server"]
external renderToStaticMarkup: React.element => string =
  "renderToStaticMarkup";

open ReactNative;

let make =
    (
      ~url: string,
      ~pageData,
      ~docsIndex: array(string),
      ~blogIndex: array(PrepareMdToJson.blogIndexEntry),
    ) => {
  // @todo find a way to get rid of this Obj.magic
  AppRegistry.registerComponent("App", () => App.make->Obj.magic);
  let app =
    AppRegistry.getApplication(
      "App",
      {
        "initialProps":
          {
            "docsIndex": docsIndex,
            "blogIndex": blogIndex,
            "pageData": pageData,
            "currentLocation": {
              "pathname": url,
            },
          }
          ->Obj.magic,
      },
    );
  let html = renderToString(app##element);
  let css = renderToStaticMarkup(app##getStyleElement());
  let helmet = BsReactHelmet.renderStatic();
  let helmetMeta = helmet##meta##toString();
  let helmetLinks = helmet##link##toString();
  let helmetTitle = helmet##title##toString();
  let helmetStyle = helmet##style##toString();
  let helmetScript = helmet##script##toString();
  {j|
<!DOCTYPE html>
<html style="height:100%">
<head>
$helmetMeta
$helmetLinks
$helmetTitle
$helmetStyle
$css
</head>
<body style="min-height:100%">
$html
$helmetScript
</body>
</html>|j};
};

let file =
    (
      ~file: FsUtils.t,
      ~docsIndex: array(string),
      ~blogIndex: array(PrepareMdToJson.blogIndexEntry),
    ) => {
  let json =
    try (Js.Json.parseExn(file.content)) {
    | _ => failwith(file.name ++ ": Error parsing JSON string")
    };
  let pageData =
    switch (Js.Json.classify(json)) {
    | Js.Json.JSONObject(value) =>
      let filename =
        switch (Js.Dict.get(value, "filename")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => v
          | _ => failwith(file.name ++ ": Expected an string for `filename`")
          }
        | None => failwith(file.name ++ ": Expected an `filename` property")
        };
      let id =
        switch (Js.Dict.get(value, "id")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => v
          | _ => failwith(file.name ++ ": Expected an string for `id`")
          }
        | None => failwith(file.name ++ ": Expected an `id` property")
        };
      let title =
        switch (Js.Dict.get(value, "title")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => v
          | _ => failwith(file.name ++ ": Expected an string for the `title`")
          }
        | None => failwith(file.name ++ ": Expected an `title` property")
        };
      let date =
        switch (Js.Dict.get(value, "date")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => Some(v)
          | _ => failwith(file.name ++ ": Expected a string for `date`")
          }
        | None => None
        };
      let author =
        switch (Js.Dict.get(value, "author")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => Some(v)
          | _ => failwith(file.name ++ ": Expected a string for `author`")
          }
        | None => None
        };
      let wip =
        switch (Js.Dict.get(value, "wip")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONTrue => Some(true)
          | Js.Json.JSONFalse => Some(false)
          | _ => failwith(file.name ++ ": Expected a boolean for `wip`")
          }
        | None => None
        };
      let autoLinkToOfficialDoc =
        switch (Js.Dict.get(value, "autoLinkToOfficialDoc")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONTrue => Some(true)
          | Js.Json.JSONFalse => Some(false)
          | _ =>
            failwith(
              file.name ++ ": Expected a boolean for `autoLinkToOfficialDoc`",
            )
          }
        | None => None
        };
      let officialDoc =
        switch (Js.Dict.get(value, "officialDoc")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => Some(v)
          | _ =>
            failwith(file.name ++ ": Expected a string for `officialDoc`")
          }
        | None => None
        };
      let body =
        switch (Js.Dict.get(value, "body")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONObject(v) => v
          | _ => failwith(file.name ++ ": Expected an object for the `body`")
          }
        | None => failwith(file.name ++ ": Expected an `body` property")
        };
      let p: PageContent.pageData = {
        filename,
        id,
        title,
        date,
        author,
        wip,
        officialDoc,
        autoLinkToOfficialDoc,
        body: body->Obj.magic,
      };
      p;
    | _ => failwith(file.name ++ ": Expected an object for pageData")
    };

  make(~url=file.name, ~docsIndex, ~blogIndex, ~pageData=Some(pageData));
};
