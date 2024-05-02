TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dailydata.cpp \
        main.cpp \
        salesdata.cpp

HEADERS += \
	dailydata.h \
	salesdata.h

DISTFILES += \
	minta-stdout.txt
