#ifndef NETWORK_H
#define NETWORK_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include "types/location.h"

class Network : public QNetworkAccessManager
{
  Q_OBJECT
public:
  Network();

  Q_INVOKABLE void openweathermapQuery(const QString& text);


signals:
  Q_INVOKABLE void sigNewLocations(QList<QSharedPointer<Location> >  );


private slots:

    void parce(QNetworkReply* reply);




};

#endif // NETWORK_H
