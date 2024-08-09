// VirtualizedList props 0.72 data, getItem, getItemCount and getItemLayout
// are not supported on FlatList
// FlatList has its own data prop, specified as array(item)

include VirtualizedListElement

type separatorComponentProps<'item> = {"highlighted": bool, "leadingItem": option<'item>}

type props<'item, 'extraData> = {
  ...VirtualizedList.props<array<'item>, 'item, 'extraData>,
  numColumns?: int,
  columnWrapperStyle?: Style.t,
}

@module("react-native")
external make: React.component<props<'item, 'extraData>> => React.element = "FlatList"
