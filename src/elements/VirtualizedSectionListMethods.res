// Methods of virtualized section list elements (`[> #virtualizedSectionList]`)

type scrollToLocationParams = {
  itemIndex: int,
  sectionIndex: int,
  animated?: bool,
  viewOffset?: int,
  viewPosition?: float,
}

@send
external scrollToLocation: (
  DOMAPI.element<[> #virtualizedSectionList]>,
  scrollToLocationParams,
) => unit = "scrollToLocation"
