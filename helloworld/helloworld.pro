#-------------------------------------------------
#
# Project created by QtCreator 2016-06-28T10:13:25
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = helloworld
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

LIBS += -losgViewer
LIBS += -losg
LIBS += -losgDB
LIBS += -losgUtil
LIBS += -losgGA
SOURCES += main.cpp
