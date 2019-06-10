open Belt;
open ReactNative;
open ReactMultiversal;

let styles =
  Style.(
    StyleSheet.create({
      "card":
        style(
          ~borderRadius=4.,
          ~borderStyle=`solid,
          ~borderWidth=Predefined.hairlineWidth,
          ~borderColor=Predefined.Colors.dark,
          (),
        ),
    })
  );

[@react.component]
let make = (~docsIndex, ~blogIndex, ~currentLocation) => {
  <>
    <Head />
    <HeaderLarge currentLocation />
    <Container
      maxWidth={1000.->Style.dp}
      style=Style.(
        style(~flexDirection=`row, ~flexWrap=`wrap, ~height=100.->pct, ())
      )>
      <ContentContainer>
        {{blogIndex->Array.map(indexEntry =>
            <ViewLink
              key=indexEntry##title
              href={Consts.baseUrl ++ "/en/blog/" ++ indexEntry##id}>
              <SpacedView style=styles##card>
                <Title> {indexEntry##title->React.string} </Title>
                <Spacer />
                <TextLight>
                  {indexEntry##date->React.string}
                  {("  |  By @" ++ indexEntry##author)->React.string}
                </TextLight>
              </SpacedView>
            </ViewLink>
          )}
         ->React.array}
      </ContentContainer>
      <SidebarDocs docsIndex />
    </Container>
  </>;
};
