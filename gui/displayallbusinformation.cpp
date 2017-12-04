#include "displayallbusinformation.h"
#include "ui_displayallbusinformation.h"
#include <QStringListModel>
#include <QDebug>

DisplayAllBusInformation::DisplayAllBusInformation(QWidget *parent) :
    m_qmlWindow(parent),
    QDialog(parent),
    m_ui(new Ui::DisplayAllBusInformation)
{
    m_ui->setupUi(this);
}

void DisplayAllBusInformation::setAllBusInformation(QList<BusInformationData> bdd){
    m_qmlData.setBusDataInformation(bdd);
    m_qmlWindow.setQmlData(&m_qmlData);
    m_qmlWindow.show();
}


DisplayAllBusInformation::~DisplayAllBusInformation()
{
    delete m_ui;
}
