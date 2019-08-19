'use strict';

var React = require("react");
var ReactNavigation = require("react-navigation");

function useNavigation(param) {
  return React.useContext(ReactNavigation.NavigationContext);
}

exports.useNavigation = useNavigation;
/* react Not a pure module */
