// const path = require("path");

// const config = {
//   getProjectRoots() {
//     return [path.resolve(__dirname, ".."), __dirname];
//   },
// };

// module.exports = config;

const { createMetroConfiguration } = require("expo-yarn-workspaces");

module.exports = createMetroConfiguration(__dirname);
