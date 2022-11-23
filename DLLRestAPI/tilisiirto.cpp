#include "tilisiirto.h"
#include "ui_tilisiirto.h"

tilisiirto::tilisiirto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilisiirto)
{
    ui->setupUi(this);
}

tilisiirto::~tilisiirto()
{
    delete ui;
}

void tilisiirto::haeRestApiData(QString SessionUser)
{
    this->SessionUser = SessionUser;
}

void tilisiirto::on_Close_button_clicked()
{
    this->close();
}



void tilisiirto::on_maksa_clicked()
{
    QString amount=ui->summa->text();

    QString id=ui->v_tilinumero->text();

    QJsonObject json_obj;
    json_obj.insert("id_lahde", SessionUser);
    json_obj.insert("id_kohde", id);
    json_obj.insert("summa", amount);

    QString site_url="http://localhost:3000/asiakas/tilisiirto";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tilisiirtoManager = new QNetworkAccessManager(this);
    connect(tilisiirtoManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(tiliSiirto(QNetworkReply*)));
    tilisiirtoReply=tilisiirtoManager->post(request, QJsonDocument(json_obj).toJson());
}

void tilisiirto::tiliSiirto(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data.compare("-4078")==0){
        ui->tilisiirto_ikkuna->setText("Virhe tietokanta yhteydessä");
    }
    else if(response_data.compare("0")==0){
        ui->tilisiirto_ikkuna->setText("Tilisiirto ei onnistunut");
    }
    else{
        ui->tilisiirto_ikkuna->setText("Tilisiirto onnistui!");
    }
    tilisiirtoReply->deleteLater();
    reply->deleteLater();
    tilisiirtoManager->deleteLater();
}

void tilisiirto::on_tyhjenna_summa_clicked()
{
    ui->summa->setText("");
    ui->tilisiirto_ikkuna->setText("");
}

void tilisiirto::on_tyhjenna_tili_clicked()
{
    ui->v_tilinumero->setText("");
    ui->tilisiirto_ikkuna->setText("");
}
