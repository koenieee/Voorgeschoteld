#ifndef GLOBALVOORGESCHOTELDVALUES_H
#define GLOBALVOORGESCHOTELDVALUES_H

#include <QString>

class GlobalVoorgeschoteldValues
{
public:
    static const QString busStopRight;
    static const QString busStopLeft;
    static const QString busUrl;


};

//richting Liendert/Vathorst
const QString GlobalVoorgeschoteldValues::busStopRight = "50421690";        //stop code for Kamp / De Stier amersfoort
//Richting CS
const QString GlobalVoorgeschoteldValues::busStopLeft = "50422570";        //stop code for Flierbeeksingel

const QString GlobalVoorgeschoteldValues::busUrl = "http://v0.ovapi.nl/tpc/";

#endif // GLOBALVOORGESCHOTELDVALUES_H
