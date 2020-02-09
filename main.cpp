#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "options/options.h"
#include "backend/location.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  // ----- Location -----
  Location location;

  if(!location.readCountryCode(QStringLiteral("country.code.json"))){
    qCritical("Country code read error");
  }

  location.setCityCodeFilename("city.list.json");
  location.readCityCode("RU", "Kal");

  // ----- Options -----
  Options options("config.ini");

  // -----  -----

  qmlRegisterUncreatableType<Options>("Options", 1, 0, "Options","Error:Options was created in QML");

  QQmlApplicationEngine engine;

  engine.rootContext()->setContextProperty("options",&options);

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
