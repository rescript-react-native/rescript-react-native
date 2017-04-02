open ReactNativeRe;
let styles = StyleSheet.create {
  "button": style marginTop::50 height::50 width::100 borderBottomWidth::StyleSheet.hairlineWidth (),
  "container": style marginTop::40 backgroundColor::"#cccccc" height::300 width::300 (),
  "inner": style marginTop::50 color::"#ff4400" borderBottomWidth::StyleSheet.hairlineWidth (),
  "innerView": style marginTop::100 backgroundColor::"#ff4400" height::100 width::200 borderBottomWidth::StyleSheet.hairlineWidth ()
};

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

  let render {props, updater} => {
    Js.log "container";
    <View style=styles##container>
      <Text ellipsizeMode=`middle style=styles##inner>
        (ReactRe.stringToElement "hello!")
      </Text>
      <View style=styles##innerView> </View>
      <Button
        style=styles##button
        title="Learn More"
        onPress=(updater handleClick)
      />
    </View>;
  }
};

include ReactRe.CreateComponent Page;

let createElement = wrapProps ();