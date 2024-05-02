TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        statcollector.cpp

HEADERS += \
	statcollector.h

DISTFILES += \
	minta-stdout.txt
