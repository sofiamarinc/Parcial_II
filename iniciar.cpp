#include "Iniciar.h"
#include "Tablero.h"
#include "Juego.h"
#include "Jugador.h"
#include "Puntaje.h"
#include "ManejoTexto.h"
#include <iostream>
using namespace std;

void Iniciar::iniciarJuego() {
    //definimos el tamaño del tablero
    int filas = 8;
    int columnas = 8;
    //inicializacion de constructores de las clases
    Juego juego(filas, columnas);
    Jugador jugador1, jugador2;
    Puntaje puntaje;

    // Configurar jugadores
    jugador1.configurarJugador('-'); // Ficha del jugador 1
    jugador2.configurarJugador('*'); // Ficha del jugador 2

    char turno = '-'; // Empieza el jugador 1
    string continuar;
    string ganador = "Ninguno";

    //ciclo donde inicia el juego hasta que halle un ganador
    while (ganador == "Ninguno") {
        juego.obtenerTablero().mostrarTablero();  // mostramos el tablero
        puntaje.calcularPuntaje(juego.obtenerTablero());
        cout << "Turno del jugador con ficha '" << turno << "'" << endl;
        int fila, columna;
        if (juego.tomarMovimiento(turno, fila, columna)) {/*este if flujo principal del juego*/
            juego.realizarMovimiento(fila, columna, turno);
        }
        // Cambia el turno al otro jugador
        turno = (turno == '-') ? '*' : '-';
        // Condición de continuar
        cout << "Desea continuar?(si/no): ";
        cin >> continuar;
        if (continuar != "si") {
            break;
        }
        ganador = puntaje.esGanador(jugador1.getNombre(), jugador2.getNombre(), juego.obtenerTablero());
        if (ganador != "Ninguno") {
            juego.obtenerTablero().mostrarTablero(); // Imprime el tablero
            puntaje.calcularPuntaje(juego.obtenerTablero()); // Muestra el puntaje
            break; // en tal caso que encuentre un gaanador
        }
    }
    //mensajes de fin de juego
    if (ganador == "Empate") {
        cout << "El juego terminó en empate." << endl;
    } else {
        cout << "El ganador es " << ganador << "!" << endl;
    }
    ManejoTexto manejoTexto;
    manejoTexto.guardarResultados(jugador1.getNombre(), jugador1.getFicha(), *puntaje.puntajeJugador1,
                                  jugador2.getNombre(), jugador2.getFicha(), *puntaje.puntajeJugador2,
                                  ganador);
}
