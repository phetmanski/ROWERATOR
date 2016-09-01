#-------------------------------------------------
#
# Project created by QtCreator 2016-09-01T17:43:27
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rowerator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypainter.cpp \
    painter.cpp \
    player.cpp \
    xmlgenerator.cpp

HEADERS  += mainwindow.h \
    mypainter.h \
    painter.h \
    player.h \
    xmlgenerator.h

FORMS    += mainwindow.ui \
    painter.ui \
    player.ui

RESOURCES += \
    resources.qrc


