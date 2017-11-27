import React from 'react';
import { render } from 'react-dom';
import { BrowserRouter as Router } from 'react-router-dom';
import App from './routes.js';

class AppRouter extends React.Component {
  render() {
    return(
      <Router location={this.props.url} context={this.props.context}>
        <App />
      </Router>
    );
  }
};

window.onload = () => {
  render(<AppRouter />, document.getElementById('root'));
};
