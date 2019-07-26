'use strict';

var ReactNavigation = require("react-navigation");

function Make(S) {
  var makeAppContainer = function ($$navigator) {
    var make = ReactNavigation.createAppContainer($$navigator);
    return /* module */[/* make */make];
  };
  return /* module */[/* makeAppContainer */makeAppContainer];
}

exports.Make = Make;
/* react-navigation Not a pure module */
