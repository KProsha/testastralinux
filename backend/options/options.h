#ifndef OPTIONS_H
#define OPTIONS_H

#include <QSettings>

class Options: public QSettings
{
  Q_OBJECT

  Q_PROPERTY(QString appId READ getAppId NOTIFY sigAppIdChanged)

public:
  Options(const QString& fileName, QObject *parent = nullptr);
  ~Options();

  void load();
  void save();

  const QString& getAppId()const{return appId;}

  static Options& i(){return *instance;}

signals:
  void sigAppIdChanged();

protected:
  QString appId;

  static Options* instance;

};

#endif // OPTIONS_H
