#-------------------------------------------------
#
# Project created by QtCreator 2017-12-31T19:31:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphBJ
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        bj.cpp \
    card.cpp \
    focusrect.cpp \
    smallbutton.cpp \
    myqgraphicsscene.cpp \
    about.cpp \
    bet.cpp

HEADERS += \
        bj.h \
    card.h \
    focusrect.h \
    smallbutton.h \
    myqgraphicsscene.h \
    about.h \
    bet.h

FORMS += \
        bj.ui \
    about.ui \
    bet.ui

RESOURCES += \
    resource.qrc
#CONFIG(debug, debug|release) {
#    DESTDIR         = $$OUT_PWD/res/Bin/Debug
#}else {
#    DESTDIR         = $$OUT_PWD/res/Bin/Release
#}
#win32:QMAKE_POST_LINK += windeployqt $$DESTDIR $$escape_expand(\\n)
