#ifndef MANEJOTEXTO_H
#define MANEJOTEXTO_H
/*la idea de esta clase es que atraves de funciones podamos leer y guardar el puntaje
el boceto de esta funcion podria ser algo como una iteracion por el nombre en el tablero
tomar nombre y el puntaje usando la memoria dinamica creada con anterioridad y guardarla
en un txt de la forma jugador 1 score jugador 2 score endl*/
/*de igual forma para crear la funcion leer historial se podria implementar algo como la
practica 4 con el metodo verhistorial y solo se llamarian en el main.cpp en el case2*/
class ManejoTexto {
public:
    void guardarPuntajes(char* nombreJugador1, int puntaje1,
                         char* nombreJugador2, int puntaje2);
};

#endif // MANEJOTEXTO_H
