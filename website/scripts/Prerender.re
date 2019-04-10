[@bs.val] [@bs.module "react-dom/server"]
external renderToString: React.element => string = "renderToString";

[@bs.val] [@bs.module "react-dom/server"]
external renderToStaticMarkup: React.element => string =
  "renderToStaticMarkup";

open ReactNative;

let make = (~url: string, ~pageData) => {
  // @todo find a way to get rid of this Obj.magic
  AppRegistry.registerComponent("App", () => App.make->Obj.magic);
  let app =
    AppRegistry.getApplication(
      "App",
      {
        "initialProps":
          {
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
  {j|
<!DOCTYPE html>
<html style="height:100%">
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
$css
<body style="min-height:100%">
$html
</body>
</html>|j};
};

let file = (file: FsUtils.t) => {
  let json =
    try (Js.Json.parseExn(file.content)) {
    | _ => failwith("Error parsing JSON string")
    };

  let pageData =
    switch (Js.Json.classify(json)) {
    | Js.Json.JSONObject(value) =>
      let id =
        switch (Js.Dict.get(value, "id")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => v
          | _ => failwith("Expected an string")
          }
        | None => failwith("Expected an `id` property")
        };
      let title =
        switch (Js.Dict.get(value, "title")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => Some(v)
          | _ => failwith("Expected an string")
          }
        | None => None // failwith("Expected an `title` property")
        };
      let body =
        switch (Js.Dict.get(value, "body")) {
        | Some(v) =>
          switch (Js.Json.classify(v)) {
          | Js.Json.JSONString(v) => v
          | _ => failwith("Expected an string")
          }
        | None => failwith("Expected an `body` property")
        };
      let p: PageContent.pageData = {id, title, body};
      p;
    | _ => failwith("Expected an object")
    };

  make(~url=file.name, ~pageData=Some(pageData));
};
