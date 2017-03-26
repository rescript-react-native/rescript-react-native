type style;

module AppRegistry: {
  type t;
  let registerComponent: string => (unit => ReactRe.reactClass) => unit;
};

module Text: {
  let createElement:
    accessible::bool? =>
    allowFontScaling::bool? =>
    ellipsizeMode::[ | `head | `middle | `tail | `clip]? =>
    numberOfLines::int? =>
    style::style? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};

module StyleSheet : {
    type t;
    let create: Js.t 'a => Js.t 'a;
};

external style :
  /* layout props */
  alignItem::([
    | `flexStart [@bs.as "flex-start"]
    | `flexEnd [@bs.as "flex-end"]
    | `center | `stretch | `baseline] [@bs.string])? =>
  alignSelf::([
    | `auto
    | `flexStart [@bs.as "flex-start"]
    | `flexEnd [@bs.as "flex-end"]
    | `center | `stretch | `baseline] [@bs.string])? =>
  aspectRation::float? =>
  borderBottomWidth::int? =>
  borderLeftWidth::int? =>
  borderRightWidth::int? =>
  borderTopWidth::int? =>
  borderWidth::int? =>
  bottom::int? =>
  bottomPct::string? =>
  flex::int? =>
  flexBasis::int? =>
  flexDirection::([
    | `row
    | `rowReverse [@bs.as "row-reverse"]
    | `column
    | `columnReverse [@bs.as "columnReverse"]] [@bs.string])? =>
  flexGrow::int? =>
  flexShrink::int? =>
  flexWrap::([`wrap | `nowrap] [@bs.string])? =>
  height::int? =>
  heightPct::string? =>
  justifyContent::([
    | `flexStart [@bs.as "flex-start"]
    | `flexEnd [@bs.as "flex-end"]
    | `center
    | `spaceBetween [@bs.as "space-between"]
    | `spaceAround [@bs.as "space-around"]] [@bs.string])? =>
  left::int? =>
  leftPct::string? =>
  margin::int? =>
  marginPct::string? =>
  marginBottom::int? =>
  marginBottomPct::string? =>
  marginHorizontal::int? =>
  marginHorizontalPct::string? =>
  marginLeft::int? =>
  marginLeftPct::string? =>
  marginRight::int? =>
  marginRightPct::string? =>
  marginTop::int? =>
  marginTopPct::string? =>
  marginVertical::int? =>
  marginVerticalPct::string? =>
  maxHeight::int? =>
  maxHeightPct::string? =>
  maxWidth::int? =>
  maxWidthPct::string? =>
  minHeight::int? =>
  minHeightPct::string? =>
  minWidth::int? =>
  minWidthPct::string? =>
  overflow::([`visible | `hidden | `scroll] [@bs.string])? =>
  padding::int? =>
  paddingPct::string? =>
  paddingBottom::int? =>
  paddingBottomPct::string? =>
  paddingHorizontal::int? =>
  paddingHorizontalPct::string? =>
  paddingLeft::int? =>
  paddingLeftPct::string? =>
  paddingRight::int? =>
  paddingRightPct::string? =>
  paddingTop::int? =>
  paddingTopPct::string? =>
  paddingVertical::int? =>
  paddingVerticalPct::string? =>
  position::([`absolute | `relative] [@bs.string])? =>
  right::int? =>
  rightPct::string? =>
  top::int? =>
  topPct::string? =>
  width::int? =>
  widthPct::string? =>
  zIndex::int? =>
  unit =>
  style =
  "" [@@bs.obj];

