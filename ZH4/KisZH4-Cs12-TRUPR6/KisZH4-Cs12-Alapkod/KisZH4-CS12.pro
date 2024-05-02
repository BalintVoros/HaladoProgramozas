TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        handler.cpp \
        tarsasjatek.cpp

HEADERS += \
    handler.h \
    tarsasjatek.h \

DISTFILES += \
    minta-stdout.txt

 SQLAPIDIR = "C:/SQLAPI"
 INCLUDEPATH += $${SQLAPIDIR}/include
 LIBS += -L$${SQLAPIDIR}/mingw-w64-x86_64-8.1.0-posix-seh-rt_v6-rev0/lib -llibsqlapi -lversion
