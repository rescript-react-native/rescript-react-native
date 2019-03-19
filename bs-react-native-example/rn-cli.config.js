const path = require("path");

const config = {
  getProjectRoots() {
    return [path.resolve(__dirname, ".."), __dirname];
  },
};

module.exports = config;
