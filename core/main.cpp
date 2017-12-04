#include "gui/voorgeschoteldwindow.h"
#include "retrievebusinformation.h"
#include "globalvoorgeschoteldvalues.h"
#include "gui/displayallbusinformation.h"
#include "gui/ShowQmlWindow.h"
#include <QApplication>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // VoorgeschoteldWindow w;
   // w.show();

    qmlRegisterType<BusDataModel>("dataModels", 1, 0, "BusDataModel");

    RetrieveBusInformation rbi{GlobalVoorgeschoteldValues::busStopLeft, GlobalVoorgeschoteldValues::busUrl};

    rbi.makeRequest();

    DisplayAllBusInformation dbi;

    QObject::connect(&rbi, &RetrieveBusInformation::busDataIsHere, &dbi, &DisplayAllBusInformation::setAllBusInformation);

    return a.exec();
}
