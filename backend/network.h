#ifndef NETWORK_H
#define NETWORK_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include "types/location.h"
#include "types/weather.h"

class Network : public QNetworkAccessManager
{
  Q_OBJECT
public:
  Network();

  Q_INVOKABLE void locationQuery(const QString& text);
  Q_INVOKABLE void weatherQuery(const QString& text);

signals:
  void sigNewLocations(QList<QSharedPointer<Location> >  );
  void sigNewWeather(QList<QSharedPointer<Weather> >  );

private slots:

  void parce(QNetworkReply* reply);

protected:

  enum EState{
    StateNotBusy,
    StateLocationQuery,
    StateWeatherQuery
  };

  EState state;

  void openweathermapQuery(const QString& text);

  void parceLocation(QNetworkReply* reply);
  void parceWeather(QNetworkReply* reply);


};

#endif // NETWORK_H
