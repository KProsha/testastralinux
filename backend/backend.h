#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

#include "backend/options/options.h"
#include "backend/options/useroptions.h"
#include "backend/models/locationmodel.h"
#include "backend/models/countrymodel.h"
#include "backend/models/weathermodel.h"
#include "backend/network.h"

class Backend : public QObject
{
  Q_OBJECT
public:
  explicit Backend(QObject *parent = nullptr);

  QSharedPointer<CountryModel> getCountryModel() const;
  QSharedPointer<LocationModel> getLocationModel() const;

  QSharedPointer<Options> getOptions() const;
  QSharedPointer<UserOptions> getUserOptions() const;

  QSharedPointer<Network> getNetwork() const;
protected:
  // ----- Location -----
  QSharedPointer<CountryModel> countryModel;
  QSharedPointer<LocationModel> locationModel;
  // ----- Options -----
  QSharedPointer<Options> options;
  QSharedPointer<UserOptions> userOptions;
  // -----  -----
  QSharedPointer<Network> network;
  // -----  -----
  QSharedPointer<WeatherModel> weatherModel;
};






#endif // BACKEND_H
