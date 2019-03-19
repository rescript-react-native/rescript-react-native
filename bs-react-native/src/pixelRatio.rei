/**
PixelRatio class gives access to the device pixel density.

You can read more on [PixelRation] API usage in official docs: {{:https://facebook.github.io/react-native/docs/pixelratio}}

{3 Methods }


*/

let get: unit => float;

/**
Returns the device pixel density
 */

let getFontScale: unit => float;
/**
Returns the scaling factor for font sizes. This is the ratio that is used to calculate the absolute font size, so any elements that heavily depend on that should use this to do calculations.

If a font scale is not set, this returns the device pixel ratio.

Currently this is only implemented on Android and reflects the user preference set in Settings > Display > Font size, on iOS it will always return the default pixel ratio.
 */

let getPixelSizeForLayoutSize: int => int;

/**
Converts a layout size (dp) to pixel size (px).

Guaranteed to return an integer number.
 */

let roundToNearestPixel: float => float;

/**
Rounds a layout size (dp) to the nearest layout size that corresponds to an integer number of pixels. For example, on a device with a PixelRatio of 3, PixelRatio.roundToNearestPixel(8.4) = 8.33, which corresponds to exactly (8.33 * 3) = 25 pixels.
 */;
