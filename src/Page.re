open ReactNativeRe;
let styles = StyleSheet.create { "inner": style marginTop::100 borderBottomWidth::StyleSheet.hairlineWidth () };
 
let test = StyleSheet.hairlineWidth;

module Page = { 
  include ReactRe.Component.JsProps;
  type props = unit;
  let name = "Page";
  type jsProps = Js.t {.};
  let jsPropsToReasonProps = Some (fun _ => ());
  let handleClick _ _ => {
    Js.log "clicked!";
    None
  };

  let render _ => <Text ellipsizeMode=`middle style=styles##inner> (ReactRe.stringToElement "hello!!") </Text>;
};

include ReactRe.CreateComponent Page;

let createElement = wrapProps ();