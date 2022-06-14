#include<iostream>
#include "interfaz.h"
using namespace std;

int main(){


    /* ingreso de nombre de jugadores */
    string jugador1, jugador2;                      // solicitacion de nombre de jugadores
    // cin.ignore();                                // para ignorar el "enter" en el ultimo ingreso (por ahora negado porque no hay nada arriba)
    cout << "Jugador #1:";
    getline(cin, jugador1);                  // permite agregar espacios en los nombres ej: maria isabel
    cout << "Jugador #2:";
    getline(cin, jugador2);

    /* sistema de turnos y lanzadas */
    int TrufasJ1 = 0, TrufasJ2 = 0, lanzamientos;    // contador de trufas y lanzamientos
    string jugando;                                  // variable para el jugador del turno
    for (int i = 1; i <= 5; ++i) {                   // 5 rondas en total
        jugando = jugador1;
        for (int j = 0; j < 2; ++j) {                   // 2 jugadores, jugador uno seria j=0 u jugador dos seria j=1
            lanzamientos = 0;                           // contador de lanzamientos
            do {                                        // while para lanzar otra vez
                lanzamientos ++;
                juego(jugador1, jugador2, TrufasJ1, TrufasJ2, jugando, i, lanzamientos); // turno de jugador
            } while (consulta());
         jugando = jugador2;                            // aca cambia la variable string por el nombre del jugador2
        }
    }
    return 0;
}

