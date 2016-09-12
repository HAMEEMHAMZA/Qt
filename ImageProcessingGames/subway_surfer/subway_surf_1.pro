#-------------------------------------------------
#
# Project created by QtCreator 2013-03-07T17:52:41
#
#-------------------------------------------------

QT       += core gui

TARGET = subway_surf_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


INCLUDE += C:\\OpenCV2.1\\include\\opencv
LIBS += -LC:\\OpenCV2.1\\lib\
 -lcv210\
 -lcv210d\
 -lcvaux210\
 -lcvaux210d\
 -lcxcore210\
 -lcxcore210d\
 -lcxts210\
 -lhighgui210\
 -lhighgui210d\
 -lml210\
 -lml210d\
 -lopencv_ffmpeg210\
 -lopencv_ffmpeg210d\


LIBS += -luser32
