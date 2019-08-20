let baseUrl = "/reason-react-native";
let title = {j|Reason React Native|j};
let titleShort = {j|RRN|j};
let defaultTitle = title ++ {j|, Reason bindings for React Native.|j};
let titleTemplate = {j|%s - |j} ++ title;

module Colors = {
  let darkest = "#1a1a1a";
  let dark = "#20232a";
  let darkless = "#282c34";
  let light = "hsl(219.1, 100%, 99%)";
  let light0 = "hsla(219.1, 100%, 99%, 0)";
  let lightest = "hsl(219.1, 100%, 99.5%)";
  let lightest0 = "hsla(219.1, 100%, 99.5%, 0)";
  let accent = "#48a9dc";
  let accentLight = "#61dafb";
  let greyLight = "#909192";
  let tabBarIconInactive = "#909192";
  let tabBarIconActive = dark;
};

type menuLink = {
  link: string,
  text: string,
  icon: (~width: string, ~height: string, ~fill: string) => React.element,
  isActive: (string, string) => bool,
};

let menuLinks = [|
  /*
   {
     link: "/",
     text: {j|Home|j},
     icon: (~width, ~height, ~fill) => <SVGMenuHome width height fill />,
     isActive: (current, link) => current == link,
   },
   */
  {
    link: baseUrl ++ "/en/docs/",
    text: {j|Docs|j},
    icon: (~width, ~height, ~fill) => <SVGDocumentation width height fill />,
    isActive: (current, _link) =>
      Js.String.startsWith(baseUrl ++ "/en/docs/", current),
  },
  {
    link: baseUrl ++ "/en/blog/",
    text: {j|Blog|j},
    icon: (~width, ~height, ~fill) => <SVGBlog width height fill />,
    isActive: (current, _link) =>
      Js.String.startsWith(baseUrl ++ "/en/blog/", current),
  },
|];

type socialLink = {
  name: string,
  text: string,
  link: string,
  componentFunc: (~iconColor: string, ~iconSize: string) => React.element,
};

let socialLinks = [|
  {
    name: "GitHub",
    text: "reason-react-native on GitHub",
    link: "https://github.com/reasonml-community/reason-react-native",
    componentFunc: (~iconColor, ~iconSize) =>
      <SVGSocialGithub fill=iconColor width=iconSize height=iconSize />,
  },
  {
    name: "Discord",
    text: "reason-react-native on Discord",
    link: "/reason-react-native/discord/",
    componentFunc: (~iconColor, ~iconSize) =>
      <SVGSocialDiscord fill=iconColor width=iconSize height=iconSize />,
  },
|];

let api = "docs/apis/";
let comp = "docs/components/";
type section = {
  title: string,
  data: list((string, string)),
};

