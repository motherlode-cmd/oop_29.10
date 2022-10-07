QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cell.cpp \
    cellview.cpp \
    controller.cpp \
    eventadd.cpp \
    eventlock.cpp \
    eventnone.cpp \
    eventunlock.cpp \
    eventwin.cpp \
    field.cpp \
    fieldview.cpp \
    main.cpp \
    commandreader.cpp \
    player.cpp \
    position.cpp

HEADERS += \
    cell.h \
    cellview.h \
    commandreader.h \
    controller.h \
    event.h \
    eventField.h \
    eventPlayer.h \
    eventadd.h \
    eventlock.h \
    eventnone.h \
    eventunlock.h \
    eventwin.h \
    field.h \
    fieldview.h \
    player.h \
    position.h

FORMS += \
    commandreader.ui

TRANSLATIONS += \
    Mediator_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
