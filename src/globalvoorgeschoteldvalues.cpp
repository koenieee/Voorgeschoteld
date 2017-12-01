#include "globalvoorgeschoteldvalues.h"

//assign values to QString variables. Outside class because of compiler issues.

const QString GlobalVoorgeschoteldValues::busStop = "NL:S:50421690";        //stop code for Kamp / De Stier amersfoort
const QString GlobalVoorgeschoteldValues::busUrl = "httpS://drgl.nl/stop/"+busStop+"/departurespanel";

