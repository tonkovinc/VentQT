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
        //qDebug() << root.size();
        //qDebug() << root.keys().at(0);
        QJsonValue roomGroupValue = root.value("roomGroup0");
        //qDebug() << roomGroupValue;
        QJsonObject roomGroupObj = roomGroupValue.toObject();
        for (int j = 0; j < (roomGroupObj.size()-1); j++){
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
        //QJsonObject roomGroup0 = root[QString("roomGroup") + QString("0")];
       /* if (root.success())
        {
            for (int j = 0; j < (roomGroup0.size() - 1); j++)
            {
                JsonObject& dayGroup0 = roomGroup0[String("dayGroup") + String(j)];
                if (dayGroup0.success())
                {
                    for (int k = 0; k < (dayGroup0.size() - 1); k++)
                    {
                        JsonArray& days = dayGroup0["days"];
                        if (days.success())
                        {
                            for (int q = 0; q < (days.size()); q++)
                            {
                                JsonObject& setting0 = dayGroup0[String("setting") + String(k)];
                                if (setting0.success())
                                {
                                    //for ()

                                    RoomStruct* Obj;//выделение памяти
                                    if (RoomStructAmount == 0)
                                    {
                                        Obj = new RoomStruct[RoomStructAmount + 1];
                                    }
                                    else
                                    {
                                        RoomStruct* tempObj = new RoomStruct[RoomStructAmount + 1];
                                        for (int r = 0; r < RoomStructAmount; r++)
                                        {
                                            tempObj[r] = OurRoomStruct[r]; // копируем во временный объект
                                        }
                                        delete [] Obj;
                                        Obj = tempObj;
                                    }
                                    OurRoomStruct = Obj;
                                    const char* time = setting0["time"];
                                    char subHours[4] = {0,};
                                    char subMin[4] = {0,};
                                    subHours[0] = time[0];
                                    subHours[1] = time[1];
                                    subMin[0] = time[3];
                                    subMin[1] = time[4];
                                    OurRoomStruct[RoomStructAmount].timeStartRoom = dayGroup0["days"][q];// * 24 * 60 +  atoi(subHours) * 60 + atoi(subMin));
                                    OurRoomStruct[RoomStructAmount].timeStartRoom = (OurRoomStruct[RoomStructAmount].timeStartRoom - 1) * 24 * 60 + atoi(subHours) * 60 + atoi(subMin);
                                    OurRoomStruct[RoomStructAmount].id = RoomStructAmount;
                                    OurRoomStruct[RoomStructAmount].tempRoom = setting0["temp"]; // 21
                                    OurRoomStruct[RoomStructAmount].humRoom = setting0["hum"]; // 55
                                    OurRoomStruct[RoomStructAmount].co2Room = setting0["co2"]; // 700
                                    OurRoomStruct[RoomStructAmount].mute = setting0["mute"]; // 0
                                    OurRoomStruct[RoomStructAmount].at_home = setting0["at_home"]; // 1
                                    RoomStructAmount++;
                                } else Serial.println("Parsing setting0!");
                            }
                        } else Serial.println("Parsing days!");
                    }
                } else Serial.println("Parsing dayGroup0!");
            }
        } else Serial.println("Parsing roomGroup0!");
        RoomStructAmount--;*/

    }

private:
    QNetworkAccessManager *manager;
};

#endif // GETALLSETTINGS_H
