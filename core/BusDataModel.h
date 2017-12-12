#ifndef VOORGESCHOTELDQMLDATA_H
#define VOORGESCHOTELDQMLDATA_H

#include <QObject>
#include <QList>
#include <QStringList>
#include <QAbstractListModel>
#include "ProcessBusData.h"

class BusDataModel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(BusRoles)

public:
    enum BusRoles {
            BusLineNumberRole = Qt::UserRole + 1,
            BusDestinationRole,
            BusTimeRole
        };


    BusDataModel(QList<BusInformationData>  bdd = QList<BusInformationData>(), QObject *parent = nullptr);
    void setBusDataInformation(QList<BusInformationData> bdd);

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

protected:
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

signals:
    void numberPopulated(int number);

public slots:
    QStringList getBusData();

private:
    QList<BusInformationData> m_currentBusInformationData;
    int busCount = 0;
};

#endif // VOORGESCHOTELDQMLDATA_H
