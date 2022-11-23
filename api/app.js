var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var asiakasRouter = require('./routes/asiakas');
var korttiRouter = require('./routes/kortti');
var tilitapahtumaRouter = require('./routes/tilitapahtuma');
var laskutRouter = require('./routes/laskut');
var loginRouter = require('./routes/login');
const basicAuth = require('express-basic-auth');


var app = express();

app.use(basicAuth({users: { 'root': 'asdf1234' }}))

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/asiakas', asiakasRouter);
app.use('/kortti', korttiRouter);
app.use('/tilitapahtuma', tilitapahtumaRouter);
app.use('/laskut', laskutRouter);
app.use('/login', loginRouter);

module.exports = app;
