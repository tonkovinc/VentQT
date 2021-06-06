#ifndef SETTING_H
#define SETTING_H

#include <QTextStream>

class Setting
{
public:
    Setting();
    Setting(uint16_t roomId);

    void setId(uint16_t roomId);
    uint16_t getId();

    void setTimeStart(uint16_t Time);
    uint16_t getTimeStart();

    void setTempRoom(float Temp);
    float getTempRoom();

    void setCO2Room(uint16_t co2);
    uint16_t getetCO2Room();

    void setHumRoom(float Hum);
    float getHumRoom();

    void setPeopleRoom(uint16_t people);
    uint16_t getPeopleRoom();
private:
    uint16_t id;
    uint16_t timeStartRoom;
    float tempRoom;
    uint16_t co2Room;
    float humRoom;
    uint16_t peopleRoom;

};

#endif // SETTING_H
