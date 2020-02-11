#include "useroptions.h"

#include "options.h"

UserOptions::UserOptions(const QString& fileName, QObject *parent):
  QSettings(fileName,QSettings::IniFormat, parent)
{  
  load();
}
//------------------------------------------------------------------------------
UserOptions::~UserOptions()
{
  save();
}
//------------------------------------------------------------------------------
int UserOptions::getCountryIndex() const
{
  return countryIndex;
}
//------------------------------------------------------------------------------
void UserOptions::setCountryIndex(int value)
{
  countryIndex = value;
}
//------------------------------------------------------------------------------
void UserOptions::save()
{
  setValue("Location/Country", countryIndex);
}
//------------------------------------------------------------------------------
void UserOptions::load()
{
  bool ok;

  countryIndex = value("Location/Country", -1).toInt(&ok);
  if(!ok) countryIndex = -1;

}
