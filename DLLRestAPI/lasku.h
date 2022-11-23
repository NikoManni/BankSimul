#ifndef LASKU_H
#define LASKU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class lasku;
}

class lasku : public QDialog
{
    Q_OBJECT

public:
    explicit lasku(QWidget *parent = nullptr);
    ~lasku();
    void haeRestApiData(QString SessionUser);

private slots:
    void on_Close_button_clicked();

    void on_maksa_clicked();

public slots:
    void laskuSlot(QNetworkReply *reply);
    void tuoLasku(QNetworkReply *reply2);
private:
    Ui::lasku *ui;
    QNetworkAccessManager *laskuManager;
    QNetworkReply *laskuReply;

    QNetworkAccessManager *laskuManager2;
    QNetworkReply *laskuReply2;

    QString SessionUser;
};

#endif // LASKU_H
