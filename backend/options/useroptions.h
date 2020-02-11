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

protected:

  int countryIndex;

};

#endif // USEROPTIONS_H
