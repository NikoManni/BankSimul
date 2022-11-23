#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include <QMessageBox>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    explicit nosto(QWidget *parent = nullptr);
    ~nosto();
    void haeRestApiData(QString SessionUser);
    void TiedotLabeliin();

private slots:
    void on_Close_button_clicked();

    void on_nosto_20_clicked();

    void on_nosto_40_clicked();

    void on_nosto_60_clicked();

    void on_nosto_100_clicked();

    void on_nosto_200_clicked();

    void on_nosto_500_clicked();

    void on_talletus_20_clicked();

    void on_talletus_40_clicked();

    void on_talletus_60_clicked();

    void on_talletus_100_clicked();

    void on_talletus_200_clicked();

    void on_talletus_500_clicked();

private:
    Ui::nosto *ui;
    QNetworkAccessManager *raiseManager;
    QNetworkReply *raiseReply;
    QString SessionUser;
    QNetworkAccessManager *tiedotManager;
    QNetworkReply *tiedotReply;

public slots:
    void nostoSlot(QNetworkReply *reply);
    void talletusSlot(QNetworkReply *reply);
    void tiedotSlot(QNetworkReply *reply);
};

#endif // NOSTO_H
