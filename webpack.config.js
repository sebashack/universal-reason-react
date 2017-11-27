const webpack = require('webpack');
const nodeExternals = require('webpack-node-externals');
const path = require('path');

const server = {
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

const client = {
  entry: path.join(__dirname, 'src', 'routes', 'client.js'),
  output: {
    path: path.join(__dirname, 'public', 'js'),
    filename: 'bundle.js'
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        use: {
          loader: 'babel-loader',
          options: 'cacheDirectory=.babel_cache'
        }
      }
    ]
  }
};

module.exports = {
  default: [client, server]
};
