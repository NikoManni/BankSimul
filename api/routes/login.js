const express = require('express');
const router = express.Router();
const db = require('../database');
const bcrypt = require('bcryptjs');

router.post('/', 
  function(request, response) {
    if(request.body.kortin_numero && request.body.pinkoodi){
      var kortin_numero = request.body.kortin_numero;
      var pinkoodi = request.body.pinkoodi;
      db.query('SELECT pinkoodi FROM kortti WHERE kortin_numero = ?',[kortin_numero], 
        function(dbError, dbResults) {
          if(dbError){
            response.json(dbError);
          }
          else {
            if (dbResults.length > 0) {
              bcrypt.compare(pinkoodi,dbResults[0].pinkoodi, 
                function(err,compareResult) {
                  if(compareResult) {
                    console.log("success");
                    response.send(true);
                  }
                  else {
                    console.log("wrong pinkoodi");
                    response.send(false);
                  }			
                }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }

      );
    }
    else{
      console.log("Give the kortin_numero and pinkoodi");
      response.send(false);
    }
  }
);

module.exports = router;