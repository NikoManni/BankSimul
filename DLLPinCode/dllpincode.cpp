#include "dllpincode.h"


void DLLPinCode::interfacePinCodeComponent()
{


    objectpinkoodi = new pinkoodi;

    connect(objectpinkoodi,SIGNAL(OikeaPinkoodi()),
            this, SLOT(receiveSignalFromEngine()));



    objectpinkoodi->setCardNum(cardNumber);
    objectpinkoodi->show();
    objectpinkoodi->exec();
    pinCodeValue = objectpinkoodi->returnPinCode();

    delete objectpinkoodi;
    objectpinkoodi = NULL;

    qDebug() << "DLLPinCode closed";

}

QString DLLPinCode::interfaceReturnPinCodeValue()
{
    return pinCodeValue;
}

QString DLLPinCode::getCardNumber() const
{
    return cardNumber;
}

void DLLPinCode::setCardNumber(const QString &value)
{
    cardNumber = value;
}

void DLLPinCode::receiveSignalFromEngine()
{
    emit sendSignalToExe();
}



