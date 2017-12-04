#ifndef DISPLAYALLBUSINFORMATION_H
#define DISPLAYALLBUSINFORMATION_H

#include <QDialog>
#include "core/processbusdata.h"
#include "core/BusDataModel.h"
#include "gui/ShowQmlWindow.h"
#include <QStringListModel>

namespace Ui {
class DisplayAllBusInformation;
}

class DisplayAllBusInformation : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayAllBusInformation(QWidget *parent = 0);
    ~DisplayAllBusInformation();

public slots:
    void setAllBusInformation(QList<BusInformationData> bdd);

private:
    Ui::DisplayAllBusInformation *  m_ui;
    BusDataModel           m_qmlData;
    ShowQmlWindow                   m_qmlWindow;
};

#endif // DISPLAYALLBUSINFORMATION_H
