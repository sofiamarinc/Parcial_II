#include "Puntaje.h"

Puntaje::Puntaje() : puntajeJugador1(0), puntajeJugador2(0) {}

void Puntaje::calcularPuntaje(const Tablero& tablero) {
    //contadores
    puntajeJugador1 = 0;
    puntajeJugador2 = 0;
    /*este cambio es importante ya que vamos a usar las funciones
     *  nuevas implementadas en tablero para poder iterarlo*/
    for (int i = 0; i < tablero.getFilas(); ++i) {
        for (int j = 0; j < tablero.getColumnas(); ++j) {
            char posicion = tablero.getPosicion(i, j);
            if (posicion == '-') {   //'-' esta es la ficha siempre del jugador 1
                ++puntajeJugador1;
            } else if (posicion == '*') {
                ++puntajeJugador2;
            }
        }
    }
}

string Puntaje::esGanador(const string& nombreJugador1, const string& nombreJugador2, const Tablero& tablero) {

}
