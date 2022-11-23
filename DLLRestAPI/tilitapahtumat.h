#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tilitapahtumat(QWidget *parent = nullptr);
    ~tilitapahtumat();
    void haeRestApiData(QString SessionUser);

private slots:
    void on_Close_Button_clicked();

public slots:
    void tilitapahtumatSlot(QNetworkReply *reply);
    void naytasaldoSlot(QNetworkReply *reply);

private:
    Ui::tilitapahtumat *ui;
    QNetworkAccessManager *tilitapahtumatManager;
    QNetworkReply *tilitapahtumatReply;
};

#endif // TILITAPAHTUMAT_H
