QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    bullet.cpp \
    introduce.cpp \
    main.cpp \
    myscene.cpp \
    myview.cpp \
    setting.cpp \
    tank.cpp \
    tank2.cpp \
    timeboard.cpp \
    widget.cpp

HEADERS += \
    board.h \
    bullet.h \
    introduce.h \
    myscene.h \
    myview.h \
    setting.h \
    tank.h \
    tank2.h \
    timeboard.h \
    widget.h

FORMS += \
    introduce.ui \
    setting.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../pic/A.png \
    ../pic/D.png \
    ../pic/S.png \
    ../pic/W.png \
    ../pic/down.png \
    ../pic/introduce.png \
    ../pic/left.png \
    ../pic/return.png \
    ../pic/right.png \
    ../pic/set.png \
    ../pic/up.png

RESOURCES += \
    pic.qrc
