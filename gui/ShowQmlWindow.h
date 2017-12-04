#ifndef SHOWQMLWINDOW_H
#define SHOWQMLWINDOW_H

#include <QObject>
#include "core/BusDataModel.h"
#include <QQuickView>

class ShowQmlWindow : public QObject
{
    Q_OBJECT
public:
    explicit ShowQmlWindow(QObject *parent = nullptr);
    void setQmlUrl();
    void setQmlData(BusDataModel * vqd);
    void show();

private:
    QQuickView              m_quickView;
    BusDataModel * m_currentQmlData;
};

#endif // SHOWQMLWINDOW_H
