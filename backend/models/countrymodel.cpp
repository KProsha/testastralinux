#include "countrymodel.h"

#include <QFile>
#include <QUrl>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

CountryModel::CountryModel():QAbstractListModel()
{

}
//------------------------------------------------------------------------------
int CountryModel::rowCount(const QModelIndex& index) const
{
  Q_UNUSED(index)
  return countryCode.count();
}
//------------------------------------------------------------------------------
QVariant CountryModel::data(const QModelIndex &index, int role) const
{
  switch (role) {
  case Qt::DisplayRole:{
    QString itemText;

    return countryCode.at(index.row()).name;
    }
  }

  return QVariant();
}
//------------------------------------------------------------------------------
QHash<int, QByteArray> CountryModel::roleNames() const
{
  return { {Qt::DisplayRole, "display"} };
}
//------------------------------------------------------------------------------
bool CountryModel::loadFromFile(const QString &fileName)
{
  beginResetModel();

  countryCode.clear();

  QFile jsonFile(fileName);
  if (!jsonFile.open(QIODevice::ReadOnly))
  {
    return false;
  }

  QByteArray jsonData = jsonFile.readAll();

  QJsonParseError error;
  QJsonDocument jsonDocument(QJsonDocument::fromJson(jsonData,&error));

  if(error.error != QJsonParseError::NoError) return false;

  QJsonArray documentArray = jsonDocument.array();
  foreach(QJsonValue countryCodeValue, documentArray){
    QJsonObject countryCodeObject = countryCodeValue.toObject();

    Country country;
    country.code = countryCodeObject.value("Code").toString();
    country.name = countryCodeObject.value("Name").toString();

    if(!country.code.isEmpty()  && !country.name.isEmpty()){
      countryCode.append(country);
    }
  }

  endResetModel();
  return true;
}
//------------------------------------------------------------------------------
QString CountryModel::getCountryCode(int pos)
{
  if((pos < 0) || (pos >= countryCode.size() ))return QString();

  return countryCode.at(pos).code;
}
