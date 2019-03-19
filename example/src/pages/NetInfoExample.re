open BsReactNative;
open Utils;

module NetInfoIsConnectedExample = {
  type action =
    | UpdateIsConnected(bool);
  type state = {isConnected: bool};
  let component = ReasonReact.reducerComponent("NetInfoIsConnectedExample");
  let make = _children => {
    ...component,
    initialState: () => {isConnected: false},
    reducer: (action, _state) =>
      switch (action) {
      | UpdateIsConnected(isConnected) => Update({isConnected: isConnected})
      },
    didMount: self => {
      let handleConnectionChange = isConnected =>
        self.send(UpdateIsConnected(isConnected));
      NetInfo.IsConnected.addEventListener(handleConnectionChange);
      self.onUnmount(() =>
        NetInfo.IsConnected.removeEventListener(handleConnectionChange)
      );
    },
    render: ({state}) =>
      Style.(
        <View>
          <View style={style([padding(Pt(10.))])}>
            <Text>
              {ReasonReact.string(
                 state.isConnected ? "Connected" : "Not connected",
               )}
            </Text>
          </View>
        </View>
      ),
  };
};

module NetInfoConnectionTypeExample = {
  type action =
    | UpdateConnectionType(NetInfo.infoType);
  type state = {connectionType: NetInfo.connectionType};
  let component =
    ReasonReact.reducerComponent("NetInfoConnectionTypeExample");
  let checkConnectionType = (_event, {ReasonReact.send}) =>
    NetInfo.getConnectionInfo()
    |> Js.Promise.then_(info => {
         send(UpdateConnectionType(info##_type));
         Js.Promise.resolve();
       })
    |> ignore;
  let make = _children => {
    ...component,
    initialState: () => {connectionType: NetInfo.Unknown},
    reducer: (action, _state) =>
      switch (action) {
      | UpdateConnectionType(infoType) =>
        let connectionType = NetInfo.connectionType(infoType);
        Update({connectionType: connectionType});
      },
    render: ({state, handle}) =>
      Style.(
        <View>
          <View style={style([padding(Pt(10.))])}>
            <TouchableOpacity onPress={handle(checkConnectionType)}>
              <Text> {ReasonReact.string("Check connection type")} </Text>
            </TouchableOpacity>
            <View>
              <Text>
                {ReasonReact.string(
                   switch (state.connectionType) {
                   | NetInfo.None => "none"
                   | NetInfo.Unknown => "unknown"
                   | NetInfo.WiFi => "wifi"
                   | NetInfo.Cellular => "cellular"
                   | _ => "something else"
                   },
                 )}
              </Text>
            </View>
          </View>
        </View>
      ),
  };
};

let title = "<NetInfo>";

let exampleType = Multiple;

let description = "NetInfo";

let displayName = "NetInfoExample";

let examples: array(Example.t) = [|
  {
    title: "NetInfo.IsConnected.addEventListener()",
    description: None,
    render: () => <NetInfoIsConnectedExample />,
  },
  {
    title: "NetInfo.getConnectionInfo()",
    description: None,
    render: () => <NetInfoConnectionTypeExample />,
  },
|];
