    #include "mainwindow.h"
    #include "ui_mainwindow.h"
    #include <unistd.h>


    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)


    {
        ui->setupUi(this);

        pSerialPort = new DLLSerialPort(this);
        pPinCode = new DLLPinCode;

            connect(pPinCode, SIGNAL(sendSignalToExe()),
                this, SLOT(oikeaPinkoodiSaatu()));

            connect(pSerialPort,SIGNAL(sendNumToExe(QString)),
                    this, SLOT(receiveNumFromDLLSerialPort(QString)));

        pSerialPort->start();

    }

    MainWindow::~MainWindow()
    {
        delete ui;
        delete pSerialPort;
        pSerialPort=nullptr;
        delete pPinCode;
        pPinCode=nullptr;
    }



    void MainWindow::receiveNumFromDLLSerialPort(QString cardNumber)
    {
        ui->label_2->setText(cardNumber);
        this->close();
        pPinCode->setCardNumber(cardNumber);
        pPinCode->interfacePinCodeComponent(); //Aukaisee PinKoodiDLL:n UI:n

        kortinnumero=cardNumber;
        qDebug()<<"ensimmäinen tarkistus" + kortinnumero;
        receiveSignalFromPinkoodi();

    }

    void MainWindow::receiveSignalFromPinkoodi()
    {       
        //haetaan kortin ID restApin kautta
        //http://localhost:3000/kortti/cardNumber
        //asetetaan postmanin palaututettu arvo muuttujaan ja muuttuja nostossa ID:n tilalle

        QJsonObject json;
        qDebug()<<"tarkistus " + kortinnumero;
        json.insert("kortin_numero",kortinnumero);
        QString site_url="http://localhost:3000/kortti/cardNumber";
        QString credentials="root:asdf1234";
        QNetworkRequest request((site_url));
        qDebug()<<site_url;
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setRawHeader( "Authorization", headerData.toLocal8Bit());
        pManager = new QNetworkAccessManager(this);
        connect(pManager, SIGNAL(finished (QNetworkReply*)),
        this, SLOT(valueToID(QNetworkReply*)));
        pReply = pManager->post(request, QJsonDocument(json).toJson());
    }
    
    void MainWindow::valueToID(QNetworkReply *reply)
    {
        QByteArray response_data=reply->readAll();
        qDebug()<<response_data;
        SessionUser=response_data;
        valikko->setSessionUser(SessionUser);
    }

    void MainWindow::oikeaPinkoodiSaatu()
    {
        qDebug()<<"pvalikko ui AUKI";
        valikko = new pvalikko;
        valikko->show();
        this->close();
    }





