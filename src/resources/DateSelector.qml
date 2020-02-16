import QtQuick 2.9
import QtQuick.Controls 2.2



Row {
    spacing: 20
    ButtonGroup {
        id: dateSelectorButtonGroup
        buttons: [todayButton, threedaysButton, fivedaysButton]
    }

    Button {
        id: todayButton
        text: qsTr("Today")
        checkable: true

        onClicked: {
            weatherStackView.push(todayWeatherPage)
        }
    }

    Button {
        id: threedaysButton
        text: qsTr("Three days")
        checkable: true

        onClicked: {
            weatherStackView.push(threeDaysWeatherPage)
        }
    }

    Button {
        id: fivedaysButton
        text: qsTr("Five days")
        checkable: true

        onClicked: {
            weatherStackView.push(fiveDaysWeatherPage)
        }
    }
}

