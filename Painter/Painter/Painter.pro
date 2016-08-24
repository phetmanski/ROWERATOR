#-------------------------------------------------
#
# Project created by QtCreator 2016-08-22T19:25:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Painter
TEMPLATE = app


SOURCES += main.cpp\
        painter.cpp \
    mainwindow.cpp \
    mypainter.cpp \
    cyclist.cpp

HEADERS  += painter.h \
    mainwindow.h \
    mypainter.h \
    cyclist.h

FORMS    += painter.ui \
    mainwindow.ui
