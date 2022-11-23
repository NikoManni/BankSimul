const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where id_asiakas=?', [id], callback);
  },
  //naytasaldo yritys
    saldo: function(id, callback) {
      return db.query('SELECT etunimi, sukunimi, saldo FROM asiakas INNER JOIN kortti ON asiakas.id_asiakas = kortti.id_asiakas INNER JOIN tili ON kortti.id_tili = tili.id_tili WHERE asiakas.id_asiakas=?;', [id], callback);
    },
    //nosto/talletus tiedot
    nostoTiedot: function(id, callback) {
      return db.query('SELECT etunimi, sukunimi, osoite, puhelinnumero, saldo FROM asiakas INNER JOIN kortti ON asiakas.id_asiakas = kortti.id_asiakas INNER JOIN tili ON kortti.id_tili = tili.id_tili WHERE asiakas.id_asiakas=?;', [id], callback);
    },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (etunimi,sukunimi,puhelinnumero,osoite) values(?,?,?,?)',
      [asiakas.etunimi, asiakas.sukunimi, asiakas.puhelinnumero, asiakas.osoite],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where id_asiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set etunimi=?,sukunimi=?, puhelinnumero=?, osoite=? where id_asiakas=?',
      [asiakas.etunimi, asiakas.sukunimi, asiakas.puhelinnumero, asiakas.osoite, id],
      callback
    );
  },
  rahansiirto: function(procedure_params, callback) {
    return db.query(
      'CALL rahansiirto (?,?)',
      [procedure_params.id, procedure_params.summa],
      callback
    );
  },
  laskunmaksu: function(procedure_params, callback) {
    return db.query(
      'CALL laskunmaksu (?)',
      [procedure_params.annettu_viitenumero],
      callback
    );
  },
  tilisiirto: function(procedure_params, callback) {
    return db.query(
      'CALL tilisiirto (?,?,?)',
      [procedure_params.id_lahde, procedure_params.id_kohde, procedure_params.summa],
      callback
    );
  }
};


module.exports = asiakas;