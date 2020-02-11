#include "network.h"

#include <QUrl>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

#include "options/options.h"

Network::Network():QNetworkAccessManager()
{
  connect(this, &Network::finished, this, &Network::parce);
}
//------------------------------------------------------------------------------
void Network::openweathermapQuery(const QString &text)
{
  QUrl url("http://api.openweathermap.org/data/2.5/" +
           text +
           "&APPID=" +
           Options::i().getAppId()
           );

  get(QNetworkRequest(url));

}
//------------------------------------------------------------------------------
void Network::parce(QNetworkReply* reply)
{

   QJsonParseError error;
   QJsonDocument jsonDocument(QJsonDocument::fromJson(reply->readAll(),&error));

   if(error.error != QJsonParseError::NoError) return ;

   QList<QSharedPointer<Location> > locationList;

   QJsonObject message = jsonDocument.object();
   QJsonArray locationsList = message.value("list").toArray();
   foreach(QJsonValue locationValue, locationsList){

     QJsonObject locationObject = locationValue.toObject();

     auto locationPtr = QSharedPointer<Location>(new Location());

     locationPtr->id      = locationObject.value("id").toInt(-1);
     locationPtr->name    = locationObject.value("name").toString();
     locationPtr->country = locationObject.value("country").toString();


     if((locationPtr->id != -1)    && !locationPtr->name.isEmpty()){
       locationList.append(locationPtr);
     }
   }

   emit sigNewLocations(locationList);
}
