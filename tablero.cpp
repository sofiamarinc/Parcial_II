#include "Tablero.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


bool soloLetras(const string& nombre) { //comprobamos que el nombre solo tenga letras
    for (char c : nombre) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

Tablero::Tablero(int filas, int columnas) {
    this->filas = filas;//accedo a las filas y columnas usando el puntero
    this->columnas = columnas;

    tablero = new char*[filas];//memoria dinamica
    for (int i = 0; i < filas; ++i) {
        tablero[i] = new char[columnas];

        for (int j = 0; j < columnas; ++j) {
            tablero[i][j] = '|'; /*este caracter me indica que la casilla esta vacia para que
                                  asi se vea el tablero ams ordenado*/
        }
    }
    //segun las reglas de othello estas son las fichas iniciales
    tablero[filas / 2 - 1][columnas / 2 - 1] = '*';
    tablero[filas / 2][columnas / 2] = '*';
    tablero[filas / 2 - 1][columnas / 2] = '-';
    tablero[filas / 2][columnas / 2 - 1] = '-';

    // Inicializa puntajes con memoria dinámica
    puntajeJugador1 = new int(0);
    puntajeJugador2 = new int(0);
}

// Destructor
Tablero::~Tablero() {
    for (int i = 0; i < filas; ++i) {
        delete[] tablero[i];
    }
    delete[] tablero;
    // Libera la memoria de los puntajes
    delete puntajeJugador1;
    delete puntajeJugador2;

}

void Tablero::mostrarTablero() {
    cout << "  ";
    //imprimir las letras de la a hasta la h en columnas
    for (char c = 'A'; c < 'A' + columnas; ++c) {
        cout<< c << " ";
    }
    cout << endl;

    // mostrar el tablero y las fias
    for (int i = 0; i < filas; ++i) {
        cout << i + 1 << " ";  // Etiquetas de filas empiezan en 1
        for (int j = 0; j < columnas; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
void Tablero::configurarJugadores() {

        cout << "Ingresa el nombre del Jugador 1: ";
        cin >> nombreJugador1;

        while (!soloLetras(nombreJugador1)) {
            cout<<"El nombre solo debe contener letras." << endl;
            cout << "Ingresa el nombre del Jugador 1: ";
            cin >> nombreJugador1;
        }

        fichaJugador1 = '-';  // Ficha negra siempre empieza
        cout << nombreJugador1 << " Tu ficha es " << fichaJugador1 << endl;

        cout << "Ingresa el nombre del Jugador 2: ";
        cin >> nombreJugador2;

        while (!soloLetras(nombreJugador2)) {
            cout<<"El nombre solo debe contener letras." << endl;
            cout << "Ingresa el nombre del Jugador 2: ";
            cin >> nombreJugador2;
        }

        fichaJugador2 = '*';  // Ficha blanca
        cout<< nombreJugador2 << " Tu ficha es " << fichaJugador2 << endl;

}

void Tablero::mostrarPuntaje() {

    // iteramos sobre toda la matriz en 2d para contar caracteres
    *puntajeJugador1 = 0;
    *puntajeJugador2 = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (tablero[i][j] == '-') (*puntajeJugador1)++;
            if (tablero[i][j] == '*') (*puntajeJugador2)++;
        }
    }

    //imprimir puntajes
    cout << "Puntaje de " << nombreJugador1 << ": " << *puntajeJugador1 << endl;
    cout << "Puntaje de " << nombreJugador2 << ": " << *puntajeJugador2 << endl;
}



void Tablero::realizarMovimiento(int fila, int columna, char ficha) {
    // depende de la ficha seleccionada * o -
    tablero[fila][columna] = ficha;

    //direcciones arriba,abajo,diagonales,derecha,arriba
    int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    // iteracion y revision de cada espacio |
    for (int d = 0; d < 8; ++d) {
        int x = fila + dx[d];
        int y = columna + dy[d];

        //verificamos que la casilla si este para poder invadirla
        if (x >= 0 && x < 8 && y >= 0 && y < 8 && tablero[x][y] != ficha && tablero[x][y] != ' ') {
            // movimientos en la misma direccion hasta encontrar el mismo caracter
            int nx = x, ny = y;
            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (tablero[nx][ny] == ficha) {
                    // rodeamos todas las fichas entre (fila, columna) y (nx, ny)
                    while (nx != fila || ny != columna) {
                        tablero[nx][ny] = ficha;
                        nx -= dx[d];
                        ny -= dy[d];
                    }
                    break;
                }
                nx += dx[d];
                ny += dy[d];
            }
        }
    }
}

void Tablero::tomarMovimiento(char ficha) {
    char *movimiento = new char[3];
    int fila, columna;

    while (true) {
        cout << "Ingrese su movimiento (a-h,1-3): ";
        cin >> movimiento;

        columna = movimiento[0] - 'a';
        fila = movimiento[1] - '1';

        if (tablero[fila][columna] == '|') {
            break;  // Salimos del loop si la casilla está vacía.
        } else {
            cout << "Casilla ocupada. Intente de nuevo." << endl;
        }
    }
    delete[] movimiento;
    //el metodo realizar movimiento para verificar
    realizarMovimiento(fila, columna, ficha);
}

string Tablero::esGanador() {
    /*la forma en la que se gana solo es cuando los jugadores llenan el tablero*/
    int *contadorFichasJugador1 = new int(0);
    int *contadorFichasJugador2 = new int(0);
    bool tableroLleno = true;

    // Contar las fichas y verificar si el tablero está lleno
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (tablero[i][j] == '-') {
                (*contadorFichasJugador1)++;
            } else if (tablero[i][j] == '*') {
                (*contadorFichasJugador2)++;
            } else if (tablero[i][j] == ' ' || tablero[i][j] == '|') {
                tableroLleno = false;
            }
        }
    }

    // Si el tablero esta lleno se verifica quien tiene mas fichas
    string ganador;
    if (tableroLleno) {
        if (*contadorFichasJugador1 > *contadorFichasJugador2) {
            ganador = nombreJugador1;
        } else if (*contadorFichasJugador2 > *contadorFichasJugador1) {
            ganador = nombreJugador2;
        } else {
            ganador = "Empate";
        }
    } else {
        ganador = "Ninguno";
    }

    // liberamos memoria dinamica
    delete contadorFichasJugador1;
    delete contadorFichasJugador2;

    return ganador;
}

void Tablero::guardarResultados() {
    // Obtener la fecha y hora actual
    std::time_t now = std::time(nullptr);
    char* reserva = new char[100]; // almacenar el tamaño
    std::strftime(reserva, 100, "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::ofstream outFile("puntajes.txt", std::ios::app); // Abre el archivo en modo append
    if (!outFile) {
        cout<< "No se pudo abrir el archivo para escribir los resultados." <<endl;
        delete[] reserva; // liberar memoria
        return;
    }

    // Escribir los resultados en el archivo
    outFile << "Jugador 1: " << nombreJugador1
            << " (Ficha " << fichaJugador1 << ") > Puntaje: " << *puntajeJugador1
            << ", Jugador 2: " << nombreJugador2
            << " (Ficha " << fichaJugador2 << ") > Puntaje: " << *puntajeJugador2
            << ", Ganador: " << esGanador()
            << ", Fecha y hora: " << reserva
            << endl;

    outFile.close(); //cerramos el archivo
    delete[] reserva; // liberar memoria
}

