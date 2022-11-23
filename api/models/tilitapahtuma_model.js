const db = require('../database');

const tilitapahtuma = {
  getById: function(id, callback) {
    return db.query('select kohdetili, summa, DATE_FORMAT(pvm,"%d.%m.%Y : %H.%i") as pvm2, tapahtuma, etunimi, sukunimi from tilitapahtuma where id_tili=? ORDER BY pvm DESC;', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtuma', callback);
  },
  add: function(tilitapahtuma, callback) {
    return db.query(
      'insert into tilitapahtuma (tilitapahtumanumero, saldo) values(?,?)',
      [tilitapahtuma.tilitapahtumanumero, tilitapahtuma.saldo],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtuma where id_tilitapahtuma=?', [id], callback);
  },
  update: function(id, tilitapahtuma, callback) {
    return db.query(
      'update tilitapahtuma set tilitapahtumanumero=?,saldo=? where id_tilitapahtuma=?',
      [tilitapahtuma.tilitapahtumanumero, tilitapahtuma.saldo, id],
      callback
    );
  }
};
module.exports = tilitapahtuma;