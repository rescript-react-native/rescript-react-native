open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "box": style [backgroundColor "#527FE4", borderColor "#000033", borderWidth 1.],
        "zIndex": style [justifyContent `spaceAround, width 100., height 50., marginTop (-10.)]
      }
    );

module ViewBorderStyleExample = {
  type state = {showBorder: bool};
  let component = ReasonReact.statefulComponent "ViewBorderStyleExample";
  let handlePress () state _self => ReasonReact.Update {showBorder: not state.showBorder};
  let make _children => {
    ...component,
    initialState: fun () => {showBorder: false},
    render: fun state self =>
      Style.(
        <TouchableWithoutFeedback onPress=(self.update handlePress)>
          <View>
            <View
              style=(
                      style [
                        borderWidth 1.,
                        borderStyle (
                          if state.showBorder {
                            `dashed
                          } else {
                            `solid
                          }
                        ),
                        padding 5.
                      ]
                    )>
              <Text style=(style [fontSize 11.])>
                (ReasonReact.stringToElement "Dashed border style")
              </Text>
            </View>
            <View
              style=(
                      style [
                        marginTop 5.,
                        borderWidth 1.,
                        borderRadius 5.,
                        borderStyle (
                          if state.showBorder {
                            `dotted
                          } else {
                            `solid
                          }
                        ),
                        padding 5.
                      ]
                    )>
              <Text style=(style [fontSize 11.])>
                (ReasonReact.stringToElement "Dotted border style")
              </Text>
            </View>
          </View>
        </TouchableWithoutFeedback>
      )
  };
};

module ZIndexExample = {
  type state = {flipped: bool};
  let component = ReasonReact.statefulComponent "ZIndexExample";
  let handlePress () state _self => ReasonReact.Update {flipped: not state.flipped};
  let make _children => {
    ...component,
    initialState: fun () => {flipped: false},
    render: fun state self => {
      open Style;
      let indices =
        if state.flipped {
          [|(-1), 0, 1, 2|]
        } else {
          [|2, 1, 0, (-1)|]
        };
      let zIndexStr i => "ZIndex " ^ string_of_int (Array.unsafe_get indices i);
      <TouchableWithoutFeedback onPress=(self.update handlePress)>
        <View>
          <Text style=(style [paddingBottom 10.])>
            (ReasonReact.stringToElement "Tap to flip sorting order")
          </Text>
          <View
            style=(
                    concat [
                      styles##zIndex,
                      style [
                        marginTop 0.,
                        backgroundColor "#E57373",
                        zIndex (Array.unsafe_get indices 0)
                      ]
                    ]
                  )>
            <Text> (ReasonReact.stringToElement (zIndexStr 0)) </Text>
          </View>
          <View
            style=(
                    concat [
                      styles##zIndex,
                      style [
                        marginLeft 50.,
                        backgroundColor "#FFF176",
                        zIndex (Array.unsafe_get indices 1)
                      ]
                    ]
                  )>
            <Text> (ReasonReact.stringToElement (zIndexStr 1)) </Text>
          </View>
          <View
            style=(
                    concat [
                      styles##zIndex,
                      style [
                        marginLeft 100.,
                        backgroundColor "#81C784",
                        zIndex (Array.unsafe_get indices 2)
                      ]
                    ]
                  )>
            <Text> (ReasonReact.stringToElement (zIndexStr 2)) </Text>
          </View>
          <View
            style=(
                    concat [
                      styles##zIndex,
                      style [
                        marginLeft 150.,
                        backgroundColor "#64B5F6",
                        zIndex (Array.unsafe_get indices 3)
                      ]
                    ]
                  )>
            <Text> (ReasonReact.stringToElement (zIndexStr 3)) </Text>
          </View>
        </View>
      </TouchableWithoutFeedback>
    }
  };
};

let title = "<View>";

let description = "Basic building block of all UI, examples that demonstrate some of the many styles available.";

let displayName = "ViewExample";

let examples: array Example.t =
  Style.[|
    {
      title: "Background Color",
      description: None,
      render: fun () =>
        <View style=(style [backgroundColor "#527FE4", padding 5.])>
          <Text style=(style [fontSize 11.])>
            (ReasonReact.stringToElement "Blue background")
          </Text>
        </View>
    },
    {
      title: "Border",
      description: None,
      render: fun () =>
        <View style=(style [borderColor "#527FE4", borderWidth 5., padding 10.])>
          <Text style=(style [fontSize 11.])>
            (ReasonReact.stringToElement "5px blue border")
          </Text>
        </View>
    },
    {
      title: "Padding/Margin",
      description: None,
      render: fun () =>
        <View style=(style [borderColor "#bb0000", borderWidth 1.])>
          <View style=(concat [styles##box, style [padding 5.]])>
            <Text style=(style [fontSize 11.])> (ReasonReact.stringToElement "5px padding") </Text>
          </View>
          <View style=(concat [styles##box, style [margin 5.]])>
            <Text style=(style [fontSize 11.])> (ReasonReact.stringToElement "5px margin") </Text>
          </View>
          <View style=(concat [styles##box, style [margin 5., padding 5., alignSelf `flexStart]])>
            <Text style=(style [fontSize 11.])>
              (ReasonReact.stringToElement "5px margin and padding,")
            </Text>
            <Text style=(style [fontSize 11.])>
              (ReasonReact.stringToElement "widthAutonomous=true")
            </Text>
          </View>
        </View>
    },
    {
      title: "Border Radius",
      description: None,
      render: fun () =>
        <View style=(style [borderWidth 1., borderRadius 5., padding 5.])>
          <Text style=(style [fontSize 11.])>
            (
              ReasonReact.stringToElement "Too much use of `borderRadius` (especially large radii) on\nanything which is scrolling may result in dropped frames.\nUse sparingly."
            )
          </Text>
        </View>
    },
    {title: "Border Style", description: None, render: fun () => <ViewBorderStyleExample />},
    {
      title: "Circle with Border Radius",
      description: None,
      render: fun () =>
        <View style=(style [borderRadius 10., borderWidth 1., width 20., height 20.]) />
    },
    {
      title: "Overflow",
      description: None,
      render: fun () =>
        <View style=(style [flexDirection `row])>
          <View
            style=(
                    style [
                      width 95.,
                      height 10.,
                      marginRight 10.,
                      marginBottom 5.,
                      overflow `hidden,
                      borderWidth StyleSheet.hairlineWidth
                    ]
                  )>
            <View style=(style [width 200., height 20.])>
              <Text> (ReasonReact.stringToElement "Overflow hidden") </Text>
            </View>
          </View>
          <View
            style=(
                    style [
                      width 95.,
                      height 10.,
                      marginBottom 5.,
                      borderWidth StyleSheet.hairlineWidth
                    ]
                  )>
            <View style=(style [width 200., height 20.])>
              <Text> (ReasonReact.stringToElement "Overflow visible") </Text>
            </View>
          </View>
        </View>
    },
    {
      title: "Opacity",
      description: None,
      render: fun () =>
        <View>
          <View style=(style [opacity 0.0])>
            <Text> (ReasonReact.stringToElement "Opacity 0") </Text>
          </View>
          <View style=(style [opacity 0.1])>
            <Text> (ReasonReact.stringToElement "Opacity 0.1") </Text>
          </View>
          <View style=(style [opacity 0.3])>
            <Text> (ReasonReact.stringToElement "Opacity 0.3") </Text>
          </View>
          <View style=(style [opacity 0.5])>
            <Text> (ReasonReact.stringToElement "Opacity 0.5") </Text>
          </View>
          <View style=(style [opacity 0.7])>
            <Text> (ReasonReact.stringToElement "Opacity 0.7") </Text>
          </View>
          <View style=(style [opacity 0.9])>
            <Text> (ReasonReact.stringToElement "Opacity 0.9") </Text>
          </View>
          <View style=(style [opacity 1.0])>
            <Text> (ReasonReact.stringToElement "Opacity 1") </Text>
          </View>
        </View>
    },
    {title: "ZIndex", description: None, render: fun () => <ZIndexExample />}
  |];