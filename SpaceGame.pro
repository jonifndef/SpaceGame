#-------------------------------------------------
#
# Project created by QtCreator 2018-01-26T11:06:59
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/blasterbolt.cpp \
    src/enemyone.cpp \
    src/game.cpp \
    src/gameobject.cpp \
    src/level.cpp \
    src/main.cpp \
    src/mainmenu.cpp \
    src/ship.cpp \
    src/spacegame.cpp \
    src/timing.cpp

HEADERS += \
    src/blasterbolt.h \
    src/defines.h \
    src/enemyone.h \
    src/game.h \
    src/gameobject.h \
    src/level.h \
    src/mainmenu.h \
    src/ship.h \
    src/spacegame.h \
    src/timing.h

FORMS += \
        spacegame.ui
