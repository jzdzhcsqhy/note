#-------------------------------------------------
#
# Project created by QtCreator 2017-07-11T13:27:32
#
#-------------------------------------------------

QT       += core gui
QT  += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = note
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cdboperate.cpp \
    cdlgdiary.cpp \
    cdlgnote.cpp \
    login.cpp \
    cdlgsearch.cpp \
    HealthStoneSimulator.cpp

HEADERS  += mainwindow.h \
    cdboperate.h \
    cdlgdiary.h \
    datastruct.h \
    globle.h \
    cdlgnote.h \
    login.h \
    cdlgsearch.h \
    HealthStoneSimulator.h

FORMS    += mainwindow.ui \
    cdlgdiary.ui \
    cdlgnote.ui \
    login.ui \
    cdlgsearch.ui \
    HealthStoneSimulator.ui

RESOURCES += \
    img.qrc

DISTFILES += \
    resource/note.ico \
    ../build-note-unknown-Release/release/note.exe
