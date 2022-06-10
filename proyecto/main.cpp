#include <stdlib.h>
#include<iostream>
#include <string>

using namespace std;

int main(){


    // ingreso de nombre de jugadores
    string jugador1, jugador2; // solicitacion de nombre de jugadores
    // cin.ignore(); // para ignorar el "enter" en el ultimo ingreso
    cout << "Jugador #1:";
    getline(cin, jugador1); // permite agregar espacios en los nombres ej: maria isabel
    cout << "Jugador #2:";
    getline(cin, jugador2);
    
    return 0;
}
