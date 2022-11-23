const db = require('../database');



const laskut = {
  getById: function(id, callback) {
    return db.query('select * from laskut where id_lasku=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from laskut', callback);
  },
  add: function(laskut, callback) {
    return db.query(
      'insert into laskut (viitenumero,kohdetili,laskusumma,tila) values(?,?,?,?)',
      [laskut.viitenumero, laskut.kohdetili, laskut.laskusumma, laskut.tila],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from laskut where id_lasku=?', [id], callback);
  },
  update: function(id, laskut, callback) {
    return db.query(
      'update laskut set viitenumero=?, kohdetili=?, laskusumma=?, tila=? where id_lasku=?',
      [laskut.viitenumero, laskut.kohdetili, laskut.laskusumma, laskut.laskusumma, id],
      callback
    );
  }
};
module.exports = laskut;