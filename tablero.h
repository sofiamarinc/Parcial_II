#ifndef TABLERO_H
#define TABLERO_H
#include <string>
using namespace std;

class Tablero {
public:
    Tablero(int filas, int columnas);  // Constructor
    ~Tablero();                        // Destructor
    void mostrarTablero();             // Metodo para mostrar el tablero
    void configurarJugadores();        // metodo para ingresar el nombre de los jugadores
    void mostrarPuntaje();             // Metodo para mostrar el puntaje
    void tomarMovimiento(char ficha);  //metodo para el movimiento del jugador
    void realizarMovimiento(int fila, int columna, char ficha);
    void guardarResultados();
    string nombreJugador1, nombreJugador2;
    char fichaJugador1, fichaJugador2;
    string esGanador();
private:
    char **tablero;                    // El tablero de juego
    int filas, columnas;               // Dimensiones del tablero
    int *puntajeJugador1, *puntajeJugador2;  // Puntaje usando memoria dinámica
};

#endif // TABLERO_H
