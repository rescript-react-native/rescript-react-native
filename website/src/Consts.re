let title = {j|BS React Native|j};
let defaultTitle = title ++ {j|, BuckleScript bindings for React Native.|j};
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
    link: "/BsReactNative/",
    text: {j|Legacy Docs|j},
    icon: (~width, ~height, ~fill) => <SVGDocumentation width height fill />,
    isActive: (current, _link) =>
      Js.String.startsWith("/BsReactNative/", current),
  },
  /*
   {
     link: "/en/docs/",
     text: {j|Docs@next|j},
     icon: (~width, ~height, ~fill) => <SVGDocumentation width height fill />,
     isActive: (current, _link) => Js.String.startsWith("/en/docs/", current),
   },*/
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
    text: "bs-react-native on GitHub",
    link: "https://github.com/reasonml-community/bs-react-native",
    componentFunc: (~iconColor, ~iconSize) =>
      <SVGSocialGithub fill=iconColor width=iconSize height=iconSize />,
  },
|];

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
      ("Example", "docs/example/"),
    ],
  },
  {
    title: "Components",
    data: [
      ("ActivityIndicator", "docs/components/ActivityIndicator/"),
      ("Button", "docs/components/Button/"),
      ("DatePickerIOS", "docs/components/DatePickerIOS/"),
      ("DrawerLayoutAndroid", "docs/components/DrawerLayoutAndroid/"),
      ("FlatList", "docs/components/FlatList/"),
      ("Image", "docs/components/Image/"),
      ("ImageBackground", "docs/components/ImageBackground/"),
      ("InputAccessoryView", "docs/components/InputAccessoryView/"),
      ("KeyboardAvoidingView", "docs/components/KeyboardAvoidingView/"),
      ("ListView", "docs/components/ListView/"),
      ("MaskedViewIOS", "docs/components/MaskedViewIOS/"),
      ("Modal", "docs/components/Modal/"),
      ("Picker", "docs/components/Picker/"),
      ("PickerIOS", "docs/components/PickerIOS/"),
      ("ProgressBarAndroid", "docs/components/ProgressBarAndroid/"),
      ("ProgressViewIOS", "docs/components/ProgressViewIOS/"),
      ("RefreshControl", "docs/components/RefreshControl/"),
      ("SafeAreaView", "docs/components/SafeAreaView/"),
      ("ScrollView", "docs/components/ScrollView/"),
      ("SectionList", "docs/components/SectionList/"),
      ("SegmentedControlIOS", "docs/components/SegmentedControlIOS/"),
      ("Slider", "docs/components/Slider/"),
      ("SnapshotViewIOS", "docs/components/SnapshotViewIOS/"),
      ("StatusBar", "docs/components/StatusBar/"),
      ("Switch", "docs/components/Switch/"),
      ("Text", "docs/components/Text/"),
      ("TextInput", "docs/components/TextInput/"),
      ("ToolbarAndroid", "docs/components/ToolbarAndroid/"),
      ("TouchableHighlight", "docs/components/TouchableHighlight/"),
      ("TouchableNativeFeedback", "docs/components/TouchableNativeFeedback/"),
      ("TouchableOpacity", "docs/components/TouchableOpacity/"),
      (
        "TouchableWithoutFeedback",
        "docs/components/TouchableWithoutFeedback/",
      ),
      ("View", "docs/components/View/"),
      ("ViewPagerAndroid", "docs/components/ViewPagerAndroid/"),
      ("VirtualizedList", "docs/components/VirtualizedList/"),
      ("WebView", "docs/components/WebView/"),
    ],
  },
  {
    title: "APIs",
    data: [
      //
      ("AccessibilityInfo", "docs/apis/AccessibilityInfo/"),
      ("ActionSheetIOS", "docs/apis/ActionSheetIOS/"),
      ("Alert", "docs/apis/Alert/"),
      ("AlertIOS", "docs/apis/AlertIOS/"),
      ("Animated", "docs/apis/Animated/"),
      ("AppRegistry", "docs/apis/AppRegistry/"),
      ("AppState", "docs/apis/AppState/"),
      ("AsyncStorage", "docs/apis/AsyncStorage/"),
      ("BackAndroid", "docs/apis/BackAndroid/"),
      ("BackHandler", "docs/apis/BackHandler/"),
      ("CameraRoll", "docs/apis/CameraRoll/"),
      ("Clipboard", "docs/apis/Clipboard/"),
      ("DatePickerAndroid", "docs/apis/DatePickerAndroid/"),
      ("Dimensions", "docs/apis/Dimensions/"),
      ("Easing", "docs/apis/Easing/"),
      ("Geolocation", "docs/apis/Geolocation/"),
      ("ImageEditor", "docs/apis/ImageEditor/"),
      ("ImagePickerIOS", "docs/apis/ImagePickerIOS/"),
      ("ImageStore", "docs/apis/ImageStore/"),
      ("Image Style Props", "docs/apis/Image Style Props/"),
      ("InteractionManager", "docs/apis/InteractionManager/"),
      ("Keyboard", "docs/apis/Keyboard/"),
      ("Layout Props", "docs/apis/LayoutProps/"),
      ("LayoutAnimation", "docs/apis/LayoutAnimation/"),
      ("Linking", "docs/apis/Linking/"),
      ("ListViewDataSource", "docs/apis/ListViewDataSource/"),
      ("NetInfo", "docs/apis/NetInfo/"),
      ("PanResponder", "docs/apis/PanResponder/"),
      ("PermissionsAndroid", "docs/apis/PermissionsAndroid/"),
      ("PixelRatio", "docs/apis/PixelRatio/"),
      ("PushNotificationIOS", "docs/apis/PushNotificationIOS/"),
      ("Settings", "docs/apis/Settings/"),
      ("Shadow Props", "docs/apis/ShadowProps/"),
      ("Share", "docs/apis/Share/"),
      ("StatusBarIOS", "docs/apis/StatusBarIOS/"),
      ("StyleSheet", "docs/apis/StyleSheet/"),
      ("Systrace", "docs/apis/Systrace/"),
      ("Text Style Props", "docs/apis/TextStyleProps/"),
      ("TimePickerAndroid", "docs/apis/TimePickerAndroid/"),
      ("ToastAndroid", "docs/apis/ToastAndroid/"),
      ("Transforms", "docs/apis/Transforms/"),
      ("Vibration", "docs/apis/Vibration/"),
      ("VibrationIOS", "docs/apis/VibrationIOS/"),
      ("View Style Props", "docs/apis/ViewStyleProps/"),
    ],
  },
];
