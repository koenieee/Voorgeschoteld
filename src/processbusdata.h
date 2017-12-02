#ifndef PROCESSHTMLDATA_H
#define PROCESSHTMLDATA_H

#include <QObject>

struct BusInformationData{
    QString expectedTime;
    QString desination;
    QString lineNumber;

    QString toString(){
        return lineNumber+ " || " + expectedTime + " || " + desination;
    }
};


class ProcessBusData : public QObject
{
    Q_OBJECT
public:
    explicit ProcessBusData(QString busStopCode, QObject *parent = nullptr);
    QList<BusInformationData> processData(QString theData);



signals:

public slots:



private:
    void printJsonObject(QJsonObject theObj);


    QString m_busStopCode;
};

#endif // PROCESSHTMLDATA_H
