include VirtualizedSectionListElement

type rec renderItemProps<'item, 'sectionData> = {
  item: 'item,
  index: int,
  section: section<'item, 'sectionData>,
  separators: separators,
}
and section<'item, 'sectionData> = {
  data: array<'item>,
  key?: string,
  renderItem?: renderItemCallback<'item, 'sectionData>,
  \"ItemSeparatorComponent"?: unit => React.element,
  keyExtractor?: ('item, int) => string,
  sectionData?: 'sectionData,
}
and separators = {
  highlight: unit => unit,
  unhighlight: unit => unit,
}
and renderItemCallback<'item, 'sectionData> = renderItemProps<'item, 'sectionData> => React.element

type rec renderSectionHeaderCallback<'item, 'sectionData> = renderSectionHeaderProps<
  'item,
  'sectionData,
> => React.element
and renderSectionHeaderProps<'item, 'sectionData> = {section: section<'item, 'sectionData>}

type separatorProps<'item, 'sectionData> = {
  highlighted: bool,
  leadingItem: 'item,
  leadingSection?: section<'item, 'sectionData>,
  section: section<'item, 'sectionData>,
  trailingItem?: 'item,
  trailingSection?: section<'item, 'sectionData>,
}

type virtualizedSectionListProps<'sectionData, 'item, 'extraData> = {
  ...VirtualizedList.virtualizedListCoreProps<'sectionData, 'item, 'extraData>,
  \"ItemSeparatorComponent"?: React.component<separatorProps<'item, 'sectionData>>,
  \"SectionSeparatorComponent"?: React.component<separatorProps<'item, 'sectionData>>,
  sections: array<section<'item, 'sectionData>>,
  renderItem: renderItemCallback<'item, 'sectionData>,
  renderSectionFooter?: renderSectionHeaderCallback<'item, 'sectionData>,
  renderSectionHeader?: renderSectionHeaderCallback<'item, 'sectionData>,
  stickySectionHeadersEnabled?: bool,
}

@react.component(: virtualizedSectionListProps<'sectionData, 'item, 'extraData>)
@module("react-native")
external make: virtualizedSectionListProps<'sectionData, 'item, 'extraData> => React.element =
  "VirtualizedSectionList"
