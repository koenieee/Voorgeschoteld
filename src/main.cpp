#include "voorgeschoteldwindow.h"
#include "retrievebusinformation.h"
#include "globalvoorgeschoteldvalues.h"
#include "ui/displayallbusinformation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // VoorgeschoteldWindow w;
   // w.show();



    RetrieveBusInformation rbi{GlobalVoorgeschoteldValues::busStopLeft, GlobalVoorgeschoteldValues::busUrl};

    rbi.makeRequest();

    QList<BusInformationData> currentInfo; //this may be empty...

    DisplayAllBusInformation dbi{currentInfo};

    QObject::connect(&rbi, &RetrieveBusInformation::busDataIsHere, &dbi, &DisplayAllBusInformation::setAllBusInformation);
    dbi.show();

    return a.exec();
}
