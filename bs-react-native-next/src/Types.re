[@bs.deriving abstract]
type insets = {
  left: float,
  right: float,
  top: float,
  bottom: float,
};

[@bs.deriving abstract]
type point = {
  x: float,
  y: float,
};

module AccessibilityState = {
  type t;

  external fromString: string => t = "%identity";

  let selected = "selected"->fromString;
  let disabled = "disabled"->fromString;
};

module AccessibilityTrait = {
  type t;

  external fromString: string => t = "%identity";

  let none = "none"->fromString;
  let button = "button"->fromString;
  let link = "link"->fromString;
  let header = "header"->fromString;
  let search = "search"->fromString;
  let image = "image"->fromString;
  let selected = "selected"->fromString;
  let plays = "plays"->fromString;
  let key = "key"->fromString;
  let text = "text"->fromString;
  let summary = "summary"->fromString;
  let disabled = "disabled"->fromString;
  let frequentUpdates = "frequentUpdates"->fromString;
  let startsMedia = "startsMedia"->fromString;
  let adjustable = "adjustable"->fromString;
  let allowsDirectInteraction = "allowsDirectInteraction"->fromString;
  let pageTurn = "pageTurn"->fromString;
};
