#include "dllrestapi.h"



DLLRestAPI::DLLRestAPI()
{

}

void DLLRestAPI::openNaytasaldo(QString SessionUser)
{
    naytasaldo *s = new naytasaldo;
    s->haeRestApiData(SessionUser);
    s->exec();
}

void DLLRestAPI::openTilitapahtuma(QString SessionUser)
{
    tilitapahtumat *t = new tilitapahtumat;
    t->haeRestApiData(SessionUser);
    t->exec();
}

void DLLRestAPI::openNosto(QString SessionUser)
{
    nosto *n = new nosto;
    n->haeRestApiData(SessionUser);
    n->TiedotLabeliin();
    n->exec();
}

void DLLRestAPI::openLasku(QString SessionUser)
{
    lasku *l = new lasku;
    l->haeRestApiData(SessionUser);
    l->exec();
}

void DLLRestAPI::openTilisiirto(QString SessionUser)
{
    tilisiirto *ts = new tilisiirto;
    ts->haeRestApiData(SessionUser);
    ts->exec();
}



