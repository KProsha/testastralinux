#ifndef USEROPTIONS_H
#define USEROPTIONS_H


#include <QSettings>

class UserOptions: public QSettings
{
  Q_OBJECT
public:
  UserOptions(const QString& fileName, QObject *parent = nullptr);
  ~UserOptions();

  void save();
  void load();

  Q_INVOKABLE int getCountryIndex() const;
  Q_INVOKABLE void setCountryIndex(int value);

  Q_INVOKABLE QString getLocationName() const;
  Q_INVOKABLE void setLocationName(const QString &value);

  Q_INVOKABLE int getLocationId() const;
  Q_INVOKABLE void setLocationId(int value);

protected:

  int countryIndex;

  QString locationName;
  int locationId;

};

#endif // USEROPTIONS_H
