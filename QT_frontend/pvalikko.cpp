#include "pvalikko.h"
#include "ui_pvalikko.h"
#include "mainwindow.h"

pvalikko::pvalikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pvalikko)


{
    ui->setupUi(this);
    idleTimer=30;
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(pvalikkoTimeout()));
        timer->start(1000);

}

pvalikko::~pvalikko()
{
    delete ui;


}
void pvalikko::setSessionUser(QString SessionUser)
{
    this->SessionUser = SessionUser;
    asetaNimiLabeliin();
}

void pvalikko::asetaNimiLabeliin()
{
    QString site_url="http://localhost:3000/asiakas/"+SessionUser;
    qDebug()<<"asetaNimiLabeliin"+ SessionUser;
            QString credentials="root:asdf1234";
            QNetworkRequest request((site_url));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
            QByteArray data = credentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
            onePersonManager = new QNetworkAccessManager(this);
            connect(onePersonManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(onePersonSlot(QNetworkReply*)));
            onePersonReply= onePersonManager->get(request);
}

void pvalikko::on_buttonsaldo_clicked()
{
    idleTimer=60;
    pRestApi->openNaytasaldo(SessionUser);
    idleTimer = 30;

}

void pvalikko::on_buttontili_clicked()
{
    idleTimer=60;
    pRestApi->openTilitapahtuma(SessionUser);
    idleTimer = 30;
}

void pvalikko::on_buttonnosto_clicked()
{
    idleTimer=60;
    pRestApi->openNosto(SessionUser);
    idleTimer = 30;
}

void pvalikko::on_buttonlasku_clicked()
{
    idleTimer=60;
    pRestApi->openLasku(SessionUser);
    idleTimer = 30;
}

void pvalikko::on_buttontilisiirto_clicked()
{
    idleTimer=60;
    pRestApi->openTilisiirto(SessionUser);
    idleTimer = 30;
}

void pvalikko::on_buttonlogout_clicked()
{
    this->close();
    MainWindow *m = new MainWindow;
    delete timer;
    timer = nullptr;
    m->show();

}

void pvalikko::pvalikkoTimeout()
{
    idleTimer--;

    qDebug() << idleTimer << Qt::endl;

    if (idleTimer == 0)
    {
        MainWindow *m = new MainWindow;
        this->close();
        delete timer;
        timer = nullptr;
        m->show();    
    }

}

void pvalikko::onePersonSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data.compare("-4078")==0){
        ui->nimi_label->setText("Virhe tietokanta yhteydessä");
    }
    else if(response_data.compare("")==0){
        ui->nimi_label->setText("Henkilöä ei löydy");
    }

    else{
        QJsonDocument json_doc=QJsonDocument::fromJson(response_data);
        QJsonObject json_obj=json_doc.object();
        QString person=json_obj["etunimi"].toString()+" "+json_obj["sukunimi"].toString()+"\r\n";
        ui->nimi_label->setText(person);
    }
    onePersonReply->deleteLater();
    reply->deleteLater();
    onePersonManager->deleteLater();
}



