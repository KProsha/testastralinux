#include "backend.h"

Backend::Backend(QObject *parent) : QObject(parent)
{
  countryModel  = QSharedPointer<CountryModel>(new CountryModel());
  locationModel = QSharedPointer<LocationModel>(new LocationModel());

  // ----- Options -----
  options     = QSharedPointer<Options>(new Options("config.ini"));
  userOptions =  QSharedPointer<UserOptions>(new UserOptions ("useroptions.ini"));
  // -----  -----
  network = QSharedPointer<Network>(new Network());
  // -----  -----
  connect(network.data(), &Network::sigNewLocations,
          locationModel.data(), &LocationModel::setLocations);

  // -----  -----
  countryModel->loadFromFile(QStringLiteral("country.code.json"));
}

QSharedPointer<Network> Backend::getNetwork() const
{
  return network;
}

QSharedPointer<UserOptions> Backend::getUserOptions() const
{
  return userOptions;
}

QSharedPointer<Options> Backend::getOptions() const
{
  return options;
}

QSharedPointer<LocationModel> Backend::getLocationModel() const
{
  return locationModel;
}

QSharedPointer<CountryModel> Backend::getCountryModel() const
{
  return countryModel;
}
