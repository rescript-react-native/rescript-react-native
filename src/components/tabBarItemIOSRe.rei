let make:
  title::string? =>
  badgeColor::string? =>
  badge::string? =>
  icon::ImageRe.Image.imageSource? =>
  onPress::'c? =>
  renderAsOriginal::bool? =>
  style::StyleRe.t? =>
  selected::bool? =>
  selectedIcon::ImageRe.Image.imageSource? =>
  isTVSelectable::bool? =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;
