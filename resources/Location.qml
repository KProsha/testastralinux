import QtQuick 2.12
import QtQuick.Controls 2.3



Button {
 //   text: qsTr("Location")

    Text {
        id: name
        //text: qsTr("Location")
        text: options.appId

        anchors.leftMargin: 10

        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter

        anchors.fill: parent
    }


}




