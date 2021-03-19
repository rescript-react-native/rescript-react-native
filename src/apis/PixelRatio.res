@scope("PixelRatio") @module("react-native")
external get: unit => float = "get"

@scope("PixelRatio") @module("react-native")
external getFontScale: unit => float = "getFontScale"

@scope("PixelRatio") @module("react-native")
external getPixelSizeForLayoutSize: float => int = "getPixelSizeForLayoutSize"

@scope("PixelRatio") @module("react-native")
external roundToNearestPixel: float => float = "roundToNearestPixel"
