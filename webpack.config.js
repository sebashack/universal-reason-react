const webpack = require('webpack');
const nodeExternals = require('webpack-node-externals');
const path = require('path');

module.exports = {
  target: 'node',
  node: {
    __dirname: false
  },
  externals: [nodeExternals({ modulesFromFile: true, modulesDir: 'node_modules' })],
  entry: {
    js: './app.js'
  },
  output: {
    path: path.resolve(__dirname, '.'),
    filename: 'app.bundle.js',
    libraryTarget: 'commonjs2'
  },
  module: {
    rules: [
      {
        test: path.resolve(__dirname, '.'),
        use: {
          loader: 'babel-loader',
          options: 'cacheDirectory=.babel_cache'
        }
      }
    ]
  }
};
