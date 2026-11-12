type t = {
  left?: float,
  right?: float,
  top?: float,
  bottom?: float,
}

// same value on all sides, e.g. `hitSlop={Rect.size(10.)}`
// (React Native accepts a number where a rect is expected for `hitSlop` and `pressRetentionOffset`)
external size: float => t = "%identity"
