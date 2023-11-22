#include "manejotexto.h"

void ManejoTexto::guardarResultados(const string& nombreJugador1, char fichaJugador1, int puntajeJugador1,
                                    const string& nombreJugador2, char fichaJugador2, int puntajeJugador2,
                                    const string& ganador) {
    // Obtener la fecha y hora actual
    std::time_t now = std::time(nullptr);
    char* dt = new char[100]; // Reserva memoria para la fecha y hora
    std::strftime(dt, 100, "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    // Abrir archivo en modo append
    std::ofstream outFile("puntajes.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "No se pudo abrir el archivo para escribir los resultados." << std::endl;
        delete[] dt; // Liberar memoria
        return;
    }

    // Escribir los resultados en el archivo
    outFile << "Jugador 1: " << nombreJugador1
            << " (Ficha " << fichaJugador1 << ") > Puntaje: " << puntajeJugador1
            << ", Jugador 2: " << nombreJugador2
            << " (Ficha " << fichaJugador2 << ") > Puntaje: " << puntajeJugador2
            << ", Ganador: " << ganador
            << ", Fecha y hora: " << dt
            << std::endl;

    // Cerrar el archivo y liberar la memoria
    outFile.close();
    delete[] dt;
}

