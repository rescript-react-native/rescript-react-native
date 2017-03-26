type style;


module StyleSheet = {
  type t; 
  external t : t = "StyleSheet" [@@bs.module "react-native"];
  external _create: t => Js.t 'a => Js.t 'a = 
    "create" [@@bs.send];
  let create : Js.t 'a => Js.t 'a = fun a => _create t a;

  external _hairlineWidth: t => int = "hairlineWidth" [@@bs.get];
  let hairlineWidth = _hairlineWidth t;

  external _absoluteFill: t => style = "absoluteFill" [@@bs.get];
  let absoluteFill = _absoluteFill t;

  external _absoluteFillObject: t => style = "absoluteFillObject" [@@bs.get];
  let absoluteFillObject = _absoluteFillObject t;
};

let combine : style => style => style = [%bs.raw {|
    function (a, b) {
      return Object.assign({}, a, b);
    }
  |}];
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

/*layout*/
/*backfaceVisibility enum('visible', 'hidden')
  backgroundColor color
  borderBottomColor color
  borderBottomLeftRadius number
  borderBottomRightRadius number
  borderBottomWidth number
  borderColor color
  borderLeftColor color
  borderLeftWidth number*/
/*module Text = {
    type ellipsizeModeT = [ | `head | `middle | `tail | `clip] [@bs.string];
    external text : ReactRe.reactClass = "Text" [@@bs.module "react-native"];
    let createElement
        accessible::(accessible: option bool)=?
        allowFontScaling::(allowFontScaling: option bool)=?
        ellipsizeMode::(ellipsizeMode: option ellipsizeModeT)=?
        numberOfLines::(numberOfLines: option int)=? =>
      ReactRe.wrapPropsShamelessly
        text
        {
          "accessible": Js.Undefined.from_opt (optionMap Js.Boolean.to_js_boolean accessible),
          "allowFontScaling":
            Js.Undefined.from_opt (optionMap Js.Boolean.to_js_boolean allowFontScaling),
          "ellipsizeMode":
            Js.Undefined.from_opt (
              optionMap
                (
                  fun
                  | `head => "head"
                  | `middle => "middle"
                  | `tail => "tail"
                  | `clip => "clip"
                )
                ellipsizeMode
            ),
          "numberOfLines": Js.Undefined.from_opt numberOfLines
        };
  };*/

module AppRegistry = {
  type t;
  external t : t = "AppRegistry" [@@bs.module "react-native"];
  external _registerComponent : t => string => (unit => ReactRe.reactClass) => unit =
    "registerComponent" [@@bs.send];
  let registerComponent name comp => _registerComponent t name comp;
};

let optionMap fn opt_value =>
  switch opt_value {
  | None => None
  | Some value => Some (fn value)
};

module Text = {
  external text : ReactRe.reactClass = "Text" [@@bs.module "react-native"];
  let createElement
      ::accessible=?
      allowFontScaling::(allowFontScaling: option bool)=?
      ellipsizeMode::(ellipsizeMode: option [ | `head | `middle | `tail | `clip])=?
      numberOfLines::(numberOfLines: option int)=?
      style::(style: option style)=? =>
    ReactRe.wrapPropsShamelessly
      text
      {
        "accessible": Js.Undefined.from_opt (optionMap Js.Boolean.to_js_boolean accessible),
        "allowFontScaling":
          Js.Undefined.from_opt (optionMap Js.Boolean.to_js_boolean allowFontScaling),
        "ellipsizeMode":
          Js.Undefined.from_opt (
            optionMap
              (
                fun
                | `head => "head"
                | `middle => "middle"
                | `tail => "tail"
                | `clip => "clip"
              )
              ellipsizeMode
          ),
        "style": Js.Undefined.from_opt style,
        "numberOfLines": Js.Undefined.from_opt numberOfLines
      };
};

module View = {
  external view : ReactRe.reactClass = "View" [@@bs.module "react-native"];
  let createElement
      accessible::(accessible: option bool)=?
      onClick::(onClick: option (ReactRe.event => unit))=? =>
    ReactRe.wrapPropsShamelessly
      view
      {
        "accessible": Js.Undefined.from_opt (optionMap Js.Boolean.to_js_boolean accessible),
        "onClick": Js.Undefined.from_opt onClick
      };
};