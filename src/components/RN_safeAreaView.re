include RN_view.CreateComponent({
  [@bs.module "react-native"]
  external view : ReasonReact.reactClass = "SafeAreaView";
  let view = view;
});
