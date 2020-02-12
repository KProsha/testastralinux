#include "weathermodel.h"

WeatherModel::WeatherModel(const QList<QSharedPointer<Weather> > &weatherListPtr):
  QAbstractListModel(),
  weatherList(weatherListPtr)
{

}
//------------------------------------------------------------------------------
int WeatherModel::rowCount(const QModelIndex& index) const
{
  Q_UNUSED(index)
  return weatherList.size();
}
//------------------------------------------------------------------------------
QVariant WeatherModel::data(const QModelIndex &index, int role) const
{
  auto weather = weatherList.at(index.row());

  switch (role) {
  case DateTimeRole:{
    return weather->dateTime.toString();
    }
  case TempRole:{
    return QString::number(static_cast<double>(weather->temp.getCelsius()), 'f', 1);
    }
  case FeelsLikeTempRole:{
    return QString::number(static_cast<double>(weather->feelsLikeTemp.getCelsius()), 'f', 1);
    }
  case PressureRole:{
    return weather->pressure;
    }
  case HumidityRole:{
    return weather->humidity;
    }
  case DescriptionRole:{
    return weather->description;
    }
  case CloudPercentageRole:{
    return weather->cloudPercentage;
    }
  case WindSpeedRole:{
    return QString::number(static_cast<double>(weather->windSpeed), 'f', 2);
    }
  case WindAngleRole:{
    return QString::number(static_cast<double>(weather->windAngle), 'f', 2);
    }
  case SnowRole:{
    return QString::number(static_cast<double>(weather->snow), 'f', 4);
    }
  case RainRole:{
    return QString::number(static_cast<double>(weather->rain), 'f', 4);
    }

  }

  return QVariant();
}
//------------------------------------------------------------------------------
QHash<int, QByteArray> WeatherModel::roleNames() const
{
  return {
    {DateTimeRole,"dateTimeRole"},
    {TempRole, "tempRole"},
    {FeelsLikeTempRole, "feelsLikeTempRole"},
    {PressureRole,"pressureRole"},
    {HumidityRole,"humidityRole"},
    {DescriptionRole,"descriptionRole"},
    {CloudPercentageRole,"cloudPercentageRole"},
    {WindSpeedRole,"windSpeedRole"},
    {WindAngleRole,"windAngleRole"},
    {SnowRole,"snowRole"},
    {RainRole,"rainRole"},

  };
}
//------------------------------------------------------------------------------
void WeatherModel::updateData()
{
  beginResetModel();


  endResetModel();

}
