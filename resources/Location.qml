import QtQuick 2.12
import QtQuick.Controls 2.3



Button {
    Text {
        id: name
        text: qsTr("Location")

        anchors.leftMargin: 10

        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter

        anchors.fill: parent
    }

    onClicked: {

        locationDialog:visible = true
        weatherStackView.push(locationDialog)
    }
}







