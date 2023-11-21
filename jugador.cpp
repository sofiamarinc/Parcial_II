#include "Jugador.h"

Jugador::Jugador() {}

bool Jugador::soloLetras(const string& nombre) {
    for (char c : nombre) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

void Jugador::configurarJugador(char fichaAsignada) {
    cout << "Ingresa el nombre del Jugador (" << fichaAsignada << "): ";
    cin >> nombre;

    while (!soloLetras(nombre)) {
        cout << "El nombre solo debe contener letras." << endl;
        cout << "Ingresa el nombre del Jugador (" << fichaAsignada << "): ";
        cin >> nombre;
    }

    ficha = fichaAsignada;
    cout << nombre << " Tu ficha es " << ficha << endl;
}

