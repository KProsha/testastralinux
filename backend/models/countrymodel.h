#ifndef COUNTRYMODEL_H
#define COUNTRYMODEL_H

#include <QAbstractListModel>
#include <QList>

class CountryModel: public QAbstractListModel
{
  Q_OBJECT

public:
  CountryModel();

  int rowCount(const QModelIndex& index = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role) const override;
  QHash<int, QByteArray> roleNames() const override;

  bool loadFromFile(const QString& fileName);

  Q_INVOKABLE QString getCountryCode(int pos);

protected:

  class Country{
  public:
    QString code;
    QString name;
  };


  QList<Country> countryCode;

};

#endif
