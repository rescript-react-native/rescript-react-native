---
id: components/DatePickerIOS
title: DatePickerIOS
wip: true
---

`DatePickerIOS` has been deprecated and will be removed from React Native in the
future.

Please refer to
[bindings](https://github.com/reason-react-native/datetimepicker) for the
replacement
[community package](https://github.com/react-native-community/react-native-datetimepicker).

---

```reason
// For localeId refer to
// https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPInternational/LanguageandLocaleIDs/LanguageandLocaleIDs.html

type localeId = string;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~date: Js.Date.t,
    ~onDateChange: Js.Date.t => unit,
    ~maximumDate: Js.Date.t=?,
    ~minimumDate: Js.Date.t=?,
    ~minuteInterval: [@bs.string] [
                       | [@bs.as "1"] `_1
                       | [@bs.as "2"] `_2
                       | [@bs.as "3"] `_3
                       | [@bs.as "4"] `_4
                       | [@bs.as "5"] `_5
                       | [@bs.as "6"] `_6
                       | [@bs.as "10"] `_10
                       | [@bs.as "12"] `_12
                       | [@bs.as "15"] `_15
                       | [@bs.as "20"] `_20
                       | [@bs.as "30"] `_30
                     ]
                       =?,
    ~mode: [@bs.string] [ | `date | `time | `datetime]=?,
    ~locale: localeId=?,
    ~timeZoneOffsetInMinutes: int=?,
    // View props
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityElementsHidden: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]=?,
    ~accessibilityRole: [@bs.string] [
                          | `none
                          | `button
                          | `link
                          | `search
                          | `image
                          | `keyboardkey
                          | `text
                          | `adjustable
                          | `header
                          | `summary
                          | `imagebutton
                        ]
                          =?,
    ~accessibilityState: Accessibility.state=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~accessibilityValue: Accessibility.value=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~collapsable: bool=?,
    ~hitSlop: View.edgeInsets=?,
    ~importantForAccessibility: [@bs.string] [
                                  | `auto
                                  | `yes
                                  | `no
                                  | [@bs.as "no-hide-descendants"]
                                    `noHideDescendants
                                ]
                                  =?,
    ~nativeID: string=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~onAccessibilityEscape: unit => unit=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
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
    ~pointerEvents: [@bs.string] [
                      | `auto
                      | `none
                      | [@bs.as "box-none"] `boxNone
                      | [@bs.as "box-only"] `boxOnly
                    ]
                      =?,
    ~removeClippedSubviews: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~style: Style.t=?,
    ~testID: string=?
  ) =>
  React.element =
  "DatePickerIOS";
```

# Example

The example below illustrates using `DatePickerIOS` to the ui based on the value
returned from the `DatePickerIOS` API using some of the examples found in the
[`DatePickerIOSExample.js`](https://github.com/facebook/react-native/blob/master/RNTester/js/examples/DatePicker/DatePickerIOSExample.js)
found in the `react-native` repository.

```reason
open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "labelContainer":
        style(
          ~flexDirection=`row,
          ~alignItems=`center,
          ~marginVertical=2.->dp,
          (),
        ),
      "labelView": style(~marginRight=10.->dp, ~paddingVertical=2.->dp, ()),
      "label": style(~fontWeight=`_500, ()),
    })
  );
module WithLabel = {
  [@react.component]
  let make = (~label, ~children) => {
    <View style={styles##labelContainer}>
      <View style={styles##labelView}>
        <Text style={styles##label}> label->React.string </Text>
      </View>
      children
    </View>;
  };
};
let nbsp = {js|  |js};

[@react.component]
let make = (~children) => {
  let (date, setDate) = React.useState(() => Js.Date.make());

  let onDateChange = date => {
    setDate(_ => date);
  };

  <View>
    <WithLabel label="Value:">
      <Text testID="date-indicator"> <Utils.DateFormat date /> </Text>
      <Text> nbsp->React.string </Text>
      <Text testID="time-indicator"> <Utils.DateTimeFormat date /> </Text>
    </WithLabel>
    {children(date, onDateChange)}
  </View>;
};

// App.re
[@react.component]
let app = () =>
  <>
    <StatusBar barStyle=`darkContent />
    <SafeAreaView>
      <ScrollView
        contentInsetAdjustmentBehavior=`automatic style={styles##scrollView}>
        {Global.hermesInternal->Belt.Option.isNone
           ? React.null
           : <View style=styles##engine>
               <Text style=styles##footer>
                 "Engine: Hermes"->React.string
               </Text>
             </View>}
        <Header />
        <View style={styles##body}>
          <View style={styles##sectionContainer}>
            <Text style={styles##sectionTitle}>
              "Date & Time Picker"->React.string
            </Text>
            <WithDatePickerData>
              {(date, onDateChange) =>
                 <DatePickerIOS
                   testID="date-and-time"
                   date
                   mode=`datetime
                   onDateChange
                 />}
            </WithDatePickerData>
          </View>
          <View style={styles##sectionContainer}>
            <Text style={styles##sectionTitle}>
              "Date Only Picker"->React.string
            </Text>
            <WithDatePickerData>
              {(date, onDateChange) =>
                 <DatePickerIOS
                   testID="date-only"
                   date
                   mode=`date
                   onDateChange
                 />}
            </WithDatePickerData>
          </View>
          <View style={styles##sectionContainer}>
            <Text style={styles##sectionTitle}>
              "Time only picker, 20-minute interval"->React.string
            </Text>
            <WithDatePickerData>
              {(date, onDateChange) =>
                 <DatePickerIOS
                   testID="time-with-interval"
                   date
                   minuteInterval=`_20
                   onDateChange
                 />}
            </WithDatePickerData>
          </View>
        </View>
      </ScrollView>
    </SafeAreaView>
  </>;

```
