#-------------------------------------------------
#
# Project created by QtCreator 2019-08-27T14:26:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Navi_gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

# ROS --------------------------------------
INCLUDEPATH += /opt/ros/kinetic/include

INCLUDEPATH += /home/tjk/catkin_ws/devel/include

LIBS += -L/opt/ros/kinetic/lib \
    -lroscpp \
    -lroscpp_serialization \
    -lrosconsole \
    -lrostime
# ------------------------------------------

SOURCES += \
        main.cpp \
        CNavi_Gui.cpp \
    ros_subscribe.cpp \
    ros_publish.cpp

HEADERS += \
        CNavi_Gui.h \
    ros_subscribe.h \
    ros_publish.h

FORMS += \
        CNavi_Gui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
