open Belt;
open ReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "container": style(~height=100.->Size.pct, ~overflow=`scroll, ()),
      "title":
        style(~fontSize=16., ~fontWeight=`_600, ~color="#333"->color, ()),
      "link":
        style(
          ~fontSize=14.,
          ~fontWeight=`_400,
          ~color="#555"->color,
          ~paddingVertical=(Spacer.space /. 4.)->Size.pt,
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
let make = () => {
  <>
    <style
      dangerouslySetInnerHTML={
        "__html": {|
.stick {
  position: -webkit-sticky;
  position: sticky;
  top: 0;
  display: flex;
  flex-direction: column;
}
|},
      }
    />
    <div
      className="stick"
      style={ReactDOMRe.Style.make(~overflowY="auto", ~height="100vh", ())}>
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
                  <TextLink key=title href={"/en/" ++ link} style=styles##link>
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
           <SpacedView key={section.title} vertical=SpacedView.S>
             <div
               className="stick"
               style={ReactDOMRe.Style.make(
                 ~background=
                   "linear-gradient("
                   ++ Consts.Colors.light
                   ++ " 75%, "
                   ++ Consts.Colors.light0
                   ++ ")",
                 (),
               )}>
               <SpacedView vertical=SpacedView.S horizontal=SpacedView.None>
                 <Text style=styles##title>
                   {section.title->String.uppercase->React.string}
                 </Text>
               </SpacedView>
             </div>
             {{section.data
               ->List.map(((title, link)) =>
                   <TextLink
                     key=title href={"/en/" ++ link} style=styles##link>
                     title->React.string
                   </TextLink>
                 )}
              ->List.toArray
              ->React.array}
           </SpacedView>
         )
       ->List.toArray
       ->React.array}
      <Spacer />
    </div>
  </>;
};
