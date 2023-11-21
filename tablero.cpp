#include "Tablero.h"

Tablero::Tablero(int filas, int columnas) {
    this->filas = filas;//accedo a las filas y columnas usando el puntero
    this->columnas = columnas;

    tablero = new char*[filas];//memoria dinamica
    for (int i = 0; i < filas; ++i) {
        tablero[i] = new char[columnas];

        for (int j = 0; j < columnas; ++j) {
            tablero[i][j] = '|'; /*este caracter me indica que la casilla esta vacia para que
                                  asi se vea el tablero ams ordenado*/
        }
    }
    //segun las reglas de othello estas son las fichas iniciales
    tablero[filas / 2 - 1][columnas / 2 - 1] = '*';
    tablero[filas / 2][columnas / 2] = '*';
    tablero[filas / 2 - 1][columnas / 2] = '-';
    tablero[filas / 2][columnas / 2 - 1] = '-';
}

// Destructor
Tablero::~Tablero() {
    for (int i = 0; i < filas; ++i) {
        delete[] tablero[i];
    }
    delete[] tablero;
}

void Tablero::mostrarTablero() const {
    cout << "  ";
    //imprimir las letras de la a hasta la h en columnas
    for (char c = 'A'; c < 'A' + columnas; ++c) {
        cout<< c << " ";
    }
    cout << endl;

    // mostrar el tablero y las fichas
    for (int i = 0; i < filas; ++i) {
        cout << i + 1 << " ";  // Etiquetas de filas empiezan en 1
        for (int j = 0; j < columnas; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

char Tablero::getPosicion(int fila, int columna) const {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        return tablero[fila][columna];
    }
}

void Tablero::setPosicion(int fila, int columna, char valor) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        tablero[fila][columna] = valor;
    }
}

int Tablero::getFilas() const {
    return filas;
}

int Tablero::getColumnas() const {
    return columnas;
}

