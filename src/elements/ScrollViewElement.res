type nativeElement = [#scrollView]
include NativeElement.Impl({type t = nativeElement})
include ScrollViewMethods

type scrollToOptions = {
  x?: float,
  y?: float,
  animated?: bool,
}

@send external scrollTo: (element, scrollToOptions) => unit = "scrollTo"
