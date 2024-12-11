include VirtualizedSectionListElement

@send
external flashScrollIndicators: element => unit = "flashScrollIndicators"

@send external recordInteraction: element => unit = "recordInteraction"

@send
external setNativeProps: (element, {..}) => unit = "setNativeProps"

type props<'sectionData, 'item, 'extraData> = {
  ref?: ref,
  ...VirtualizedSectionList.virtualizedSectionListProps<'sectionData, 'item, 'extraData>,
}

@module("react-native")
external make: React.component<props<'sectionData, 'item, 'extraData>> = "SectionList"
