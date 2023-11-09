TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.cpp \
        game.cpp \
        main.cpp \
        player.cpp

HEADERS += \
    board.h \
    game.h \
    player.h
