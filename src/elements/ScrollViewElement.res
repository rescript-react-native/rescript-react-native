type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asScrollViewElement: DOMAPI.anyElement => element = "%identity"

include ScrollViewMethods.Make({
  type t = element
})

type scrollToParams = {
  x: float,
  y: float,
  animated?: bool,
  duration?: float,
}

@send external scrollTo: (element, scrollToParams) => unit = "scrollTo"
