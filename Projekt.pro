TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
SOURCES += \
        animatedSprite.cpp \
        dragon.cpp \
        heroine.cpp \
        main.cpp \
        misc.cpp \
        orb.cpp \
        util.cpp
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

DISTFILES += \
    Makefile \
    Projekt.pro.user

HEADERS += \
    animatedSprite.h \
    dragon.h \
    heroine.h \
    misc.h \
    orb.h \
    util.h
