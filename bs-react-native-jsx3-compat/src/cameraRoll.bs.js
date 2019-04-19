

import * as Block from "bs-platform/lib/es6/block.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";

function mapFileType(fileType) {
  if (fileType) {
    return "photo";
  } else {
    return "video";
  }
}

function mapGroupType(groupType) {
  switch (groupType) {
    case 0 : 
        return "All";
    case 1 : 
        return "Album";
    case 2 : 
        return "Event";
    case 3 : 
        return "Faces";
    case 4 : 
        return "Library";
    case 5 : 
        return "PhotoStream";
    case 6 : 
        return "SavedPhotos";
    
  }
}

function mapAssetType(assetType) {
  switch (assetType) {
    case 0 : 
        return "All";
    case 1 : 
        return "Videos";
    case 2 : 
        return "Photos";
    
  }
}

function saveToCameraRoll(uri, type_, param) {
  var fileType = Js_undefined.fromOption(Belt_Option.map(type_, mapFileType));
  return ReactNative.CameraRoll.saveToCameraRoll(uri, fileType).then((function (uri) {
                  return Promise.resolve(/* Ok */Block.__(0, [uri]));
                })).catch((function (error) {
                return Promise.resolve(/* Error */Block.__(1, [error]));
              }));
}

function getPhotos(first, after, $staropt$star, groupName, $staropt$star$1, mimeTypes, param) {
  var groupTypes = $staropt$star !== undefined ? $staropt$star : /* SavedPhotos */6;
  var assetType = $staropt$star$1 !== undefined ? $staropt$star$1 : /* Photos */2;
  var groupTypes$1 = mapGroupType(groupTypes);
  var assetType$1 = mapAssetType(assetType);
  var tmp = {
    first: first,
    groupTypes: groupTypes$1,
    assetType: assetType$1
  };
  if (after !== undefined) {
    tmp.after = Caml_option.valFromOption(after);
  }
  if (groupName !== undefined) {
    tmp.groupName = Caml_option.valFromOption(groupName);
  }
  if (mimeTypes !== undefined) {
    tmp.mimeTypes = Caml_option.valFromOption(mimeTypes);
  }
  return ReactNative.CameraRoll.getPhotos(tmp);
}

export {
  saveToCameraRoll ,
  getPhotos ,
  
}
/* react-native Not a pure module */
