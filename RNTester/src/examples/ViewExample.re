open BsReactNative;

let styles =
  StyleSheet.create(
    Style.(
      {
        "box":
          style([
            backgroundColor("#527FE4"),
            borderColor("#000033"),
            borderWidth(1.)
          ]),
        "zIndex":
          style([
            justifyContent(SpaceAround),
            width(Pt(100.)),
            height(Pt(50.)),
            marginTop(Pt(-10.))
          ])
      }
    )
  );

module ViewBorderStyleExample = {
  type action =
    | UpdateBorderState(bool);
  type state = {showBorder: bool};
  let component = ReasonReact.reducerComponent("ViewBorderStyleExample");
  let handlePress = (_event, {ReasonReact.send, ReasonReact.state}) =>
    send(UpdateBorderState(! state.showBorder));
  let make = _children => {
    ...component,
    initialState: () => {showBorder: false},
    reducer: (action, _state) =>
      switch action {
      | UpdateBorderState(showBorder) => Update({showBorder: showBorder})
      },
    render: self =>
      Style.(
        <TouchableWithoutFeedback onPress=(self.handle(handlePress))>
          <View>
            <View
              style=(
                style([
                  borderWidth(1.),
                  borderStyle(
                    if (self.state.showBorder) {
                      Dashed;
                    } else {
                      Solid;
                    }
                  ),
                  padding(Pt(5.))
                ])
              )>
              <Text style=(style([fontSize(Float(11.))]))>
                (ReasonReact.stringToElement("Dashed border style"))
              </Text>
            </View>
            <View
              style=(
                style([
                  marginTop(Pt(5.)),
                  borderWidth(1.),
                  borderRadius(5.),
                  borderStyle(
                    if (self.state.showBorder) {
                      Dotted;
                    } else {
                      Solid;
                    }
                  ),
                  padding(Pt(5.))
                ])
              )>
              <Text style=(style([fontSize(Float(11.))]))>
                (ReasonReact.stringToElement("Dotted border style"))
              </Text>
            </View>
          </View>
        </TouchableWithoutFeedback>
      )
  };
};

module ZIndexExample = {
  type action =
    | UpdateFlippedState(bool);
  type state = {flipped: bool};
  let component = ReasonReact.reducerComponent("ZIndexExample");
  let handlePress = (_event, {ReasonReact.send, ReasonReact.state}) =>
    send(UpdateFlippedState(! state.flipped));
  let make = _children => {
    ...component,
    initialState: () => {flipped: false},
    reducer: (action, _state) =>
      switch action {
      | UpdateFlippedState(flipped) => Update({flipped: flipped})
      },
    render: ({state, handle}) => {
      open Style;
      let indices =
        if (state.flipped) {
          [|(-1), 0, 1, 2|];
        } else {
          [|2, 1, 0, (-1)|];
        };
      let zIndexStr = i =>
        "ZIndex " ++ string_of_int(Array.unsafe_get(indices, i));
      <TouchableWithoutFeedback onPress=(handle(handlePress))>
        <View>
          <Text style=(style([paddingBottom(Pt(10.))]))>
            (ReasonReact.stringToElement("Tap to flip sorting order"))
          </Text>
          <View
            style=(
              concat([
                styles##zIndex,
                style([
                  marginTop(Pt(0.)),
                  backgroundColor("#E57373"),
                  zIndex(Array.unsafe_get(indices, 0))
                ])
              ])
            )>
            <Text> (ReasonReact.stringToElement(zIndexStr(0))) </Text>
          </View>
          <View
            style=(
              concat([
                styles##zIndex,
                style([
                  marginLeft(Pt(50.)),
                  backgroundColor("#FFF176"),
                  zIndex(Array.unsafe_get(indices, 1))
                ])
              ])
            )>
            <Text> (ReasonReact.stringToElement(zIndexStr(1))) </Text>
          </View>
          <View
            style=(
              concat([
                styles##zIndex,
                style([
                  marginLeft(Pt(100.)),
                  backgroundColor("#81C784"),
                  zIndex(Array.unsafe_get(indices, 2))
                ])
              ])
            )>
            <Text> (ReasonReact.stringToElement(zIndexStr(2))) </Text>
          </View>
          <View
            style=(
              concat([
                styles##zIndex,
                style([
                  marginLeft(Pt(150.)),
                  backgroundColor("#64B5F6"),
                  zIndex(Array.unsafe_get(indices, 3))
                ])
              ])
            )>
            <Text> (ReasonReact.stringToElement(zIndexStr(3))) </Text>
          </View>
        </View>
      </TouchableWithoutFeedback>;
    }
  };
};

let title = "<View>";

let description = "Basic building block of all UI, examples that demonstrate some of the many styles available.";

let displayName = "ViewExample";

