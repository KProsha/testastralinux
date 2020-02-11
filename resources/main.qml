import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3


Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Weather")

    color: "#99CCFF"

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
            id:weekWeatherPage
            WeekWeather{
                id:weekWeather
            }
        }

        Component{
            id:tenDaysWeatherPage
            TenDaysWeather{
                id:tenDaysWeather
            }
        }

        Component{
            id:locationPage
            LocationDialog{
                id:locationDialog
            }
        }
    }
}
