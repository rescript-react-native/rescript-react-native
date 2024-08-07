include VirtualizedSectionListElement

@send
external flashScrollIndicators: element => unit = "flashScrollIndicators"

@send external recordInteraction: element => unit = "recordInteraction"

@send
external setNativeProps: (element, Js.t<'a>) => unit = "setNativeProps"

@react.component(:
  VirtualizedSectionList.virtualizedSectionListProps<'sectionData, 'item, 'extraData>
)
@module("react-native")
external make: VirtualizedSectionList.virtualizedSectionListProps<
  'sectionData,
  'item,
  'extraData,
> => React.element = "SectionList"
