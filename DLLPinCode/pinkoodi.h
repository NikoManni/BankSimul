#ifndef PINKOODI_H
#define PINKOODI_H

#include <QMessageBox>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDialog>
#include <QDebug>
#include <QLineEdit>
#include <QObject>
#include <QTimer>


namespace Ui {
class pinkoodi;
}

class pinkoodi : public QDialog
{
    Q_OBJECT
public slots:

    void timeoutPinkoodi();

public:
    explicit pinkoodi(QWidget *parent = nullptr);
    ~pinkoodi();
    QString returnPinCode();

    QString getCardNum() const;
    void setCardNum(const QString &value);
signals:
    void OikeaPinkoodi();
private slots:
    void on_Button1_clicked();
    void on_Button2_clicked();
    void on_Button3_clicked();
    void on_Button4_clicked();
    void on_Button5_clicked();
    void on_Button6_clicked();
    void on_Button7_clicked();
    void on_Button8_clicked();
    void on_Button9_clicked();
    void on_Button0_clicked();
    void on_Clear_Button_clicked();
    void on_Enter_Button_clicked();
    void CheckPinkoodi(QNetworkReply *reply);

private:
    Ui::pinkoodi *ui;
    QString valuePinCode;
    QTimer *timer;
    int idleTimer;
    QNetworkAccessManager *pManager;
    QNetworkReply *pReply;
    QString cardNum;
    int korttiStatus;
    bool korttiLukitus;

};

#endif // PINKOODI_H
