#-------------------------------------------------
#
# Project created by QtCreator 2019-01-07T15:05:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtHello
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    card.cpp \
    hand.cpp \
    genericplayer.cpp \
    player.cpp \
    house.cpp \
    deck.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    card.h \
    hand.h \
    genericplayer.h \
    player.h \
    house.h \
    deck.h \
    game.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
