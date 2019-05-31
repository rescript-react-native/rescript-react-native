open Belt;
open ReactNative;
open ReactMultiversal;

type location = {. "pathname": string};

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
           <>
             <Container
               maxWidth={1000.->Style.pt}
               style=Style.(
                 style(
                   ~flexDirection=`row,
                   ~flexWrap=`wrap,
                   ~height=100.->pct,
                   (),
                 )
               )>
               <BsReactHelmet>
                 <title>
                   {("BsReactNative " ++ pageData.title)->React.string}
                 </title>
               </BsReactHelmet>
               <PageContent pageData />
               <Sidebar modulesIndex={pageData.modulesIndex} />
             </Container>
           </>
         )
       ->Option.getWithDefault(<Text> "Error :'("->React.string </Text>)}
      <HeaderLarge currentLocation />
    </>
  };
};
