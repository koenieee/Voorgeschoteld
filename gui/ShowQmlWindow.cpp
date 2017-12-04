#include "ShowQmlWindow.h"
#include <QQmlContext>

ShowQmlWindow::ShowQmlWindow(QObject *parent) :
    QObject(parent)
{
}

void ShowQmlWindow::setQmlUrl() {
    m_quickView.setSource(QUrl("qrc:/busInfoDisplay"));
}

void ShowQmlWindow::show(){
    if(m_currentQmlData)
    {
        qDebug() << "Setting data";
        m_quickView.rootContext()->setContextProperty("qmlData", m_currentQmlData);
    }
    setQmlUrl();
    m_quickView.show();
}

void ShowQmlWindow::setQmlData(BusDataModel * vqd){
    m_currentQmlData = vqd;
}
