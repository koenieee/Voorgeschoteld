#include "displayallbusinformation.h"
#include "ui_displayallbusinformation.h"
#include <QStringListModel>
#include <QDebug>

DisplayAllBusInformation::DisplayAllBusInformation(QList<BusInformationData> bdi, QWidget *parent) :
    m_currentBusData(bdi),
    QDialog(parent),
    ui(new Ui::DisplayAllBusInformation)
{
    ui->setupUi(this);
    setAllBusInformation(m_currentBusData);

}

void DisplayAllBusInformation::setAllBusInformation(QList<BusInformationData> bdd){
    qDebug() << "Settings busInformation";
    m_currentBusData = bdd;
    // Create model

    QStringList List;

    for(BusInformationData bu : m_currentBusData){
        List.append(bu.toString());
    }

    m_busModelValues.setStringList(List);
    ui->listView->setModel(&m_busModelValues);
}


DisplayAllBusInformation::~DisplayAllBusInformation()
{
    delete ui;
}
