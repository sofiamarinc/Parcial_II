#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <iostream>

using namespace std;

class Jugador {
private:
    string nombre;
public:
    string getNombre() const { return nombre; }
    char getFicha() const { return ficha; }
    char ficha;
    Jugador();
    bool soloLetras(const string& nombre);
    void configurarJugador(char fichaAsignada);
};

#endif // JUGADOR_H
