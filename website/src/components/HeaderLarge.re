open ReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "menu":
        style(
          ~justifyContent=`center,
          ~alignItems=`center,
          ~borderTopWidth=8.,
          ~borderColor=color(Consts.Colors.accent),
          ~shadowColor=color("#000"),
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
      "barWrapper": style(~backgroundColor=color(Consts.Colors.dark), ()),
      "logo":
        style(
          ~flex=1.,
          ~flexDirection=`row,
          ~position=`relative,
          ~zIndex=1,
          ~paddingHorizontal=Size.pt(10.),
          ~alignItems=`center,
          (),
        ),
      "logoText":
        style(
          ~fontSize=18.,
          ~fontWeight=`_700,
          ~color=color(Consts.Colors.light),
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
          ~padding=Size.pt(10.),
          ~fontSize=18.,
          ~lineHeight=18. *. 1.7,
          ~fontWeight=`_300,
          ~color=color(Consts.Colors.light),
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
          ~paddingHorizontal=Size.pt(12.),
          ~paddingVertical=Size.pt(6.),
          ~fontSize=12.,
          (),
        ),
    },
  );

[@react.component]
let make = (~currentLocation) => {
  let uri = Consts.baseUrl ++ "/apple-touch-icon.png";
  let width = 36.;
  let height = 36.;
  <View style=styles##menu>
    <Container style=styles##bar wrapperStyle=styles##barWrapper>
      <ViewLink style=styles##logo href={Consts.baseUrl ++ "/"}>
        /* <SVGLogo width=20. height=20. fill=Consts.Colors.dark /> */
        /* react-native-web doesn't render source when renderToString is used*/

          <Image
            source={
              Image.uriSource(~uri, ~width, ~height, ())
              ->Image.Source.fromUriSource
            }
            defaultSource={Image.DefaultSource.fromUri(
              ~uri,
              ~width,
              ~height,
              (),
            )}
          />
          <Text style=styles##logoText>
            {("  " ++ Consts.title)->ReasonReact.string}
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
