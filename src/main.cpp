#include "voorgeschoteldwindow.h"
#include "retrievebusinformation.h"
#include "globalvoorgeschoteldvalues.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VoorgeschoteldWindow w;
    w.show();

    RetrieveBusInformation rbi{};

    rbi.setBusInformationUrl(GlobalVoorgeschoteldValues::busUrl);
    rbi.setBusStopCode(GlobalVoorgeschoteldValues::busStop);

    rbi.makeRequest();
    return a.exec();
}
