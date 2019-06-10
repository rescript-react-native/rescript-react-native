open Belt;
open ReactNative;
open ReactMultiversal;

let styles =
  StyleSheet.create(
    Style.{
      "container": style(~height=100.->pct, ~overflow=`scroll, ()),
      "title": style(~fontSize=16., ~fontWeight=`_600, ~color="#333", ()),
      "link":
        style(
          ~fontSize=14.,
          ~fontWeight=`_400,
          ~color="#555",
          ~paddingVertical=(Spacer.space /. 4.)->dp,
          (),
        ),
      "notlink":
        style(
          ~fontSize=14.,
          ~fontWeight=`_400,
          ~color="#ddd",
          ~paddingVertical=(Spacer.space /. 4.)->dp,
          (),
        ),
    },
  );

type item = (string, string);

let makeSections =
    (sections: list(Consts.section))
    : array(VirtualizedSectionList.section(item)) => {
  sections
  ->List.toArray
  ->Array.map(section =>
      {
        "key": Some(section.title),
        "data": section.data->List.toArray,
        "renderItem": None,
        "ItemSeparatorComponent": None,
        "keyExtractor": None,
      }
    );
};

let sections = makeSections(Consts.sections);

[@react.component]
let make = (~docsIndex) => {
  <div
    className="stick"
    style={ReactDOMRe.Style.make(
      ~top="0",
      ~display="flex",
      ~flexDirection="column",
      ~overflowY="auto",
      ~height="100vh",
      (),
    )}>
    <Spacer />
    /* until we have client side react too, section list won't sticky headers...
       <div className="stick" style={ReactDOMRe.Style.make(~height="100vh", ())}>
          <SpacedView vertical=SpacedView.S style=Style.(style(~flex=1., ()))>
            <SectionList
              initialNumToRender=200 // SSR
              // disableVirtualization=true // SSR
              style=Style.(style(~flex=1., ()))
              contentContainerStyle=Style.(style(~flex=1., ()))
              sections
              renderItem={renderItemBag => {
                let (title, link) = renderItemBag##item;
                <TextLink key=title href={Consts.baseUrl++ "/en/" ++ link} style=styles##link>
                  title->React.string
                </TextLink>;
              }}
              renderSectionHeader={renderSectionBag =>
                <SpacedView
                  vertical=SpacedView.S
                  horizontal=SpacedView.None
                  style=styles##titleContainer>
                  <Text style=styles##title>
                    {renderSectionBag##section##key
                     ->Option.getWithDefault("")
                     ->String.uppercase
                     ->React.string}
                  </Text>
                </SpacedView>
              }
              keyExtractor={((title, link), _index) => title ++ link}
            />
          </SpacedView>
          */
    {Consts.sections
     ->List.map(section =>
         <SpacedView key={section.title} vertical=SpacedView.None>
           <div
             className="stick"
             style={ReactDOMRe.Style.make(
               ~top="0",
               ~display="flex",
               ~flexDirection="column",
               ~background=
                 "linear-gradient("
                 ++ Consts.Colors.light
                 ++ " 75%, "
                 ++ Consts.Colors.light0
                 ++ ")",
               (),
             )}>
             <SpacedView vertical=SpacedView.M horizontal=SpacedView.None>
               <Text style=styles##title>
                 {section.title->String.uppercase->React.string}
               </Text>
             </SpacedView>
           </div>
           {{section.data
             ->List.map(((title, link)) =>
                 !(link |> Js.String.startsWith("docs/apis/"))
                 && !(link |> Js.String.startsWith("docs/components/"))
                 || (
                   link
                   |> Js.String.startsWith("docs/apis/")
                   || link
                   |> Js.String.startsWith("docs/components/")
                 )
                 && docsIndex->Array.some(path =>
                      link == "docs/" ++ path ++ "/"
                    )
                   ? <TextLink
                       key=title
                       href={Consts.baseUrl ++ "/en/" ++ link}
                       style=styles##link>
                       title->React.string
                     </TextLink>
                   : <Text key=title style=styles##notlink>
                       title->React.string
                     </Text>
               )}
            ->List.toArray
            ->React.array}
           <Spacer size=Spacer.S />
         </SpacedView>
       )
     ->List.toArray
     ->React.array}
    <Spacer />
  </div>;
};
