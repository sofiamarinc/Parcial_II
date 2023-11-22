#include <iostream>
#include "Tablero.h"
#include "juego.h"
#include "jugador.h"
#include "puntaje.h"
#include "manejotexto.h"
#include <fstream>
using namespace std;

void iniciarJuego();

int main() {
    int opcion;

    while (true) {
        cout << "---BIENVENIDO(A) A MI JUEGO OTHELLO---" << endl;
        cout << "Elige una opcion:" << endl;
        cout << "1. Iniciar Juego" << endl;
        cout << "2. Revisar Historial" << endl;
        cout << "3. Salir" << endl;
        cout << "--->";
        cin >> opcion;

        switch (opcion) {
        case 1:
            iniciarJuego();
            break;
        case 2:
            //revisarHistorial("puntajes.txt");
            //cout<< "falta implementarla xD"<<endl;
            break;
        case 3:
            cout << "GRACIAS POR INGRESAR A MI PROGRAMA :D " << endl;
            return 0;
        default:
            cout << "opcion ingresada no valida." << endl;
        }
    }

    return 0;
}

void iniciarJuego() {
    int filas = 8; //definimos el tamaño del tablero
    int columnas = 8;

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
        puntaje.calcularPuntaje(juego.obtenerTablero()); //falta mejorar el codigo ya que no nos muestra el puntaje como el anterior codigo
        cout << "Turno del jugador con ficha '" << turno << "'" << endl;
        int fila, columna;
        if (juego.tomarMovimiento(turno, fila, columna)) {
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
            // juego.guardarResultados(); // falta implementar
            break; // en tal caso que encuentre un gaanador
        }
    }
//mensajes de fin de juego
    if (ganador == "Empate") {
        cout << "El juego terminó en empate." << endl;
    } else {
        cout << "El ganador es " << ganador << "!" << endl;
    }
}

//se verifica funcionalidad del codigo
