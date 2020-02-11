QT += quick network
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    backend/options/options.h \
    backend/models/locationmodel.h \
    backend/models/countrymodel.h \
    backend/options/useroptions.h \
    backend/network.h \
    backend/types/location.h \
    backend/backend.h \
    backend/models/weathermodel.h \
    backend/types/weather.h


SOURCES += \
    main.cpp \
    backend/options/options.cpp \
    backend/models/locationmodel.cpp \
    backend/models/countrymodel.cpp \
    backend/options/useroptions.cpp \
    backend/network.cpp \
    backend/backend.cpp \
    backend/models/weathermodel.cpp


RESOURCES += $$PWD/resources/qml.qrc


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


