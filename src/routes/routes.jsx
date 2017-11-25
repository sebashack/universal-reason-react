import React from 'react';
import { render } from 'react-dom';
import { BrowserRouter as Router, Route, Link  } from 'react-router-dom';
import Home from '../../lib/es6/src/components/Home.js';
import About from '../../lib/es6/src/components/About.js';
import Contact from '../../lib/es6/src/components/Contact.js';
import LangsIndex from '../../lib/es6/src/components/programming_langs/LangIndex.js';
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
      <Route path='/contact' component={Contact}/>
      <Route path='/programming' component={LangsIndex}/>
    </Layout>
  </Router>,
  document.getElementById('root')
);
