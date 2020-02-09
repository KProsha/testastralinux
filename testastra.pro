QT += quick
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    options/options.h \
    backend/location.h

SOURCES += \
    main.cpp \
    options/options.cpp \
    backend/location.cpp

RESOURCES += $$PWD/resources/qml.qrc


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


