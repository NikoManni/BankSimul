#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QWidget>
#include <QDebug>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <dllserialport.h>
#include <dllpincode.h>
#include <dllrestapi.h>
#include "pvalikko.h"
#include "pinkoodi.h"
#include "naytasaldo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void checkKorttiData();
    void AloitaPinKoodi();




private:
    Ui::MainWindow *ui;
    DLLSerialPort *pSerialPort;
    DLLPinCode *pPinCode;
    QString SessionUser;
    QNetworkAccessManager *pManager;
    QNetworkReply *pReply;
    DLLRestAPI *pRestApi;
    QString kortinnumero;
    pvalikko *valikko;


public slots:
    void receiveNumFromDLLSerialPort(QString);
    void receiveSignalFromPinkoodi();
    void valueToID(QNetworkReply *reply);
    void oikeaPinkoodiSaatu();

};
#endif // MAINWINDOW_H
