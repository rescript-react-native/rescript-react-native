type element
type ref = Ref.t<element>

include ScrollViewMethods.Make({
  type t = element
})

type scrollToParams = {
  x: float,
  y: float,
  animated?: bool,
  duration?: float,
}

@obj
external // @deprecated("Directly create record instead")
scrollToParams: (
  ~x: float,
  ~y: float,
  ~animated: bool=?,
  ~duration: float=?,
  unit,
) => scrollToParams = ""
@send external scrollTo: (element, scrollToParams) => unit = "scrollTo"
