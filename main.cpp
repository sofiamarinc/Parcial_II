#include <iostream>
#include "manejotexto.h"
#include "iniciar.h"
using namespace std;

int main() {
    int opcion;
    Iniciar iniciar;

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
            iniciar.iniciarJuego();
            break;
        case 2:
            ManejoTexto manejoTexto;
            manejoTexto.revisarHistorial();
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


