open ReactNative;

let filter =
  Image.Source.fromRequired(Packager.require("../Icons/filter.png"));

let settings =
  Image.Source.fromRequired(Packager.require("../Icons/settings.png"));

let home = Image.Source.fromRequired(Packager.require("../Icons/home.png"));

let message =
  Image.Source.fromRequired(Packager.require("../Icons/message.png"));

let notification =
  Image.Source.fromRequired(Packager.require("../Icons/notification.png"));

let search =
  Image.Source.fromRequired(Packager.require("../Icons/search.png"));

let compose =
  Image.Source.fromRequired(Packager.require("../Icons/compose.png"));

let avatar =
  Image.(
    Source.fromUriSource(
      uriSource(~uri="https://github.com/reasonml-community.png", ()),
    )
  );
