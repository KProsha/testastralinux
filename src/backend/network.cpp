#include "network.h"

#include <QUrl>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

#include "options/options.h"

Network::Network():QNetworkAccessManager()
{
  setState(StateNotBusy);

  connect(this, &Network::finished, this, &Network::parce);
}
//------------------------------------------------------------------------------
void Network::openweathermapQuery(const QString &text)
{
  QUrl url("http://api.openweathermap.org/data/2.5/" +
           text +
           "&APPID=" +
           Options::i().getAppId()
           );

  get(QNetworkRequest(url));

}
//------------------------------------------------------------------------------
void Network::parceLocation(QNetworkReply *reply)
{
  QJsonParseError error;
  QJsonDocument jsonDocument(QJsonDocument::fromJson(reply->readAll(),&error));

  if(error.error != QJsonParseError::NoError) {
    return ;
  }

  QList<QSharedPointer<Location> > locationList;

  QJsonObject message = jsonDocument.object();
  QJsonArray locationsList = message.value("list").toArray();
  foreach(QJsonValue locationValue, locationsList){

    QJsonObject locationObject = locationValue.toObject();

    auto locationPtr = QSharedPointer<Location>(new Location());

    locationPtr->id      = locationObject.value("id").toInt(-1);
    locationPtr->name    = locationObject.value("name").toString();
    locationPtr->country = locationObject.value("country").toString();


    if((locationPtr->id != -1)    && !locationPtr->name.isEmpty()){
      locationList.append(locationPtr);
    }
  }

  emit sigNewLocations(locationList);
}
//------------------------------------------------------------------------------
void Network::parceWeather(QNetworkReply *reply)
{
  QJsonParseError error;
  QJsonDocument jsonDocument(QJsonDocument::fromJson(reply->readAll(),&error));

  if(error.error != QJsonParseError::NoError) {
    return ;
  }

//{"dt":1581433200,
//"main":{"temp":273.88,"feels_like":267.31,"temp_min":273.88,
//"temp_max":274.4,"pressure":994,"sea_level":994,"grnd_level":970,"humidity":97,
//"temp_kf":-0.52},

//"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13n"}],

//"clouds":{"all":100},

//"wind":{"speed":6.61,"deg":219},"snow":{"3h":0.69},"sys":{"pod":"n"},"dt_txt":"2020-02-11 15:00:00"}

  QList<QSharedPointer<Weather> > weatherList;

  QJsonObject message = jsonDocument.object();
  QJsonArray daysList = message.value("list").toArray();
  foreach(QJsonValue dayValue, daysList){
    auto weatherPtr = QSharedPointer<Weather>(new Weather());

    //-----  -----
    QJsonObject dayObject = dayValue.toObject();
    weatherPtr->dateTime = QDateTime::fromSecsSinceEpoch(dayObject.value("dt").toInt(0));

    //-----  -----
    QJsonObject mainObject = dayObject.value("main").toObject();
    weatherPtr->temp.setKelvin         (static_cast<float>(mainObject.value("temp").toDouble(0)));
    weatherPtr->feelsLikeTemp.setKelvin(static_cast<float>(mainObject.value("feels_like").toDouble(0)));
    weatherPtr->tempMin.setKelvin      (static_cast<float>(mainObject.value("temp_min").toDouble(0)));
    weatherPtr->tempMax.setKelvin      (static_cast<float>(mainObject.value("temp_max").toDouble(0)));

    weatherPtr->pressure = static_cast<quint16>(mainObject.value("grnd_level").toInt(0));
    weatherPtr->humidity = static_cast<quint8>(mainObject.value("humidity").toInt(0));

    //-----  -----
    QJsonArray descriptionArray = dayObject.value("weather").toArray();
    QJsonObject descriptionObject = descriptionArray.first().toObject();
    weatherPtr->description = descriptionObject.value("description").toString();

    //-----  -----
    QJsonObject cloudsObject = dayObject.value("clouds").toObject();
    weatherPtr->cloudPercentage = static_cast<quint8>(cloudsObject.value("all").toInt(0));

    //-----  -----
    QJsonObject windObject = dayObject.value("wind").toObject();
    weatherPtr->windSpeed = static_cast<float>(windObject.value("speed").toDouble(0));
    weatherPtr->windAngle = static_cast<float>(windObject.value("deg").toDouble(0));

    //-----  -----
    QJsonObject snowObject = dayObject.value("snow").toObject();
    if(!snowObject.isEmpty()){
      weatherPtr->snow = static_cast<float>(snowObject.value("3h").toDouble(0));     
    }

    //-----  -----
    QJsonObject rainObject = dayObject.value("rain").toObject();
    if(!rainObject.isEmpty()){
      weatherPtr->rain = static_cast<float>(rainObject.value("3h").toDouble(0));      
    }
    //-----  -----
    weatherList.append(weatherPtr);
  }

  emit sigNewWeather(weatherList);
}
//------------------------------------------------------------------------------
void Network::locationQuery(const QString &text)
{
  if(state != StateNotBusy) return;

  setState(StateLocationQuery);

  openweathermapQuery(text);
}
//------------------------------------------------------------------------------
void Network::weatherQuery(const QString &text)
{
  if(state != StateNotBusy) return;

  setState(StateWeatherQuery);

  openweathermapQuery(text);
}
//------------------------------------------------------------------------------
bool Network::isBusy()
{
  if(state != StateNotBusy) return true;

  return false;
}
//------------------------------------------------------------------------------
void Network::parce(QNetworkReply* reply)
{
  switch (state) {
  case StateLocationQuery: parceLocation(reply); break;
  case StateWeatherQuery:  parceWeather(reply);  break;
  default: break;
  }

  setState(StateNotBusy);
}
//------------------------------------------------------------------------------
void Network::setState(Network::EState newState)
{
  state = newState;
  emit sigBusyChanged();
}
