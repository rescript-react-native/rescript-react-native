const moduleAlias = require("module-alias");
moduleAlias.addAliases({
  "react-native": require.resolve("react-native-web"),
});
moduleAlias();

// require.extensions['.web.js'] = require.extensions['.js'];

require("./BuildWebsite.bs.js");
