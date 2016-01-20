QT += core
#QT -= gui

CONFIG += c++11

TARGET = OpenCvTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

QT += sql

QTPLUGIN += QSQLMYSQL

SOURCES += main.cpp

INCLUDEPATH += C:\opencv_mingw\install\include
LIBS += -L/usr/local/lib
LIBS += -L/usr/lib/x86_64-linux-gnu
#LIBS += -lopencv_core249 -lopencv_highgui249 -lopencv_imgproc249 -lopencv_features2d249 -lopencv_photo249 -lopencv_ml249 -lopencv_objdetect249
LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_features2d -lopencv_photo -lopencv_ml -lopencv_objdetect
