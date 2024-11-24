QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SendFile.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    SendFile.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

win32:{
    message("windows")
    CONFIG(debug, debug|release){
        message("debug")
#        contains(QMAKE_HOST.arch, x86_64){
#        contains(QMAKE_TARGET.arch, x86_64){
        contains(DEFINES, WIN64){
            message("x64")
            DESTDIR = $$PWD/bin/win64/debug
        }
        else{
            message("x32")
            DESTDIR = $$PWD/bin/win32/debug
        }
    }
    else{
        message("release")
        contains(DEFINES, WIN64){
            message("x64")
            DESTDIR = $$PWD/bin/win64/release
        }
        else{
            message("x32")
            DESTDIR = $$PWD/bin/win32/release
        }
    }
}

unix:{
    message("unix")
    CONFIG(debug, debug|release){
        message("debug")
        contains(DEFINES, WIN64){
            message("x64")
            DESTDIR = $$PWD/bin/unix64/debug
        }
        else{
            message("x32")
            DESTDIR = $$PWD/bin/unix32/debug
        }
    }
    else{
        message("release")
        contains(DEFINES, WIN64){
            message("x64")
            DESTDIR = $$PWD/bin/unix64/release
        }
        else{
            message("x32")
            DESTDIR = $$PWD/bin/unix32/release
        }
    }
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
