
#include "dllserialport.h"

DLLSerialPort::DLLSerialPort(QObject *parent):QObject(parent)
{
    ptrEngine = new engine;

    connect(ptrEngine, SIGNAL(sendSignalToInterface(QString)),
            this, SLOT(receiveNumFromEngine(QString)));
}

DLLSerialPort::~DLLSerialPort()
{
    delete ptrEngine;
    ptrEngine = nullptr;
}

void DLLSerialPort::start()
{
    ptrEngine -> open();
}


void DLLSerialPort::receiveNumFromEngine(QString cardNumber)
{
    qDebug() << "signaali enginestä vastaanotettu" << Qt::endl;
    qDebug() << cardNumber << Qt::endl;
    emit sendNumToExe(cardNumber);
}
