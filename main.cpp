#include <QCoreApplication>
#include <iostream>
#include "main.h"
#include "getallsettings.h"

int main(int argc, char *argv[]) {
    auto app = new QApplication(argc, argv);
    auto GET = new GetAllSettings();
    GET->sendRequest();
    //GET->parseJSON(GET->getJsonData());
    return QApplication::exec();
}
