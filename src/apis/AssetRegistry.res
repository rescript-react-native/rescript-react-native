type resolver = [#android | #generic]

type packagerAsset = {
  fileSystemLocation: string,
  httpServerLocation: string,
  width?: float,
  height?: float,
  scales: array<float>,
  hash: string,
  name: string,
  @as("type") type_: string,
  resolver?: resolver,
}

@module("react-native") @scope("AssetRegistry")
external registerAsset: packagerAsset => Packager.required = "registerAsset"

@module("react-native") @scope("AssetRegistry")
external getAssetByID: Packager.required => packagerAsset = "getAssetByID"
