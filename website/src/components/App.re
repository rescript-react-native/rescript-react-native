open Belt;

type location = {. "pathname": string};
open ReactNative;

[@react.component]
let make =
    (~pageData: option(PageContent.pageData)=?, ~currentLocation: location) => {
  switch (Js.String.split("/", currentLocation##pathname)->List.fromArray) {
  | [""] => <> <HeaderLarge currentLocation /> <Homepage /> </>
  | _ =>
    <>
      <link
        rel="stylesheet"
        href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/styles/atom-one-light.min.css"
      />
      <style
        dangerouslySetInnerHTML={
          "__html": {|
.hljs {
  font-size: 14px;
  padding: 20px;
  border: 1px solid rgba(0,0,0,0.05);
  background: rgba(0,0,0,0.01);
  border-radius: 4px;
}

.hljs.javascript {
  background-color: rgba(247, 223, 30, .03)
}

table .hljs {
  border: none;
  background: none
}

.hljs-operator {
  color: #a626a4
}

.hljs-character {
  color: #50a14f
}

.hljs-module-identifier {
  color: #4078f2
}

.hljs-constructor {
  color: #e45649
}

.stick { position: -webkit-sticky; position: sticky; }

|},
        }
      />
      <HeaderLarge currentLocation />
      {pageData
       ->Option.map(pageData =>
           <Container
             style=Style.(
               style(~flexDirection=`row, ~height=100.->Size.pct, ())
             )>
             <Sidebar modulesIndex={pageData.modulesIndex} />
             <PageContent pageData />
           </Container>
         )
       ->Option.getWithDefault(<Text> "Error :'("->React.string </Text>)}
      <HeaderLarge currentLocation />
    </>
  };
};
