#ifndef WEATHER_H
#define WEATHER_H

#include <QDateTime>
#include <QObject>

class Weather: public QObject
{
 Q_OBJECT

public:
  //-----   -----
  class Temperature
  {
  public:
    void  setKelvin(float kelvinValue){kelvin = kelvinValue;}
    float getKelvin()  const {return kelvin;}
    float getCelsius() const {return kelvin - static_cast<float>(273.15); }

  protected:
    float kelvin;
  };

  Temperature temp;
  Temperature feelsLikeTemp;
  Temperature tempMin;
  Temperature tempMax;

  quint16 pressure;
  quint8  humidity;

  QString description;

  quint8 cloudPercentage;

  float windSpeed;
  float windAngle;

  float snow;
  float rain;

  QDateTime dateTime;

};

//{"dt":1581433200,
//"main":{"temp":273.88,"feels_like":267.31,"temp_min":273.88,
//"temp_max":274.4,"pressure":994,"sea_level":994,"grnd_level":970,"humidity":97,
//"temp_kf":-0.52},

//"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13n"}],

//"clouds":{"all":100},

//"wind":{"speed":6.61,"deg":219},"snow":{"3h":0.69},"sys":{"pod":"n"},"dt_txt":"2020-02-11 15:00:00"}


#endif // WEATHER_H
