let make:
  barTintColor::string? =>
  itemPositioning::[ | `fill | `center | `auto]? =>
  style::StyleRe.t? =>
  tintColor::string? =>
  translucent::bool? =>
  unselectedItemTintColor::string? =>
  unselectedTintColor::string? =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;
