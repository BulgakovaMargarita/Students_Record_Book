#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T11:17:06
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    pupil.cpp \
    teacher.cpp

HEADERS += \
    pupil.h \
    teacher.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
