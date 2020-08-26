module IOS = {
  [@bs.module "react-native"]
  external get:
    (
    [@bs.string]
    [
      | `label
      | `secondaryLabel
      | `tertiaryLabel
      | `quaternaryLabel
      | `systemFill
      | `secondarySystemFill
      | `tertiarySystemFill
      | `quaternarySystemFill
      | `placeholderText
      | `systemBackground
      | `secondarySystemBackground
      | `tertiarySystemBackground
      | `systemGroupedBackground
      | `secondarySystemGroupedBackground
      | `tertiarySystemGroupedBackground
      | `separator
      | `opaqueSeparator
      | `link
      | `darkText
      | `lightText
    ]
    ) =>
    Color.t =
    "PlatformColor";
};

module Android = {
  [@bs.deriving jsConverter]
  type androidColor = [
    | `background_dark
    | `background_light
    | `black
    | `darker_gray
    | `holo_blue_bright
    | `holo_blue_dark
    | `holo_blue_light
    | `holo_green_dark
    | `holo_green_light
    | `holo_orange_dark
    | `holo_orange_light
    | `holo_purple
    | `holo_red_dark
    | `holo_red_light
    | `primary_text_dark
    | `primary_text_dark_nodisable
    | `primary_text_light
    | `primary_text_light_nodisable
    | `secondary_text_dark
    | `secondary_text_dark_nodisable
    | `secondary_text_light
    | `secondary_text_light_nodisable
    | `tab_indicator_text
    | `tertiary_text_dark
    | `tertiary_text_light
    | `transparent
    | `white
    | `widget_edittext_dark
  ];

  [@bs.deriving jsConverter]
  type attrColor = [
    | `color
    | `colorAccent
    | `colorActivatedHighlight
    | `colorBackground
    | `colorBackgroundFloating
    | `colorButtonNormal
    | `colorControlHighlight
    | `colorControlNormal
    | `colorEdgeEffect
    | `colorError
    | `colorFocusedHighlight
    | `colorForeground
    | `colorForegroundInverse
    | `colorLongPressedHighlight
    | `colorMultiSelectHighlight
    | `colorPressedHighlight
    | `colorPrimary
    | `colorPrimaryDark
    | `colorSecondary
  ];

  type t =
    | Attr(attrColor)
    | Color(androidColor);

  [@bs.module "react-native"]
  external unsafeGet: string => Color.t = "PlatformColor";

  let get = color => {
    let colorString =
      switch (color) {
      | Attr(value) => "?attr/" ++ attrColorToJs(value)
      | Color(value) => "@android:color/" ++ androidColorToJs(value)
      };

    unsafeGet(colorString);
  };
};
