#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include "naytasaldo.h"
#include "tilitapahtumat.h"
#include "lasku.h"
#include "nosto.h"
#include "tilisiirto.h"
#include <QDebug>

class DLLRESTAPI_EXPORT DLLRestAPI:public QObject
{
    Q_OBJECT

public:
    DLLRestAPI();
    void openNaytasaldo(QString SessionUser);
    void openTilitapahtuma(QString SessionUser);
    void openNosto(QString SessionUser);
    void openLasku(QString SessionUser);
    void openTilisiirto(QString SessionUser);

private:    
naytasaldo *pNaytasaldo;
lasku *pLasku;
nosto *pNosto;
tilisiirto *pTilisiirto;
tilitapahtumat *pTilitapahtumat;

};

#endif // DLLRESTAPI_H
