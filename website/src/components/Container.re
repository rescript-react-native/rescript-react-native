open ReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "wrapper":
        style(
          ~flex=1.,
          ~width=Size.pct(100.),
          ~overflow=`hidden,
          ~alignItems=`center,
          (),
        ),
      "container":
        style(
          ~justifyContent=`center,
          ~flex=1.,
          ~width=Size.pct(100.),
          ~paddingHorizontal=Size.pt(Spacer.space /. 4.),
          (),
        ),
    },
  );

[@react.component]
let make =
    (
      ~spaceVertical=SpacedView.None,
      ~spaceHorizontal=SpacedView.None,
      ~wrapperStyle=?,
      ~style as s=?,
      ~backgroundColor=Some(Consts.Colors.light),
      ~maxWidth=1200.,
      ~children,
    ) =>
  <SpacedView
    vertical=spaceVertical
    horizontal=spaceHorizontal
    style=Style.(
      arrayOption([|
        Some(styles##wrapper),
        backgroundColor->Belt.Option.map(bg =>
          style(~backgroundColor=color(bg), ())
        ),
        wrapperStyle,
      |])
    )>
    <View
      style=Style.(
        arrayOption([|
          Some(styles##container),
          Some(style(~maxWidth=Size.pt(maxWidth), ())),
          s,
        |])
      )>
      ...children
    </View>
  </SpacedView>;
