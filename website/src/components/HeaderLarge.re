open ReactNative;

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
      "bar":
        style(
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`spaceBetween,
          (),
        ),
      "barWrapper": style(~backgroundColor=Consts.Colors.dark, ()),
      "logo":
        style(
          ~flex=1.,
          ~flexDirection=`row,
          ~position=`relative,
          ~zIndex=1,
          ~paddingHorizontal=pt(10.),
          ~alignItems=`center,
          (),
        ),
      "logoText":
        style(
          ~fontSize=18.,
          ~fontWeight=`_700,
          ~color=Consts.Colors.light,
          (),
        ),
      "links":
        style(
          ~flex=1.,
          ~flexDirection=`row,
          ~justifyContent=`center,
          ~alignItems=`center,
          (),
        ),
      "link":
        style(
          ~padding=pt(10.),
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
        style(~flex=1., ~flexDirection=`row, ~justifyContent=`flexEnd, ()),
      "icon":
        style(
          ~display=`flex,
          ~flexDirection=`row,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~paddingHorizontal=pt(12.),
          ~paddingVertical=pt(6.),
          ~fontSize=12.,
          (),
        ),
    },
  );

[@react.component]
let make = (~currentLocation) => {
  <View style=styles##menu>
    <Container style=styles##bar wrapperStyle=styles##barWrapper>
      <ViewLink style=styles##logo href={Consts.baseUrl ++ "/"}>
        <SVGBsReactNative
          width={36.->ReactFromSvg.Size.pt}
          height={36.->ReactFromSvg.Size.pt}
          fill=Consts.Colors.lightest
        />
        <Text style=styles##logoText>
          {("   " ++ Consts.title)->ReasonReact.string}
        </Text>
      </ViewLink>
      <View style=styles##links>
        {Consts.menuLinks
         ->Belt.Array.map(item => {
             let isActive =
               item.isActive(currentLocation##pathname, item.link);
             <TextLink
               key={item.link}
               href={item.link}
               style=Style.(
                 arrayOption([|
                   Some(styles##link),
                   isActive ? Some(styles##linkActive) : None,
                 |])
               )>
               item.text->React.string
             </TextLink>;
           })
         ->React.array}
      </View>
      <View style=styles##icons>
        {Consts.socialLinks
         ->Belt.Array.map(item =>
             <ViewLink
               key={item.link}
               href={item.link}
               style=styles##icon
               accessibilityLabel={item.text}>
               {item.componentFunc(
                  ~iconColor=Consts.Colors.light,
                  ~iconSize=22.->Svg.Size.pt,
                )}
               <Text style=styles##link> item.name->React.string </Text>
             </ViewLink>
           )
         ->ReasonReact.array}
      </View>
    </Container>
  </View>;
};
