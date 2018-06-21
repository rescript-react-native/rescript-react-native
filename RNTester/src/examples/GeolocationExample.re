open Rebolt;
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
          <View style=(style([padding(Pt(10.))]))>
            <TouchableOpacity onPress=(handle(getCurrentPosition))>
              <Text> (ReasonReact.string("Get current position")) </Text>
            </TouchableOpacity>
            <Text>
              (
                ReasonReact.string(
                  "latitude:" ++ string_of_float(state.coords.latitude),
                )
              )
            </Text>
            <Text>
              (
                ReasonReact.string(
                  "longitude:" ++ string_of_float(state.coords.longitude),
                )
              )
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
    subscriptions: ({send}) => [
      Sub(
        () =>
          Geolocation.watchPosition(
            position =>
              send(
                UpdateCoords({
                  latitude: position##coords##latitude,
                  longitude: position##coords##longitude,
                }),
              ),
            error => Js.log(error),
          ),
        Geolocation.clearWatch,
      ),
    ],
    render: ({state}) =>
      Style.(
        <View>
          <View style=(style([padding(Pt(10.))]))>
            <Text>
              (
                ReasonReact.string(
                  "latitude:" ++ string_of_float(state.coords.latitude),
                )
              )
            </Text>
            <Text>
              (
                ReasonReact.string(
                  "longitude:" ++ string_of_float(state.coords.longitude),
                )
              )
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