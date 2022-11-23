#ifndef NAYTASALDO_H
#define NAYTASALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class naytasaldo;
}

class naytasaldo : public QDialog
{
    Q_OBJECT

public:
    explicit naytasaldo(QWidget *parent = nullptr);
    ~naytasaldo();
    void haeRestApiData(QString SessionUser);

private slots:
    void on_Close_button_clicked();

public slots:
    void naytasaldoSlot(QNetworkReply *reply);
    void tilitapahtumaSlot(QNetworkReply *reply);


private:
    Ui::naytasaldo *ui;
    QNetworkAccessManager *naytasaldoManager;
    QNetworkReply *naytasaldoReply;
    QNetworkAccessManager *naytasaldoManager2;
    QNetworkReply *naytasaldoReply2;
};

#endif // NAYTASALDO_H
