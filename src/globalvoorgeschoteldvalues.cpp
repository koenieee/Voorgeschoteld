#include "globalvoorgeschoteldvalues.h"

//assign values to QString variables. Outside class because of compiler issues.

const QString GlobalVoorgeschoteldValues::busStop = "amfcol";        //stop code for Kamp / De Stier amersfoort
const QString GlobalVoorgeschoteldValues::busUrl = "http://v0.ovapi.nl/stopareacode/"+busStop;
