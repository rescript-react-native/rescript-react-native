// Methods of virtualized section list elements (`[> #virtualizedSectionList]`)

type scrollToLocationParams = {
  itemIndex: int,
  sectionIndex: int,
  animated?: bool,
  viewOffset?: float,
  viewPosition?: float,
}

@send
external scrollToLocation: (
  DOMAPI.element<[> #virtualizedSectionList]>,
  scrollToLocationParams,
) => unit = "scrollToLocation"

@send
external recordInteraction: DOMAPI.element<[> #virtualizedSectionList]> => unit =
  "recordInteraction"

@send
external flashScrollIndicators: DOMAPI.element<[> #virtualizedSectionList]> => unit =
  "flashScrollIndicators"
