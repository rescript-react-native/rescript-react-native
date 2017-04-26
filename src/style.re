type t;

let combine (a: Js.t t) (b: Js.t t) :Js.t t =>
  Obj.magic (Js.Obj.assign (Obj.magic a) (Obj.magic b));

let a = {"width": 5, "height": 4};
external style :
  alignContent::[
    | `flexStart [@bs.as "flex-start"]
    | `flexEnd [@bs.as "flex-end"]
    | `center
    | `stretch
    | `spaceAround [@bs.as "space-around"]
    | `spaceBetween  [@bs.as "space-between"]
    ] [@bs.string]? =>
  alignItem::[ | `flexStart [@bs.as "flex-start"] | `flexEnd [@bs.as "flex-end"] | `center | `stretch | `baseline] [@bs.string]? =>
  alignSelf::[ | `auto | `flexStart [@bs.as "flex-start"]  | `flexEnd [@bs.as "flex-end"] | `center | `stretch | `baseline] [@bs.string]? =>
  aspectRation::float? =>
  backgroundColor::string? =>
  borderBottomWidth::int? =>
  borderLeftWidth::int? =>
  borderRightWidth::int? =>
  borderTopWidth::int? =>
  borderWidth::int? =>
  bottom::int? =>
  bottomString::string? =>
  color::string? =>
  flex::int? =>
  flexBasis::int? =>
  flexDirection::[
    | `row
    | `rowReverse [@bs.as "row-reverse"]
    | `column
    | `columnReverse [@bs.as "column-reverse"]
    ] [@bs.string]? =>
  flexGrow::int? =>
  flexShrink::int? =>
  flexWrap::[ | `wrap | `nowrap] [@bs.string]? =>
  height::int? =>
  heightString::string? =>
  justifyContent::[
    | `flexStart [@bs.as "flex-start"]
    | `flexEnd [@bs.as "flex-end"]
    | `center
    | `spaceBetween [@bs.as "space-between"]
    | `spaceAround  [@bs.as "space-around"]
    ][@bs.string]? =>
  left::int? =>
  leftString::string? =>
  margin::int? =>
  marginString::string? =>
  marginBottom::int? =>
  marginBottomString::string? =>
  marginHorizontal::int? =>
  marginHorizontalString::string? =>
  marginLeft::int? =>
  marginLeftString::string? =>
  marginRight::int? =>
  marginRightString::string? =>
  marginTop::int? =>
  marginTopString::string? =>
  marginVertical::int? =>
  marginVerticalString::string? =>
  maxHeight::int? =>
  maxHeightString::string? =>
  maxWidth::int? =>
  maxWidthString::string? =>
  minHeight::int? =>
  minHeightString::string? =>
  minWidth::int? =>
  minWidthString::string? =>
  overflow::[ | `visible | `hidden | `scroll] [@bs.string]? =>
  padding::int? =>
  paddingString::string? =>
  paddingBottom::int? =>
  paddingBottomString::string? =>
  paddingHorizontal::int? =>
  paddingHorizontalString::string? =>
  paddingLeft::int? =>
  paddingLeftString::string? =>
  paddingRight::int? =>
  paddingRightString::string? =>
  paddingTop::int? =>
  paddingTopString::string? =>
  paddingVertical::int? =>
  paddingVerticalString::string? =>
  position::[ | `absolute | `relative] [@bs.string]? =>
  right::int? =>
  rightString::string? =>
  top::int? =>
  topString::string? =>
  width::int? =>
  widthString::string? =>
  zIndex::int? =>
  /* text */
  fontFamiliy::string? =>
  fontSize::int? =>
  fontStyle::[ | `normal | `italic] [@bs.string]? =>
  fontWeight::[ | `normal | `bold 
  | `_100 [@bs.as "100"]
  | `_200 [@bs.as "200"]
  | `_300 [@bs.as "300"]
  | `_400 [@bs.as "400"]
  | `_500 [@bs.as "500"]
  | `_600 [@bs.as "600"]
  | `_700 [@bs.as "700"]
  | `_800 [@bs.as "800"]
  | `_900 [@bs.as "900"] ] [@bs.string]? =>
  lineHeight::int? =>
  textAlign::([ | `auto | `left | `right | `center | `justify ] [@bs.string])? =>
  textDecorationLine::([
    | `none
    | `underline
    | `lineThrough [@bs.as "line-through"]
    | `underlineLineThrough [@bs.as "underline line-through"]
  ] [@bs.string])? =>
  textShadowColor::string? =>
  textShadowOffset::(Js.t {. height: int, width: int} )? =>
  textShadowRadius::int? =>
  includeFontPadding::Js.boolean? =>
  textAlign::([ | `auto | `top | `bottom | `center ] [@bs.string])? =>
  fontVariant::(array string)? =>
  letterSpacing::float? =>
  textDecorationColor::string? =>
  textDecorationStyle::([ | `solid | `double | `dotted | `dashed] [@bs.string])? =>
  writingDirection::([ | `auto | `ltr | `rtl ] [@bs.string])? =>
  unit =>
  t =
  "" [@@bs.obj];