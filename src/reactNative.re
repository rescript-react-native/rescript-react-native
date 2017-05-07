/**
 * Components
 */

module ActivityIndicator = ActivityIndicatorRe;
module Button = ButtonRe;
module DatePickerIOS = DatePickerIOSRe;
module FlatList = FlatListRe;
module Modal = ModalRe;
module Picker = PickerRe;
module ScrollView = ScrollViewRe.ScrollView;
module SectionList = SectionListRe;
module StatusBar = StatusBarRe;
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
    module View = AnimatedComponentsRe.ScrollView;
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
module Platform = PlatformRe;
module StyleSheet = StyleSheetRe;
module PanResponder = {
  include PanResponderRe;
  include PanResponderUtils;
};

/**
 * New Modules due to Reason
 */

module Packager = PackagerRe;
module Style = StyleRe;
