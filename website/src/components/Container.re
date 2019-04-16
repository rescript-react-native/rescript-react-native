open ReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "wrapper":
        style(~flex=1., ~alignItems=`center, ~width=Size.pct(100.), ()),
      "container":
        style(~flex=1., ~justifyContent=`center, ~width=Size.pct(100.), ()),
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
    <SpacedView
      vertical=SpacedView.None
      horizontal=SpacedView.XXS
      style=Style.(
        arrayOption([|
          Some(styles##container),
          Some(style(~maxWidth=Size.pt(maxWidth), ())),
          s,
        |])
      )>
      ...children
    </SpacedView>
  </SpacedView>;
