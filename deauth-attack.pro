TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -ltins

SOURCES += \
        mac.cpp \
        main.cpp

HEADERS += \
    mac.h
