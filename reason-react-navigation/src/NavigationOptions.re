[@bs.deriving {abstract: light}]
type t = {
  [@bs.optional]
  title: string,
  /* header: option [ | `custom (headerProps => React.element) | `notVisible], */
  [@bs.optional]
  headerTitle: React.element,
  [@bs.optional]
  headerTitleStyle: ReactNative.Style.t,
  [@bs.optional]
  headerTintColor: string,
  [@bs.optional]
  headerBackTitle: Js.Nullable.t(string),
  [@bs.optional]
  headerTruncatedBackTitle: string,
  [@bs.optional]
  headerLeft: React.element,
  [@bs.optional]
  headerBackTitleStyle: ReactNative.Style.t,
  [@bs.optional]
  headerPressColorAndroid: string,
  [@bs.optional]
  headerRight: React.element,
  [@bs.optional]
  headerStyle: ReactNative.Style.t,
  [@bs.optional]
  gesturesEnabled: bool,
  /* Drawer Navigator */
  [@bs.optional]
  drawerIcon: React.element,
  [@bs.optional]
  drawerLabel: string,
  /* {
       .
       "focused": bool,
       "tintColor": string,
     } =>
     React.element, */
  [@bs.optional]
  drawerLockMode: string /* unlocked | locked-closed | locked-open */
};
