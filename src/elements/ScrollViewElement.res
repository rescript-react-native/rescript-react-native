type element
type ref = Ref.t<element>

include ScrollViewMethods.Make({
  type t = element
})

type scrollToParams
@obj
external scrollToParams: (
  ~x: float,
  ~y: float,
  ~animated: bool=?,
  ~duration: float=?,
  unit,
) => scrollToParams = ""
@send external scrollTo: (element, scrollToParams) => unit = "scrollTo"
