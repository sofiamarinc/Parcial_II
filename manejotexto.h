#ifndef MANEJOTEXTO_H
#define MANEJOTEXTO_H
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class ManejoTexto {
public:
    void guardarResultados(const string& nombreJugador1, char fichaJugador1, int puntajeJugador1,
                           const string& nombreJugador2, char fichaJugador2, int puntajeJugador2,
                           const string& ganador);
};

#endif // MANEJOTEXTO_H
