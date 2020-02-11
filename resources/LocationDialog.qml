import QtQuick 2.12
import QtQuick.Controls 2.3


Rectangle{
    color: "#99CCFF"

  //  Component.onCompleted: visible = false

    property bool  searchItemVisible: true

    Button {
        id: applyButton
        x: 540
        y: 418
        height: 30
        text: qsTr("Apply")
        focusPolicy: Qt.NoFocus
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        onClicked: {
            location.getCurrentLocationFromModel();
            weatherStackView.push(todayWeatherPage)
        }

    }

    ComboBox {
        id: countryComboBox
        width: 250
        height: 30
        spacing: -3
        anchors.left: countryLabel.right
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10

        model: countryModel

        property bool userOptionsLoaded: false

        Component.onCompleted: {
            currentIndex = userOptions.getCountryIndex();
            userOptionsLoaded = true;
        }

        onCurrentIndexChanged: {
            if(userOptionsLoaded)
                userOptions.setCountryIndex(currentIndex);
        }
    }

    Label {
        id: countryLabel
        width: 70
        height: 30
        text: qsTr("Country")
        lineHeight: 0.6
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
    }

    Label {
        id: cityLabel
        x: -9
        y: -8
        width: 70
        height: 30
        text: qsTr("City")
        anchors.leftMargin: 10
        anchors.top: countryLabel.bottom
        lineHeight: 0.6
        anchors.topMargin: 10
        anchors.left: parent.left
    }

    TextField {
        id: cityEdit
        width: 250
        height: 30
        text: qsTr("Kaluga")
        visible: true
        anchors.left: countryLabel.right
        anchors.leftMargin: 10
        anchors.top: countryComboBox.bottom
        anchors.topMargin: 10
    }

    Button {
        id: citySearchButton
        height: 30
        text: qsTr("Search")
        visible: true
        anchors.left: countryLabel.right
        anchors.leftMargin: 10
        anchors.top: cityEdit.bottom
        anchors.topMargin: 10

        onClicked: {
            var queryOptions =  "find?q=" +
                            cityEdit.text.trim() +
                            "," +
                            countryModel.getCountryCode(countryComboBox.currentIndex);

            network.openweathermapQuery(queryOptions);

        }
    }

    ListView {
        id: citiesListView
        visible: false
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.left: countryLabel.right
        anchors.leftMargin: 10
        anchors.top: citySearchButton.bottom
        anchors.topMargin: 10

        delegate: Rectangle{
            implicitWidth: 200
            implicitHeight: 30

            Text {
                anchors.fill: parent
                text: display
            }
            MouseArea{
                anchors.fill: parent

                onClicked: {
                    cityEdit.text = display;

                    locationModel.setCurrentIndex(locationNumber);
                    searchItemVisible = false;
                }
            }

        }

        model:locationModel
    }

    Button {
        id: resetButton
        x: -9
        y: -8
        height: 30
        text: qsTr("Reset")
        anchors.top: countryComboBox.bottom
        anchors.left: cityEdit.right
        anchors.leftMargin: 10
        anchors.topMargin: 10
        visible: false

        onClicked: {
            searchItemVisible = true;
        }
    }
    states: [
        State {
            name: "locationSearch"; when: searchItemVisible == true;
            PropertyChanges { target: resetButton; visible: false }
            PropertyChanges { target: citySearchButton; visible: true }
            PropertyChanges { target: citiesListView; visible: true }
            PropertyChanges { target: cityEdit; readOnly: false }

        },
        State {
            name: "locationFixed"; when: searchItemVisible == false;
            PropertyChanges { target: resetButton; visible: true }
            PropertyChanges { target: citySearchButton; visible: false }
            PropertyChanges { target: citiesListView; visible: false }
            PropertyChanges { target: cityEdit; readOnly: true }
        }
    ]
}







































/*##^## Designer {
    D{i:2;anchors_x:86;anchors_y:8}D{i:3;anchors_x:24;anchors_y:8}D{i:4;anchors_x:24;anchors_y:8}
D{i:5;anchors_x:90;anchors_y:50}D{i:6;anchors_x:90;anchors_y:92}D{i:7;anchors_height:160;anchors_width:110;anchors_x:95;anchors_y:135}
D{i:11;anchors_x:90;anchors_y:92}
}
 ##^##*/
