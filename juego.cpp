#include "Juego.h"

Juego::Juego(int filas, int columnas) : tablero(filas, columnas) {}

bool Juego::tomarMovimiento(char ficha, int& fila, int& columna) {
    char *movimiento = new char[3];  //memoria dinamica para el ingreso del usuario
    bool movimientoValido = false;

    while (!movimientoValido) {
        cout << "Ingrese su movimiento (a-h,1-8): ";
        cin >> movimiento[0] >> movimiento[1]; //mejoramos la validacion que el usuario ingrese fila columna y se verifica que termine en el caracter nulo
        movimiento[2] = '\0';

        columna = tolower(movimiento[0]) - 'a'; //convertimos a minuscula para mejorar validacion
        fila = movimiento[1] - '1'; // calculamos el indice de la fila

        //validamos que este en el rango con este primer if
        if (fila >= 0 && fila < obtenerTablero().getFilas() &&
            columna >= 0 && columna < obtenerTablero().getColumnas()) {
            // verificamos que la posicion este vacia en este segundo if
            if (obtenerTablero().getPosicion(fila, columna) == '|') {
                movimientoValido = true; // El movimiento es válido
                obtenerTablero().setPosicion(fila, columna, ficha);
            } else {
                cout << "Casilla ocupada. Intente de nuevo." << endl;
            }
        } else {
            cout << "Movimiento fuera de rango. Intente de nuevo." << endl;
        }
    }

    delete[] movimiento; // Liberar la memoria asignada
    return movimientoValido;
}

void Juego::realizarMovimiento(int fila, int columna, char ficha) {
    tablero.setPosicion(fila, columna, ficha);

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int d = 0; d < 8; ++d) {
        int x = fila + dx[d];
        int y = columna + dy[d];

        // Comprueba que la primera ficha es del oponente
        if (x >= 0 && x < tablero.getFilas() && y >= 0 && y < tablero.getColumnas() && tablero.getPosicion(x, y) != ficha && tablero.getPosicion(x, y) != '|') {
            while (x >= 0 && x < tablero.getFilas() && y >= 0 && y < tablero.getColumnas() && tablero.getPosicion(x, y) != ficha) {
                x += dx[d];
                y += dy[d];
            }

            //verificacion de que no salgamos del tablero y que tengamos fichas del color a encerrar
            if (x >= 0 && x < tablero.getFilas() && y >= 0 && y < tablero.getColumnas() && tablero.getPosicion(x, y) == ficha) {
                // Retrocede y cambia las fichas
                x -= dx[d];
                y -= dy[d];
                while (x != fila || y != columna) {
                    tablero.setPosicion(x, y, ficha);
                    x -= dx[d];
                    y -= dy[d];
                }
            }
        }
    }
}
