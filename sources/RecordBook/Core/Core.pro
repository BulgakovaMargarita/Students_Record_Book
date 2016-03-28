#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T11:17:06
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += core.cpp

HEADERS += core.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
