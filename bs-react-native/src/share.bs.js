

import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReactNative from "react-native";

function share(content, title, subject, tintColor, excludedActivityTypes, dialogTitle, param) {
  if (content[0] >= 5843823) {
    var tmp = {
      url: content[1]
    };
    if (title !== undefined) {
      tmp.title = Caml_option.valFromOption(title);
    }
    var tmp$1 = { };
    if (subject !== undefined) {
      tmp$1.subject = Caml_option.valFromOption(subject);
    }
    if (tintColor !== undefined) {
      tmp$1.tintColor = Caml_option.valFromOption(tintColor);
    }
    if (excludedActivityTypes !== undefined) {
      tmp$1.excludedActivityTypes = Caml_option.valFromOption(excludedActivityTypes);
    }
    if (dialogTitle !== undefined) {
      tmp$1.dialogTitle = Caml_option.valFromOption(dialogTitle);
    }
    return ReactNative.Share.share(tmp, tmp$1);
  } else {
    var tmp$2 = {
      message: content[1]
    };
    if (title !== undefined) {
      tmp$2.title = Caml_option.valFromOption(title);
    }
    var tmp$3 = { };
    if (subject !== undefined) {
      tmp$3.subject = Caml_option.valFromOption(subject);
    }
    if (tintColor !== undefined) {
      tmp$3.tintColor = Caml_option.valFromOption(tintColor);
    }
    if (excludedActivityTypes !== undefined) {
      tmp$3.excludedActivityTypes = Caml_option.valFromOption(excludedActivityTypes);
    }
    if (dialogTitle !== undefined) {
      tmp$3.dialogTitle = Caml_option.valFromOption(dialogTitle);
    }
    return ReactNative.Share.share(tmp$2, tmp$3);
  }
}

export {
  share ,
  
}
/* react-native Not a pure module */
