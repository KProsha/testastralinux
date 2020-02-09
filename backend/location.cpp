#include "location.h"

#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

Location::Location(QObject *parent) : QObject(parent)
{

}
//------------------------------------------------------------------------------
bool Location::readCountryCode(const QString& fileName)
{
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

    QString code = countryCodeObject.value("Code").toString();
    QString name = countryCodeObject.value("Name").toString();

    if(!code.isEmpty()  && !name.isEmpty()){
      countryCode[name] = code;
    }
  }

  return true;
}
//------------------------------------------------------------------------------
bool Location::readCityCode(const QString& fileName)
{
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
  foreach(QJsonValue cityValue, documentArray){
    QJsonObject cityObject = cityValue.toObject();

    int id            = cityObject.value("id").toInt(-1);
    QString name      = cityObject.value("name").toString();
    QString country   = cityObject.value("country").toString();
    QJsonObject coord = cityObject.value("coord").toObject();

    double coordLon = coord.value("lon").toDouble(-1);
    double coordLat = coord.value("lat").toDouble(-1);

  }

  return true;
}

