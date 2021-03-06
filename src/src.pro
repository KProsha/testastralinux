QT += quick network
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS


TARGET = testastra

HEADERS += \
    backend/options/options.h \
    backend/models/locationmodel.h \
    backend/models/countrymodel.h \
    backend/options/useroptions.h \
    backend/network.h \
    backend/types/location.h \
    backend/backend.h \
    backend/types/weather.h \
    backend/models/weathermodellist.h \
    backend/models/weathermodel.h


SOURCES += \
    main.cpp \
    backend/options/options.cpp \
    backend/models/locationmodel.cpp \
    backend/models/countrymodel.cpp \
    backend/options/useroptions.cpp \
    backend/network.cpp \
    backend/backend.cpp \
    backend/models/weathermodellist.cpp \
    backend/models/weathermodel.cpp


RESOURCES += $$PWD/resources/qml.qrc

DESTDIR = ../bin
MOC_DIR = ../build/moc
RCC_DIR = ../build/rcc
UI_DIR = ../build/ui
unix:OBJECTS_DIR = ../build/o/unix
win32:OBJECTS_DIR = ../build/o/win32
macx:OBJECTS_DIR = ../build/o/mac


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


