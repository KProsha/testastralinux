#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>
#include <QString>
#include <QHash>
#include <QList>
#include <QSharedPointer>


class City{
public:
  int id;
  QString name;
  QString country;
};


class Location : public QObject
{
  Q_OBJECT

//  Q_PROPERTY(QString country READ getCountry NOTIFY sigCountryChanged)

public:
  explicit Location(QObject *parent = nullptr);

  bool readCountryCode(const QString& fileName);
  bool readCityCode(const QString& countryCode, const QString& namePart);

  void setCityCodeFilename(const QString& fileName){cityCodeFileName = fileName;}



signals:

public slots:

protected:
  QString cityCodeFileName;

  QHash<QString, QString> countryCode;
  QList<QSharedPointer<City> > selectedCities;








};

#endif // LOCATION_H