let sections = [
  {
    title: "Getting Started",
    data: [
      ("Introduction", "docs/"),
      ("Installation", "docs/install/"),
      ("Usage", "docs/usage/"),
      // ("Style", api ++ "docs/style/"),
      ("Example", "docs/example/"),
      ("Cheatsheet", "docs/cheatsheet/"),
      ("Migration from bs-react-native", "docs/migration/jsx3/"),
    ],
  },
  {
    title: "Components",
    data: [
      ("ActivityIndicator", comp ++ "ActivityIndicator/"),
      ("Button", comp ++ "Button/"),
      ("DatePickerIOS", comp ++ "DatePickerIOS/"),
      ("DrawerLayoutAndroid", comp ++ "DrawerLayoutAndroid/"),
      ("FlatList", comp ++ "FlatList/"),
      ("Image", comp ++ "Image/"),
      ("ImageBackground", comp ++ "ImageBackground/"),
      ("InputAccessoryView", comp ++ "InputAccessoryView/"),
      ("KeyboardAvoidingView", comp ++ "KeyboardAvoidingView/"),
      ("ListView", comp ++ "ListView/"),
      ("MaskedViewIOS", comp ++ "MaskedViewIOS/"),
      ("Modal", comp ++ "Modal/"),
      ("Picker", comp ++ "Picker/"),
      ("PickerIOS", comp ++ "PickerIOS/"),
      ("ProgressBarAndroid", comp ++ "ProgressBarAndroid/"),
      ("ProgressViewIOS", comp ++ "ProgressViewIOS/"),
      ("RefreshControl", comp ++ "RefreshControl/"),
      ("SafeAreaView", comp ++ "SafeAreaView/"),
      ("ScrollView", comp ++ "ScrollView/"),
      ("SectionList", comp ++ "SectionList/"),
      ("SegmentedControlIOS", comp ++ "SegmentedControlIOS/"),
      ("Slider", comp ++ "Slider/"),
      ("SnapshotViewIOS", comp ++ "SnapshotViewIOS/"),
      ("StatusBar", comp ++ "StatusBar/"),
      ("Switch", comp ++ "Switch/"),
      ("Text", comp ++ "Text/"),
      ("TextInput", comp ++ "TextInput/"),
      ("ToolbarAndroid", comp ++ "ToolbarAndroid/"),
      ("TouchableHighlight", comp ++ "TouchableHighlight/"),
      ("TouchableNativeFeedback", comp ++ "TouchableNativeFeedback/"),
      ("TouchableOpacity", comp ++ "TouchableOpacity/"),
      ("TouchableWithoutFeedback", comp ++ "TouchableWithoutFeedback/"),
      ("View", comp ++ "View/"),
      ("ViewPagerAndroid", comp ++ "ViewPagerAndroid/"),
      ("VirtualizedList", comp ++ "VirtualizedList/"),
      ("WebView", comp ++ "WebView/"),
    ],
  },
  {
    title: "APIs",
    data: [
      //
      ("AccessibilityInfo", api ++ "AccessibilityInfo/"),
      ("ActionSheetIOS", api ++ "ActionSheetIOS/"),
      ("Alert", api ++ "Alert/"),
      ("AlertIOS", api ++ "AlertIOS/"),
      ("Animated", api ++ "Animated/"),
      ("AnimationFrame", api ++ "AnimationFrame/"),
      ("AppRegistry", api ++ "AppRegistry/"),
      ("AppState", api ++ "AppState/"),
      ("AsyncStorage", api ++ "AsyncStorage/"),
      ("BackAndroid", api ++ "BackAndroid/"),
      ("BackHandler", api ++ "BackHandler/"),
      ("CameraRoll", api ++ "CameraRoll/"),
      ("Clipboard", api ++ "Clipboard/"),
      ("DatePickerAndroid", api ++ "DatePickerAndroid/"),
      ("Dimensions", api ++ "Dimensions/"),
      ("Easing", api ++ "Easing/"),
      ("Event *", api ++ "Event/"),
      ("Geolocation", api ++ "Geolocation/"),
      ("ImageEditor", api ++ "ImageEditor/"),
      ("ImagePickerIOS", api ++ "ImagePickerIOS/"),
      ("ImageStore", api ++ "ImageStore/"),
      ("InteractionManager", api ++ "InteractionManager/"),
      ("Keyboard", api ++ "Keyboard/"),
      ("Layout Props", api ++ "LayoutProps/"),
      ("LayoutAnimation", api ++ "LayoutAnimation/"),
      ("Linking", api ++ "Linking/"),
      ("ListViewDataSource", api ++ "ListViewDataSource/"),
      ("NetInfo", api ++ "NetInfo/"),
      ("Packager *", api ++ "Packager/"),
      ("PanResponder", api ++ "PanResponder/"),
      ("PermissionsAndroid", api ++ "PermissionsAndroid/"),
      ("PixelRatio", api ++ "PixelRatio/"),
      ("Platform", api ++ "Platform/"),
      ("PushNotificationIOS", api ++ "PushNotificationIOS/"),
      ("Settings", api ++ "Settings/"),
      ("Shadow Props", api ++ "ShadowProps/"),
      ("Share", api ++ "Share/"),
      ("StatusBarIOS", api ++ "StatusBarIOS/"),
      ("Style *", api ++ "Style/"),
      ("StyleSheet", api ++ "StyleSheet/"),
      ("Systrace", api ++ "Systrace/"),
      ("TimePickerAndroid", api ++ "TimePickerAndroid/"),
      ("ToastAndroid", api ++ "ToastAndroid/"),
      ("Transforms", api ++ "Transforms/"),
      ("Vibration", api ++ "Vibration/"),
      ("VibrationIOS", api ++ "VibrationIOS/"),
    ],
  },
];
