/**

  Date/time picker for ios in {{:https://facebook.github.io/react-native/docs/datepickerios} React Native DOC},
  requires date and onDateChange props to be rendered:

  {2 Example}

  {3 default}
  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self =>
        <DatePickerIOS
          date=(Js.Date.fromString("February 12, 1990 17:40"))
          onDateChange=(date => Js.log(date))
        />,
    };
  ]}

  Here you can find BuckleScript's {{:https://bucklescript.github.io/bucklescript/api/Js_date.html} Js.Date API}

  {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date} The JavaScript Date API} might also be a useful resource.

  {3 mode}
  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self =>
        <DatePickerIOS
          date=(Js.Date.fromString("February 12, 1990 17:40"))
          onDateChange=(date => Js.log(date))
          mode=`date
        />,
    };
  ]}

  {2 Props}

  {3 date}
  {[
    ~date: Js.Date.t
  ]}

  {3 onDateChange}
  {[
    ~onDateChange: Js.Date.t => unit
  ]}

  {3 maximumDate}
  {[
    maximumDate: Js.Date.t=?
  ]}

  {3 minimumDate}
  {[
    ~minimumDate: Js.Date.t=?
  ]}

  {3 mode}
  {[
    ~mode: [
      | `date
      | `datetime
      | `time
    ]=?
  ]}

  {3 minuteInterval}
  {[
    ~minuteInterval: int=?
  ]}

  {3 timeZoneOffsetInMinutes}
  {[
    ~timeZoneOffsetInMinutes: int=?
  ]}

  {3 accessibilityLabel}
  {[
    ~accessibilityLabel: ReasonReact.reactElement=?
  ]}

  {3 accessible}
  {[
    ~accessible: bool=?
  ]}

  {3 hitSlop}
  {[
    ~hitSlop: Types.insets=?
  ]}

  {4 reference:}
  Types.rei
  {[
    type insets = {
      .
      "left": int,
      "right": int,
      "top": int,
      "bottom": int,
    };
  ]}

  {3 onAccessibilityTap}
  {[
    ~onAccessibilityTap: unit => unit=?
  ]}

  {3 onLayout}
  {[
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?
  ]}

  {3 onMagicTap}
  {[
    ~onMagicTap: unit => unit=?
  ]}

  {3 responderHandlers}
  {[
    ~responderHandlers: Types.touchResponderHandlers=?
  ]}

  {4 reference:}
  Types.rei
  {[
    type insets = {
      .
      "left": int,
      "right": int,
      "top": int,
      "bottom": int,
    };
  ]}

  RNEvent.rei
  {[
    module NativeEvent: {
      type t;
      let changedTouches: t => array(Js.t({..}));
      let identifier: t => int;
      let locationX: t => float;
      let locationY: t => float;
      let pageX: t => float;
      let pageY: t => float;
      let target: t => Js.t({..});
      let touches: t => array(Js.t({..}));
      let timestamp: t => int;
      let data: t => string;
    };
  ]}

  {3 pointerEvents}
  {[
    ~pointerEvents: [
      | `auto
      | `none
      | `boxNone
      | `boxOnly
    ]=?
  ]}

  {3 style}
  {[
    ~style: Style.t=?
  ]}

  {3 testID}
  {[
    ~testID: string=?
  ]}

  {3 accessibilityComponentType}
  {[
    ~accessibilityComponentType: [
      | `none
      | `button
      | `radiobutton_checked
      | `radiobutton_unchecked
    ]=?
  ]}

  {3 accessibilityLiveRegion}
  {[
    ~accessibilityLiveRegion: [
      | `none
      | `polite
      | `assertive
    ]=?
  ]}

  {3 collapsable}
  {[
    ~collapsable: bool=?
  ]}

  {3 importantForAccessibility}
  {[
    ~importantForAccessibility: [
      | `auto
      | `yes
      | `no
      | `noHideDescendants
    ]=?
  ]}

  {3 needsOffscreenAlphaCompositing}
  {[
    ~needsOffscreenAlphaCompositing: bool=?
  ]}

  {3 renderToHardwareTextureAndroid}
  {[
    ~renderToHardwareTextureAndroid: bool=?
  ]}

  {3 accessibilityTraits}
  {[
    ~accessibilityTraits:
      list(
        [
          | `adjustable
          | `allowsDirectInteraction
          | `button
          | `disabled
          | `frequentUpdates
          | `header
          | `image
          | `key
          | `link
          | `none
          | `pageTurn
          | `plays
          | `search
          | `selected
          | `startsMedia
          | `summary
          | `text
        ],
      )=?
  ]}

  {3 accessibilityViewIsModal}
  {[
    ~accessibilityViewIsModal: bool=?
  ]}

  {3 accessibilityViewIsModal}
  {[
    ~shouldRasterizeIOS: bool=?
  ]}
 */
let make:
  (
    ~date: Js.Date.t,
    ~onDateChange: Js.Date.t => unit,
    ~maximumDate: Js.Date.t=?,
    ~minimumDate: Js.Date.t=?,
    ~mode: [ | `date | `datetime | `time]=?,
    ~minuteInterval: int=?,
    ~timeZoneOffsetInMinutes: int=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(
                            [
                              | `none
                              | `button
                              | `link
                              | `header
                              | `search
                              | `image
                              | `selected
                              | `plays
                              | `key
                              | `text
                              | `summary
                              | `disabled
                              | `frequentUpdates
                              | `startsMedia
                              | `adjustable
                              | `allowsDirectInteraction
                              | `pageTurn
                            ],
                          )
                            =?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
