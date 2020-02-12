import QtQuick 2.0
import QtQuick.Controls 2.3



Rectangle {
    id: rectangle
    height: 150

    //    border.width: 2
    //    border.color: "black"

    property string dateTime: ""

    property string temp: ""
    property string feelsLike: ""

    property int pressure: 0
    property int humidity:0

    property string description:""

    property int cloudPercentage: 0

    property string windSpeed: ""
    property string windAngle: ""
    property string snow: ""
    property string rain: ""


    gradient: mainGradient

    Text {
        id: thermometerLabel
        width: 101
        height: 20
        text: qsTr("Temperature")
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 40
       // fontSizeMode: Text.Fit
        font.pixelSize: 14
    }

    Text {
        id: thermometerValueLabel
        width: 80
        height: 20
        anchors.left: thermometerLabel.right
        anchors.leftMargin: 10
        anchors.top: thermometerLabel.top
        anchors.topMargin: 0
        font.pixelSize: 14
     //   fontSizeMode: Text.Fit

        text: parent.temp

    }

    Text {
        id: feelsLikeTempLabel
        y: 2
        width: 101
        height: 20
        text: qsTr("Feels like")
        font.pixelSize: 14
        anchors.topMargin: 0
        anchors.left: thermometerValueLabel.right
        anchors.leftMargin: 10
        anchors.top: thermometerLabel.top
      //  fontSizeMode: Text.Fit
    }

    Text {
        id: feelsLikeTempValueLabel
        width: 40
        height: 20
        font.pixelSize: 14
        fontSizeMode: Text.Fit
        text: parent.feelsLike
        anchors.left: feelsLikeTempLabel.right
        anchors.leftMargin: 0
        anchors.top: feelsLikeTempLabel.top
        anchors.topMargin: 0
    }

    Text {
        id: dateTimeLabel
        x: -6
        y: 0
        width: 200
        height: 20
        font.pixelSize: 14
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
      //  fontSizeMode: Text.Fit
        text: parent.dateTime
    }

    Text {
        id: descriptionLabel
        width: 101
        height: 20
        text: description
        font.pixelSize: 14
        anchors.top: dateTimeLabel.top
     //   fontSizeMode: Text.Fit
        anchors.topMargin: 0
        anchors.leftMargin: 50
        anchors.left: dateTimeLabel.right
    }

    Text {
        id: pressureValueLabel
        x: 9
        y: 9
        width: 80
        height: 20
        font.pixelSize: 14
        anchors.top: pressureLabel.top
        //  fontSizeMode: Text.Fit
        anchors.topMargin: 0
        anchors.leftMargin: 10
        anchors.left: thermometerLabel.right

        text: pressure + " hPa"
    }

    Text {
        id: pressureLabel
        x: 11
        y: 16
        width: 101
        height: 20
        text: qsTr("Pressure")
        font.pixelSize: 14
        anchors.top: thermometerLabel.bottom
        //  fontSizeMode: Text.Fit
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.left: parent.left


    }

    Text {
        id: humidityValueLabel
        x: 3
        y: 3
        width: 50
        height: 20

        font.pixelSize: 14
        anchors.top: pressureLabel.top
        //   fontSizeMode: Text.Fit
        anchors.topMargin: 0
        anchors.leftMargin: 10
        anchors.left: humidityLabel.right

        text:  humidity  + "%"
    }

    Text {
        id: humidityLabel
        x: 5
        y: 10
        width: 101
        height: 20
        text: qsTr("Humidity")
        font.pixelSize: 14
        anchors.top: pressureLabel.top
        //  fontSizeMode: Text.Fit
        anchors.topMargin: 0
        anchors.leftMargin: 10
        anchors.left: pressureValueLabel.right
    }

    Text {
        id: windSpeedValueLabel
        x: 9
        y: 9
        width: 80
        height: 20
        text: windSpeed + " mps"
        font.pixelSize: 14
        anchors.top: windSpeedLabel.top
        anchors.topMargin: 0
        anchors.leftMargin: 10
        anchors.left: windSpeedLabel.right
    }

    Text {
        id: windSpeedLabel
        x: 11
        y: 16
        width: 101
        height: 20
        text: qsTr("Wind speed")
        font.pixelSize: 14
        anchors.top: humidityLabel.bottom
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.left: parent.left
    }

    Text {
        id: windAngleValueLabel
        x: 7
        y: 7
        width: 80
        height: 20
        text: windAngle
        font.pixelSize: 14
        anchors.top: windSpeedLabel.top
        anchors.topMargin: 0
        anchors.leftMargin: 10
        anchors.left: windAngleLabel.right


    }

    Text {
        id: windAngleLabel
        x: 9
        y: 14
        width: 101
        height: 20
        text: qsTr("Wind angle")
        font.pixelSize: 14
        anchors.top: humidityLabel.bottom
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.left: windSpeedValueLabel.right
    }

    Text {
        id: rainSnowLabel
        x: -4
        y: 4
        width: 150
        height: 20
        text:  (rain > 0) ? "rain " + rain + " mm":"" + "  "   + (snow > 0)? "snow " + snow + " mm":""
        font.pixelSize: 14
        anchors.top: dateTimeLabel.top
        anchors.topMargin: 0
        anchors.leftMargin: 10
        anchors.left: descriptionLabel.right
    }


}

