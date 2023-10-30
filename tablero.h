#pragma once

class Tablero {
public:
    Tablero(int size);  // Constructor
    ~Tablero();  // Destructor

    void mostrar();  // Muestra el tablero en la consola
    char getFicha(int fila, int columna);  // Obtiene la ficha en una posición dada
    void setFicha(int fila, int columna, char ficha);  // Coloca una ficha en una posición dada
    bool esMovimientoValido(int fila, int columna, char ficha);

private:
    char **tablero;  // Matriz dinámica para el tablero
    int size;  // Tamaño del tablero
};
