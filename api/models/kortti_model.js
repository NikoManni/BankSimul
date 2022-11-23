const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const kortti={
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  get_cardID: function(kortin_numero, callback) {
    return db.query('select id_kortti from kortti where kortin_numero = ?', kortin_numero, callback);
  },
  getById: function(id, callback) {
    return db.query('select * from kortti where id_kortti=?', [id], callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.pinkoodi, saltRounds, function(err, hash) {
      return db.query('insert into kortti (pinkoodi, id_tili, id_asiakas, kortin_numero) values(?,?,?,?)',
      [hash, kortti.id_tili, kortti.id_asiakas, kortti.kortin_numero], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where id_kortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.pinkoodi, saltRounds, function(err, hash) {
      return db.query('update kortti set pinkoodi=?, id_tili=?,id_asiakas=?,kortin_numero=? where id_kortti=?',
      [hash, kortti.id_tili, kortti.id_asiakas, kortti.kortin_numero, id], callback);
    });
  }

}

module.exports = kortti;