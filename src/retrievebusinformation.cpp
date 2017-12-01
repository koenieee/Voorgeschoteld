#include "retrievebusinformation.h"
#include <QNetworkReply>
#include <QtNetwork>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "processhtmldata.h"


RetrieveBusInformation::RetrieveBusInformation()
{
    connect(&m_networkManager, &QNetworkAccessManager::finished, this, &RetrieveBusInformation::doneRequest);

}

void RetrieveBusInformation::makeRequest(){
    if(!m_busInformationUrl.isEmpty()){

        QUrl url(m_busInformationUrl);
        QNetworkRequest request;
       // request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
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

    QStringList propertyNames;
    QStringList propertyKeys;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonObject jsonArray = jsonObject["amfcol"].toObject();
QJsonObject passes = jsonArray["50421690"].toObject();
QJsonObject haltes = passes["Passes"].toObject();


    QJsonDocument doc;
    doc.setObject(haltes);

    QString dataToString(doc.toJson());
    qDebug().noquote() << "Array: " << dataToString.toLatin1();

    foreach (const QJsonValue & value, haltes) {
        QJsonObject info = value.toObject();
        QString lineNumber = info["LinePublicNumber"].toString();
        QString destinationName = info["DestinationName50"].toString();
        qDebug().noquote() << "Naam: " <<destinationName;

    }


   // qDebug() << propertyNames;

    /*data.remove(QChar('\\'), Qt::CaseInsensitive);
     data.remove(QChar('\n'), Qt::CaseInsensitive);
    data.trimmed();
    qDebug() << "Data was:" << data;
   // qDebug() << "Printing data: " << data;
   // m_htmlParser.processData(data);
*/

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
