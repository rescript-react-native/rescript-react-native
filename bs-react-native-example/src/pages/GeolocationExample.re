open BsReactNative;
open Utils;

module GeolocationGetCurrentPositionExample = {
  type coords = {
    latitude: float,
    longitude: float,
  };
  type action =
    | UpdateCoords(coords);
  type state = {coords};
  let getCurrentPosition = (_event, {ReasonReact.send}) =>
    Geolocation.getCurrentPosition(
      position =>
        send(
          UpdateCoords({
            latitude: position##coords##latitude,
            longitude: position##coords##longitude,
          }),
        ),
      error => Js.log(error),
    );
  let component =
    ReasonReact.reducerComponent("GeolocationGetCurrentPositionExample");
  let make = _children => {
    ...component,
    initialState: () => {
      coords: {
        latitude: 0.0,
        longitude: 0.0,
      },
    },
    reducer: (action, _state) =>
      switch (action) {
      | UpdateCoords(coords) => Update({coords: coords})
      },
    render: ({state, handle}) =>
      Style.(
        <View>
          <View style={style([padding(Pt(10.))])}>
            <TouchableOpacity onPress={handle(getCurrentPosition)}>
              <Text> {ReasonReact.string("Get current position")} </Text>
            </TouchableOpacity>
            <Text>
              {ReasonReact.string(
                 "latitude:" ++ Js.Float.toString(state.coords.latitude),
               )}
            </Text>
            <Text>
              {ReasonReact.string(
                 "longitude:" ++ Js.Float.toString(state.coords.longitude),
               )}
            </Text>
          </View>
        </View>
      ),
  };
};

module GeolocationWatchPositionExample = {
  type coords = {
    latitude: float,
    longitude: float,
  };
  type action =
    | UpdateCoords(coords);
  type state = {coords};
  let component =
    ReasonReact.reducerComponent("GeolocationWatchPositionExample");
  let make = _children => {
    ...component,
    initialState: () => {
      coords: {
        latitude: 0.0,
        longitude: 0.0,
      },
    },
    reducer: (action, _state) =>
      switch (action) {
      | UpdateCoords(coords) => Update({coords: coords})
      },
    didMount: self => {
      let watchId =
        Geolocation.watchPosition(
          position =>
            self.send(
              UpdateCoords({
                latitude: position##coords##latitude,
                longitude: position##coords##longitude,
              }),
            ),
          error => Js.log(error),
        );
      self.onUnmount(() => Geolocation.clearWatch(watchId));
    },
    render: ({state}) =>
      Style.(
        <View>
          <View style={style([padding(Pt(10.))])}>
            <Text>
              {ReasonReact.string(
                 "latitude:" ++ Js.Float.toString(state.coords.latitude),
               )}
            </Text>
            <Text>
              {ReasonReact.string(
                 "longitude:" ++ Js.Float.toString(state.coords.longitude),
               )}
            </Text>
          </View>
        </View>
      ),
  };
};

let title = "<GeolocationExample>";

let exampleType = Multiple;

let description = "GeolocationExample";

let displayName = "GeolocationExample";

let examples: array(Example.t) = [|
  {
    title: "Geolocation.getCurrentPosition(success, error, options)",
    description: None,
    render: () => <GeolocationGetCurrentPositionExample />,
  },
  {
    title: "Geolocation.watchPosition(success, error, options)",
    description: None,
    render: () => <GeolocationWatchPositionExample />,
  },
|];
