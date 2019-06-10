open ReactNative;

type htmlProps = {
  .
  "id": string,
  "name": string,
  "for": string,
  "class": string,
  "href": string,
};

type reasonChildren = array(reasonChild)
and reasonChild =
  | String(string)
  | Element(string, htmlProps, reasonChildren)
  | Empty;

type t = {
  .
  "t": string,
  "p": htmlProps,
  "c": Js.Undefined.t(array(t)),
};

let rec jsTreeToReason = (jsChild: t) =>
  switch ([%bs.raw {| Object.prototype.toString.call(jsChild) |}]) {
  | "[object String]" => String(Js.String.make(jsChild))
  | "[object Object]" =>
    let tag = Js.String.make(jsChild##t);
    let props = jsChild##p;
    let children =
      switch (Js.Undefined.toOption(jsChild##c)) {
      | Some(c) => c->Belt.Array.map(jsTreeToReason)
      | None => [||]
      };
    Element(tag, props, children);
  | _ => Empty
  };

let stringMapPartial = (f, s) => {
  let b = Buffer.create(String.length(s));
  s
  |> String.iter(c =>
       switch (f(c)) {
       | None => ()
       | Some(c') => Buffer.add_char(b, c')
       }
     );
  b->Buffer.contents;
};

let lastSiblingHasLineBreaking = ref(false);

let cleanupNewlines = (string, siblingHasLineBreaking) =>
  stringMapPartial(
    char =>
      char === '\n' && siblingHasLineBreaking
        ? None : Some(char === '\n' ? ' ' : char),
    string,
  );

let cleanupNewlinesPre = (string, siblingHasLineBreaking) =>
  stringMapPartial(
    char => char === '\n' && siblingHasLineBreaking ? None : Some(char),
    string,
  );

let rec renderChild = (parentTag, index: int, child) => {
  /* @todo we can do better */
  let key = index->string_of_int;
  let siblingHasLineBreaking = lastSiblingHasLineBreaking^;
  lastSiblingHasLineBreaking := false;
  let renderChildren = (parentTag, children) =>
    if (children->Belt.Array.length == 0) {
      React.null;
    } else {
      children->Belt.Array.mapWithIndex(renderChild(parentTag))->React.array;
    };
  switch (child) {
  | String(string) =>
    switch (parentTag) {
    | "ul" => React.null
    | "ol" => React.null
    | "li" =>
      <Html.Text>
        {cleanupNewlines(string, siblingHasLineBreaking)->React.string}
      </Html.Text>
    | "code" =>
      cleanupNewlinesPre(string, siblingHasLineBreaking)->React.string
    | _ => cleanupNewlines(string, siblingHasLineBreaking)->React.string
    }
  | Element(tag, props, children) =>
    switch (tag) {
    /* html tags */
    | "a" =>
      <Html.A key href=props##href> {renderChildren(tag, children)} </Html.A>
    | "h1" => <Html.H1 key> {renderChildren(tag, children)} </Html.H1>
    | "h2" => <Html.H2 key> {renderChildren(tag, children)} </Html.H2>
    | "h3" => <Html.H3 key> {renderChildren(tag, children)} </Html.H3>
    | "h4" => <Html.H4 key> {renderChildren(tag, children)} </Html.H4>
    | "h5" => <Html.H5 key> {renderChildren(tag, children)} </Html.H5>
    | "h6" => <Html.H6 key> {renderChildren(tag, children)} </Html.H6>
    | "p" => <Html.P key> {renderChildren(tag, children)} </Html.P>
    | "ul" => <Html.Ul key> {renderChildren(tag, children)} </Html.Ul>
    | "li" => <Html.Li key> {renderChildren(tag, children)} </Html.Li>
    | "blockquote" =>
      <Html.BlockQuote key> {renderChildren(tag, children)} </Html.BlockQuote>
    | "pre" =>
      <Html.Pre key props> {renderChildren(tag, children)} </Html.Pre>
    | "code" =>
      switch (parentTag) {
      | "pre" =>
        <Html.CodeBlock key props>
          {renderChildren(tag, children)}
        </Html.CodeBlock>
      | _ => <Html.Code key> {renderChildren(tag, children)} </Html.Code>
      }
    | "br" =>
      lastSiblingHasLineBreaking := true;
      <Html.Br key />;
    | "hr" => <Html.Hr key />
    | _ =>
      ReactDOMRe.createElement(
        tag,
        ~props=
          ReactDOMRe.objToDOMProps(
            Js.Obj.empty()
            ->Js.Obj.assign({"key": key})
            ->Js.Obj.assign(props),
          ),
        [|renderChildren(tag, children)|],
      )
    }
  | Empty => React.null
  };
};

[@react.component]
let make = (~body: t, ~renderChild=renderChild, ()) => {
  let tree = jsTreeToReason(body);
  <View> {renderChild("", 0, tree)} </View>;
};
