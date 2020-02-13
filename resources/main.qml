import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2



Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Weather")


    Gradient {
        id: mainGradient
       // orientation: Gradient.Horizontal

        GradientStop { position: 0.0; color: "#AAEEFF" }
        GradientStop { position: 1.0; color: "#66AAFF" }
    }


    Rectangle{
        id: mainRect

        anchors.fill: parent

        gradient: mainGradient


        BusyIndicator {
            id: busyIndicator
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            running: network.busy

        }


        Location{
            id: location
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.topMargin: 10
            focusPolicy: Qt.NoFocus
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.left: parent.left

        }

        DateSelector{
            id: dateSelector
            height: 40
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: location.bottom
        }

        StackView {
            id: weatherStackView
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10

            anchors.top: dateSelector.bottom
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            initialItem: todayWeatherPage

            Component{
                id:todayWeatherPage

                TodayWeather{
                    id:todayWeather
                }
            }

            Component{
                id:threeDaysWeatherPage
                ThreeDaysWeather{
                    id:threeDaysWeather
                }
            }

            Component{
                id:fiveDaysWeatherPage
                FiveDaysWeather{
                    id:fiveDaysWeather
                }
            }

            Component{
                id:locationPage
                LocationDialog{
                    id:locationDialog
                }
            }

        }

        RoundButton {
            id: updateButton
            x: 555
            width: 100
            height: 40
            text: "Update"
            anchors.top: location.bottom
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10

            onClicked: {
                location.getWeather();
            }
        }

    }
}

