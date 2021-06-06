#ifndef GETALLSETTINGS_H
#define GETALLSETTINGS_H
#include "connectclass.h"

#include <QJsonDocument>
#include <QJsonArray>

class GetAllSettings : public ConnectClass
{
public:
    GetAllSettings() : ConnectClass() {
        manager = new QNetworkAccessManager();
    }

    void sendRequest() {
        auto status = connect(manager, &QNetworkAccessManager::finished,
                              this, &GetAllSettings::ReplyFinished);
        qDebug() << "Connection status:" << status;
        QNetworkRequest request = QNetworkRequest(QUrl("https://back.vc-app.ru/dev/script?did=10155&sc_id=98"));
        request.setRawHeader("Authorization", "Yandex AgAAAAAf34VAAAa-idNGLE5cz0tusy1Wgd8Humk");
        manager->get(request);
    }
    void ReplyFinished(QNetworkReply *reply) {
        QByteArray a = reply->readAll();
        if(!reply->error()){
            QJsonDocument document = QJsonDocument::fromJson(a);
            parseJSON(document);
        }
        setJsonData(a);
        //qDebug() << getJsonData();
        setHTTPcode(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute));
        if(httpCode.isValid()){
            QString status = httpCode.toString();
            qDebug() << status;
        }
    }
    void setJsonData(const QByteArray &JsonData) {
        jsonData = JsonData;
    }
    QByteArray getJsonData() const {
        return jsonData;
    }

    void setHTTPcode(const QVariant &p_httpCode){
        httpCode = p_httpCode;
    }
    QVariant getHTTPcode() const{
        return httpCode;
    }

    void parseJSON(const QJsonDocument &doc){

        QJsonObject root = doc.object();
        int count = 0;
        QJsonValue roomGroupValue = root.value("roomGroup0");
        //qDebug() << roomGroupValue;
        QJsonObject roomGroupObj = roomGroupValue.toObject();
        for (int j = 0; j < roomGroupObj.size(); j++){
            QJsonValue dayGroupValue = roomGroupObj.value(QString("dayGroup") + QString(QString::number(j)));
            QJsonObject dayGroupObj = dayGroupValue.toObject();
            for (int k = 0; k < dayGroupObj.size(); k++){
                QJsonArray daysArr = dayGroupObj.value("days").toArray();
                for (int q = 0; q < daysArr.size(); q++){
                    QJsonValue settingValue = roomGroupObj.value(QString("setting") + QString(QString::number(k)));
                    QJsonObject settingObj = settingValue.toObject();
                    count++;
                    qDebug() << settingValue;
                }
            }
        }
        qDebug() << count;
    }

private:
    QNetworkAccessManager *manager;
};

#endif // GETALLSETTINGS_H
