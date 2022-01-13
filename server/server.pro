QT += network
QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        src/server.cpp \
        src/communication.cpp \
        src/main.cpp

HEADERS += \
        include/server.h \
        include/communication.h
