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
      <HeaderLarge currentLocation />
      {pageData
       ->Option.map(pageData =>
           <Container
             style=Style.(
               style(~flexDirection=`row, ~height=100.->Size.pct, ())
             )>
             <Sidebar />
             <PageContent pageData />
           </Container>
         )
       ->Option.getWithDefault(<Text> "Error :'("->React.string </Text>)}
      <HeaderLarge currentLocation />
    </>
  };
};