let examples: array(Example.t) =
  Style.(
    [|
      {
        title: "Background Color",
        description: None,
        render: () =>
          <View style=(style([backgroundColor("#527FE4"), padding(Pt(5.))]))>
            <Text style=(style([fontSize(Float(11.))]))>
              (ReasonReact.stringToElement("Blue background"))
            </Text>
          </View>
      },
      {
        title: "Border",
        description: None,
        render: () =>
          <View
            style=(
              style([
                borderColor("#527FE4"),
                borderWidth(5.),
                padding(Pt(10.))
              ])
            )>
            <Text style=(style([fontSize(Float(11.))]))>
              (ReasonReact.stringToElement("5px blue border"))
            </Text>
          </View>
      },
      {
        title: "Padding/Margin",
        description: None,
        render: () =>
          <View style=(style([borderColor("#bb0000"), borderWidth(1.)]))>
            <View style=(concat([styles##box, style([padding(Pt(5.))])]))>
              <Text style=(style([fontSize(Float(11.))]))>
                (ReasonReact.stringToElement("5px padding"))
              </Text>
            </View>
            <View style=(concat([styles##box, style([margin(Pt(5.))])]))>
              <Text style=(style([fontSize(Float(11.))]))>
                (ReasonReact.stringToElement("5px margin"))
              </Text>
            </View>
            <View
              style=(
                concat([
                  styles##box,
                  style([
                    margin(Pt(5.)),
                    padding(Pt(5.)),
                    alignSelf(FlexStart)
                  ])
                ])
              )>
              <Text style=(style([fontSize(Float(11.))]))>
                (ReasonReact.stringToElement("5px margin and padding,"))
              </Text>
              <Text style=(style([fontSize(Float(11.))]))>
                (ReasonReact.stringToElement("widthAutonomous=true"))
              </Text>
            </View>
          </View>
      },
      {
        title: "Border Radius",
        description: None,
        render: () =>
          <View
            style=(style([borderWidth(1.), borderRadius(5.), padding(Pt(5.))]))>
            <Text style=(style([fontSize(Float(11.))]))>
              (
                ReasonReact.stringToElement(
                  "Too much use of `borderRadius` (especially large radii) on\nanything which is scrolling may result in dropped frames.\nUse sparingly."
                )
              )
            </Text>
          </View>
      },
      {
        title: "Border Style",
        description: None,
        render: () => <ViewBorderStyleExample />
      },
      {
        title: "Circle with Border Radius",
        description: None,
        render: () =>
          <View
            style=(
              style([
                borderRadius(10.),
                borderWidth(1.),
                width(Pt(20.)),
                height(Pt(20.))
              ])
            )
          />
      },
      {
        title: "Overflow",
        description: None,
        render: () =>
          <View style=(style([flexDirection(Row)]))>
            <View
              style=(
                style([
                  width(Pt(95.)),
                  height(Pt(10.)),
                  marginRight(Pt(10.)),
                  marginBottom(Pt(5.)),
                  overflow(Hidden),
                  borderWidth(StyleSheet.hairlineWidth)
                ])
              )>
              <View style=(style([width(Pt(200.)), height(Pt(20.))]))>
                <Text> (ReasonReact.stringToElement("Overflow hidden")) </Text>
              </View>
            </View>
            <View
              style=(
                style([
                  width(Pt(95.)),
                  height(Pt(10.)),
                  marginBottom(Pt(5.)),
                  borderWidth(StyleSheet.hairlineWidth)
                ])
              )>
              <View style=(style([width(Pt(200.)), height(Pt(20.))]))>
                <Text>
                  (ReasonReact.stringToElement("Overflow visible"))
                </Text>
              </View>
            </View>
          </View>
      },
      {
        title: "Opacity",
        description: None,
        render: () =>
          <View>
            <View style=(style([opacity(Float(0.0))]))>
              <Text> (ReasonReact.stringToElement("Opacity 0")) </Text>
            </View>
            <View style=(style([opacity(Float(0.1))]))>
              <Text> (ReasonReact.stringToElement("Opacity 0.1")) </Text>
            </View>
            <View style=(style([opacity(Float(0.3))]))>
              <Text> (ReasonReact.stringToElement("Opacity 0.3")) </Text>
            </View>
            <View style=(style([opacity(Float(0.5))]))>
              <Text> (ReasonReact.stringToElement("Opacity 0.5")) </Text>
            </View>
            <View style=(style([opacity(Float(0.7))]))>
              <Text> (ReasonReact.stringToElement("Opacity 0.7")) </Text>
            </View>
            <View style=(style([opacity(Float(0.9))]))>
              <Text> (ReasonReact.stringToElement("Opacity 0.9")) </Text>
            </View>
            <View style=(style([opacity(Float(1.0))]))>
              <Text> (ReasonReact.stringToElement("Opacity 1")) </Text>
            </View>
          </View>
      },
      {title: "ZIndex", description: None, render: () => <ZIndexExample />}
    |]
  );
