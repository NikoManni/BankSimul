#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include "DLLSerialPort_global.h"
#include "engine.h"

class DLLSERIALPORT_EXPORT DLLSerialPort:public QObject
{
    Q_OBJECT
public:
    DLLSerialPort(QObject * parent = nullptr);
    ~DLLSerialPort();
    void start();
private:
    engine * ptrEngine;
signals:
    void sendInfoToExe(QString);
    void sendNumToExe(QString);
public slots:
    void receiveNumFromEngine(QString);

};

#endif // DLLSERIALPORT_H
