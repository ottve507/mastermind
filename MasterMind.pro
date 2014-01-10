#-------------------------------------------------
#
# Project created by QtCreator 2013-12-05T10:14:37
#
#-------------------------------------------------

#QMAKE_CXXFLAGS += -std=c++11
QT       += core gui
QT      +=  multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MasterMind
TEMPLATE = app


SOURCES += main.cpp\
        mastermind.cpp \
    boardarea.cpp \
    gamelogic.cpp \
    roundarea.cpp \
    answerarea.cpp \
    controllerarea.cpp \
    piece.cpp \
    resultarea.cpp \
    popup.cpp \
    sound.cpp

HEADERS  += mastermind.h \
    boardarea.h \
    gamelogic.h \
    roundarea.h \
    answerarea.h \
    controllerarea.h \
    piece.h \
    resultarea.h \
    popup.h \
    sound.h
