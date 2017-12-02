#include "processbusdata.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

ProcessBusData::ProcessBusData(QString busStopCode, QObject *parent) : QObject(parent)
{
    m_busStopCode = busStopCode;
}


void ProcessBusData::printJsonObject(QJsonObject theObj){
    QJsonDocument doc;
    doc.setObject(theObj);

    QString dataToString(doc.toJson());
    qDebug().noquote() << "JSON DATA: " << dataToString.toLatin1();
}


QList<BusInformationData> ProcessBusData::processData(QString data){

    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonObject jsonArray = jsonObject[m_busStopCode].toObject();
    QJsonObject busStops = jsonArray["Passes"].toObject();


    QList<BusInformationData> busInfo;

    foreach (const QJsonValue & value, busStops) {
        BusInformationData bid;

        QJsonObject info = value.toObject();
        QString lineNumber = info["LinePublicNumber"].toString();
        QString expectedTime = info["ExpectedDepartureTime"].toString();
        QString destinationName = info["DestinationName50"].toString();

        bid.lineNumber = lineNumber;
        bid.desination = destinationName;
        bid.expectedTime = expectedTime;
        busInfo.append(bid);
    }

    return busInfo;
}
