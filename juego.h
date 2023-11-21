#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"

class Juego {
private:
    Tablero tablero;


public:
    Tablero& obtenerTablero()  { return tablero; }
    Juego(int filas, int columnas);
    bool tomarMovimiento(char ficha, int& fila, int& columna); // modificamos esta funcion para que nos devuelva un bool y nos de fila y columna por referencia
    void realizarMovimiento(int fila, int columna, char ficha);
};

#endif // JUEGO_H
