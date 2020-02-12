#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QPalette>

#include "backend/backend.h"



int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  Backend backend;

//  QPalette palette = app.palette();
//  palette.setColor(QPalette::Base,QColor("blue"));

//  app.setPalette(palette);


  qmlRegisterUncreatableType<Options>("Options", 1, 0, "Options","Error:Options was created in QML");
  qmlRegisterUncreatableType<UserOptions>("UserOptions", 1, 0, "UserOptions","Error:UserOptions was created in QML");
  qmlRegisterUncreatableType<CountryModel>("CountryModel", 1, 0, "CountryModel","Error:CountryModel was created in QML");
  qmlRegisterUncreatableType<LocationModel>("LocationModel", 1, 0, "LocationModel","Error:LocationModel was created in QML");
  qmlRegisterUncreatableType<Network>("Network", 1, 0, "Network","Error:Network was created in QML");

  qmlRegisterUncreatableType<WeatherModel>("OneDayWeatherModel", 1, 0, "OneDayWeatherModel","Error:OneDayWeatherModel was created in QML");


  QQmlApplicationEngine engine;

  engine.rootContext()->setContextProperty("options", backend.getOptions().data());
  engine.rootContext()->setContextProperty("userOptions", backend.getUserOptions().data());
  engine.rootContext()->setContextProperty("countryModel", backend.getCountryModel().data());
  engine.rootContext()->setContextProperty("locationModel", backend.getLocationModel().data());
  engine.rootContext()->setContextProperty("network", backend.getNetwork().data());

  engine.rootContext()->setContextProperty("oneDayWeatherModel",
                                           backend.getWeatherModel()->getOneDayWeatherModel().data());

  engine.rootContext()->setContextProperty("threeDaysWeatherModel",
                                           backend.getWeatherModel()->getThreeDaysWeatherModel().data());
  engine.rootContext()->setContextProperty("fiveDaysWeatherModel",
                                           backend.getWeatherModel()->getFiveDaysWeatherModel().data());


  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
