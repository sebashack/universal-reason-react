import React from 'react';
import { render } from 'react-dom';
import { StaticRouter as SRouter, Switch, Link, Route } from 'react-router-dom';
import Home from '../../lib/js/src/components/Home.js';
import About from '../../lib/js/src/components/About.js';
import Contact from '../../lib/js/src/components/Contact.js';
import NotFound from '../../lib/js/src/components/NotFound.js';
import LangDetail from '../../lib/js/src/components/programming_langs/LangDetail.js';
import makeLangsIndex from '../../lib/js/src/components/programming_langs/LangIndex.js';
import makeLayout from '../../lib/js/src/components/Layout.js';

// NOTE: We ware using commonjs compilation instead of es6 due to issues with
// node-externals webpack plug-in...

// Also note that we are not using the BrowserRouter, but the StaticRouter.


const Layout = (props) => {
  const Wrapper = makeLayout(props.children);
  return <Wrapper/>;
};


// Subrouter for programming languages
class LangsRouter extends React.Component {
  render() {
    let LangsIndex = makeLangsIndex(this.props.match.url);

    return(
      <div>
        <Route exact path={this.props.match.url} component={LangsIndex}/>
        <Route exact path={`${this.props.match.url}/:lang`} component={LangDetail}/>
      </div>
    );
  }
}


const App = (props) =>
      <Layout>
        <Switch>
          <Route exact path='/' component={Home}/>
          <Route path='/about' component={About}/>
          <Route path='/contact' component={Contact}/>
          <Route path='/programming' component={LangsRouter} />
          <Route component={NotFound} />
        </Switch>
      </Layout>;

export default App;
