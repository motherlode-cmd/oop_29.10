QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cell.cpp \
    cellview.cpp \
    consolelogger.cpp \
    controller.cpp \
    dialog.cpp \
    eventadd.cpp \
    eventkey.cpp \
    eventlock.cpp \
    eventnone.cpp \
    eventunlock.cpp \
    eventwin.cpp \
    field.cpp \
    fieldview.cpp \
    filelogger.cpp \
    generatelevel.cpp \
    main.cpp \
    commandreader.cpp \
    player.cpp \
    position.cpp \
    tmplogger.cpp

HEADERS += \
    cell.h \
    cellview.h \
    commandreader.h \
    consolelogger.h \
    controller.h \
    dialog.h \
    event.h \
    eventField.h \
    eventPlayer.h \
    eventadd.h \
    eventkey.h \
    eventlock.h \
    eventnone.h \
    eventunlock.h \
    eventwin.h \
    field.h \
    fieldview.h \
    filelogger.h \
    generatelevel.h \
    logger.h \
    player.h \
    position.h \
    tmplogger.h

FORMS += \
    commandreader.ui \
    dialog.ui

TRANSLATIONS += \
    Mediator_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
