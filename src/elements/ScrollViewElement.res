type nativeElement

include NativeElement.Impl({type t = nativeElement})

include ScrollViewMethods.Make({type t = element})

type scrollToOptions = {
  x: float,
  y: float,
  animated?: bool,
  duration?: float,
}

@send external scrollTo: (element, scrollToOptions) => unit = "scrollTo"
