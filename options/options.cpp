#include "options.h"

Options::Options(const QString& fileName, QObject *parent):
  QSettings(fileName,QSettings::IniFormat, parent)
{

  load();
}
//------------------------------------------------------------------------------
Options::~Options()
{

}
//------------------------------------------------------------------------------
void Options::save()
{
  setValue("openweathermap.org/AppId",appId);
}
//------------------------------------------------------------------------------
void Options::load()
{
  appId = value("openweathermap.org/AppId").toString();

  emit sigAppIdChanged();

}
