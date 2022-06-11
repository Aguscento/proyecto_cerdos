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

    /* los 5 turnos del juego y tiradas */
    int TrufasJ1 = 0, TrufasJ2 = 0;                 // contador de trufas
    for (int i = 0; i < 5; ++i) {                   // 5 rondas en total
        char continuar;                           // char para colocar S o N
        do {                                        // while para lanzar otra vez
            juego(jugador1, jugador2, TrufasJ1, TrufasJ2, jugador1 ); // turno de jugador 1
            cout << "Continuar? (S/N)" << endl;
            cin >> continuar;
        } while (continuar == 's' || continuar == 'S' );
        do {
            juego(jugador1, jugador2, TrufasJ1, TrufasJ2, jugador2 ); // turno de jugador 2
            cout << "Continuar? (S/N)" << endl;
            cin >> continuar;
        } while (continuar == 's' || continuar == 'S' );
    }
    return 0;
}

