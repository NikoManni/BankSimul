const express = require('express');
const router = express.Router();
const asiakas = require('../models/asiakas_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    asiakas.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
          //palautetaan json objekti eli ainoa alkio
        response.json(dbResult[0]);
      }
    });
    
  } else {
    asiakas.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  asiakas.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json("Asiakas lisätty.");
    }
  });
});


router.delete('/:id', 
function(request, response) {
  asiakas.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  asiakas.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      console.log(dbResult);
      if(dbResult.affectedRows==1){
        response.json("Asiakas päivitetty.");
      }
      else{
        response.json("Asiakasta ei ole olemassa.");
      }

    }
  });
});

router.post('/rahansiirto', 
function(request, response) {
  asiakas.rahansiirto(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      console.log(dbResult.affectedRows);
      if(dbResult.affectedRows==1)
      {
        response.send(true);
      }
      else response.send(false);
      //response.send("true");
      //response.send(dbResult.affectedRows);
    }
  });
});

router.post('/tilisiirto', 
function(request, response) {
  asiakas.tilisiirto(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json("Tilisiirto onnistui.");
      //response.json(dbResult.affectedRows);
    }
  });
});
//naytasaldo yritys
router.get('/naytasaldo/:id',
function(request, response) {
  if (request.params.id) {
    asiakas.saldo(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
          //palautetaan json objekti eli ainoa alkio
        response.json(dbResult[0]);
     }
    });
    
  } else {
    asiakas.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

router.get('/nostotiedot/:id',
function(request, response) {
  if (request.params.id) {
    asiakas.nostoTiedot(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
          //palautetaan json objekti eli ainoa alkio
        response.json(dbResult[0]);
     }
    });
    
  } else {
    asiakas.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

//laskun maksu proseduuri
router.post('/laskunmaksu', 
function(request, response) {
  asiakas.laskunmaksu(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
      
    } else {
      if(dbResult.affectedRows>0){
        response.json("Laskunmaksu onnistui.");
      }
      else{
        response.json("Maksu epäonnistui");
      }
      //response.json(dbResult.affectedRows);
    }
  });
});


module.exports = router;