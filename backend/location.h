#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>
#include <QString>
#include <QHash>


class Location : public QObject
{
  Q_OBJECT

//  Q_PROPERTY(QString country READ getCountry NOTIFY sigCountryChanged)

public:
  explicit Location(QObject *parent = nullptr);

  bool readCountryCode(const QString& fileName);
  bool readCityCode(const QString& fileName);

  void setCityCodeFilename(const QString& fileName){cityCodeFileName = fileName;}



signals:

public slots:

protected:

  QHash<QString, QString> countryCode;

  QString cityCodeFileName;




};

#endif // LOCATION_H
