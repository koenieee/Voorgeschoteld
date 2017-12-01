#include "processhtmldata.h"
#include <QtXml/QDomDocument>
#include <QDebug>

ProcessHtmlData::ProcessHtmlData(QObject *parent) : QObject(parent)
{

}


void ProcessHtmlData::processData(QString html){
        QString newHtmlString = html.remove(0, 141);
        QDomDocument doc;
        QString errors;
        int line;
        int col;
        doc.setContent(newHtmlString, &errors, &line, &col);
        qDebug() << "HTML: " << newHtmlString.toLatin1().constData();


        qDebug() << "Errors:" << errors<< "on line: " << line << " col: " << col;

    QDomNodeList rates = doc.elementsByTagName("a");
    qDebug() << "Rates: " << rates.size();

    for (int i = 0; i < rates.size(); i++) {
        QDomNode n = rates.item(i);
        QString nextLink = n.toElement().attributeNode("href").value();

        QString className = n.firstChild().firstChild().firstChild().nodeValue();

  /*
        BusInformationData bid;

        //qDebug() << "ClassName: " << className;
      if("col-md-2 col-xs-4" == className){
            bid.time = n.firstChild().firstChild().nodeValue();
            qDebug() << "BusTime:" << bid.time;
        }
        if("ott-linecode col-md-1 col-xs-4" == className){
            bid.lineNumber = n.firstChild().nodeValue();
            qDebug() << "BusNumber:" << bid.lineNumber;
        }
        if("ott-destination" == className){
            bid.desination = n.firstChild().nodeValue();
            qDebug() << "BusDestination:" << bid.desination;
        }
        allBuses.append(bid);
        */

        qDebug() << "Classname: " << className;
    }


/*
    QList<BusInformationData> allBuses;

    for (int i = 0; i < rates.size(); i++) {
        QDomNode n = rates.item(i);
        QString className = n.attributes().item(0).toAttr().value();

        BusInformationData bid;

        //qDebug() << "ClassName: " << className;
        if("col-md-2 col-xs-4" == className){
            bid.time = n.firstChild().firstChild().nodeValue();
            qDebug() << "BusTime:" << bid.time;
        }
        if("ott-linecode col-md-1 col-xs-4" == className.){
            bid.lineNumber = n.firstChild().nodeValue();
            qDebug() << "BusNumber:" << bid.lineNumber;
        }
        if("ott-destination" == className){
            bid.desination = n.firstChild().nodeValue();
            qDebug() << "BusDestination:" << bid.desination;
        }
        allBuses.append(bid);
    }
*/
  //  qDebug() << "Desination: " << allBuses.first().desination;


}
