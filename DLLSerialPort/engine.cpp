#include "engine.h"

engine::engine(QObject *parent):QObject(parent)
{
    pQSerialPort = new QSerialPort;
    connect(pQSerialPort, SIGNAL(readyRead()), this, SLOT(readPort()));
    pQSerialPortInfo = new QSerialPortInfo;
}

engine::~engine()
{
    delete pQSerialPort;
    pQSerialPort = nullptr;
    delete pQSerialPortInfo;
    pQSerialPortInfo = nullptr;
}

void engine::open()
{
    pQSerialPort->setPortName("COM4");
    qDebug() << pQSerialPort->portName();
    pQSerialPort->setBaudRate(QSerialPort::Baud9600);
    pQSerialPort->setDataBits(QSerialPort::Data8);
    pQSerialPort->setParity(QSerialPort::NoParity);
    pQSerialPort->setStopBits(QSerialPort::OneStop);
    pQSerialPort->setFlowControl(QSerialPort::HardwareControl);

    if (!pQSerialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "ei aukea" << Qt::endl;
    }
    else
    {
        qDebug() << "portti aukesi" << Qt::endl;

    }
//    qDebug()<<"suljetaan lopuksi";
//    pQSerialPort->close();
}

void engine::info()
{
    QList<QSerialPortInfo> ports = pQSerialPortInfo->availablePorts();

    foreach(QSerialPortInfo info, ports)
    {
        emit sendSignalToInterface(info.portName());
        emit sendSignalToInterface(info.manufacturer());
    }
}

void engine::readPort()
{
    cardNumber = pQSerialPort->readAll();
    cardNumber.remove(0,3);
    cardNumber.chop(3);
    qDebug()<<cardNumber;
    emit sendSignalToInterface(cardNumber);
}
