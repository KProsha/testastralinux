#include "location.h"

#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QTextStream>

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
bool Location::readCityCode(const QString& countryCode, const QString &namePart)
{
  selectedCities.clear();

  QFile jsonFile(cityCodeFileName);
  if (!jsonFile.open(QIODevice::ReadOnly))
  {
    return false;
  }

  QTextStream fileStream(&jsonFile);

  QString Line = jsonFile.readLine();

  // ----- Read all file -----
  while(fileStream.readLineInto(&Line)){


    // ----- Read json object for city  -----
    if(Line.trimmed() == "{") {
      QByteArray  cityObjectString("{");
      int braceCount = 2;

      while(fileStream.readLineInto(&Line)){
        QString trimmedLine = Line.trimmed();
        if(trimmedLine.isEmpty()) continue;

        if (trimmedLine.at(0) == "}" )
          --braceCount;

        if(braceCount == 0) break;

        cityObjectString.append(trimmedLine);
      }
      cityObjectString.append("}");

      QJsonParseError error;
      QJsonDocument jsonDocument(QJsonDocument::fromJson(cityObjectString,&error));

      if(error.error != QJsonParseError::NoError) continue;

      QJsonObject cityObject = jsonDocument.object();

      auto city = QSharedPointer<City>(new City);

      city->id      = cityObject.value("id").toInt(-1);
      city->name    = cityObject.value("name").toString();
      city->country = cityObject.value("country").toString();

      if(city->country != countryCode) continue;
      if(!city->name.startsWith(namePart)) continue;

      selectedCities.append(city);

    }
  }

  return true;
}

