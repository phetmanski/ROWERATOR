#-------------------------------------------------
#
# Project created by QtCreator 2016-08-29T21:04:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Painter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypainter.cpp \
    painter.cpp

HEADERS  += mainwindow.h \
    mypainter.h \
    painter.h

FORMS    += mainwindow.ui \
    painter.ui
