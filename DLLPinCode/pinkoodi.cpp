#include "pinkoodi.h"
#include "ui_pinkoodi.h"


pinkoodi::pinkoodi(QWidget *parent):
    QDialog(parent),
    ui(new Ui::pinkoodi)
{
    ui->setupUi(this);

    idleTimer=11;
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutPinkoodi()));
        timer->start(1000);

    korttiStatus=0;
    korttiLukitus = true;
}

pinkoodi::~pinkoodi()
{
    qDebug() << "PinCode dialog closed and UI destroyed";
    delete ui;

}

void pinkoodi::on_Button1_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "1";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button2_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "2";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button3_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "3";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button4_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "4";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button5_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "5";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button6_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "6";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button7_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "7";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button8_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "8";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button9_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "9";
    ui->textEdit->setText(valuePinCode);
}

void pinkoodi::on_Button0_clicked()
{
    idleTimer=11;
    valuePinCode = valuePinCode + "0";
    ui->textEdit->setText(valuePinCode);
}

QString pinkoodi::returnPinCode()
{
    return valuePinCode;
}

void pinkoodi::on_Clear_Button_clicked()
{
    idleTimer=20;
    valuePinCode = "";
    ui->textEdit->setText("");
}

void pinkoodi::on_Enter_Button_clicked()
{
    if (korttiLukitus == true)
{
    QJsonObject json;
    json.insert("pinkoodi",valuePinCode);
    json.insert("kortin_numero",cardNum);

    QString site_url="http://localhost:3000/login";
    QString credentials="root:asdf1234";
    QNetworkRequest request((site_url));
    qDebug()<<site_url;
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        pManager = new QNetworkAccessManager(this);
        connect(pManager, SIGNAL(finished (QNetworkReply*)),
        this, SLOT(CheckPinkoodi(QNetworkReply*)));
        pReply = pManager->post(request, QJsonDocument(json).toJson());
}
else
{
    QMessageBox::information(this, "Error", "Kortti lukittu");
    this->close();
}
}

void pinkoodi::CheckPinkoodi(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;

    if(response_data == "true")
    {
        emit OikeaPinkoodi();
        this->close();
    }
    else
    {
        idleTimer=20;
        valuePinCode="";
        ui->textEdit->setText("");
        QMessageBox::information(this, "Error", "Väärä PIN");
        korttiStatus++;
        if(korttiStatus>=3)
        {
            korttiLukitus = false;
        }

    }
    pReply->deleteLater();
    reply->deleteLater();
    pManager->deleteLater();
}

QString pinkoodi::getCardNum() const
{
    return cardNum;
}

void pinkoodi::setCardNum(const QString &value)
{
    cardNum = value;
}


void pinkoodi::timeoutPinkoodi()
{
    idleTimer--;

    qDebug() << idleTimer << Qt::endl;

    if (idleTimer < 1)
    {
        this->close();
    }
}
