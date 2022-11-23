#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

tilitapahtumat::tilitapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilitapahtumat)
{
    ui->setupUi(this);

}

tilitapahtumat::~tilitapahtumat()
{
    delete ui;
}

void tilitapahtumat::haeRestApiData(QString SessionUser)
{
    QString site_url="http://localhost:3000/tilitapahtuma/"+SessionUser;    // Hae Osoite+SessionUser;
    QString credentials="root:asdf1234";                       //Basic authorization
    QNetworkRequest request((site_url));                            //Pyydä vastaus urlista
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //Joku tarvittava asetus kai vielä tähän samaan.
    QByteArray data = credentials.toLocal8Bit().toBase64();         //Tarvittava muutos tuohon credentialsiin biteissä kun tuodaan se QT:n puolelle
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tilitapahtumatManager = new QNetworkAccessManager(this);            //Luodaan olio luokasta
    connect(tilitapahtumatManager, SIGNAL(finished (QNetworkReply*)),   //Connectataan signaali slottiin niin tulee slotin rungon ajo
    this, SLOT(tilitapahtumatSlot(QNetworkReply*)));
    tilitapahtumatReply = tilitapahtumatManager->get(request);




    //Saldo näkyviin
    QString site_url2="http://localhost:3000/asiakas/naytasaldo/" + SessionUser;    // Hae Osoite
    QString credentials2="root:asdf1234";                       //Basic authorization
    QNetworkRequest request2((site_url2));                            //Pyydä vastaus urlista
    request2.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //Joku tarvittava asetus kai vielä tähän samaan.
    QByteArray data2 = credentials2.toLocal8Bit().toBase64();         //Tarvittava muutos tuohon credentialsiin biteissä kun tuodaan se QT:n puolelle
    QString headerData2 = "Basic " + data2;
    request2.setRawHeader( "Authorization", headerData2.toLocal8Bit() );
    tilitapahtumatManager = new QNetworkAccessManager(this);            //Luodaan olio luokasta
    connect(tilitapahtumatManager, SIGNAL(finished (QNetworkReply*)),   //Connectataan signaali slottiin niin tulee slotin rungon ajo
    this, SLOT(naytasaldoSlot(QNetworkReply*)));
    tilitapahtumatReply = tilitapahtumatManager->get(request2);
}

void tilitapahtumat::on_Close_Button_clicked()
{
    this->close();
}

void tilitapahtumat::tilitapahtumatSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();          //luetaan mitä osoite vastaa
        qDebug()<<response_data;                            //Tulee konsoliin samoja tietoja mitä postmanissa getallpersons samoilla merkeillä
        if(response_data.compare("-4078")==0 || response_data.compare("")==0){  //Virhevertailu kun postman antaa virheen ja jos se data matchaa tässä konsolissa eli sama virhe niin print virhesignal
            ui->textEdit->setText("Virhe tietokanta yhteydessä");
        }
        else{   //Eli jos datan tuonti onnistui...
            QJsonDocument json_doc=QJsonDocument::fromJson(response_data);  //Muutetaan data JsonDocumentiksi
            QJsonArray json_array=json_doc.array();          //Ja vielä kerran muutetaan Json Arrayksi tuo aiempi koska tulee monta objektia eikä vain yksi
            QString tilitapahtumat;            //Luodaan QString muuttuja.
            foreach(const QJsonValue &value, json_array){       //Käydään läpi jokainen value sieltä ja muutetaan ne uusiin tietomuotoihin jotka liitetään sitten persons muuttujaan että persons tulostaa nämä haluamat tiedot.
               QJsonObject json_obj=value.toObject();
            tilitapahtumat+= /*QString::number((json_obj["id_tilitapahtuma"].toInt()))+" "+*/ json_obj["kohdetili"].toString()+
            "\t"+QString::number((json_obj["summa"].toDouble()))+"€"+"\t"+json_obj["pvm2"].toString()+
            "\t"+json_obj["tapahtuma"].toString()+"\t"+json_obj["etunimi"].toString()+" "+json_obj["sukunimi"].toString()+"\t"+json_obj["id_tili"].toString()+" \r\n";
        }
            ui->textEdit->setText(tilitapahtumat);  //Laitetaan ui widgettiin se persons muuttujan rivi tietoja.
        }

        tilitapahtumatReply->deleteLater();
        reply->deleteLater();                           //Deletelater toiminto tässä jostain syystä? Poistaa sitten kai kun on tämä toiminto suoritettu kokonaan
        tilitapahtumatManager->deleteLater();
}

void tilitapahtumat::naytasaldoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();          //luetaan mitä osoite vastaa
        qDebug()<<"naytasaldon responsedata" + response_data;                            //Tulee konsoliin samoja tietoja mitä postmanissa getallpersons samoilla merkeillä
        if(response_data.compare("-4078")==0 || response_data.compare("")==0){  //Virhevertailu kun postman antaa virheen ja jos se data matchaa tässä konsolissa eli sama virhe niin print virhesignal
            ui->saldoikkuna->setText("Virhe tietokanta yhteydessä");
        }
        else{   //Eli jos datan tuonti onnistui...
            QJsonDocument json_doc=QJsonDocument::fromJson(response_data);  //Muutetaan data JsonDocumentiksi
            QJsonObject json_object=json_doc.object();          //Ja vielä kerran muutetaan Json Arrayksi tuo aiempi koska tulee monta objektia eikä vain yksi
            QString saldo;            //Luodaan QString muuttuja.
            saldo+=json_object["etunimi"].toString()+" "+json_object["sukunimi"].toString()+"\t"+QString::number(json_object["saldo"].toDouble());
            ui->saldoikkuna->setText(saldo + "€");  //Laitetaan ui widgettiin se persons muuttujan rivi tietoja.

        }

//        naytasaldoReply->deleteLater();
//        reply->deleteLater();                           //Deletelater toiminto tässä jostain syystä? Poistaa sitten kai kun on tämä toiminto suoritettu kokonaan
//        naytasaldoManager->deleteLater();
}
