import QtQuick 2.12
import QtQuick.Controls 2.3



Button {   
    Text {
        id: locationText
        text: qsTr("Unknoun location")

        anchors.leftMargin: 10

        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter

        anchors.fill: parent
    }

    function getCurrentLocationFromModel(){
        locationText.text = locationModel.getCurrentLocationName() ;
    }

    onClicked: {

        locationDialog:visible = true
        weatherStackView.push(locationPage)
    }
}







