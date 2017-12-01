#ifndef PROCESSHTMLDATA_H
#define PROCESSHTMLDATA_H

#include <QObject>

struct BusInformationData{
    QString time;
    QString desination;
    QString lineNumber;
    QString lineLink;
};


class ProcessHtmlData : public QObject
{
    Q_OBJECT
public:
    explicit ProcessHtmlData(QObject *parent = nullptr);

    void processData(QString theData);



signals:

public slots:
};

#endif // PROCESSHTMLDATA_H
