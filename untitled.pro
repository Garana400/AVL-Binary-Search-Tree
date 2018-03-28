#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T23:32:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
    avl.cpp \
    form.cpp

HEADERS  +=  \
    avl.h \
    form.h \
    mainwindow.h
FORMS    += \
    form.ui
CONFIG += console

RESOURCES += \
    pics.qrc
