open ReactNative;
open ReactMultiversal;

let styles =
  StyleSheet.create(
    Style.{
      "menu":
        style(
          ~justifyContent=`center,
          ~alignItems=`center,
          ~borderTopWidth=8.,
          ~borderColor=Consts.Colors.accent,
          ~shadowColor="#000",
          ~shadowOffset=offset(~width=0., ~height=5.),
          ~shadowOpacity=0.15,
          ~shadowRadius=20.,
          ~zIndex=1,
          (),
        ),
      "barWrapper":
        style(~backgroundColor=Consts.Colors.dark, ~overflow=`visible, ())
        ->unsafeAddStyle({"overflow-y": "visible", "overflow-x": "hidden"}),
      "bar":
        style(
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`spaceBetween,
          (),
        ),

      "logoLink":
        style(
          ~flexGrow=1.,
          ~flexShrink=1.,
          ~position=`relative,
          ~zIndex=1,
          (),
        ),
      "logo":
        style(~flexGrow=1., ~flexDirection=`row, ~alignItems=`center, ()),
      "logoText":
        style(
          ~fontSize=18.,
          ~fontWeight=`_700,
          ~color=Consts.Colors.light,
          (),
        ),
      "search": style(),
      "links":
        style(
          ~flexGrow=1.,
          ~flexShrink=1.,
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`center,
          ~alignItems=`center,
          (),
        ),
      "link":
        style(
          ~fontSize=18.,
          ~lineHeight=18. *. 1.7,
          ~fontWeight=`_300,
          ~color=Consts.Colors.light,
          (),
        ),
      "linkActive":
        style(
          ~textDecorationLine=`underline,
          ~textDecorationStyle=`solid,
          (),
        ),
      "icons":
        style(
          ~flexGrow=1.,
          ~flexShrink=1.,
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`flexEnd,
          (),
        ),
      "icon":
        style(
          ~display=`flex,
          ~flexDirection=`row,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~paddingHorizontal=12.->dp,
          ~paddingVertical=6.->dp,
          ~fontSize=12.,
          (),
        ),
    },
  );

[@react.component]
let make = (~currentLocation) => {
  <View style=styles##menu>
    <Container
      maxWidth={1000.->Style.dp}
      style=styles##bar
      wrapperStyle=styles##barWrapper>
      <ViewLink href={Consts.baseUrl ++ "/"} style=styles##logoLink>
        <SpacedView style=styles##logo vertical=XS horizontal=XS>
          <SVGBsReactNative
            width={36.->ReactFromSvg.Size.pt}
            height={36.->ReactFromSvg.Size.pt}
            fill=Consts.Colors.lightest
          />
          <WindowSizeFilter.Small>
            <Text style=styles##logoText>
              {("   " ++ Consts.titleShort)->ReasonReact.string}
            </Text>
          </WindowSizeFilter.Small>
          <WindowSizeFilter.NotSmall>
            <Text style=styles##logoText>
              {("   " ++ Consts.title)->ReasonReact.string}
            </Text>
          </WindowSizeFilter.NotSmall>
        </SpacedView>
      </ViewLink>
      <SpacedView style=styles##links vertical=XS horizontal=XS>
        {Consts.menuLinks
         ->Belt.Array.map(item => {
             let isActive =
               item.isActive(currentLocation##pathname, item.link);
             <ViewLink
               key={item.link}
               href={item.link}
               style=Style.(
                 arrayOption([|
                   Some(styles##link),
                   isActive ? Some(styles##linkActive) : None,
                 |])
               )>
               <SpacedView vertical=None horizontal=S>
                 <Text> item.text->React.string </Text>
               </SpacedView>
             </ViewLink>;
           })
         ->React.array}
      </SpacedView>
      <SpacedView style=styles##search vertical=XS horizontal=XS>
        <input
          id="SearchInput"
          placeholder="Search"
          style={ReactDOMRe.Style.make(
            ~fontSize="15px",
            ~width="120px",
            ~borderRadius="20px",
            ~border="0",
            ~padding="10px 20px",
            (),
          )}
        />
      </SpacedView>
      <SpacedView style=styles##icons vertical=XS horizontal=XS>
        {Consts.socialLinks
         ->Belt.Array.map(item =>
             <ViewLink
               key={item.link}
               href={item.link}
               style=styles##icon
               accessibilityLabel={item.text}>
               {item.componentFunc(
                  ~iconColor=Consts.Colors.light,
                  ~iconSize=22.->ReactFromSvg.Size.pt,
                )}
               <WindowSizeFilter.NotSmall>
                 <Spacer size=XS />
                 <Text style=styles##link> item.name->React.string </Text>
               </WindowSizeFilter.NotSmall>
             </ViewLink>
           )
         ->ReasonReact.array}
      </SpacedView>
    </Container>
  </View>;
};
