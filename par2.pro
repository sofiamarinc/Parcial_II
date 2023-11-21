TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        juego.cpp \
        jugador.cpp \
        main.cpp \
        manejotexto.cpp \
        puntaje.cpp \
        tablero.cpp

HEADERS += \
    juego.h \
    jugador.h \
    manejotexto.h \
    puntaje.h \
    tablero.h
