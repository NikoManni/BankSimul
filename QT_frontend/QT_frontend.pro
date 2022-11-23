QT       += core gui sql
QT       += network
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    pvalikko.cpp

HEADERS += \
    mainwindow.h \
    pvalikko.h

FORMS += \
    mainwindow.ui \
    pvalikko.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




win32: LIBS += -L$$PWD/../build-DLLPinCode-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lDLLPinCode

INCLUDEPATH += $$PWD/../DLLPinCode
DEPENDPATH += $$PWD/../DLLPinCode

win32: LIBS += -L$$PWD/../build-DLLRestAPI-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lDLLRestAPI

INCLUDEPATH += $$PWD/../DLLRestAPI
DEPENDPATH += $$PWD/../DLLRestAPI

win32: LIBS += -L$$PWD/../build-DLLSerialPort-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lDLLSerialPort

INCLUDEPATH += $$PWD/../DLLSerialPort
DEPENDPATH += $$PWD/../DLLSerialPort

win32: LIBS += -L$$PWD/../build-DLLPinCode-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/ -lDLLPinCode

INCLUDEPATH += $$PWD/../DLLPinCode
DEPENDPATH += $$PWD/../DLLPinCode

win32: LIBS += -L$$PWD/../build-DLLRestAPI-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/ -lDLLRestAPI

INCLUDEPATH += $$PWD/../DLLRestAPI
DEPENDPATH += $$PWD/../DLLRestAPI

win32: LIBS += -L$$PWD/../build-DLLSerialPort-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/ -lDLLSerialPort

INCLUDEPATH += $$PWD/../DLLSerialPort
DEPENDPATH += $$PWD/../DLLSerialPort
