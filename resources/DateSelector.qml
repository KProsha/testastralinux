import QtQuick 2.12
import QtQuick.Controls 2.3



Row {
    spacing: 20
    ButtonGroup {
        id: dateSelectorButtonGroup
        buttons: [todayButton, threedaysButton, tendaysButton, weekButton]


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
        id: weekButton
        text: qsTr("Week")
        checkable: true

        onClicked: {
            weatherStackView.push(weekWeatherPage)
        }
    }

    Button {
        id: tendaysButton
        text: qsTr("Ten days")
        checkable: true

        onClicked: {
            weatherStackView.push(tenDaysWeatherPage)
        }
    }
}

