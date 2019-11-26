QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        ../src/main/ygitlab.cpp \
        ../src/main/yissue.cpp \
        ../src/main/yrequest.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../src/main/ygitlab.h \
    ../src/main/yissue.h \
    ../src/main/yrequest.h

RESOURCES += \
    ../res/test.qrc
