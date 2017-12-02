#ifndef DISPLAYALLBUSINFORMATION_H
#define DISPLAYALLBUSINFORMATION_H

#include <QDialog>
#include "core/processbusdata.h"
#include <QStringListModel>

namespace Ui {
class DisplayAllBusInformation;
}

class DisplayAllBusInformation : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayAllBusInformation(QList<BusInformationData> bdi, QWidget *parent = 0);
    ~DisplayAllBusInformation();

public slots:
    void setAllBusInformation(QList<BusInformationData> bdd);

private:
    Ui::DisplayAllBusInformation *  m_ui;
    QList<BusInformationData>       m_currentBusData;
    QStringListModel                m_busModelValues;
};

#endif // DISPLAYALLBUSINFORMATION_H
