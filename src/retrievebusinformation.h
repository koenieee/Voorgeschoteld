#ifndef RETRIEVEBUSINFORMATION_H
#define RETRIEVEBUSINFORMATION_H

#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QObject>
#include "processhtmldata.h"

class RetrieveBusInformation : public QObject
{
    Q_OBJECT

public:
    RetrieveBusInformation();

    void setBusStopCode(QString busStopCode);
    void setBusInformationUrl(QString busUrl);

    void makeRequest();

    QString getBusInformationUrl() const;
    QString getBusStopCode() const;

public slots:
    void doneRequest(QNetworkReply * reply);

private:
    QNetworkAccessManager   m_networkManager;
    QString                 m_busStopCode;
    QString                 m_busInformationUrl;
    ProcessHtmlData         m_htmlParser;


};

#endif // RETRIEVEBUSINFORMATION_H

