/**
 * Components
 */

module ActivityIndicator = ActivityIndicatorRe;
module Button = ButtonRe;
module DatePickerIOS = DatePickerIOSRe;
module FlatList = FlatListRe;
module Modal = ModalRe;
module Picker = PickerRe;
module RefreshControl = RefreshControlRe;
module ScrollView = ScrollViewRe.ScrollView;
module SectionList = SectionListRe;
module Slider = SliderRe;
module StatusBar = StatusBarRe;
module Switch = SwitchRe;
module Text = TextRe.Text;
module TextInput = TextInputRe;
module TouchableHighlight = TouchableHighlightRe;
module TouchableOpacity = TouchableOpacityRe;
module TouchableWithoutFeedback = TouchableWithoutFeedbackRe;
module View = {
  include ViewRe.View;
  include ResponderUtils;
};
module Image = ImageRe.Image;
module Animated = {
    include AnimatedRe;
    module Text = AnimatedComponentsRe.Text;
    module ScrollView = AnimatedComponentsRe.ScrollView;
    module View = AnimatedComponentsRe.View;
    module Image = AnimatedComponentsRe.Image;
};

/**
 *  APIs
 */

module Alert = AlertRe;
module AlertIOS = AlertIOSRe;
module AppRegistry = AppRegistryRe;
module AppState = AppStateRe;
module AsyncStorage = AsyncStorageRe;
module BackHandler = BackHandlerRe;
module Dimensions = DimensionsRe;
module NativeModules = NativeModulesRe;
module NativeEventEmitter = NativeEventEmitterRe;
module Platform = PlatformRe;
module StyleSheet = StyleSheetRe;
module PanResponder = {
  include PanResponderRe;
  include PanResponderUtils;
};
module Vibration = VibrationRe;

/**
 * New Modules due to Reason
 */

module Packager = PackagerRe;
module Style = StyleRe;
