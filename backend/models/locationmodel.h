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

  void setLocations(QList<QSharedPointer<Location> > list);

  Q_INVOKABLE int getCurrentIndex() const;
  Q_INVOKABLE void setCurrentIndex(int value);

  Q_INVOKABLE QSharedPointer<Location> getCurrentLocation();
  Q_INVOKABLE int getCurrentLocationId();
  Q_INVOKABLE QString getCurrentLocationName();

protected:

  QList<QSharedPointer<Location> > locations;

  int currentIndex;





};

#endif
