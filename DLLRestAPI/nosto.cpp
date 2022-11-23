#include "nosto.h"
#include "ui_nosto.h"

nosto::nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);
}

nosto::~nosto()
{
    delete ui;
    ui=nullptr;
}

void nosto::haeRestApiData(QString SessionUser)
{
    this->SessionUser = SessionUser;
}

void nosto::TiedotLabeliin()
{

    QString site_url="http://localhost:3000/asiakas/nostoTiedot/" + SessionUser;    // Hae Osoite
    QString credentials="root:asdf1234";                       //Basic authorization
    QNetworkRequest request((site_url));                            //Pyydä vastaus urlista
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //Joku tarvittava asetus kai vielä tähän samaan.
    QByteArray data = credentials.toLocal8Bit().toBase64();         //Tarvittava muutos tuohon credentialsiin biteissä kun tuodaan se QT:n puolelle
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tiedotManager = new QNetworkAccessManager(this);            //Luodaan olio luokasta
    connect(tiedotManager, SIGNAL(finished (QNetworkReply*)),   //Connectataan signaali slottiin niin tulee slotin rungon ajo
    this, SLOT(tiedotSlot(QNetworkReply*)));
    tiedotReply = tiedotManager->get(request);
}

void nosto::on_Close_button_clicked()
{
    this->close();
}

void nosto::on_nosto_20_clicked()
{

     QJsonObject json_obj;
     json_obj.insert("id",SessionUser);
     json_obj.insert("summa",-20);
     QString site_url="http://localhost:3000/asiakas/rahansiirto";
     QString credentials="root:asdf1234";
     QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
     "application/json");
     QByteArray data = credentials.toLocal8Bit().toBase64();
     QString headerData = "Basic " + data;
     request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
     raiseManager = new QNetworkAccessManager(this);
     connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
     this, SLOT(nostoSlot(QNetworkReply*)));
     raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
     TiedotLabeliin();
}

void nosto::on_nosto_40_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",-40);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(nostoSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_nosto_60_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",-60);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(nostoSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_nosto_100_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",-100);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(nostoSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_nosto_200_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",-200);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(nostoSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_nosto_500_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",-500);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(nostoSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_talletus_20_clicked()
{

    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",20);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(talletusSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_talletus_40_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",40);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(talletusSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_talletus_60_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",60);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(talletusSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_talletus_100_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",100);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(talletusSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_talletus_200_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",200);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(talletusSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::on_talletus_500_clicked()
{
    QJsonObject json_obj;
    json_obj.insert("id",SessionUser);
    json_obj.insert("summa",500);
    QString site_url="http://localhost:3000/asiakas/rahansiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    raiseManager = new QNetworkAccessManager(this);
    connect(raiseManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(talletusSlot(QNetworkReply*)));
    raiseReply=raiseManager->post(request, QJsonDocument(json_obj).toJson());
    TiedotLabeliin();
}

void nosto::nostoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
        if(response_data.compare("-4078")==0){
            ui->textEdit->setText("Virhe tietokanta yhteydessä");
        }
        else if(response_data=="false") {
            ui->textEdit->setText("Nosto ei onnistu");
        }
        else{
            ui->textEdit->setText("Nosto onnistui");
        }
        raiseReply->deleteLater();
        reply->deleteLater();
        raiseManager->deleteLater();
}

void nosto::talletusSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
        if(response_data.compare("-4078")==0){
            ui->textEdit->setText("Virhe tietokanta yhteydessä");
        }
        else if(response_data.compare("0")==0){
            ui->textEdit->setText("Talletus ei onnistu");
        }
        else{
            ui->textEdit->setText("Talletus onnistui");
        }
        raiseReply->deleteLater();
        reply->deleteLater();
        raiseManager->deleteLater();
}

void nosto::tiedotSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();          //luetaan mitä osoite vastaa
        qDebug()<<response_data;                            //Tulee konsoliin samoja tietoja mitä postmanissa getallpersons samoilla merkeillä
        if(response_data.compare("-4078")==0 || response_data.compare("")==0){  //Virhevertailu kun postman antaa virheen ja jos se data matchaa tässä konsolissa eli sama virhe niin print virhesignal
            ui->tietoikkuna->setText("Virhe tietokanta yhteydessä");
        }
        else{   //Eli jos datan tuonti onnistui...
            QJsonDocument json_doc=QJsonDocument::fromJson(response_data);  //Muutetaan data JsonDocumentiksi
            QJsonObject json_object=json_doc.object();          //Ja vielä kerran muutetaan Json Arrayksi tuo aiempi koska tulee monta objektia eikä vain yksi
            QString tietoja;            //Luodaan QString muuttuja.

            tietoja+=json_object["etunimi"].toString()+" "+json_object["sukunimi"].toString()+"\n"+json_object["osoite"].toString()+"\n"+json_object["puhelinnumero"].toString()+"\n"+QString::number(json_object["saldo"].toDouble())+"€"+"\r\n";

            ui->tietoikkuna->setText(tietoja);  //Laitetaan ui widgettiin se persons muuttujan rivi tietoja.
        }

        tiedotReply->deleteLater();
        reply->deleteLater();                           //Deletelater toiminto tässä jostain syystä? Poistaa sitten kai kun on tämä toiminto suoritettu kokonaan
        tiedotManager->deleteLater();

}


