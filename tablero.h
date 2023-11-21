#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>

using namespace std;

class Tablero {
public:
    Tablero(int filas, int columnas);
    ~Tablero();
    void mostrarTablero()const;
    char getPosicion(int fila, int columna)const;
    void setPosicion(int fila, int columna, char valor);
    int getFilas() const;
    int getColumnas() const;


private:
    char **tablero;  // El tablero de juego, utilizando memoria dinámica
    int filas, columnas;
};

#endif // TABLERO_H
