include NativeElement

type ellipsizeMode = [#clip | #head | #middle | #tail]

type textBreakStrategy = [#simple | #highQuality | #balanced]

@react.component @bs.module("react-native")
external make: (
  ~ref: ref=?,
  ~accessible: // Text props
  bool=?,
  ~accessibilityHint: string=?,
  ~accessibilityLabel: string=?,
  ~accessibilityRole: // `accessibilityRole` communicates the purpose of a component to the user of an assistive technology.
  // roles that are specific for react-native-web are also included:
  // article, banner, complementary, contentinfo, form, list, listItem, main, navigation, region
  Accessibility.role=?,
  ~ariaLevel: int=?,
  ~allowFontScaling: bool=?,
  ~ellipsizeMode: ellipsizeMode=?,
  ~numberOfLines: int=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onLongPress: Event.pressEvent => unit=?,
  ~onPress: Event.pressEvent => unit=?,
  ~pressRetentionOffset: View.edgeInsets=?,
  ~selectable: bool=?,
  ~style: Style.t=?,
  ~testID: string=?,
  ~selectionColor: string=?,
  ~textBreakStrategy: textBreakStrategy=?,
  ~adjustsFontSizeToFit: bool=?,
  ~minimumFontScale: float=?,
  ~suppressHighlighting: bool=?,
  ~value: string=?,
  ~children: React.element=?,
  ~rel: // React Native Web Props
  @bs.string
  [
    | #alternate
    | #author
    | @bs.as("dns-prefetch")
    #dnsPrefetch
    | #icon
    | #license
    | #next
    | #pingback
    | #preconnect
    | #prefetch
    | #preload
    | #prerender
    | #prev
    | #search
    | #stylesheet
  ]=?,
  ~href: string=?,
  ~target: Web.target=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseMove: ReactEvent.Mouse.t => unit=?,
  ~onMouseOver: ReactEvent.Mouse.t => unit=?,
  ~onMouseOut: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
) => React.element = "Text"
