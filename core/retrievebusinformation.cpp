#include "retrievebusinformation.h"
#include <QNetworkReply>
#include <QtNetwork>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "processbusdata.h"


RetrieveBusInformation::RetrieveBusInformation(QString busStopCode, QString busInfoUrl, QObject * parent):
    m_busParser(busStopCode),
    m_busStopCode(busStopCode),
    m_busInformationUrl(busInfoUrl),
    QObject(parent)
{
    connect(&m_networkManager, &QNetworkAccessManager::finished, this, &RetrieveBusInformation::doneRequest);

}

void RetrieveBusInformation::makeRequest(){
    if(!m_busInformationUrl.isEmpty()){

        QUrl url(m_busInformationUrl + "/" + m_busStopCode);
        QNetworkRequest request;
        request.setUrl(url);
        m_networkManager.get(request);

    }
}


void RetrieveBusInformation::doneRequest(QNetworkReply * reply){
    QString data;

    if (reply->error() == QNetworkReply::NoError)
    {
        //process data only when there are no errors.
        data = QString(reply->readAll ());
        m_currentBusInformationData = m_busParser.processData(data);
        qDebug() << "Emitting";
        emit busDataIsHere(m_currentBusInformationData);
    }
    else
    {
        data = QString(reply->errorString ());
    }
}

QList<BusInformationData> RetrieveBusInformation::getAllBusInfo(){
    return m_currentBusInformationData;
}

void RetrieveBusInformation::setBusStopCode(QString busStopCode){
    m_busStopCode = busStopCode;
}

void RetrieveBusInformation::setBusInformationUrl(QString busUrl){
    m_busInformationUrl = busUrl;
}


QString RetrieveBusInformation::getBusInformationUrl() const{
    return m_busInformationUrl;
}
QString RetrieveBusInformation::getBusStopCode() const{
    return m_busStopCode;
}
