#ifndef PVALIKKO_H
#define PVALIKKO_H

#include <QDialog>
#include <QTimer>
#include <QDebug>
#include "dllrestapi.h"


namespace Ui {
class pvalikko;
}

class pvalikko : public QDialog
{
    Q_OBJECT

public:
    explicit pvalikko(QWidget *parent = nullptr);
    ~pvalikko();
    void closeConnection();
    void setSessionUser(QString SessionUser);
    void asetaNimiLabeliin();

public slots:

    void pvalikkoTimeout();
    void onePersonSlot(QNetworkReply *reply);

private slots:

    void on_buttonsaldo_clicked();

    void on_buttontili_clicked();

    void on_buttonnosto_clicked();

    void on_buttonlasku_clicked();

    void on_buttontilisiirto_clicked();

    void on_buttonlogout_clicked();

private:
    Ui::pvalikko *ui;
    QTimer *timer;
    DLLRestAPI *pRestApi;
    int idleTimer;
    QString SessionUser;
    QNetworkAccessManager *onePersonManager;
    QNetworkReply *onePersonReply;
};

#endif // PVALIKKO_H
