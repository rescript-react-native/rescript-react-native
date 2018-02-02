const path = require('path')
const babel = require('babel-core')

const moduleResolverPlugin = require('babel-plugin-module-resolver').default
const reactNativePreset = require('babel-preset-react-native')

const transform = ({ src, filename }) => {
  const config = {
    filename,
    sourceFileName: filename,
    babelrc: false,
    presets: [
      reactNativePreset,
    ],
    plugins: [
      [moduleResolverPlugin, {
        alias: {
          'bs-react-native': path.resolve(__dirname, '..'),
        },
      }],
    ],
  }
  const { ast, code, map } = babel.transform(src, config)

  return {
    ast,
    code,
    map,
    filename,
  }
}

module.exports = ({
  transform,
})
