#ifndef PUNTAJE_H
#define PUNTAJE_H
#include "Tablero.h"//incluimos tablero ya que segun nuestro flujo de juego vemos que de ahi vamos a sacar la informacion del puntaje

class Puntaje {
public:
    int* puntajeJugador1;
    int* puntajeJugador2;
    Puntaje();
    ~Puntaje();
    void calcularPuntaje(const Tablero& tablero);
    string esGanador(const string& nombreJugador1, const string& nombreJugador2, const Tablero& tablero);
};

#endif // PUNTAJE_H

