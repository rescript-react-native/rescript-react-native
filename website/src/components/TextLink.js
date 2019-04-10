/*
import React from "react";
import { Text } from "react-native";

export default function TextLink(props, context) {
  const { style, activeStyle, ...otherProps } = props;
  const href = props.to || props.href || "";
  return (
    <Text
      {...otherProps}
      accessibilityLabel={props.accessibilityLabel}
      accessibilityRole="link"
      href=href
      style=style
      // @todo activeStyle
    />
  );
}
*/
"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true,
});
exports.default = TextLink;

var _react = _interopRequireDefault(require("react"));

var _reactNative = require("react-native");

function _interopRequireDefault(obj) {
  return obj && obj.__esModule ? obj : { default: obj };
}

function _extends() {
  _extends =
    Object.assign ||
    function(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i];
        for (var key in source) {
          if (Object.prototype.hasOwnProperty.call(source, key)) {
            target[key] = source[key];
          }
        }
      }
      return target;
    };
  return _extends.apply(this, arguments);
}

function _objectWithoutProperties(source, excluded) {
  if (source == null) return {};
  var target = _objectWithoutPropertiesLoose(source, excluded);
  var key, i;
  if (Object.getOwnPropertySymbols) {
    var sourceSymbolKeys = Object.getOwnPropertySymbols(source);
    for (i = 0; i < sourceSymbolKeys.length; i++) {
      key = sourceSymbolKeys[i];
      if (excluded.indexOf(key) >= 0) continue;
      if (!Object.prototype.propertyIsEnumerable.call(source, key)) continue;
      target[key] = source[key];
    }
  }
  return target;
}

function _objectWithoutPropertiesLoose(source, excluded) {
  if (source == null) return {};
  var target = {};
  var sourceKeys = Object.keys(source);
  var key, i;
  for (i = 0; i < sourceKeys.length; i++) {
    key = sourceKeys[i];
    if (excluded.indexOf(key) >= 0) continue;
    target[key] = source[key];
  }
  return target;
}

function TextLink(props, context) {
  var style = props.style,
    activeStyle = props.activeStyle,
    otherProps = _objectWithoutProperties(props, ["style", "activeStyle"]);

  var href = props.to || props.href || "";
  return _react.default.createElement(
    _reactNative.Text,
    _extends({}, otherProps, {
      accessibilityLabel: props.accessibilityLabel,
      accessibilityRole: "link",
      href: href,
      style: style, // @todo activeStyle
    }),
  );
}
