#ifndef RETRIEVEBUSINFORMATION_H
#define RETRIEVEBUSINFORMATION_H

#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QObject>
#include "processbusdata.h"

class RetrieveBusInformation : public QObject
{
    Q_OBJECT

public:
    RetrieveBusInformation(QString busStopCode, QString busInfoUrl, QObject *parent = nullptr);

    void setBusStopCode(QString busStopCode);
    void setBusInformationUrl(QString busUrl);

    void makeRequest();

    QString getBusInformationUrl() const;
    QString getBusStopCode() const;
    QList<BusInformationData> getAllBusInfo();

signals:
    void busDataIsHere(QList<BusInformationData> bdd);

public slots:
    void doneRequest(QNetworkReply * reply);


private:
    QNetworkAccessManager   m_networkManager;
    QString                 m_busStopCode;
    QString                 m_busInformationUrl;
    ProcessBusData          m_busParser;
    QList<BusInformationData> m_currentBusInformationData;


};

#endif // RETRIEVEBUSINFORMATION_H

