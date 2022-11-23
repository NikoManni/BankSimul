#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "DLLPinCode_global.h"
#include "pinkoodi.h"
#include <QString>
#include <QDebug>

class DLLPINCODE_EXPORT DLLPinCode:public QObject
{
    Q_OBJECT
public:
    void interfacePinCodeComponent();
    QString interfaceReturnPinCodeValue();
    QString getCardNumber() const;
    void setCardNumber(const QString &value);

private:
    pinkoodi *objectpinkoodi;
    QString pinCodeValue;
    QString cardNumber;
public slots:
    void receiveSignalFromEngine();
signals:
    void sendSignalToExe();
};

#endif // DLLPINCODE_H
