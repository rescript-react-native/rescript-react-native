// VirtualizedList props 0.72 data, getItem, getItemCount and getItemLayout
// are not supported on FlatList
// FlatList has its own data prop, specified as array(item)

include VirtualizedListElement

type props<'item, 'extraData> = {
  ref?: ref,
  ...VirtualizedList.coreProps<array<'item>, 'item, 'extraData>,
  numColumns?: int,
  columnWrapperStyle?: Style.t,
}

@module("react-native")
external make: React.component<props<'item, 'extraData>> = "FlatList"
