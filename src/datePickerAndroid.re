[@bs.scope "DatePickerAndroid"] [@bs.module "react-native"]
external dateSet: string = "dateSetAction";

[@bs.scope "DatePickerAndroid"] [@bs.module "react-native"]
external dismissed: string = "dismissedAction";

[@bs.deriving jsConverter]
type mode = [ | `calendar | `spinner | `default];

type response = {
  year: int,
  month: int,
  day: int,
};

type action =
  | Dismissed
  | Set(response);

[@bs.deriving abstract]
type responseJs = {
  action: string,
  year: int,
  month: int,
  day: int,
};

[@bs.deriving abstract]
type optsJs = {
  date: Js.Date.t,
  minDate: Js.Nullable.t(Js.Date.t),
  maxDate: Js.Nullable.t(Js.Date.t),
  mode: string,
};

let action = resp =>
  if (actionGet(resp) == dateSet) {
    Set({year: yearGet(resp), month: monthGet(resp), day: dayGet(resp)});
  } else if (actionGet(resp) == dismissed) {
    Dismissed;
  } else {
    failwith(
      "Unknown action received from DatePickerAndroid. Please report this in the bs-react-native repository",
    );
  };

[@bs.scope "DatePickerAndroid"] [@bs.module "react-native"]
external _open: optsJs => Js.Promise.t(responseJs) = "open";

let open_ = (~date: Js.Date.t, ~minDate=?, ~maxDate=?, ~mode=`default, ()) =>
  _open(
    optsJs(
      ~date,
      ~minDate=minDate |> Js.Nullable.fromOption,
      ~maxDate=maxDate |> Js.Nullable.fromOption,
      ~mode=modeToJs(mode),
    ),
  )
  |> Js.Promise.then_((resp: responseJs) =>
       resp |> action |> Js.Promise.resolve
     );
