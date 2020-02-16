#ifndef LOCATIONMODEL_H
#define LOCATIONMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QSharedPointer>

#include "../types/location.h"

class LocationModel: public QAbstractListModel
{
  Q_OBJECT

public:
  LocationModel();

  int rowCount(const QModelIndex& index = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role) const override;
  QHash<int, QByteArray> roleNames() const override;



  Q_INVOKABLE void createCurrentLocation(int id, const QString& name, const QString& country);

  Q_INVOKABLE void setCurrentLocationByIndex(int value);

  Q_INVOKABLE QSharedPointer<Location> getCurrentLocation();
  Q_INVOKABLE int getCurrentLocationId();
  Q_INVOKABLE QString getCurrentLocationName();

public slots:
  void setLocations(QList<QSharedPointer<Location> > list);

protected:

  QList<QSharedPointer<Location> > locations;

  QSharedPointer<Location> currentLocation;





};

#endif
