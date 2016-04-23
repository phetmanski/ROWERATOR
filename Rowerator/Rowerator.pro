#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T19:51:06
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rowerator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    player.h

FORMS    += mainwindow.ui \
    player.ui

RESOURCES += \
    resources.qrc
