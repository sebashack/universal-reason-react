import path from 'path';
import express from 'express';
import React from 'react';
import { StaticRouter as Router } from 'react-router-dom';
import App from './src/routes/routes.js';
import { renderToStaticMarkup } from 'react-dom/server';


const port = process.env.PORT || 3000;

const app = express();

app.set('view engine', 'ejs');
app.set('views', path.resolve(__dirname, 'views'));

app
  .use(express.static(path.resolve(__dirname, 'public')))
  .get('*', (req, res) => {
    let markup = '';
    let status = 200;

    const context = {};

   //  Main Static Router
    class AppRouter extends React.Component {
      render() {
        return(
            <Router location={this.props.url} context={this.props.context}>
              <App />
            </Router>
        );
      }
    };

    markup = renderToStaticMarkup(<AppRouter location={req.url} context={context} />);

    if(context.is404) {
      status = 404;
    }

    return res.status(status).render('index', { markup });
  });

app.listen(port);
console.log("server started on port " + port);
