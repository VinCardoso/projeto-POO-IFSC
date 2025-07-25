QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ball.cpp \
    game_object.cpp \
    goal.cpp \
    main.cpp \
    myscene.cpp \
    paddle.cpp \
    player.cpp \
    qtgraphics.cpp \
    wall.cpp

HEADERS += \
    ball.h \
    constants.h \
    game_object.h \
    goal.h \
    myscene.h \
    paddle.h \
    player.h \
    qtgraphics.h \
    wall.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
