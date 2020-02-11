#include "locationmodel.h"

#include <QFile>
#include <QUrl>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

LocationModel::LocationModel():QAbstractListModel()
{
  currentLocation = QSharedPointer<Location>(nullptr);
}
//------------------------------------------------------------------------------
int LocationModel::rowCount(const QModelIndex& index) const
{
  Q_UNUSED(index)
  return locations.count();
}
//------------------------------------------------------------------------------
QVariant LocationModel::data(const QModelIndex &index, int role) const
{
  switch (role) {
  case Qt::DisplayRole:{
    QString itemText;

    return locations.at(index.row())->name;
    }
  case Qt::UserRole:{

    return index.row();
    }


  }

  return QVariant();
}
//------------------------------------------------------------------------------
QHash<int, QByteArray> LocationModel::roleNames() const
{
  return { {Qt::DisplayRole, "display"}, {Qt::UserRole, "locationNumber"}  };
}
//------------------------------------------------------------------------------
void LocationModel::setLocations(QList<QSharedPointer<Location> > list)
{
  beginResetModel();

  locations.clear();

  locations = list;

  endResetModel();
}
//------------------------------------------------------------------------------
void LocationModel::createCurrentLocation(int id, const
                                          QString &name,
                                          const QString &country)
{
  if(id < 0 ){
      currentLocation = QSharedPointer<Location>(nullptr);
      return;
  }

  currentLocation = QSharedPointer<Location>(new Location());

  currentLocation->id = id;
  currentLocation->name = name;
  currentLocation->country = country;

}
//------------------------------------------------------------------------------
void LocationModel::setCurrentLocationByIndex(int value)
{
  if((value < 0) || (value >= locations.size())){
      currentLocation = QSharedPointer<Location>(nullptr);
      return;
  }

  currentLocation = locations.at(value);
}
//------------------------------------------------------------------------------
QSharedPointer<Location> LocationModel::getCurrentLocation()
{
  return currentLocation;
}
//------------------------------------------------------------------------------
int LocationModel::getCurrentLocationId()
{
  auto location =  getCurrentLocation();
  if(location.isNull()) return -1;

  return location->id;
}
//------------------------------------------------------------------------------
QString LocationModel::getCurrentLocationName()
{
  auto location =  getCurrentLocation();
  if(location.isNull()) return "Unknoun location";

  return location->name;
}
