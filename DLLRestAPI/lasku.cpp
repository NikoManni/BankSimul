#include "lasku.h"
#include "ui_lasku.h"

lasku::lasku(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lasku)
{
    ui->setupUi(this);
}

lasku::~lasku()
{
    delete ui;
}

void lasku::haeRestApiData(QString SessionUser)
{
    this->SessionUser = SessionUser;

    QString site_url="http://localhost:3000/laskut/"+SessionUser; //käyttäjä ID tähän
    QString credentials="root:asdf1234";                       //Basic authorization
    QNetworkRequest request((site_url));                            //Pyydä vastaus urlista
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //Joku tarvittava asetus kai vielä tähän samaan.
    QByteArray data = credentials.toLocal8Bit().toBase64();         //Tarvittava muutos tuohon credentialsiin biteissä kun tuodaan se QT:n puolelle
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit());
    //Muuttujaan Tieto laskusta ja tämä tulostetaan ikkunaan kun laskuikkuna avataan. Tilassa aluksi ei maksettu -> maksun jälkeen hakee tiedon uudestaan jossa laskun tila maksettu.
    laskuManager2 = new QNetworkAccessManager(this);
    connect(laskuManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(tuoLasku(QNetworkReply*)));
    laskuReply2 = laskuManager2->get(request);
}

void lasku::on_Close_button_clicked()
{
    this->close();

}

void lasku::on_maksa_clicked()
{
    ui->maksuikkuna->setText(" ");
    QString viite=ui->viitenumero_input->text();
    QJsonObject json_obj;

    json_obj.insert("annettu_viitenumero",viite);

    QString site_url="http://localhost:3000/asiakas/laskunmaksu";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    laskuManager = new QNetworkAccessManager(this);
    connect(laskuManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(laskuSlot(QNetworkReply*)));
    laskuReply=laskuManager->post(request, QJsonDocument(json_obj).toJson());
}

void lasku::laskuSlot(QNetworkReply *reply)
{
    QString site_url="http://localhost:3000/laskut/"+SessionUser; //käyttäjä ID tähän
    QString credentials="root:asdf1234";                       //Basic authorization
    QNetworkRequest request((site_url));                            //Pyydä vastaus urlista
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //Joku tarvittava asetus kai vielä tähän samaan.
    QByteArray data = credentials.toLocal8Bit().toBase64();         //Tarvittava muutos tuohon credentialsiin biteissä kun tuodaan se QT:n puolelle
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit());
    //Muuttujaan Tieto laskusta ja tämä tulostetaan ikkunaan kun laskuikkuna avataan. Tilassa aluksi ei maksettu -> maksun jälkeen hakee tiedon uudestaan jossa laskun tila maksettu.
    laskuManager2 = new QNetworkAccessManager(this);
    connect(laskuManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(tuoLasku(QNetworkReply*)));
    laskuReply2 = laskuManager2->get(request);
}

void lasku::tuoLasku(QNetworkReply *reply2) //Tuo laskun näytille UI:n avaamisen yhteydessä
{
    QByteArray response_data=reply2->readAll();
    qDebug()<<response_data;


        //Tiedon tuonti epäonnistui
    if(response_data.compare("-4078")==0){
        ui->maksuikkuna->setText("Virhe tietokanta yhteydessä");
    }
        //Tiedon tuonti onnistui
    else{
        QJsonDocument json_doc=QJsonDocument::fromJson(response_data);  //Muutetaan data JsonDocumentiksi
        QJsonArray json_array=json_doc.array();          //Ja vielä kerran muutetaan Json Arrayksi tuo aiempi koska tulee monta objektia eikä vain yksi
        QString laskutieto;            //Luodaan QString muuttuja.
        foreach(const QJsonValue &value, json_array){       //Käydään läpi jokainen value sieltä ja muutetaan ne uusiin tietomuotoihin jotka liitetään sitten persons muuttujaan että persons tulostaa nämä haluamat tiedot.
           QJsonObject json_obj=value.toObject();
        laskutieto+=QString::number (json_obj["viitenumero"].toInt())+" "+json_obj["kohdetili"].toString()+" "+QString::number(json_obj["laskusumma"].toDouble())+"€" +" "+json_obj["tila"].toString()+"\r\n";
        ui->maksuikkuna->setText(laskutieto);
    }

    }

    laskuReply2->deleteLater();
    reply2->deleteLater();
    laskuManager2->deleteLater();
}
