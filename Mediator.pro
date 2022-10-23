QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Events/EventPlayer/eventkey.cpp \
    Events/EventField/eventlock.cpp \
    Events/EventField/eventunlock.cpp \
    Events/EventField/eventwin.cpp \
    Events/EventPlayer/eventadd.cpp \
    Events/EventPlayer/eventnone.cpp \
    GameLogic/cell.cpp \
    GameLogic/controller.cpp \
    GameLogic/field.cpp \
    GameLogic/generatelevel.cpp \
    GameLogic/player.cpp \
    GameLogic/position.cpp \
    Logger/consolelogger.cpp \
    Logger/filelogger.cpp \
    Observable/gamesubject.cpp \
    Observer/loggerobserver.cpp \
    Views/cellview.cpp \
    Views/fieldview.cpp \
    dialog.cpp \
    main.cpp \
    commandreader.cpp

HEADERS += \
    Events/EventField/eventField.h \
    Events/EventPlayer/eventkey.h \
    Events/EventField/eventlock.h \
    Events/EventField/eventunlock.h \
    Events/EventField/eventwin.h \
    Events/EventPlayer/eventPlayer.h \
    Events/EventPlayer/eventadd.h \
    Events/EventPlayer/eventnone.h \
    Events/event.h \
    GameLogic/cell.h \
    GameLogic/controller.h \
    GameLogic/field.h \
    GameLogic/generatelevel.h \
    GameLogic/player.h \
    GameLogic/position.h \
    Logger/Level.h \
    Logger/Logger.h \
    Logger/consolelogger.h \
    Logger/filelogger.h \
    Observable/Observable.h \
    Observable/gamesubject.h \
    Observer/Observer.h \
    Observer/loggerobserver.h \
    Views/cellview.h \
    Views/fieldview.h \
    commandreader.h \
    dialog.h

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
