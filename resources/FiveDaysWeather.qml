import QtQuick 2.12
import QtQuick.Controls 2.3



ListView {
    id: todayWeatherListView
    clip: true


    delegate: DayWeatherDelegate{
        dateTime:  dateTimeRole
        temp: tempRole
        feelsLike: feelsLikeTempRole

        pressure: pressureRole
        humidity: humidityRole

        description: descriptionRole

        cloudPercentage: cloudPercentageRole

        windSpeed: windSpeedRole
        windAngle: windAngleRole

        snow: snowRole
        rain: rainRole
    }

    model:fiveDaysWeatherModel
}


