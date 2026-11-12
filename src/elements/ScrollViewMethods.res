// Methods of elements that are scroll views (`[> #scrollView]`)

type scrollToEndOptions = {animated?: bool, duration?: float}

@send
external scrollToEnd: (DOMAPI.element<[> #scrollView]>, ~options: scrollToEndOptions=?) => unit =
  "scrollToEnd"

@send
external flashScrollIndicators: DOMAPI.element<[> #scrollView]> => unit = "flashScrollIndicators"
