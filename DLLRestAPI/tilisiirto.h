#ifndef TILISIIRTO_H
#define TILISIIRTO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class tilisiirto;
}

class tilisiirto : public QDialog
{
    Q_OBJECT

public:
    explicit tilisiirto(QWidget *parent = nullptr);
    ~tilisiirto();
    void haeRestApiData(QString SessionUser);

private slots:
    void on_Close_button_clicked();

    void on_maksa_clicked();

    void on_tyhjenna_summa_clicked();

    void on_tyhjenna_tili_clicked();

public slots:
    void tiliSiirto(QNetworkReply *reply);

private:
    Ui::tilisiirto *ui;
    QNetworkAccessManager *tilisiirtoManager;
    QNetworkReply *tilisiirtoReply;
    QString SessionUser;
};

#endif // TILISIIRTO_H
