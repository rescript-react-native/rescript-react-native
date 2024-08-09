include VirtualizedSectionListElement

@send
external flashScrollIndicators: element => unit = "flashScrollIndicators"

@send external recordInteraction: element => unit = "recordInteraction"

@send
external setNativeProps: (element, Js.t<'a>) => unit = "setNativeProps"

@module("react-native")
external make: React.component<VirtualizedSectionList.props<'sectionData, 'item, 'extraData>> =
  "SectionList"
