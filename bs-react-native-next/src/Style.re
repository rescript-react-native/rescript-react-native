let pct = num => num->Js.Float.toString ++ "%";

// Unsafe, unfortunately, but allows us to pass animated values everywhere.
// May be refined later.
external animated: AnimatedRe.value('a) => 'b = "%identity";

module Margin = {
  type t;

  external pt: float => t = "%identity";
  let pct: float => t = pct->Obj.magic;
  let auto: t = "auto"->Obj.magic;
};

module Size = {
  type t;

  external pt: float => t = "%identity";
  let pct: float => t = pct->Obj.magic;
};

type color;
external color: string => color = "%identity";

module Transform = {
  type angle;

  let deg: float => angle =
    num => (num->Js.Float.toString ++ "deg")->Obj.magic;
  let rad: float => angle =
    num => (num->Js.Float.toString ++ "rad")->Obj.magic;

  type t;
  [@bs.obj] external perspective: (~perspective: float) => t = "";
  [@bs.obj] external rotate: (~rotate: angle) => t = "";
  [@bs.obj] external rotateX: (~rotateX: angle) => t = "";
  [@bs.obj] external rotateY: (~rotateY: angle) => t = "";
  [@bs.obj] external rotateZ: (~rotateZ: angle) => t = "";
  [@bs.obj] external scale: (~scale: float) => t = "";
  [@bs.obj] external scaleX: (~scaleX: float) => t = "";
  [@bs.obj] external scaleY: (~scaleY: float) => t = "";
  [@bs.obj] external translateX: (~translateX: float) => t = "";
  [@bs.obj] external translateY: (~translateY: float) => t = "";
  [@bs.obj] external skewX: (~skewX: angle) => t = "";
  [@bs.obj] external skewY: (~skewY: angle) => t = "";
};

module FontVariant = {
  type t;

  external fromString: string => t = "%identity";

  let smallCaps = "small-caps"->fromString;
  let oldstyleNums = "oldstyle-nums"->fromString;
  let liningNums = "lining-nums"->fromString;
  let tabularNums = "tabular-nums"->fromString;
  let proportionalNums = "proportional-nums"->fromString;
};

type offset;
[@bs.obj] external offset: (~height: float, ~width: float) => offset = "";

type t;

[@bs.obj]
// Layout Props (https://facebook.github.io/react-native/docs/layout-props#props)
// View Style Props https://facebook.github.io/react-native/docs/view-style-props#props
external style:
  (
    ~alignContent: [@bs.string] [
                     | [@bs.as "flex-start"] `flexStart
                     | [@bs.as "flex-end"] `flexEnd
                     | `center
                     | `stretch
                     | [@bs.as "space-around"] `spaceAround
                     | [@bs.as "space-between"] `spaceBetween
                   ]
                     =?,
    ~alignItems: [@bs.string] [
                   | [@bs.as "flex-start"] `flexStart
                   | [@bs.as "flex-end"] `flexEnd
                   | `center
                   | `stretch
                   | `baseline
                 ]
                   =?,
    ~alignSelf: [@bs.string] [
                  | [@bs.as "flex-start"] `flexStart
                  | [@bs.as "flex-end"] `flexEnd
                  | `center
                  | `stretch
                  | `baseline
                ]
                  =?,
    ~aspectRatio: float=?,
    ~backfaceVisibility: [@bs.string] [ | `visible | `hidden]=?,
    ~backgroundColor: color=?,
    ~borderBottomColor: color=?,
    ~borderBottomEndRadius: float=?,
    ~borderBottomLeftRadius: float=?,
    ~borderBottomRightRadius: float=?,
    ~borderBottomStartRadius: float=?,
    ~borderBottomWidth: float=?,
    ~borderColor: color=?,
    ~borderEndColor: color=?,
    ~borderEndWidth: float=?,
    ~borderLeftColor: color=?,
    ~borderLeftWidth: float=?,
    ~borderRadius: float=?,
    ~borderRightColor: color=?,
    ~borderRightWidth: float=?,
    ~borderStartColor: color=?,
    ~borderStartWidth: float=?,
    ~borderStyle: [@bs.string] [ | `solid | `dotted | `dashed]=?,
    ~borderTopColor: color=?,
    ~borderTopEndRadius: float=?,
    ~borderTopLeftRadius: float=?,
    ~borderTopRightRadius: float=?,
    ~borderTopStartRadius: float=?,
    ~borderTopWidth: float=?,
    ~borderWidth: float=?,
    ~bottom: Size.t=?,
    ~direction: [@bs.string] [ | [@bs.as "inherit"] `inherit_ | `ltr | `ltr]=?,
    ~display: [@bs.string] [ | `none | `flex]=?,
    ~elevation: float=?,
    ~_end: float=?,
    ~flex: float=?,
    ~flexBasis: Margin.t=?,
    ~flexDirection: [@bs.string] [
                      | `row
                      | [@bs.as "row-reverse"] `rowReverse
                      | `column
                      | [@bs.as "column-reverse"] `columnReverse
                    ]
                      =?,
    ~flexGrow: float=?,
    ~flexShrink: float=?,
    ~flexWrap: [@bs.string] [ | `wrap | `nowrap]=?,
    ~height: Size.t=?,
    ~justifyContent: [@bs.string] [
                       | [@bs.as "flex-start"] `flexStart
                       | [@bs.as "flex-end"] `flexEnd
                       | `center
                       | [@bs.as "space-around"] `spaceAround
                       | [@bs.as "space-between"] `spaceBetween
                       | [@bs.as "space-evenly"] `spaceEvenly
                     ]
                       =?,
    ~left: Size.t=?,
    ~margin: Margin.t=?,
    ~marginBottom: Margin.t=?,
    ~marginEnd: Margin.t=?,
    ~marginHorizontal: Margin.t=?,
    ~marginLeft: Margin.t=?,
    ~marginRight: Margin.t=?,
    ~marginStart: Margin.t=?,
    ~marginTop: Margin.t=?,
    ~marginVertical: Margin.t=?,
    ~maxHeight: Size.t=?,
    ~maxWidth: Size.t=?,
    ~minHeight: Size.t=?,
    ~minWidth: Size.t=?,
    ~opacity: float=?,
    ~overflow: [@bs.string] [ | `visible | `hidden | `scroll]=?,
    ~padding: Size.t=?,
    ~paddingBottom: Size.t=?,
    ~paddingEnd: Size.t=?,
    ~paddingHorizontal: Size.t=?,
    ~paddingLeft: Size.t=?,
    ~paddingRight: Size.t=?,
    ~paddingStart: Size.t=?,
    ~paddingTop: Size.t=?,
    ~paddingVertical: Size.t=?,
    ~position: [@bs.string] [ | `absolute | `relative]=?,
    ~right: Size.t=?,
    ~start: Size.t=?,
    ~top: Size.t=?,
    ~width: Size.t=?,
    ~zIndex: int=?,
    // Shadow Props (https://facebook.github.io/react-native/docs/shadow-props)
    ~shadowColor: color=?,
    ~shadowOffset: offset=?,
    ~shadowOpacity: float=?,
    ~shadowRadius: float=?,
    // Transform Props (https://facebook.github.io/react-native/docs/transforms#props)
    ~transform: array(Transform.t)=?, // all other transform props are deprecated
    // Text Style Props (https://facebook.github.io/react-native/docs/text-style-props)
    ~color: color=?,
    ~fontFamily: string=?,
    ~fontSize: float=?,
    ~fontStyle: [@bs.string] [ | `normal | `italic]=?,
    ~fontVariant: array(FontVariant.t)=?,
    ~fontWeight: [@bs.string] [
                   | `normal
                   | `bold
                   | [@bs.as "100"] `_100
                   | [@bs.as "200"] `_200
                   | [@bs.as "300"] `_300
                   | [@bs.as "400"] `_400
                   | [@bs.as "500"] `_500
                   | [@bs.as "600"] `_600
                   | [@bs.as "700"] `_700
                   | [@bs.as "800"] `_800
                   | [@bs.as "900"] `_900
                 ]
                   =?,
    ~includeFontPadding: bool=?,
    ~letterSpacing: float=?,
    ~lineHeight: float=?,
    ~textAlign: [@bs.string] [ | `auto | `left | `right | `center | `justify]=?,
    ~textAlignVertical: [@bs.string] [ | `auto | `top | `bottom | `center]=?,
    ~textDecorationColor: color=?,
    ~textDecorationLine: [@bs.string] [
                           | `none
                           | `underline
                           | [@bs.as "line-through"] `lineThrough
                           | [@bs.as "underline line-through"]
                             `underlineLineThrough
                         ]
                           =?,
    ~textDecorationStyle: [@bs.string] [
                            | `solid
                            | `double
                            | `dotted
                            | `dashed
                          ]
                            =?,
    ~textShadowColor: color=?,
    ~textShadowOffset: offset=?,
    ~textShadowRadius: float=?,
    ~textTransform: [@bs.string] [
                      | `none
                      | `uppercase
                      | `lowercase
                      | `capitalize
                    ]
                      =?,
    ~writingDirection: [@bs.string] [ | `auto | `ltr | `ltr]=?,
    // Image Style Props (https://facebook.github.io/react-native/docs/image-style-props)
    ~resizeMode: [@bs.string] [
                   | `cover
                   | `contain
                   | `stretch
                   | `repeat
                   | `center
                 ]
                   =?,
    ~overlayColor: color=?,
    ~tintColor: color=?,
    unit
  ) =>
  t =
  "";

external array: array(t) => t = "%identity";
external arrayOption: array(option(t)) => t = "%identity";
external list: list(t) => t = "%identity";
external listOption: list(option(t)) => t = "%identity";
