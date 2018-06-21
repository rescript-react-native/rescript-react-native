[@bs.module "react-native"]
external snapshotViewIOS : ReasonReact.reactClass = "SnapshotViewIOS";

let make = (~onSnapshotReady=?, ~testIdentifier=?) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=snapshotViewIOS,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "onSnapshotReady": fromOption(onSnapshotReady),
            "testIdentifier": fromOption(testIdentifier),
          }
        ),
      ),
  );