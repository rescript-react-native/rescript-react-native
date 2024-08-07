// VirtualizedList props 0.72 data, getItem, getItemCount and getItemLayout
// are not supported on FlatList
// FlatList has its own data prop, specified as array(item)

include VirtualizedListElement

type separatorComponentProps<'item> = {"highlighted": bool, "leadingItem": option<'item>}

type flatListProps<'item, 'extraData> = {
  ...VirtualizedList.virtualizedListProps<array<'item>, 'item, 'extraData>,
  numColumns?: int,
  columnWrapperStyle?: Style.t,
}

@react.component(: flatListProps<'item, 'extraData>) @module("react-native")
external make: flatListProps<'item, 'extraData> => React.element = "FlatList"
