#ifndef WEATHERMODEL_H
#define WEATHERMODEL_H

#include <QAbstractListModel>
#include <QSharedPointer>

#include "../types/weather.h"

#define DateTimeRole          Qt::UserRole

#define TempRole              Qt::UserRole + 1
#define FeelsLikeTempRole     Qt::UserRole + 2

#define PressureRole          Qt::UserRole + 3
#define HumidityRole          Qt::UserRole + 4

#define DescriptionRole       Qt::UserRole + 5

#define CloudPercentageRole   Qt::UserRole + 6

#define WindSpeedRole         Qt::UserRole + 7
#define WindAngleRole         Qt::UserRole + 8

#define SnowRole              Qt::UserRole + 9
#define RainRole              Qt::UserRole + 10

class WeatherModel:public QAbstractListModel
{
   Q_OBJECT
public:
  WeatherModel(  const QList<QSharedPointer<Weather> >& weatherListPtr);

  int rowCount(const QModelIndex& index = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role) const override;
  QHash<int, QByteArray> roleNames() const override;


  void updateData();

protected:

  const QList<QSharedPointer<Weather> >& weatherList;



};

#endif // WEATHERMODEL_H
