open Belt;

type location = {. "pathname": string};
open ReactNative;

[@react.component]
let make =
    (~pageData: option(PageContent.pageData)=?, ~currentLocation: location) => {
  switch (Js.String.split("/", currentLocation##pathname)->List.fromArray) {
  | [""] => <> <Head /> <HeaderLarge currentLocation /> <Homepage /> </>
  | _ =>
    <>
      <Head />
      <HeaderLarge currentLocation />
      {pageData
       ->Option.map(pageData =>
           <Container
             style=Style.(style(~flexDirection=`row, ~height=100.->pct, ()))>
             <BsReactHelmet>
               <title>
                 {("BsReactNative " ++ pageData.title)->React.string}
               </title>
             </BsReactHelmet>
             <Sidebar modulesIndex={pageData.modulesIndex} />
             <PageContent pageData />
           </Container>
         )
       ->Option.getWithDefault(<Text> "Error :'("->React.string </Text>)}
      <HeaderLarge currentLocation />
    </>
  };
};
