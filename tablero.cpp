#include <iostream>
#include "Tablero.h"
using namespace std;

const int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

Tablero::Tablero(int size) : size(size) {
    tablero = new char*[size];
    for (int i = 0; i < size; ++i) {
        tablero[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            tablero[i][j] = ' ';  // Espacio vacío
        }
    }
    // Coloca las cuatro fichas iniciales
    tablero[size / 2 - 1][size / 2 - 1] = '*';
    tablero[size / 2][size / 2] = '*';
    tablero[size / 2 - 1][size / 2] = '-';
    tablero[size / 2][size / 2 - 1] = '-';
}

Tablero::~Tablero() {
    for (int i = 0; i < size; ++i) {
        delete[] tablero[i];
    }
    delete[] tablero;
}

void Tablero::mostrar() {
    // Mostrar las letras para las columnas
    cout << "  ";
    for (char letra = 'a'; letra < 'a' + size; ++letra) {
        cout << ' ' << letra;
    }
    cout <<endl;

    // Mostrar el tablero
    for (int i = 0; i < size; ++i) {
        // Mostrar el número de la fila
        cout << i + 1 << ' ';

        // Mostrar las celdas
        for (int j = 0; j < size; ++j) {
            cout << '|' << tablero[i][j];
        }
        cout << '|' <<endl;
    }
}

char Tablero::getFicha(int fila, int columna) {
    return tablero[fila][columna];
}

void Tablero::setFicha(int fila, int columna, char ficha) {
    tablero[fila][columna] = ficha;
}

bool Tablero::esMovimientoValido(int fila, int columna, char ficha) {
    char oponente = (ficha == '*') ? '-' : '*';
    if (tablero[fila][columna] != ' ') return false;  // Casilla ya ocupada

    for (int dir = 0; dir < 8; ++dir) {
        int x = fila + dx[dir];
        int y = columna + dy[dir];

        if (x >= 0 && x < size && y >= 0 && y < size && tablero[x][y] == oponente) {
            while (x >= 0 && x < size && y >= 0 && y < size) {
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && x < size && y >= 0 && y < size) {
                    if (tablero[x][y] == ' ') break;
                    if (tablero[x][y] == ficha) return true;
                }
            }
        }
    }

    return false;
}
