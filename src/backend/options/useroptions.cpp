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
QString UserOptions::getLocationName() const
{
  return locationName;
}
//------------------------------------------------------------------------------
void UserOptions::setLocationName(const QString &value)
{
  locationName = value;
}
//------------------------------------------------------------------------------
int UserOptions::getLocationId() const
{
  return locationId;
}
//------------------------------------------------------------------------------
void UserOptions::setLocationId(int value)
{
  locationId = value;
}
//------------------------------------------------------------------------------
void UserOptions::save()
{
  setValue("Location/Country", countryIndex);

  setValue("Location/LocationName", locationName);
  setValue("Location/LocationId", locationId);

}
//------------------------------------------------------------------------------
void UserOptions::load()
{
  bool ok;

  countryIndex = value("Location/Country", -1).toInt(&ok);
  if(!ok) countryIndex = -1;

  locationId = value("Location/LocationId", -1).toInt(&ok);
  if(!ok) locationId = -1;

  if(locationId == -1)  {
    locationName = tr("Unknoun location");
  }else {
    locationName = value("Location/LocationName", tr("Unknoun location")).toString();
  }
}
