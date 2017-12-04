import dataModels 1.0
import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

    Item {
        id: root
        anchors.fill: parent
        Item {
            id: tableview
            width: parent.width
            anchors.leftMargin: 640
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.rightMargin: 0
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            TableView {
                anchors.fill: parent
                model: BusDataModel{}
                TableViewColumn {
                    width: 150
                    role: "busLineNumber"
                    title: "Lijnnummer"
                }
                TableViewColumn {
                    width: 180
                    role: "busDestination"
                    title: "Bestemming"
                }
                TableViewColumn {
                    width: 160
                    role: "busTime"
                    title: "Vertrektijd"
                }
            }
        }
    }

