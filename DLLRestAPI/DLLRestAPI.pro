QT -= gui
QT += widgets
QT += network

TEMPLATE = lib
DEFINES += DLLRESTAPI_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dllrestapi.cpp \
    lasku.cpp \
    naytasaldo.cpp \
    nosto.cpp \
    tilisiirto.cpp \
    tilitapahtumat.cpp

HEADERS += \
    DLLRestAPI_global.h \
    dllrestapi.h \
    lasku.h \
    naytasaldo.h \
    nosto.h \
    tilisiirto.h \
    tilitapahtumat.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    lasku.ui \
    naytasaldo.ui \
    nosto.ui \
    tilisiirto.ui \
    tilitapahtumat.ui
