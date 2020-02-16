import QtQuick 2.9
import QtQuick.Controls 2.2



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

        userOptions.setLocationName(locationModel.getCurrentLocationName());
        userOptions.setLocationId(locationModel.getCurrentLocationId());

        getWeather();
    }

    function getWeather(){
        if(locationModel.getCurrentLocationId() === -1) return;
        var queryOptions = "forecast?id=" + locationModel.getCurrentLocationId();
        network.weatherQuery(queryOptions);
    }

    Component.onCompleted: {

        locationText.text = userOptions.getLocationName();

        locationModel.createCurrentLocation(userOptions.getLocationId(),
                                            userOptions.getLocationName(),
                                            userOptions.getCountryIndex()
                                            ) ;

        getWeather();
    }

    onClicked: {
        locationDialog:visible = true
        weatherStackView.push(locationPage)
    }
}







