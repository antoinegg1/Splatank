QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    bullet.cpp \
<<<<<<< HEAD
    form.cpp \
    main.cpp \
    subform.cpp \
    tank.cpp \
=======
    main.cpp \
    myscene.cpp \
    myview.cpp \
    tank.cpp \
    tank2.cpp \
>>>>>>> c9835b1f649d8de747fc08e1cf97824ae2bb7def
    widget.cpp

HEADERS += \
    board.h \
    bullet.h \
<<<<<<< HEAD
    form.h \
    subform.h \
    tank.h \
    widget.h

FORMS += \
    form.ui \
    subform.ui \
=======
    myscene.h \
    myview.h \
    tank.h \
    tank2.h \
    widget.h

FORMS += \
>>>>>>> c9835b1f649d8de747fc08e1cf97824ae2bb7def
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

<<<<<<< HEAD
RESOURCES += \
    rec.qrc
=======
DISTFILES +=

RESOURCES += \
    pic.qrc
>>>>>>> c9835b1f649d8de747fc08e1cf97824ae2bb7def
