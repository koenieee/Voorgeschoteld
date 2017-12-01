#include "retrievebusinformation.h"
#include <QNetworkReply>
#include <QtNetwork>
#include <QObject>
#include <QNetworkAccessManager>
#include "processhtmldata.h"


RetrieveBusInformation::RetrieveBusInformation()
{
    connect(&m_networkManager, &QNetworkAccessManager::finished, this, &RetrieveBusInformation::doneRequest);

}

void RetrieveBusInformation::makeRequest(){
    if(!m_busInformationUrl.isEmpty()){

        QUrl url(m_busInformationUrl);
        QNetworkRequest request;
        request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
        request.setUrl(url);


        m_networkManager.get(request);

    }
}


void RetrieveBusInformation::doneRequest(QNetworkReply * reply){
  //  qDebug() << "DoneRequest:: is called" << reply->hasRawHeader("GET");
    QString data = "leeg";
    if (reply->error() == QNetworkReply::NoError)
    {
        data = QString(reply->readAll ());
    }
    else
    {
        data = QString(reply->errorString ());
    }
    data.remove(QChar('\\'), Qt::CaseInsensitive);
     data.remove(QChar('\n'), Qt::CaseInsensitive);
    data.trimmed();
 //   qDebug() << "Data was:" << "leeg";
   // qDebug() << "Printing data: " << data;
    m_htmlParser.processData(data);


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
