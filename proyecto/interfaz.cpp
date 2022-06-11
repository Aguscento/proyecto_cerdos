#include<iostream>
#include <string>
#include "Interfaz.h"

using namespace std;

void juego(string jugador1, string jugador2, int trufasj1, int trufasj2, string turno_de, int i) {
    cout << endl << "GRAN CERDO" << endl;
    cout << "_________________________________________________________________________________" << endl;
    cout << jugador1 << ":" << trufasj1 << " trufas acumuladas" << "            " << jugador2 << ":" << trufasj2 << " trufas acumuladas" << endl;
    cout << endl << "TURNO DE " << turno_de << endl;
    cout << "+------------------------+" << endl;
    cout << "| RONDAS #" << i << "               |" << endl;
    cout << "| TRUFAS DE LA RONDA:    |" << endl;
    cout << "| lANZAMIENTOS:          |" << endl;
    cout << "+------------------------+" << endl;
}
