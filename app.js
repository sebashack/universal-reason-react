import path from 'path';
import express from 'express';
import React from 'react';
import { renderToString } from 'react-dom/server';
import { match, RouterContext } from 'react-router';
import { StaticRouter as Router } from 'react-router-dom';
import routes from './src/routes/routes.js';

const port = process.env.PORT || 3000;

const app = express();

app.set('view engine', 'pug');
app.set('views', path.resolve(__dirname, 'views'));

app
  .use('/static', express.static(path.resolve(__dirname, 'public')))
  .get('/', (req, res) => {
    res.render('index.pug');
  });
  // .get('*', (req, res) => {
  //   res.sendFile(path.resolve(__dirname, 'public', 'index.html'));
  // });

app.listen(port);
console.log("server started on port " + port);
