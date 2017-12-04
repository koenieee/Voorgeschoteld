#include "BusDataModel.h"

BusDataModel::BusDataModel(QObject *parent) :
    QAbstractListModel(parent)
{
    beginResetModel();
    m_currentBusInformationData = {
         { "5", "Centraal Station", "11:30" },
         { "5", "Centraal Station", "11:32" },
         { "206", "Uithof","11:38"  }
     };
    busCount = 0;
    endResetModel();
}


void BusDataModel::setBusDataInformation(QList<BusInformationData> bdd){

    beginResetModel();
    m_currentBusInformationData = bdd;
    busCount = 0;
    endResetModel();


    /*m_currentBusInformationData = bdd;
    emit busDataChanged(); //let the gui know there changed something.
    */
}

QStringList BusDataModel::getBusData(){

    QStringList list;
   /*
    for(BusInformationData bu : m_currentBusInformationData){
        list.append(bu.toString());
    }
*/
    return list;
}

bool BusDataModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
   if (!hasIndex(index.row(), index.column(), index.parent()) || !value.isValid())
       return false;

   BusInformationData &item = m_currentBusInformationData[index.row()];
   if (role == BusDestinationRole) item.desination = value.toString();
   else if (role == BusLineNumberRole) item.lineNumber = value.toString();
   else if (role == BusTimeRole) item.lineNumber = value.toString();
   else return false;

   emit dataChanged(index, index, { role } );

   return true ;

}


QVariant BusDataModel::data(const QModelIndex & index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_currentBusInformationData.size() || index.row() < 0)
        return QVariant();

    const BusInformationData &item = m_currentBusInformationData.at(index.row());
    if (role == BusDestinationRole) return item.desination;
    if (role == BusLineNumberRole) return item.lineNumber;
    if (role == BusTimeRole) return item.expectedTime;
    return QVariant();
}


QHash<int, QByteArray> BusDataModel::roleNames() const {
        return { { BusLineNumberRole, "busLineNumber" },
            { BusDestinationRole, "busDestination" },
            { BusTimeRole, "busTime" },
        };
    }


int BusDataModel::rowCount(const QModelIndex & /* parent */) const
{
    return busCount;
}


bool BusDataModel::canFetchMore(const QModelIndex & /* index */) const
{
    if (busCount < m_currentBusInformationData.size())
        return true;
    else
        return false;
}

void BusDataModel::fetchMore(const QModelIndex & /* index */)
{
    int remainder = m_currentBusInformationData.size() - busCount;
    int itemsToFetch = qMin(100, remainder);

    beginInsertRows(QModelIndex(), busCount, busCount+itemsToFetch-1);

    busCount += itemsToFetch;

    endInsertRows();

    emit numberPopulated(itemsToFetch);
}
