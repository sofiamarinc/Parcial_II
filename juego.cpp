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
