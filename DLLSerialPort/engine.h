#ifndef ENGINE_H
#define ENGINE_H
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QList>

class engine:public QObject
{
    Q_OBJECT
public:
    engine(QObject * parent = nullptr);
    ~engine();
    void open(void);
    void info(void);
private:
    QSerialPort * pQSerialPort;
    QSerialPortInfo * pQSerialPortInfo;
    QString cardNumber;
signals:
    void sendSignalToInterface(QString);
    void sendNumToInterface(QString);
private slots:
    void readPort();
};

#endif // ENGINE_H
