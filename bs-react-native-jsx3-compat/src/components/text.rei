module type TextComponent = {
  /**
A React component for displaying text.
You can read more on [Text] component usage in official docs: {{:https://facebook.github.io/react-native/docs/text}}

  {3 Props}

  {4 accessible}
  {[
    ~accessible: bool=?
  ]}
  {4 accessibilityHint}
  {[
    ~accessibilityHint: string=?
  ]}
  {4 accessibilityLabel}
  {[
    ~accessibilityLabel: string=?
  ]}
  {4 allowFontScaling}
  {[
    ~allowFontScaling: bool=?
  ]}
  {4 ellipsizeMode}
  {[
    ~ellipsizeMode: [
      | `clip
      | `head
      | `middle
      | `tail
    ]=?
  ]}
  {4 numberOfLines}
  {[
    ~numberOfLines: int=?
  ]}
  {4 onLayout}
  {[
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?
  ]}
  reference:
  {[
    module NativeLayoutEvent: {
      type t;
      type layout = {
        x: float,
        y: float,
        width: float,
        height: float
      };
      let layout: t => layout;
    };
  ]}
  {4 onLongPress}
  {[
    ~onLongPress: unit => unit=?
  ]}
  {4 onPress}
  {[
    ~onPress: unit => unit=?
  ]}
  {4 pressRetentionOffset}
  {[
    ~pressRetentionOffset: Types.insets=?
  ]}
  reference:
  {[
    type insets = {
      .
      "left": int,
      "right": int,
      "top": int,
      "bottom": int,
    };
  ]}
  {4 selectable}
  {[
    ~selectable: bool=?
  ]}
  {4 style}
  {[
    ~style: Style.t=?
  ]}
  {4 testID}
  {[
    ~testID: string=?
  ]}
  {4 selectionColor}
  {[
    ~selectionColor: string=?
  ]}
  {4 textBreakStrategy}
  {[
    ~textBreakStrategy: [
      | `balanced
      | `highQuality
      | `simple
    ]=?
  ]}
  {4 adjustsFontSizeToFit}
  {[
    ~adjustsFontSizeToFit: bool=?
  ]}
  {4 minimumFontScale}
  {[
    ~minimumFontScale: float=?
  ]}
  {4 suppressHighlighting}
  {[
    ~suppressHighlighting: bool=?
  ]}
  {4 value}
  {[
    ~value: string=?
  ]}
 */

  let make:
    (
      ~accessible: bool=?,
      ~accessibilityHint: string=?,
      ~accessibilityLabel: string=?,
      ~allowFontScaling: bool=?,
      ~ellipsizeMode: [ | `clip | `head | `middle | `tail]=?,
      ~numberOfLines: int=?,
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
      ~onLongPress: unit => unit=?,
      ~onPress: unit => unit=?,
      ~pressRetentionOffset: Types.insets=?,
      ~selectable: bool=?,
      ~style: Style.t=?,
      ~testID: string=?,
      ~selectionColor: string=?,
      ~textBreakStrategy: [ | `balanced | `highQuality | `simple]=?,
      ~adjustsFontSizeToFit: bool=?,
      ~minimumFontScale: float=?,
      ~suppressHighlighting: bool=?,
      ~value: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent: (Impl: View.Impl) => TextComponent;

include TextComponent;
