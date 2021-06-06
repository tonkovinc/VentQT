#include "setting.h"

Setting::Setting()
{
}

Setting::Setting(uint16_t roomId){
    Setting::setId(roomId);
}

void Setting::setId(uint16_t roomId){
    Setting::id = roomId;
}
uint16_t Setting::getId(){
    return Setting::id;
}

void Setting::setTimeStart(uint16_t Time){
    Setting::timeStartRoom = Time;
}
uint16_t Setting::getTimeStart(){
    return Setting::timeStartRoom;
}

void Setting::setTempRoom(float Temp){
    Setting::tempRoom = Temp;
}
float Setting::getTempRoom(){
    return Setting::tempRoom;
}

void Setting::setCO2Room(uint16_t co2){
    Setting::co2Room = co2;
}
uint16_t Setting::getetCO2Room(){
    return Setting::co2Room;
}

void Setting::setHumRoom(float Hum){
    Setting::humRoom = Hum;
}
float Setting::getHumRoom(){
    return Setting::humRoom;
}

void Setting::setPeopleRoom(uint16_t people){
    Setting::peopleRoom = people;
}

uint16_t Setting::getPeopleRoom(){
    return Setting::peopleRoom;
}
