type nativeElement = [#scrollView]
include NativeElement.Impl({type t = nativeElement})
include ScrollViewMethods

type scrollToOptions = {
  ...Layout.point,
  animated?: bool,
  duration?: float,
}

@send external scrollTo: (element, scrollToOptions) => unit = "scrollTo"
