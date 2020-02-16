#include "weathermodellist.h"

WeatherModelList::WeatherModelList(QObject *parent) : QObject(parent)
{
  oneDayWeatherModel    = QSharedPointer<WeatherModel>(new WeatherModel(oneDayWeatherList));
  threeDaysWeatherModel = QSharedPointer<WeatherModel>(new WeatherModel(threeDaysWeatherList));
  fiveDaysWeatherModel  = QSharedPointer<WeatherModel>(new WeatherModel(fiveDaysWeatherList));


}
//------------------------------------------------------------------------------
void WeatherModelList::setWeather(QList<QSharedPointer<Weather> > list)
{
  weatherList.clear();
  oneDayWeatherList.clear();

  weatherList = list;

  foreach(auto weather, weatherList){
    QDate weatherDate = weather->dateTime.date();

    QDate threeDays = QDate::currentDate().addDays(2);
    QDate fiveDays  = QDate::currentDate().addDays(4);

    if(weatherDate == QDate::currentDate()){
      oneDayWeatherList.append(weather);
    }

    if(weatherDate <= threeDays){
      threeDaysWeatherList.append(weather);
    }

    if(weatherDate <= fiveDays){
      fiveDaysWeatherList.append(weather);
    }
  }

  oneDayWeatherModel->updateData();
  threeDaysWeatherModel->updateData();
  fiveDaysWeatherModel->updateData();
}
//------------------------------------------------------------------------------
QSharedPointer<WeatherModel> WeatherModelList::getFiveDaysWeatherModel() const
{
  return fiveDaysWeatherModel;
}
//------------------------------------------------------------------------------
QSharedPointer<WeatherModel> WeatherModelList::getThreeDaysWeatherModel() const
{
  return threeDaysWeatherModel;
}
//------------------------------------------------------------------------------
QSharedPointer<WeatherModel> WeatherModelList::getOneDayWeatherModel() const
{
    return oneDayWeatherModel;
}
//------------------------------------------------------------------------------
