const fs = require("fs-extra");
const path = require("path");

fs.ensureDirSync(path.join(__dirname, "../react-native"));
fs.copySync(path.join(__dirname, "../../src"), path.join(__dirname, "../react-native"));
