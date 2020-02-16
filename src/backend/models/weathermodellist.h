#ifndef WEATHERMODELLIST_H
#define WEATHERMODELLIST_H

#include <QObject>
#include <QSharedPointer>

#include "../types/weather.h"
#include "weathermodel.h"


class WeatherModelList : public QObject
{
  Q_OBJECT
public:
  explicit WeatherModelList(QObject *parent = nullptr);

  QSharedPointer<WeatherModel> getOneDayWeatherModel() const;

  QSharedPointer<WeatherModel> getThreeDaysWeatherModel() const;

  QSharedPointer<WeatherModel> getFiveDaysWeatherModel() const;

signals:

public slots:
  void setWeather(QList<QSharedPointer<Weather> > list);

protected:
  QList<QSharedPointer<Weather> > weatherList;

  QSharedPointer<WeatherModel> oneDayWeatherModel;
  QList<QSharedPointer<Weather> > oneDayWeatherList;

  QSharedPointer<WeatherModel>    threeDaysWeatherModel;
  QList<QSharedPointer<Weather> > threeDaysWeatherList;

  QSharedPointer<WeatherModel>    fiveDaysWeatherModel;
  QList<QSharedPointer<Weather> > fiveDaysWeatherList;

};

#endif // WEATHERMODEL_H
