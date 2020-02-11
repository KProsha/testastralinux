#include "weathermodel.h"

WeatherModel::WeatherModel(QObject *parent) : QObject(parent)
{

}
//------------------------------------------------------------------------------
void WeatherModel::setWeather(QList<QSharedPointer<Weather> > list)
{
  weather.clear();

  weather = list;

}
//------------------------------------------------------------------------------
