#ifndef WEATHERMODEL_H
#define WEATHERMODEL_H

#include <QObject>
#include "../types/weather.h"

class WeatherModel : public QObject
{
  Q_OBJECT
public:
  explicit WeatherModel(QObject *parent = nullptr);

signals:

public slots:
  void setWeather(QList<QSharedPointer<Weather> > list);

protected:
  QList<QSharedPointer<Weather> > weather;

};

#endif // WEATHERMODEL_H
