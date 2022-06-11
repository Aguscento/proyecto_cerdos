#include<iostream>
#include <cstring>
#include "interfaz.h"
using namespace std;

int main(){


    /* ingreso de nombre de jugadores */
    string jugador1, jugador2;                      // solicitacion de nombre de jugadores
    // cin.ignore();                                // para ignorar el "enter" en el ultimo ingreso
    cout << "Jugador #1:";
    getline(cin, jugador1);                  // permite agregar espacios en los nombres ej: maria isabel
    cout << "Jugador #2:";
    getline(cin, jugador2);

    /* sistema de turnos y lanzadas */
    int TrufasJ1 = 0, TrufasJ2 = 0;                 // contador de trufas
    string jugando;                                  // variable para el jugador del turno
    for (int i = 1; i <= 5; ++i) {                   // 5 rondas en total
        jugando = jugador1;
        for (int j = 0; j < 2; ++j) {
            do {                                        // while para lanzar otra vez
                juego(jugador1, jugador2, TrufasJ1, TrufasJ2, jugando, i ); // turno de jugador
            } while (consulta());                       // inexacto para repeterir al jugador si quiere volver a lanzar dados
         jugando = jugador2;                            // aca cambia el turno del jugador
        }


    }
    return 0;
}

