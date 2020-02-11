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
  currentIndex = -1;
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

void LocationModel::setLocations(QList<QSharedPointer<Location> > list)
{
  beginResetModel();

  locations.clear();

  locations = list;

  endResetModel();
}
//------------------------------------------------------------------------------
int LocationModel::getCurrentIndex() const
{
  return currentIndex;
}
//------------------------------------------------------------------------------
void LocationModel::setCurrentIndex(int value)
{
  currentIndex = value;
}
//------------------------------------------------------------------------------
QSharedPointer<Location> LocationModel::getCurrentLocation()
{
  if((currentIndex < 0) || (currentIndex >= locations.size()))
      return QSharedPointer<Location>(nullptr);

  return locations.at(currentIndex);
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
