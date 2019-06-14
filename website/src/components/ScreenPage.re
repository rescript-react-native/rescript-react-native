open Belt;
open ReactNative;
open ReactMultiversal;

type mode = [ | `docs | `blog];

[@react.component]
let make =
    (
      ~mode=`docs,
      ~docsIndex,
      ~blogIndex,
      ~pageData: option(PageContent.pageData)=?,
      ~currentLocation,
    ) => {
  <>
    <Head />
    <HeaderLarge currentLocation />
    <Container
      maxWidth={1000.->Style.dp}
      style=Style.(
        style(~flexDirection=`row, ~flexWrap=`wrap, ~height=100.->pct, ())
      )>
      {pageData
       ->Option.map(pageData =>
           <>
             <BsReactHelmet>
               <title>
                 {(Consts.title ++ " " ++ pageData.title)->React.string}
               </title>
             </BsReactHelmet>
             <PageContent pageData />
           </>
         )
       ->Option.getWithDefault(
           <>
             <BsReactHelmet>
               <title> Consts.title->React.string </title>
             </BsReactHelmet>
             <Text> "Nothing to see :'("->React.string </Text>
           </>,
         )}
      {switch (mode) {
       | `blog => <SidebarBlog blogIndex />
       | _ => <SidebarDocs docsIndex currentLocation />
       }}
    </Container>
  </>;
};
