import React from 'react';
import { render } from 'react-dom';
import { BrowserRouter as Router, Route, Link  } from 'react-router-dom';
import Home from '../../lib/es6/src/components/Home.js';
import About from '../../lib/es6/src/components/About.js';
import makeLayout from '../../lib/es6/src/components/Layout.js';


const Layout = (props) => {
  const Wrapper = makeLayout(props.children);
  return <Wrapper/>;
};

render(
  <Router>
    <Layout>
      <Route exact path='/' component={Home}/>
      <Route path='/about' component={About}/>
    </Layout>
  </Router>,
  document.getElementById('root')
);
