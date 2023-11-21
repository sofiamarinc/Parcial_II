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
