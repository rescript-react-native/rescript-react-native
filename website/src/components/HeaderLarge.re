open ReactNative;
open ReactMultiversal;

let styles =
  StyleSheet.create(
    Style.{
      "menu":
        viewStyle(
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
        viewStyle(~backgroundColor=Consts.Colors.dark, ~overflow=`visible, ())
        ->unsafeAddStyle({"overflow-y": "visible", "overflow-x": "hidden"}),
      "bar":
        viewStyle(
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`spaceBetween,
          (),
        ),

      "logoLink":
        viewStyle(
          ~flexGrow=1.,
          ~flexShrink=1.,
          ~position=`relative,
          ~zIndex=1,
          (),
        ),
      "logo":
        viewStyle(~flexGrow=1., ~flexDirection=`row, ~alignItems=`center, ()),
      "logoText":
        textStyle(
          ~fontSize=18.,
          ~fontWeight=`_700,
          ~color=Consts.Colors.light,
          (),
        ),
      "search": viewStyle(~justifyContent=`center, ()),
      "searchInputWrapper":
        viewStyle(
          ~flexDirection=`row,
          ~backgroundColor="#fff",
          ~borderRadius=6.,
          ~alignItems=`center,
          (),
        ),
      "links":
        viewStyle(
          ~flexGrow=1.,
          ~flexShrink=1.,
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`flexEnd,
          ~alignItems=`center,
          (),
        ),
      "link":
        textStyle(
          ~fontSize=18.,
          ~lineHeight=18. *. 1.7,
          ~fontWeight=`_300,
          ~color=Consts.Colors.light,
          (),
        ),
      "linkActive":
        textStyle(
          ~textDecorationLine=`underline,
          ~textDecorationStyle=`solid,
          (),
        ),
      "icons":
        viewStyle(
          ~flexGrow=1.,
          ~flexShrink=1.,
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`flexEnd,
          (),
        ),
      "icon":
        textStyle(
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
      <SpacedView vertical=XS horizontal=XS style=styles##search>
        <SpacedView
          vertical=XXS horizontal=XS style=styles##searchInputWrapper>
          <input
            id="SearchInput"
            placeholder="Search..."
            style={ReactDOMRe.Style.make(
              ~fontSize="16px",
              ~width="120px",
              ~border="0",
              (),
            )}
          />
          <Spacer size=XS />
          <SVGSearch fill=Predefined.Colors.dark width="18" height="18" />
        </SpacedView>
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
