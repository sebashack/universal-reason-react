import React from 'react';
import { render } from 'react-dom';
import { BrowserRouter as Router, Route, Link, Switch  } from 'react-router-dom';
import Home from '../../lib/es6/src/components/Home.js';
import About from '../../lib/es6/src/components/About.js';
import Contact from '../../lib/es6/src/components/Contact.js';
import LangDetail from '../../lib/es6/src/components/programming_langs/LangDetail.js';
import makeLangsIndex from '../../lib/es6/src/components/programming_langs/LangIndex.js';
import makeLayout from '../../lib/es6/src/components/Layout.js';


const Layout = (props) => {
  const Wrapper = makeLayout(props.children);
  return <Wrapper/>;
};


// Subrouter for programming languages
class LangsRouter extends React.Component {
  render() {
    let LangsIndex = makeLangsIndex(this.props.match.url);
    console.log(this.props.match.url);
    return(
      <div>
        <Route exact path={this.props.match.url} component={LangsIndex}/>
        <Route path={`${this.props.match.url}/:lang`} component={LangDetail}/>
      </div>
    );
  }
}

// Main Router
render(
  <Router>
    <Layout>
      <Route exact path='/' component={Home}/>
      <Route path='/about' component={About}/>
      <Route path='/contact' component={Contact}/>
      <Route path='/programming' component={LangsRouter} />
    </Layout>
  </Router>,
  document.getElementById('root')
);
