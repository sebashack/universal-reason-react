import React from 'react';
import { render } from 'react-dom';
import { BrowserRouter as Router, Route  } from 'react-router-dom';
import { default as Home } from '../../lib/es6/src/components/Home.js';

render(
  <Router>
    <Route path="/" component={Home}/>
  </Router>,
  document.getElementById('root')
);
