#include <iostream>
#include "Tablero.h"
#include <fstream>
using namespace std;

void iniciarJuego();
void revisarHistorial(const string& nombreArchivo);

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
            revisarHistorial("puntajes.txt");
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


void iniciarJuego(){

    int filas = 8, columnas = 8;

    // creacion del tablero
    Tablero miTablero(filas, columnas);
    /*una regla de othello es que siempre inicia el negro*/
    char turno = '-';

    string continuar;
    string ganador = "Ninguno";
    // Configurar jugadores
    miTablero.configurarJugadores();
    /*creacion del puntaje*/
    miTablero.mostrarPuntaje();
    /* el juego se cerrara de dos opciones encontrando un ganador que todas las casillas esten llenas
o al no continuar despues de una jugada*/
    while (ganador == "Ninguno") {
        miTablero.mostrarTablero();  //imprime el tablero
        miTablero.mostrarPuntaje();  //muestra el puntaje

        cout << "Turno del jugador con ficha '" << turno << "'" << endl;
        miTablero.tomarMovimiento(turno);  //revisa el movimiento ingresado

        // Cambia el turno al otro jugador
        turno = (turno == '-') ? '*' : '-';

        // Condición de continuar
        cout << "Desea continuar?(si/no):";
        cin >> continuar;
        if (continuar != "si") {
            break;
        }

        ganador = miTablero.esGanador();
        if (ganador != "Ninguno") {
            miTablero.mostrarTablero();  //imprime el tablero
            miTablero.mostrarPuntaje();  //muestra el puntaje
            miTablero.guardarResultados(); //como terminamos, guardamos resultados
            break;  // Si hay un ganador, termina el juego
        }
    }
    if (ganador == "Empate") {
        cout << "El juego terminó en empate." << endl;
    } else {
        cout << "El ganador es " << ganador << "!" << endl;
    }


}

void revisarHistorial(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo); // Crear un flujo de entrada para leer del archivo
    if (!archivo) {
        cerr << "Error al abrir el archivo de historial." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {  // Leer el archivo línea por línea
        cout << linea << endl;  // Imprimir cada línea
    }

    archivo.close();  // Cerrar el flujo del archivo
}
