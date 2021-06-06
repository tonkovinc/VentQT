#ifndef CONNECTCLASS_H
#define CONNECTCLASS_H
#include <QByteArray>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QApplication>

class ConnectClass : public QObject{
Q_OBJECT
public:
    ConnectClass(){
    }
    virtual void sendRequest() = 0;
    virtual void ReplyFinished(QNetworkReply *reply) = 0;
    virtual void setJsonData(const QByteArray &jsonData) = 0;
    virtual QByteArray getJsonData() const = 0;
    virtual void setHTTPcode(const QVariant &httpCode) = 0;
    virtual QVariant getHTTPcode() const = 0;


private:

protected:
    QByteArray jsonData;
    QVariant httpCode;
};

#endif // CONNECTCLASS_H
