const path = require('path')

const config = {
  getProjectRoots() {
    return [
      path.resolve(__dirname, '..'),
      __dirname,
    ]
  },
  getTransformModulePath() {
    return path.resolve(__dirname, 'transformer.js')
  },
}

module.exports = config
