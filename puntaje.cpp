#include "Puntaje.h"

Puntaje::Puntaje() {
    puntajeJugador1 = new int(0); // Asignar memoria
    puntajeJugador2 = new int(0); // Asignar memoria
}

Puntaje::~Puntaje() {
    delete puntajeJugador1; // Liberar memoria
    delete puntajeJugador2; // Liberar memoria
}

void Puntaje::calcularPuntaje(const Tablero& tablero) {
    *puntajeJugador1 = 0;
    *puntajeJugador2 = 0;
    for (int i = 0; i < tablero.getFilas(); ++i) {
        for (int j = 0; j < tablero.getColumnas(); ++j) {
            char posicion = tablero.getPosicion(i, j);
            if (posicion == '-') {
                (*puntajeJugador1)++;
            } else if (posicion == '*') {
                (*puntajeJugador2)++;
            }
        }
    }
    cout << "el puntaje del JUGADOR 1 es: " << *puntajeJugador1 << endl;
    cout << "el puntaje del JUGADOR 2 es: " << *puntajeJugador2 << endl;
}

string Puntaje::esGanador(const string& nombreJugador1, const string& nombreJugador2, const Tablero& tablero) {
    int contadorFichasJugador1 = 0;
    int contadorFichasJugador2 = 0;
    bool tableroLleno = true;
    //verificamos que el tablero este lleno
    for (int i = 0; i < tablero.getFilas(); ++i) {
        for (int j = 0; j < tablero.getColumnas(); ++j) {
            char posicion = tablero.getPosicion(i, j);
            if (posicion == '-') {
                contadorFichasJugador1++;
            } else if (posicion == '*') {
                contadorFichasJugador2++;
            } else if (posicion == ' ' || posicion == '|') {
                tableroLleno = false;
            }
        }
    }
    //cuando el tablero este lleno contamos las fichas el que tenga ams gana
    if (tableroLleno) {
        if (contadorFichasJugador1 > contadorFichasJugador2) {
            return nombreJugador1;
        } else if (contadorFichasJugador2 > contadorFichasJugador1) {
            return nombreJugador2;
        } else {
            return "Empate";
        }
    } else {
        return "Ninguno";
    }
}
