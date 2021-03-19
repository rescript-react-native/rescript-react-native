include NativeElement;

type dataDetectorType = [
  | `phoneNumber
  | `link
  | `address
  | `calendarEvent
  | `none
  | `all
];

type ellipsizeMode = [ | `clip | `head | `middle | `tail];

type textBreakStrategy = [ | `simple | `highQuality | `balanced];

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // Text props
    ~accessibilityHint: string=?,
    ~accessibilityLabel: string=?,
    ~accessibilityRole: Accessibility.role=?,
    ~accessibilityState: Accessibility.state=?,
    ~accessible: bool=?,
    ~adjustsFontSizeToFit: bool=?,
    ~allowFontScaling: bool=?,
    ~ariaLevel: int=?,
    ~children: React.element=?,
    ~dataDetectorTypes: array(dataDetectorType)=?,
    ~disabled: bool=?,
    ~ellipsizeMode: ellipsizeMode=?,
    ~maxFontSizeMultiplier: int=?,
    ~minimumFontScale: float=?,
    ~nativeID: string=?,
    ~numberOfLines: int=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~onPress: Event.pressEvent => unit=?,
    ~onTextLayout: Event.textLayoutEvent => unit=?,
    ~pressRetentionOffset: View.edgeInsets=?,
    ~selectable: bool=?,
    ~selectionColor: string=?,
    ~style: Style.t=?,
    ~suppressHighlighting: bool=?,
    ~testID: string=?,
    ~textBreakStrategy: textBreakStrategy=?,
    ~value: string=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~onResponderEnd: Event.pressEvent => unit=?,
    ~onResponderGrant: Event.pressEvent => unit=?,
    ~onResponderMove: Event.pressEvent => unit=?,
    ~onResponderReject: Event.pressEvent => unit=?,
    ~onResponderRelease: Event.pressEvent => unit=?,
    ~onResponderStart: Event.pressEvent => unit=?,
    ~onResponderTerminate: Event.pressEvent => unit=?,
    ~onResponderTerminationRequest: Event.pressEvent => bool=?,
    ~onStartShouldSetResponder: Event.pressEvent => bool=?,
    ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
    // React Native Web Props
    ~rel: [@bs.string] [
            | `alternate
            | `author
            | [@bs.as "dns-prefetch"] `dnsPrefetch
            | `icon
            | `license
            | `next
            | `pingback
            | `preconnect
            | `prefetch
            | `preload
            | `prerender
            | `prev
            | `search
            | `stylesheet
          ]
            =?,
    ~href: string=?,
    ~target: Web.target=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseMove: ReactEvent.Mouse.t => unit=?,
    ~onMouseOver: ReactEvent.Mouse.t => unit=?,
    ~onMouseOut: ReactEvent.Mouse.t => unit=?,
    ~onMouseUp: ReactEvent.Mouse.t => unit=?
  ) =>
  React.element =
  "Text";
