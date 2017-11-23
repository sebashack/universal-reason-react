import React from 'react';
import { render } from 'react-dom';
import { BrowserRouter as Router, Route, Link  } from 'react-router-dom';
import Home from '../../lib/es6/src/components/Home.js';
import Layout from '../../lib/es6/src/components/Layout.js';

const LayoutWrapper = (props) => {
  const LO = Layout(props.children);
  return <LO/>;
};

render(
  <Router>
    <LayoutWrapper>
      <Route exact path='/' component={Home}/>
    </LayoutWrapper>
  </Router>,
  document.getElementById('root')
);
