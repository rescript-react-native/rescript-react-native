open Belt;

type location = {. "pathname": string};

[@react.component]
let make = (~docsIndex, ~blogIndex, ~pageData=?, ~currentLocation: location) => {
  switch (Js.String.split("/", currentLocation##pathname)->List.fromArray) {
  | [""] => <ScreenHomepage currentLocation />
  | [_, "blog"] => <ScreenBlogIndex docsIndex blogIndex currentLocation />
  | [_, "blog", _]
  | [_, "blog", _, _] =>
    <ScreenPage docsIndex blogIndex ?pageData currentLocation mode=`blog />
  | _ =>
    <ScreenPage docsIndex blogIndex ?pageData currentLocation mode=`docs />
  };
};
